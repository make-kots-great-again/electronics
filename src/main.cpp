#include <main.h>


void setup()
{
  lcdSetup();
  scanSetup();
  encoderSetup();
  espSetup();
}


void loop()
{
  testingLoop();
}

/**
 * Fonction utilisée à des fins de tests, à supprimer une fois fini
 */
void testingLoop() {
    scanListener();
  if (getEncoderValue().hasChanged) {
    lcdClear();
    lcdPrint(String(getEncoderValue().value));
  };

  if (checkBtnPress().wasPressed) {
    lcdClear();
    lcdPrint(String(checkBtnPress().time));
  };
  
};