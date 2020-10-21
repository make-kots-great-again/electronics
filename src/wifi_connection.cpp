#include "wifi_connection.h"

void connectToWifi()
{
    lcdPrint("Recherche de PA");
    networks networks = listNetworks();
    lcdClear(); 
    lcdPrint("Choose Network:");
    lcdCursor(1,0); 
    lcdPrint(networks.SSID[0]);
    
    int netIndex = 0;
    encValue enc;
    while(true){
        if(!checkBtnPress().wasPressed){
            //TODO a verifier une fois composants souder!
            enc = getEncoderValue();
            if(enc.hasChanged){
                Serial.println(enc.direction);
                if(enc.direction == 1){
                    netIndex = (netIndex < networks.nets-1)?  netIndex + 1 : netIndex;
                    lcdClearLine(1);
                    lcdPrint(networks.SSID[netIndex]);
                }
                else if(enc.direction == -1){
                    netIndex = (netIndex > 0)?  netIndex - 1 : netIndex;
                    lcdClearLine(1);
                    lcdPrint(networks.SSID[netIndex]);
                }
            }
        }
        else{
            if(checkBtnPress().time < 1000){
                if(connectToNetwork(networks.SSID[netIndex],getPassword())){
                    //Connection réussie
                    lcdClear();
                    lcdPrint("Conn. réussie!");
                    delay(2500);
                    lcdClear();
                    break;
                }
                else{
                    //Connection échouée
                    lcdClear();
                    lcdPrint("Conn. échouée!");
                    delay(2500);
                    lcdClear();
                    connectToWifi();
                    break;
                }
            }
            else{
                //l'utilisateur souhaite rafraîchir la liste des PA.
                networks = listNetworks();
            }
        }

    }
}


String getPassword()
{
    //TODO
}
