#ifndef wifi_connection_h
#define wifi_connection_h

#include "helpers/esp.h"
#include "helpers/lcd.h"
#include "helpers/encoder.h"
#include "helpers/eepromData.h"

void connectToWifi();
void newWifiCon();
boolean autoConnect();
boolean askAutoConnect();
String getPassword(String ssid);
void printCurrentNet(int index);
void printCurrentChar(int index);

#endif