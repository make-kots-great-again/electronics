#include <main.h>


void setup(){

  Serial.begin(9600); //! delete after testings
  lcdSetup();
  lcdClear(); lcdPrint("Booting...");
  scanSetup();
  encoderSetup();
  espSetup();
  eepromDataSetup();
  
  delay(1500);
  lcdClear();
  
  //connectToWifi();
  //setQuantity();
}


void loop()
{
  peremption();
  //test();
  //setQuantity();
  //testingLoop();
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