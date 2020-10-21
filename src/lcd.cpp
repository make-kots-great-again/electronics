#include "lcd.h"

//LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidCrystal_I2C_GY lcd(0x38,16,2); //! Uniquement pour LCD de martin (pas le meme chipset)

void lcdSetup() {
    //lcd.begin();
    lcd.init(); //! Uniquement pour LCD de martin (pas le meme chipset)
    lcd.backlight();       
    lcd.noAutoscroll();
    lcd.setCursor(0, 0); 
    lcd.print("Ready");
};

void lcdPrint(String s){
    lcd.print(s);
};

void lcdPrintChar(char c){
    lcd.print(c);
};

void lcdClear(){
    lcd.clear();
};

void lcdCursor(int r, int c){
    lcd.setCursor(r,c);
}