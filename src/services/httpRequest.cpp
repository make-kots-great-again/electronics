#include "httpRequest.h"

WiFiEspClient client;

char serverURL[] = "kotsapp.herokuapp.com";
String apiURL = "/server/api";
String endLine = "\r\n";
unsigned int timeOut = 10000; //temps max d'attente de réponse du serveur (ms)
unsigned int currentTime = 0;

httpResp res;

//TODO replace JWT with real jwt from EEPROM 
const String JWT = "JWT eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6ImphbWVzQGdtYWlsLmNvbSIsInVzZXJJZCI6ImEzZTg3OGY1LWNiOGUtNGUzYi05MGM0LWVlOGY4MDU0MDc3YyIsImlhdCI6MTYwMzQ2NTI4OCwiZXhwIjoxNjA0MDcwMDg4fQ.k2s5Bp0tE95Pmn71D7IitG4weigt1R-LYwlAjcr2lDQ";

/**
 * Fonction permettant d'envoyer une requête GET à notre serveur à un endpoint donnée.
 * @param {String} endpint - de la requête api
 * @param {boolean} withAuth - (OPTIONNEL) si true, ajout du header "Authorization JWT"
 * @return {httpResp} voir doc de la structure
 */
httpResp apiGET(String endPoint, boolean withAuth = false){
    String reqHeaders = "GET https://"+ String(serverURL) + apiURL + endPoint + " HTTP/1.1" + endLine;
    reqHeaders += "Connection: keep-alive" + endLine;
    reqHeaders += "Host: " + String(serverURL) + endLine;
    if(withAuth){
        reqHeaders += "Authorization: " + JWT + endLine;
    }
    
    if (client.connectSSL(serverURL, 443)) {
        client.println(reqHeaders);
    }

    waitForResponse();
    
    return res;
}

/**
 * Fonction permettant d'envoyer une requête POST à notre serveur à un endpoint donnée.
 * @param {String} endpint - de la requête api
 * @param {String} jsonData - les données à envoyer en format JSON
 * @param {boolean} withAuth - (OPTIONNEL) si true, ajout du header "Authorization JWT"
 * @return {httpResp} voir doc de la structure
 */
httpResp apiPOST(String endPoint, String jsonData, boolean withAuth = false){
    String reqHeaders = "POST https://"+ String(serverURL) + apiURL + endPoint + " HTTP/1.1" + endLine;
    reqHeaders += "Connection: keep-alive" + endLine;
    reqHeaders += "Content-Type: application/json; charset=utf-8" + endLine;
    reqHeaders += "Host: " + String(serverURL) + endLine;
    if(withAuth){
        reqHeaders += "Authorization: " + JWT + endLine;
    }
    reqHeaders += "Content-Length: " + String(jsonData.length()) + endLine + endLine;
    reqHeaders += jsonData;

    if (client.connectSSL(serverURL, 443)) {
        client.println(reqHeaders);
    }

    waitForResponse();
    
    return res;
}


void waitForResponse(){
    currentTime = millis();
    int lineNumber = 0;
    byte returnNumber = 0;
    boolean finishedReading = false;
    String statusLine = "";
    String body = "";
    String other = "";

    while(true){
        while(client.available()) {
            char c = client.read();
            if(c == '\r'){
                lineNumber ++;
                returnNumber ++;
            }
            if(returnNumber == 2){
                if(c != '\r' && c != '\n'){
                    body += String(c);
                }
            }
            else{
                if(c != '\r' && c != '\n'){
                    returnNumber = 0;
                }
                if(lineNumber == 0){
                    statusLine += String(c);
                }
                else{
                    other += String(c);
                }
            }
            finishedReading = true;
        }
        if(finishedReading){
            res.status = statusLine.substring(9,12).toInt();
            res.message = statusLine.substring(13);
            res.body = body;
            //Serial.println(other);
            client.stop();
            break;
        }
        else if(millis()-currentTime > timeOut){
            res.status = 500;
            res.message = "server response timeout";
            res.body = "";
            client.stop();
            break;
        }
    }
}