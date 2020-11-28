#include "group_connection.h"

String groupId = "";
//String groupId = "f0ae70e4939a"; //! Décommenter et remplacer le string par le groupBarCode d'un groupe existant

void connectToGroup()
{
    if (!autoConnectGroup())
    {
        newGroupCon();
    }
}

void newGroupCon()
{
    lcdClear();
    lcdPrint("Scannez le code-");
    lcdCursor(1,0);
    lcdPrint("barre du groupe");

    while(true) //! METTRE a false pour pouvoir se connecter au group sans scanner
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

    getJWT(groupId);
}

boolean autoConnectGroup()
{   
    String groupId = eepromGetGroup();
    if (groupId != "")
    {
        if (askYesNo("Auto-con GROUP ?"))
        {
            displayGroupCon();
            return getJWT(groupId);
        }
        return false;
    }
    return false;
}

boolean getJWT(String groupId)
{   
    String endPoint = "/group/token/" + groupId;
    httpResp res = apiGET(endPoint);
    if(res.status == 200){
        setJWT(getObject(res.body)["token"]);
        lcdClear();
        lcdPrint("Connexion");
        lcdCursor(1, 9);
        lcdPrint("reussie");
        delay(2500);
        lcdClear();
        return true;
    }
    else{
        lcdClear();
        lcdPrint("Connexion");
        lcdCursor(1, 9);
        lcdPrint("echouee");
        delay(2500);
        lcdClear();
        return false;
    }
}


void displayGroupCon(){
    lcdClear();
    lcdPrint("Connexion au ");
    lcdCursor(1, 0);
    lcdPrint("groupe");
}