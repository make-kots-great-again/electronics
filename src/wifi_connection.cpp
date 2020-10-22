#include "wifi_connection.h"

networks nets;

void connectToWifi()
{
    lcdClear();
    lcdPrint("Recherche de PA");
    nets = listNetworks();
    lcdClear();
    lcdPrint("Choix PA :");
    lcdCursor(0, 13);
    lcdPrint("1/");
    lcdPrint(String(nets.nets));
    lcdCursor(1, 0);
    lcdPrint(nets.SSID[0]);

    int netIndex = 0;
    encValue enc;
    while (true)
    {
        if (!checkBtnPress().wasPressed)
        {
            enc = getEncoderValue();
            if (enc.hasChanged)
            {
                if (enc.direction == 1)
                {
                    netIndex = (netIndex < nets.nets - 1) ? netIndex + 1 : netIndex;
                    printCurrentNet(netIndex);
                }
                else if (enc.direction == -1)
                {
                    netIndex = (netIndex > 0) ? netIndex - 1 : netIndex;
                    printCurrentNet(netIndex);
                }
            }
        }
        else
        {
            if (checkBtnPress().time < 1000)
            {   String net = nets.SSID[netIndex];
                int  connStatus = connectToNetwork(net, getPassword(net));
                if (connStatus == 1)
                {
                    //Connection réussie
                    lcdClear();
                    lcdPrint("Conn. reussie!");
                    delay(2500);
                    lcdClear();
                    break;
                }
                else if (connStatus == -1)
                {
                    //Connection échouée
                    lcdClear();
                    lcdPrint("Conn. echouee!");
                    delay(2500);
                    lcdClear();
                    connectToWifi();
                    break;
                }
                else
                {
                    connectToWifi();
                    break;
                }
            }
            else
            {
                //l'utilisateur souhaite rafraîchir la liste des PA.
                connectToWifi();
                break;
            }
        }
    }
}

String choices = "        0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ _-?!,.:;%#*<>+=        ";

String getPassword(String ssid)
{
    int charIndex = 8; //position du premier char.
    String pwd = "";
    encValue enc;

    lcdClear();
    lcdPrint("Entrez mdp :");
    printCurrentChar(8);

    while (true)
    {
        if (!checkBtnPress().wasPressed)
        {
            enc = getEncoderValue();
            if (enc.hasChanged)
            {
                if (enc.direction == 1)
                {
                    charIndex = (charIndex < choices.length() - 9) ? charIndex + 1 : charIndex;
                    printCurrentChar(charIndex);
                }
                else if (enc.direction == -1)
                {
                    charIndex = (charIndex > 8) ? charIndex - 1 : charIndex;
                    printCurrentChar(charIndex);
                }
            }
        }
        else
        {
            if (checkBtnPress().time < 1000)
            {
                if (choices[charIndex] == '•'){
                    lcdClear(); lcdPrint("Connection a :");
                    lcdCursor(1,0); lcdPrint(ssid);
                    Serial.println(pwd);
                }
                else{
                    pwd += choices[charIndex]; //TODO replace 0 by value
                }
            }
            else
            {
                pwd = "0"; //annulation de la tentative de connection
                break;
            }
        }
    }
    return pwd;
}

void printCurrentNet(int index){
    lcdCursor(0, 13);lcdPrint(String(index+1));
    lcdClearLine(1);
    lcdPrint(nets.SSID[index]);
}

void printCurrentChar(int index){
    //TODO highlight character 
    String leftChoices = choices.substring(index-6,index);
    String rightChoices = choices.substring(index+1,index+8);
    lcdClearLine(1);
    lcdCursor(1,0);
    lcdPrint(leftChoices);
    lcdCursor(1,7);
    lcdPrintChar(choices[index]);
    lcdCursor(1,9);
    lcdPrint(rightChoices);
}