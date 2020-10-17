#include "scan.h"

USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD> Keyboard(&Usb);

class KbdRptParser : public KeyboardReportParser
{
  void PrintKey(uint8_t mod, uint8_t key);

protected:
  virtual void OnKeyDown(uint8_t mod, uint8_t key);
  virtual void OnKeyPressed(uint8_t key);
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  uint8_t c = OemToAscii(mod, key);

  if (c)
    OnKeyPressed(c);
}

String code = ""; 

void KbdRptParser::OnKeyPressed(uint8_t key)
{
  static uint32_t next_time = 0;     //watchdog

  if (millis() > next_time)
  {
    code = "";
  }
  next_time = millis() + 200;         //reset watchdog


  if( key != 19 ){          //la fin du code bar se termine par le char de controle 'DC3' -> 19 en code ASCII
    code += (char)key;
  }
  else{
    lcdClear();
    lcdPrint(code);
    //TODO call function when scan comes in 
  }
  
};

KbdRptParser Prs;

void scanSetup(){
  if (Usb.Init() == -1)
  {
    Serial.println("OSC did not start.");
  }
  delay(200);
  Hid.SetReportParser(0, (HIDReportParser *)&Prs);
};

void scanListener() {
     Usb.Task();
}