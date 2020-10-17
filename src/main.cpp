#include <main.h>


void setup()
{
  lcdSetup();
  scanSetup();
}

void loop()
{
  scanListener();
}
