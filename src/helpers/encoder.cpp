#include "encoder.h"

// PINS
RotaryEncoder encoder(A2, A3);
#define btn 4   

//VARS
encValue currentValue;
long newValue = 0;
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
 * @return {encValue}  - voir doc de la structure
 */
encValue getEncoderValue(){
    encoder.tick();
    newValue = encoder.getPosition() - oldValue;
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
    oldValue = encoder.getPosition();
}

/**
 * Fonction détectant l'appui sur le bouton de l'encodeur et renvoie le temps
 * que le bouton a été appuyé en ms.
 * @return {btnValue} voir doc de la structure
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



