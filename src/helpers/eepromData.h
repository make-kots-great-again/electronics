#ifndef eepromData_h
#define eepromData_h

#include <Arduino.h>
#include <EEPROM.h>

void eepromDataSetup();
void eepromSetSSID_PWD(String ssid, String pwd);
void eepromSetGroup(String groupId);
void eepromSetAllData(String ssid, String pwd, String group);
String eepromGetSSID();
String eepromGetPWD();
String eepromGetGroup();
void eepromClear();

#endif