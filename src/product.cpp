#include "product.h"

/**
 * Fonction qui demande à l'utilisateur de mettre la quantité de produit 
 * qu'il souhaite envoyer.
 * @return int compt
 */
int getQuantity() {
    int compt = 0 ;
    encValue enc;

    enc = getEncoderValue();

    if (enc.hasChanged) {
       lcdClear();
        compt = enc.value;
        lcdPrint("Quantity: "+String(enc.value));    
    };
    if (checkBtnPress().wasPressed) {
        if(checkBtnPress().time < 1000){
            lcdClear();               
            lcdPrint("envoi!");
            delay(1000);
            lcdClear();
            if (compt<0){
                compt = 0;
            };
            resetEncoderValue();
            return compt;
        }
        else{
            lcdClear();
            resetEncoderValue();
            lcdPrint("Annulation");
            delay(2500);
        };   
    };
}

int test(){
}