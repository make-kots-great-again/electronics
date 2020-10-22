#include "product.h"
int getQuantity() {
    
    int compt(0);
    encValue enc;

    lcdClear();
    lcdPrint("Quantity: 0");


    while(true){
        if(getEncoderValue().hasChanged){
            enc = getEncoderValue();
            if(enc.direction==1){
                compt++;
            }
            else{
                compt--;
                if(compt<=0){
                    compt = 0;
                }
            }
            lcdClear();
            lcdPrint("Quantity: "+ compt);
        }
        else{
            if(checkBtnPress().wasPressed){
                lcdClear();
                lcdPrint("Confirmation");
                if(checkBtnPress().time < 1000){
                    break;
                }
                else{
                    lcdPrint("Annulation");
                }
            }
        }
    }
    lcdClear();
    lcdPrint("Quantity confirmed");
    return compt;
}