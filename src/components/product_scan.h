#ifndef product_scan_h
#define product_scan_h

#include "helpers/global.h"
#include "helpers/scan.h"
#include "helpers/lcd.h"
#include "helpers/encoder.h"
#include "helpers/setProductInfo.h"
#include "services/httpRequest.h"
#include "services/jsonMaker.h"


typedef struct product
{
    String id = "";
    int quantity = 0;
    int peremption = 0;
} product;

void productScan();
String getProdName(String prodId);
boolean sendToReserve(product prod);
void addProduct(String productId,int quantity, int peremtion);
void displayReadyToScan();

#endif