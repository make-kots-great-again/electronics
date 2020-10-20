#include <main.h>


void setup()
{
  lcdSetup();
  scanSetup();
  encoderSetup();
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


void loop()
{
  testingLoop();
}
