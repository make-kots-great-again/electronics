#ifndef scan_h
#define scan_h

#include <Arduino.h>
#include <usbhid.h>
#include <hiduniversal.h>
#include <avr/pgmspace.h>
#include <Usb.h>
#include <usbhub.h>
#include <avr/pgmspace.h>
#include <hidboot.h>


void scanSetup();
void scanListener();
void scanListener_STOP();
String getScannedCode();

#endif
