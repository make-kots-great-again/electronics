#ifndef product_service_h
#define product_service_h

#include "helpers/httpRequest.h"
#include "helpers/jsonMaker.h"

typedef struct product
{
    String id = "";
    int quantity = 0;
    int peremption = 0;
} product;

String getProdName(String prodId);
boolean sendToReserve(product product, String groupId);

#endif