#include "product.h"

/**
 * Fonction qui demande à l'utilisateur de mettre la quantité de produit 
 * qu'il souhaite envoyer.
 * @return int compt
 */
int setQuantity() {
    int compt(0) ;
    encValue enc;

    enc = getEncoderValue();

    if (enc.hasChanged) {
       lcdClear();
        compt = enc.value;
        if (enc.value < 0){
            resetEncoderValue();
        }
        else{
            compt = enc.value;
        }
        lcdPrint("Quantity: "+String(compt));    
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
/**
 * Fonction qui demande à l'utilisateur de mettre la date de péremption
 * du produit qu'il a entré
 * @return int compt
 */
int setPeremption(){
    int jour(0);
    int mois(0);
    int annee(0);

    encValue enc;
    enc = getEncoderValue();
    if (enc.hasChanged) {
        //TODO
    }
    if (checkBtnPress().wasPressed) {
        //TODO
    }
    return 0;
}
int test(){
    return 0;
}