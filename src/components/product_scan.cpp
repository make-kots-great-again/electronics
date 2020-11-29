#include "product_scan.h"

void productScan()
{
    String productId = "";
    int quantity = 0;
    int peremtion = 0;

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
                    if (quantity > 0)
                    {
                        peremtion = setPeremption();
                        if (peremtion != 0)
                        {
                            if (askYesNo("Ajouter produit?"))
                            {
                                addProduct(productId,quantity,peremtion);
                            }
                        }
                    }
                    else if (quantity < 0)
                    {
                        if (askYesNo("Retirer produit?"))
                        {
                            addProduct(productId,quantity,peremtion);
                        }
                    }
                }
                displayReadyToScan();
            }
            else
            {
                lcdClear();
                lcdCursor(0, 3);
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

void addProduct(String productId,int quantity, int peremtion)
{
    product prod;

    prod.id = productId;
    prod.quantity = quantity;
    prod.peremption = peremtion;
    if (!sendToReserve(prod))
    {
        lcdClear();
        lcdCursor(0, 4);
        lcdPrint("Echec de ");
        lcdCursor(1, 4);
        lcdPrint("l'envoie");
        delay(2500);
    }
}

void displayReadyToScan()
{
    lcdClear();
    lcdCursor(0, 3);
    lcdPrint("Scannez un");
    lcdCursor(1, 4);
    lcdPrint("produit !");
}