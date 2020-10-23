#include <main.h>

void setup()
{
  Serial.begin(9600); //! delete after testings
  lcdSetup();
  lcdClear(); lcdPrint("Booting...");
  scanSetup();
  encoderSetup();
  espSetup();
  eepromDataSetup();
  
  delay(1500);
  lcdClear();

  connectToWifi();

}


void loop()
{

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

  DynamicJsonDocument user(1024);
  user["pseudo"] = "james";
  user["password"] = "toto";
  httpResp resp = apiPOST("/login", makeJsonString(user));  
  Serial.println("-------------------");
  Serial.println(resp.status);
  Serial.println(resp.message);
  Serial.println(resp.body);
  Serial.println("-------------------");
  
  resp = apiGET("/user",true);  
  Serial.println("-------------------");
  Serial.println(resp.status);
  Serial.println(resp.message);
  Serial.println(resp.body);
  String email = getObject(resp.body.substring(1,resp.body.length()-1))["email"];
  Serial.println(email);
  Serial.println("-------------------");
  
};