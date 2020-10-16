#include <main.h>


void setup()
{
  lcdSetup();
  scanSetup();
  encoderSetup();
}

void loop()
{
  scanListener();
}
