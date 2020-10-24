#include "eepromData.h"

/**
 * 
 * Les 3 premier bits nous donnes les informations sur la longeur de chaque données: 
 * addr: 
 *  0 => addr du dernier char du SSID
 *  1 => addr du dernier char du Password
 *  2 => addr du dernier char du Groupe ID
 * 
 *  5 => Début de notre data
 */


const byte dataAddrStart = 5; 

String SSID = "";
String PWD = "";
String GROUPID = "";

void eepromDataSetup(){
    byte ssidLastBit = EEPROM.read(0);
    int ssidLen = ssidLastBit - dataAddrStart;
    byte pwdLastBit = EEPROM.read(1);
    int pwdLen = pwdLastBit - ssidLastBit;
    byte groupLastBit = EEPROM.read(2);
    int groupLen = groupLastBit - pwdLastBit;

    if(ssidLastBit != 0){
        for(byte i = 0; i < ssidLen; i++){
            SSID += String(char(EEPROM.read(dataAddrStart+i)));
        }
        for(byte i = 0; i < pwdLen; i++){
            PWD += String(char(EEPROM.read(ssidLastBit + i)));
        }
    }

    if(groupLastBit != 0){
        for(byte i = 0; i < groupLen; i++){
            GROUPID += String(char(EEPROM.read(pwdLastBit + i)));
        }
    }

}


void eepromSetSSID_PWD(String ssid, String pwd){
    eepromSetAllData(ssid,pwd,GROUPID);
}

void eepromSetGroup(String groupId){
    eepromSetAllData(SSID,PWD,groupId);
}

void eepromSetAllData(String ssid, String pwd, String group){
    eepromClear();    
    EEPROM.write(0, dataAddrStart + ssid.length());
    EEPROM.write(1, dataAddrStart + ssid.length() + pwd.length());
    EEPROM.write(2, dataAddrStart + ssid.length() + pwd.length() + group.length());
    for (unsigned int i = 0 ; i < ssid.length() ; i++) {
        EEPROM.write(dataAddrStart + i, ssid[i]);
    }
    for (unsigned int i = 0 ; i < pwd.length() ; i++) {
        EEPROM.write(dataAddrStart + ssid.length() + i, pwd[i]);
    }
    for (unsigned int i = 0 ; i < group.length() ; i++) {
        EEPROM.write(dataAddrStart + ssid.length() + pwd.length() + i, group[i]);
    }
}

String eepromGetSSID(){
    return SSID;
}

String eepromGetPWD(){
    return PWD;
}

String eepromGetGroup(){
    return GROUPID;
}

void eepromClear(){
    for (unsigned int i = 0 ; i < EEPROM.length() ; i++) {
        EEPROM.write(i, 0);
    }
}