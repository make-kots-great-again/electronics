#ifndef esp_h
#define esp_h

#include "WiFiEsp.h"

const int maxNumberOfNetworks = 50;

/**
 * @param {String[]} SSID - array de string contant le nom des réseaux
 * @param {int} RSSI - puissance du signal en dB
 * @param {int} nets - nombre de réseaux 
 */
typedef struct networks
{
    String SSID[maxNumberOfNetworks];
    int RSSI[maxNumberOfNetworks];
    int nets = 0;
} networks;

void espSetup();
networks listNetworks();
int connectToNetwork(String SSID, String pwd);

#endif