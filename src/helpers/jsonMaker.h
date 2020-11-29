#ifndef jsonMaker_h
#define jsonMaker_h

#include "ArduinoJson.h"

String makeJsonString(DynamicJsonDocument obj);
DynamicJsonDocument getObject(String jsonString);

#endif
