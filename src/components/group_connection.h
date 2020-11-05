#ifndef group_connection_h
#define group_connection_h

#include "helpers/global.h"
#include "helpers/scan.h"
#include "helpers/lcd.h"
#include "helpers/encoder.h"
#include "helpers/eepromData.h"
#include "services/httpRequest.h"
#include "services/jsonMaker.h"

void connectToGroup();
void newGroupCon();
boolean autoConnectGroup();
boolean getJWT(String groupId);

#endif