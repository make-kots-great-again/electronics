#include "encoder2.h"

// PINS
Encoder encoder(5, 6);
#define btn 4   

//VARS
encValue currentValue;
long oldValue = 0;
btnValue buttonValue;

/**
 * Fonction setup
 */
void encoderSetup() {
    pinMode(btn, INPUT);
}

/**
 * Fonction détectant la rotation de l'encodeur et renvoie sa valeur.
 * @return struct encValue
 */
encValue getEncoderValue() {
    long newValue = encoder.read()/4 - oldValue;
    if (newValue != currentValue.value) {
        currentValue.direction = (newValue > currentValue.value)? 1 : -1;
        currentValue.value = newValue;
        currentValue.hasChanged = true;
    }
    else{
        currentValue.hasChanged = false;
    }
    return currentValue;
}

/**
 * Fonction remettant à 0 la valeur du compteur de l'encodeur.
 */
void resetEncoderValue() {
    oldValue = encoder.read()/4;
}

/**
 * Fonction détectant l'appui sur le bouton de l'encodeur et renvoie le temps
 * que le bouton a été appuyé en ms.
 * @return struct btnValue
 */
btnValue checkBtnPress(){
    buttonValue.wasPressed = false;
    if(digitalRead(btn) == HIGH){
        unsigned long currenTime = millis();
        buttonValue.wasPressed = true;
        // resetEncoderValue(); //reset du compteur de l'encodeur
        while(digitalRead(btn) == HIGH){
            buttonValue.time = millis() - currenTime;
        }
    }
    return buttonValue;
}
