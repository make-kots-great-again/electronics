#ifndef group_connection_h
#define group_connection_h

#include "helpers/global.h"
#include "helpers/scan.h"
#include "helpers/lcd.h"
#include "helpers/encoder.h"
#include "helpers/eepromData.h"
#include "helpers/httpRequest.h"
#include "helpers/jsonMaker.h"

#include "services/group_service.h"

void connectToGroup();
boolean newGroupCon();
boolean autoConnectGroup();
boolean getJWT(String groupId);
void displayGroupCon();

#endif