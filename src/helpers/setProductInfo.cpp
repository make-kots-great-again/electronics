#include "setProductInfo.h"

/**
 * Fonction qui demande à l'utilisateur de mettre la quantité de produit 
 * @return int compt
 */
int setQuantity()
{
    int compt(0);
    encValue enc;
    resetEncoderValue();

    lcdClear();
    lcdPrint("Quantity: " + String(compt));

    while (true)
    {
        enc = getEncoderValue();
        if (enc.hasChanged)
        {
            compt = enc.value;
            lcdClear();
            lcdPrint("Quantity: " + String(compt));
        }
        if (checkBtnPress().wasPressed)
        {
            if (checkBtnPress().time < 1000) {
                break;
            }
            compt = 0;
            break;
        }
    };
    return compt;
}

/**
 * Fonction qui demande à l'utilisateur de mettre le temps de péremption du produit 
 * @return int compt
 */
int setPeremption()
{
    int compt(1);
    encValue enc;
    resetEncoderValue();

    lcdClear();
    lcdPrint("Peremption dans:");
    lcdCursor(1, 0);
    lcdPrint(String(compt) + " jour(s)");


    while (true)
    {
        enc = getEncoderValue();
        if (enc.hasChanged)
        {
            compt = enc.value + 1;
            if (enc.value < 0)
            {
                resetEncoderValue();
            }
            lcdClearLine(1);
            lcdPrint(String(compt) + " jour(s)");
        };
        if (checkBtnPress().wasPressed)
        {
            if (checkBtnPress().time < 1000) {
                break;
            }
            compt = 0;
            break;
        };
    }
    return compt;
}
