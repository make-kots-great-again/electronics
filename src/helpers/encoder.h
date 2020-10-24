#ifndef encoder2_h
#define encoder2_h

#include <RotaryEncoder.h>

/**
 * @param {boolean} hasChanged - (true) si la valeur de l'encodeur à changé
 * @param {long} value - la valeur absolue de l'encodeur
 * @param {int} direction - (+1) ou (-1) en fonction du sens de rotation de l'encodeur
 */
typedef struct encValue
{
    boolean hasChanged = false;
    long value = 0;
    int direction = 0;
} encValue;

/**
 * @param {boolean} wasPressed - (true) si le bouton a été appuyé
 * @param {unsigned-long} time - le temps que le bouton a été appuyé en ms
 */
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
