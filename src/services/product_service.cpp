#include "product_service.h"

String getProdName(String prodId)
{
    String endPoint = "/product/" + prodId;
    httpResp res = apiGET(endPoint, true);

    if (res.status == 200)
    {
        return getObject(getObject(res.body)["productInfo"])["product_name"];
    }

    return "error";
}

boolean sendToReserve(product product, String groupId)
{
    String endPoint = "/reserve/" + groupId;
    DynamicJsonDocument prod(1024);
    prod["code"] = product.id.toInt();
    prod["quantity"] = product.quantity;
    prod["expiringIn"] = product.peremption;
    String body = makeJsonString(prod);

    httpResp res = apiPOST(endPoint, body, true);  
    if (res.status == 200)
    {
        return true;
    }

    return false;
}