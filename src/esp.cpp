#include "esp.h"

void espSetup() {
    Serial.begin(9600);
    Serial1.begin(115200);
    WiFi.init(&Serial1);
}
