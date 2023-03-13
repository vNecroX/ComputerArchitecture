//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int ledPin = 32;

String message = "";
char incomingChar;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (SerialBT.available()){
    incomingChar = SerialBT.read();

    if(incomingChar != '\n')
      message += String(incomingChar);
    else
      message = "";

    Serial.write(incomingChar);
    
  }

  if(message == "ON")
    digitalWrite(ledPin, HIGH);
  else if(message == "OFF")
    digitalWrite(ledPin, LOW);
  
  delay(20);
}
