#include "product.h"

/**
 * Fonction qui demande à l'utilisateur de mettre la quantité de produit 
 * qu'il souhaite envoyer.
 * @return int compt
 */
int setQuantity()
{
    int compt(0);
    encValue enc;
    while (true)
    {
        enc = getEncoderValue();
        if (enc.hasChanged)
        {
            lcdClear();
            compt = enc.value;
            lcdPrint("Quantity: " + String(compt));
        };
        if (checkBtnPress().wasPressed)
        {
            if (askConfirmation())//demande de confirmation
            {
                lcdClear();
                lcdPrint("envoi !");
                return compt;
            }
            else
            {
                peremption();
            }
        };
    };
    return compt;
}

/**
 * Fonction qui demande à l'utilisateur de mettre la date de péremption
 * du produit qu'il a entré avec confirmation de l'utilisateur
 * @return int date
 */
int peremption()
{

    int date;
    date = setPeremption();
    lcdClear();
    lcdPrint("confirmation ?");
    lcdCursor(1, 0);
    lcdPrint(String(date));
    delay(2500);
    if (askConfirmation()){//demande de confirmation
        lcdClear();
        lcdPrint("envoi !");
        return date;
    }
    else
    {
        peremption();
    }
    return date;
}
/**
 * Fonction qui demande à l'utilisateur de mettre la quantité de produit 
 * qu'il souhaite envoyer.
 * @return int compt
 */
int setPeremption()
{
    int compt(1);
    encValue enc;

    while (true)
    {
        enc = getEncoderValue();
        if (enc.hasChanged)
        {
            lcdClear();
            compt = enc.value + 1;
            if (enc.value < 0)
            {
                resetEncoderValue();
            }
            else
            {
                compt = enc.value + 1;
            }
            lcdPrint("Peremption dans:");
            lcdCursor(1, 0);
            lcdPrint(String(compt) + " jour(s)");
        };
        if (checkBtnPress().wasPressed)
        {
            lcdClear();
            lcdPrint("ok !");
            delay(1000);
            resetEncoderValue();
            return compt;
        };
    }
    return compt;
}
/**
 * Demande confirmation à l'utilisateur dans le LCD
 * @return boolean 
 */
boolean askConfirmation()
{
    String yesNo = "Y";
    encValue enc;
    lcdClear();
    lcdPrint("Confirmation ");
    lcdCursor(1, 11);
    lcdPrint("N");
    lcdCursor(1, 4);
    lcdPrint("Y");
    lcdCursor(1, 4);
    lcdShowCursor(true);
    while (true)
    {
        if (!checkBtnPress().wasPressed)
        {
            enc = getEncoderValue();
            if (enc.hasChanged)
            {
                if (enc.direction == 1)
                {
                    lcdCursor(1, 11);
                    yesNo = "N";
                }
                else if (enc.direction == -1)
                {
                    lcdCursor(1, 4);
                    yesNo = "Y";
                }
            }
        }
        else
        {
            lcdShowCursor(false);
            return (yesNo == "Y") ? true : false;
            break;
        }
    }
    return false;
}