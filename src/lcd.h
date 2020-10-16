#ifndef lcd_h
#define lcd_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

void lcdSetup();
void lcdClear();
void lcdCursor(int r, int c);
void lcdPrint(String s);
void lcdPrintChar(char c);


#endif