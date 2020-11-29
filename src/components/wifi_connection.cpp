#include "wifi_connection.h"

networks nets;

void connectToWifi()
{
    if (!autoConnect())
    {
        newWifiCon();
    }
}

void newWifiCon()
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
            {
                String net = nets.SSID[netIndex];
                String pass = getPassword(net);
                int connStatus = connectToNetwork(net, pass);
                if (connStatus == 1)
                {
                    eepromSetSSID_PWD(net, pass);
                    //Connection réussie
                    dispCon_OK();
                    break;
                }
                else if (connStatus == -1)
                {
                    //Connection échouée
                    dispCon_NOK();
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

char confirmChar = 0x00 + 126;
String confirm = String(confirmChar);
String choices = "        " + confirm + "0123456789" + confirm + "abcdefghijklmnopqrstuvwxyz" + confirm + "ABCDEFGHIJKLMNOPQRSTUVWXYZ" + confirm + " _-?!,.:;%#*<>+=" + confirm + "        ";

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
                if (choices[charIndex] == confirmChar)
                {
                    lcdClear();
                    lcdPrint("Connexion a :");
                    lcdCursor(1, 0);
                    lcdPrint(ssid);
                    break;
                }
                else
                {
                    pwd += choices[charIndex];
                    delay(100); //débounce
                }
            }
            else
            {
                pwd = "-1"; //annulation de la tentative de connection
                break;
            }
        }
    }
    return pwd;
}

void printCurrentNet(int index)
{
    lcdCursor(0, 13);
    lcdPrint(String(index + 1));
    lcdClearLine(1);
    lcdPrint(nets.SSID[index]);
}

void printCurrentChar(int index)
{
    String leftChoices = choices.substring(index - 6, index);
    String rightChoices = choices.substring(index + 1, index + 8);
    lcdClearLine(1);
    lcdCursor(1, 0);
    lcdPrint(leftChoices);
    lcdCursor(1, 6);
    lcdPrintCustomChar(1);
    lcdCursor(1, 7);
    lcdPrint(choices[index]);
    lcdCursor(1, 8);
    lcdPrintCustomChar(0);
    lcdCursor(1, 9);
    lcdPrint(rightChoices);
}

boolean autoConnect()
{
    if (eepromGetSSID() != "")
    {
        if (askYesNo("Auto-con WIFI ?"))
        {
            lcdClear();
            lcdPrint("Connexion a :");
            lcdCursor(1, 0);
            lcdPrint(eepromGetSSID());
            int connStatus = connectToNetwork(eepromGetSSID(), eepromGetPWD());
            if (connStatus == 1)
            {
                //Connection réussie
                dispCon_OK();
                return true;
            }
            else if (connStatus == -1)
            {
                //Connection échouée
                dispCon_NOK();
                return false;
            }
        }
        return false;
    }
    return false;
}
