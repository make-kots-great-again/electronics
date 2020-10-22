#ifndef lcd_h
#define lcd_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
//#include <LiquidCrystal_I2C_GY.h> //! Uniquement pour LCD de martin (pas le meme chipset) => //TODO a supprimer une fois en prod

void lcdSetup();
void lcdClear();
void lcdCursor(int r, int c);
void lcdPrint(String s);
void lcdPrintChar(char c);
void lcdClearLine(int r);
void lcdShowCursor(boolean show);
void lcdPrintCustomChar(byte id);

#endif
