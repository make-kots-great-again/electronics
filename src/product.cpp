#include "product.h"
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