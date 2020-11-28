#include "product_scan.h"

void productScan()
{
    String productId = "";
    int quantity = 0;
    int peremtion = 0;
    product prod;

    displayReadyToScan();

    while (true)
    {
        scanListener();
        productId = getScannedCode();
        if (productId != "")
        {
            scanListener_STOP();
            String productName = getProdName(productId);
            if (productName != "error")
            {
                if (askYesNo(productName + " ?")) //TODO, scroll product name!
                {
                    quantity = setQuantity();
                    if (quantity != 0)
                    {
                        peremtion = setPeremption();
                        if (peremtion != 0)
                        {
                            if (askYesNo("Ajouter produit?"))
                            {
                                prod.id = productId;
                                prod.quantity = quantity;
                                prod.peremption = peremtion;
                                if (!sendToReserve(prod))
                                {
                                    lcdClear();
                                    lcdPrint("Echec de ");
                                    lcdCursor(1, 8);
                                    lcdPrint("l'envoie");
                                    delay(2500);
                                }
                            }
                        }
                    }
                }
                displayReadyToScan();
            }
            else
            {
                lcdClear();
                lcdPrint("Ce produit");
                lcdCursor(1, 0);
                lcdPrint("n'existe pas..");
                delay(2500);
                displayReadyToScan();
            }
            productId = "";
            quantity = 0;
            peremtion = 0;
        }
    }
}

String getProdName(String prodId)
{
    Serial.println(prodId);
    String endPoint = "/product/" + prodId;
    httpResp res = apiGET(endPoint, true);
    Serial.println(res.status);

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

void displayReadyToScan()
{
    lcdClear();
    lcdPrint("Scannez un");
    lcdCursor(1, 9);
    lcdPrint("produit !");
}