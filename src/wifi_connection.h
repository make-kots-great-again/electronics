#ifndef wifi_connection_h
#define wifi_connection_h

#include "esp.h"
#include "lcd.h"
#include "encoder.h"

void connectToWifi();
String getPassword(String ssid);
void printCurrentNet(int index);
void printCurrentChar(int index);

#endif