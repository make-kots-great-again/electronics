#include "product_service.h"

String getProdName(String prodId)
{
    String endPoint = "/product/" + prodId;
    httpResp res = apiGET(endPoint, true);

    if (res.status == 200)
    {
        return getObject(getObject(res.body)["product"])["product_name"];
    }

    return "error";
}

boolean sendToReserve(product product, String groupId)
{
    String endPoint = "/reserve/" + groupId;
    Serial.println(endPoint);
    DynamicJsonDocument prod(1024);
    prod["code"] = product.id.toInt();
    prod["quantity"] = product.quantity;
    prod["expiringIn"] = product.peremption;
    String body = makeJsonString(prod);
    Serial.println(body);

    httpResp res = apiPOST(endPoint, body, true);  
    Serial.println(res.status);
    Serial.println(res.message);
    if (res.status == 200)
    {
        return true;
    }

    return false;
}