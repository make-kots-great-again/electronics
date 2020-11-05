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

#include "services/jsonMaker.h"
#include "services/httpRequest.h"

#include "components/wifi_connection.h"
#include "components/group_connection.h"


void testingLoop();

#endif
