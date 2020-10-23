#include "esp.h"

/**
 * Fonction setup
 */
void espSetup()
{
    Serial1.begin(115200);
    WiFi.init(&Serial1);
}

/**
 * Fonction récupérant tous les réseau wifi détecté.
 * @return networks: objet contenant 
 *              - les SSID's (String[])
 *              - la qualité de chaque réseau (int[])
 *              - le nombre de réseau (int)
 */
networks listNetworks()
{
    int numSsid = WiFi.scanNetworks();
    networks networks;
    if (numSsid == -1)
    {
       return networks;
    }
    else
    {   //TODO vérifier si le réseau n'as pas déjà été ajouté!
        numSsid = (numSsid > maxNumberOfNetworks)? maxNumberOfNetworks : numSsid;
        networks.nets = numSsid;
        for( int net = 0; net < numSsid; net++ ){
            networks.SSID[net]= WiFi.SSID(net);
            networks.RSSI[net]= WiFi.RSSI(net);
        }
        return networks;
    }
}

/**
 * Fonction permettant de se connecter à un certain réseau wifi.
 * @param SSID:String Le nom du réseau.
 * @param PWD:String Le mot de passe du réseau (WPA2).
 * @return int: 
 *              1   si la connection a réussie
 *              -1  si la connection a échouée
 *              0   si l'opération a été annulée 
 */
int connectToNetwork(String SSID, String PWD)
{
    if (PWD == "0"){
        return 0;
    }
    char ssid[1000]; SSID.toCharArray(ssid,1000);
    char pass[1000]; PWD.toCharArray(pass,1000);
    int status = WL_IDLE_STATUS; //statut de la connection
    int connAttempts = 0;
    while ( status != WL_CONNECTED && connAttempts < 3) {
        status = WiFi.begin(ssid, pass);
        connAttempts ++;
    }
    return (status != WL_CONNECTED) ? -1 : 1; 
}
