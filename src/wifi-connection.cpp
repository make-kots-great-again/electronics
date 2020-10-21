#include "wifi-connection.h"

void connectToWifi()
{
    lcdPrint("Recherche de PA");
    networks networks = listNetworks();
    lcdClear(); 
    lcdPrint("Choose Network:");
    lcdCursor(1,0); 
    lcdPrint(networks.SSID[0]);
    while(!checkBtnPress().wasPressed){
        if(getEncoderValue().hasChanged){
            lcdPrint(String(getEncoderValue().direction));
        }
    }
    

}