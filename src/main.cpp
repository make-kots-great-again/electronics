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
  connectToGroup();
  productScan();
  
  //espAPITest();

}


void loop()
{
  //scannerTest();
  //encoderTest();
}

/**
 * Fonctions utilisée à des fins de tests, à supprimer une fois fini
 */

void scannerTest(){
  scanListener();
  String code = getScannedCode();
  if(code != "")
  {
    lcdClear();
    lcdPrint(code);
  };
}

void encoderTest(){
  if (getEncoderValue().hasChanged) {
    lcdClear();
    lcdPrint(String(getEncoderValue().value));
  };

  if (checkBtnPress().wasPressed) {
    lcdClear();
    lcdPrint(String(checkBtnPress().time));
  };
}

void espAPITest() {
  Serial.println("-------POST USER--------");
  DynamicJsonDocument user(1024);
  user["pseudo"] = "james";
  user["password"] = "toto";
  httpResp resp = apiPOST("/login", makeJsonString(user));  
  Serial.println("-------------------");
  Serial.println(resp.status);
  Serial.println(resp.message);
  Serial.println(resp.body);
  String usr = getObject(resp.body)["user"];
  String token = getObject(usr)["token"];
  setJWT(token);
  Serial.println("-------------------");
  
  Serial.println("-------_GET USER--------");
  resp = apiGET("/user",true);  
  Serial.println("-------------------");
  Serial.println(resp.status);
  Serial.println(resp.message);
  Serial.println(resp.body);
  String email = getObject(resp.body.substring(1,resp.body.length()-1))["email"];
  Serial.println(email);
  Serial.println("-------------------");
};