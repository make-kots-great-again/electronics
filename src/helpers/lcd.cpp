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

byte _Y_[8] = {
  B10001,
  B10001,
  B10001,
  B01010,
  B00100,
  B00100,
  B00100,
  B11111,
};

byte _N_[8] = {
  B10001,
  B10001,
  B11001,
  B10101,
  B10011,
  B10001,
  B10001,
  B11111,
};


void lcdSetup() {
    lcd.init();
    //lcd.begin();
    lcd.backlight();       
    lcd.noAutoscroll();
    lcd.setCursor(0, 0); 
    lcd.createChar(0, leftBar);
    lcd.createChar(1, rightBar);
    lcd.createChar(2, _Y_);
    lcd.createChar(3, _N_);
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


boolean askYesNo(String question)
{
    String yesNo = "Y";
    encValue enc;
    int qLen = question.length();
    unsigned long prevTime = millis();
    int scrollCount = 0;
    unsigned int scrollPeriod = 400;

    lcdClear();
    lcdPrint(question +" ");
    lcdCursor(1, 4);
    lcdPrintCustomChar(2);
    lcdCursor(1, 11);
    lcdPrint("N");

    while (true)
    {
        if (!checkBtnPress().wasPressed)
        {
            enc = getEncoderValue();
            if (enc.hasChanged)
            {
                if (enc.direction == 1)
                {
                    lcdCursor(1, 4);
                    lcdPrint("Y");
                    lcdCursor(1, 11);
                    lcdPrintCustomChar(3);
                    yesNo = "N";
                }
                else if (enc.direction == -1)
                {
                    lcdCursor(1, 4);
                    lcdPrintCustomChar(2);
                    lcdCursor(1, 11);
                    lcdPrint("N");
                    yesNo = "Y";
                }
            }
        }
        else
        {
            return (yesNo == "Y") ? true : false;
            break;
        }

        if(qLen > 16)
        {
            if(millis()-prevTime > scrollPeriod)
            {   
                if (scrollCount == qLen-15){
                    scrollCount = 0;
                    scrollPeriod = 2000;
                }
                else
                {
                    lcdClearLine(0);
                    lcdPrint(question.substring(scrollCount));
                    scrollPeriod = 400;
                    scrollCount++;
                }
                prevTime = millis();
            }
        }

        scanListener(); //to prevent scan hangup 
    }
}

void dispCon_OK()
{
    lcdClear();
    lcdCursor(0, 3);
    lcdPrint("Connexion");
    lcdCursor(1, 4);
    lcdPrint("reussie");
    delay(2500);
    lcdClear();
}

void dispCon_NOK()
{
    lcdClear();
    lcdCursor(0, 3);
    lcdPrint("Connexion");
    lcdCursor(1, 4);
    lcdPrint("echouee");
    delay(2500);
    lcdClear();
}
