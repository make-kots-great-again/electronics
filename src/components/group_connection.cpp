#include "group_connection.h"

String groupId = "";

void connectToGroup()
{   
    if (!autoConnectGroup())
    {
        if(!newGroupCon()){
            connectToGroup();
        }
    }
}

boolean newGroupCon()
{
    lcdClear();
    lcdPrint("Scannez le code-");
    lcdCursor(1,0);
    lcdPrint("barre du groupe");

    while(true) 
    {   
        scanListener();
        groupId = getScannedCode();
        if(groupId != ""){
            scanListener_STOP();
            displayGroupCon();
            eepromSetGroup(groupId);
            break;
        }
    }

    //return getJWT(groupId);
    return getGroupJWT(groupId);
}

boolean autoConnectGroup()
{   
    String groupId = eepromGetGroup();
    if (groupId != "")
    {
        if (askYesNo("Auto-con GROUP ?"))
        {
            displayGroupCon();
            //return getJWT(groupId);
            return getGroupJWT(groupId);
        }
    }
    return false;
}


void displayGroupCon(){
    lcdClear();
    lcdPrint("Connexion au ");
    lcdCursor(1, 0);
    lcdPrint("groupe");
}