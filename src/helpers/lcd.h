#ifndef lcd_h
#define lcd_h

#include <Arduino.h>
#include "encoder.h"
#include "scan.h"

#if __has_include("envMartin.h")
    #define ENV_MARTIN  true
#else
    #define ENV_MARTIN  false
#endif

void lcdSetup();
void lcdClear();
void lcdCursor(int r, int c);
void lcdPrint(String s);
void lcdPrint(char c);
void lcdClearLine(int r);
void lcdShowCursor(boolean show);
void lcdPrintCustomChar(byte id);

boolean askYesNo(String Question);
void dispCon_OK();
void dispCon_NOK();

#endif
