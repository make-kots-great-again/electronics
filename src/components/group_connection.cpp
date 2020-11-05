#include "group_connection.h"

//String groupId = "";
String groupId = "3eb8df17-bdd4-4130-b5e4-a79b89204f30"; //TODO supprimer apres tests

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

    while(false) //TODO set to TRUE ! 
    {   
        scanListener();
        groupId = getScannedCode();
        if(groupId != ""){
            break;
        }
    }

    getJWT(groupId);
}

boolean autoConnectGroup()
{
    return false;
}

void getJWT(String groupId)
{   
    String endPoint = "/group/token/" + groupId;
    httpResp res = apiGET(endPoint);
    setJWT(getObject(res.body)["token"]);
    lcdClear();
    lcdPrint("Connexion");
    lcdCursor(1, 9);
    lcdPrint("reussie");
    delay(2500);
    lcdClear();
}