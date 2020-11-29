#ifndef httpRequest_h
#define httpRequest_h

#include ".env.h"
#include "global.h"
#include "esp.h"

/**
 * @param {unsigned-int} status - le statut de la requête: 200,404,500,...
 * @param {String} message - le message associé au statut  
 * @param {String} body - la réponse en elle-même 
 */
typedef struct httpResp {
    unsigned int status = 0;
    String message = "";
    String body = "";
} httpResp;

httpResp apiGET(String endPoint, boolean withAuth = false);
httpResp apiPOST(String endPoint, String jsonData, boolean withAuth = false);
httpResp waitForResponse();
#endif
