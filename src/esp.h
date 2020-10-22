#ifndef esp_h
#define esp_h

#include "WiFiEsp.h"

const int maxNumberOfNetworks = 50;

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