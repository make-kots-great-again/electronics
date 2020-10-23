#ifndef httpRequest_h
#define httpRequest_h

#include "esp.h"

typedef struct httpResp {
    unsigned int status;
    String message;
    String body;
} httpResp;

httpResp apiGET(String endPoint, boolean withAuth = false);
httpResp apiPOST(String endPoint, String jsonData, boolean withAuth = false);
void waitForResponse();
#endif
