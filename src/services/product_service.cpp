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

boolean sendToReserve(product prod)
{
    //TODO
    return false;
}