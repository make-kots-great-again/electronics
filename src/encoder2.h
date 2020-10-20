#ifndef encoder2_h
#define encoder2_h

#include <Encoder.h>

typedef struct encValue
{
    boolean hasChanged = false;
    long value = 0;
} encValue;

typedef struct btnValue
{
    boolean wasPressed= false;
    unsigned long time = 0;
} btnValue;

void encoderSetup();
encValue getEncoderValue();
void resetEncoderValue();
btnValue checkBtnPress();

#endif
