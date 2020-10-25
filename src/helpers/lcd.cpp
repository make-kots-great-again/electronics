#include "lcd.h"

#if ENV_MARTIN == true
    #include <LiquidCrystal_I2C_GY.h>
    LiquidCrystal_I2C_GY lcd(0x38,16,2);
#else
    #include <LiquidCrystal_I2C.h>
    LiquidCrystal_I2C lcd(0x27, 16, 2);
#endif

byte rightBar[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
};
byte leftBar[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};


void lcdSetup() {
    lcd.init();
    //lcd.begin();
    lcd.backlight();       
    lcd.noAutoscroll();
    lcd.setCursor(0, 0); 
    lcd.createChar(0, leftBar);
    lcd.createChar(1, rightBar);
};

void lcdPrint(String s){
    lcd.print(s);
};

void lcdPrint(char c){
    lcd.print(c);
};

void lcdClear(){
    lcd.clear();
};

void lcdCursor(int r, int c){
    lcd.setCursor(c,r);
}

void lcdClearLine(int r){
    lcd.setCursor(0,r);
    lcd.print("                ");
    lcd.setCursor(0,r);
}

void lcdShowCursor(boolean show){
    (show)? lcd.cursor_on() : lcd.cursor_off();
}

void lcdPrintCustomChar(byte id) {
    lcd.write(id);
}