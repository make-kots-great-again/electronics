#ifndef main_h
#define main_h

#include <Arduino.h>
#include <Wire.h>

#include "helpers/global.h"
#include "helpers/lcd.h"
#include "helpers/scan.h"
#include "helpers/encoder.h"
#include "helpers/esp.h"
#include "helpers/eepromData.h"
#include "helpers/jsonMaker.h"
#include "helpers/httpRequest.h"

#include "components/wifi_connection.h"
#include "components/group_connection.h"
#include "components/product_scan.h"

void scannerTest();
void encoderTest();
void espAPITest();

#endif
