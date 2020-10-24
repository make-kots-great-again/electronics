#include "jsonMaker.h"


/**
 * Fonction transformant un objet en string JSON.
 * @param {DynamicJsonDocument} obj - Objet à transformer
 * @return {String} String Json de l'objet.
 */
String makeJsonString(DynamicJsonDocument obj){

    String jsonString = "";
    serializeJson(obj, jsonString);

    return jsonString;
}

/**
 * Fonction transformant un string JSON en objet.
 * @param {String} jsonString - Le string JSON qui doit être convertit 
 *  !!! ATTENTION !!! le string JSON doit être au format {"key":"value"} et non [{"key:value"}]!
 * @return {DynamicJsonDocument} object manipulable :
 *      -> String value = obj["key"];
 */
DynamicJsonDocument getObject(String jsonString){
    
    DynamicJsonDocument obj(1024);
    deserializeJson(obj, jsonString);

    return obj;
}
