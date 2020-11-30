#ifndef product_scan_h
#define product_scan_h

#include "helpers/global.h"
#include "helpers/scan.h"
#include "helpers/lcd.h"
#include "helpers/encoder.h"
#include "helpers/setProductInfo.h"
#include "helpers/httpRequest.h"
#include "helpers/jsonMaker.h"
#include "helpers/eepromData.h"

#include "services/product_service.h"


void productScan();
void addProduct(String productId,int quantity, int peremtion);
void displayReadyToScan();

#endif