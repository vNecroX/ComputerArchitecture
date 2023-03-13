#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

String message = "";
char incomingChar;

int brightness = 0;   
int fadeAmount = 5;   

int flag = 0;

int pin_gpio = 13;  //a
int pin_gpio2 = 12; //b
int pin_gpio3 = 14; //c
int pin_gpio4 = 27; //d
int pin_gpio5 = 26; //e
int pin_gpio6 = 25; //f     
int pin_gpio7 = 33; //g  

int count = 0;

int BUTTON_GPIO = 36;

int buttonState = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (SerialBT.available()){
    incomingChar = SerialBT.read();
    Serial.write(incomingChar);
  }

  if(incomingChar == '2' || incomingChar == '3' || incomingChar == '4'){
    pinMode(pin_gpio, OUTPUT);
    pinMode(pin_gpio2, OUTPUT);
    pinMode(pin_gpio3, OUTPUT);
    pinMode(pin_gpio4, OUTPUT);
    pinMode(pin_gpio5, OUTPUT);
    pinMode(pin_gpio6, OUTPUT);
    pinMode(pin_gpio7, OUTPUT);
  }

  if(incomingChar == '5'){
    pinMode(pin_gpio, OUTPUT);
    pinMode(BUTTON_GPIO, INPUT);

    digitalWrite(pin_gpio, HIGH);
  }

  if(incomingChar == '1'){               //Fade
    ledcAttachPin(pin_gpio, 0);
    ledcSetup(0, 400, 8);
    fade();
  }

  if(incomingChar == '2')                //On-Off
    onOff();
    
  if(incomingChar == '3')                //Blink
    blinkLed();
  
  if(incomingChar == '4')                //Display
    showDisplay();
  
  if(incomingChar == '5')                //DataReading
    dataReading();
}

void fade(){
    ledcWrite(0, brightness);
 
    brightness = brightness + fadeAmount;
  
    if (brightness <= 0 || brightness >= 255)
      fadeAmount = -fadeAmount;
    
    delay(30);

    fade();
}

void onOff(){
  if(flag == 0){
    flag = 1;
    digitalWrite(pin_gpio2, HIGH);
  }
  else{
    flag = 0;
    digitalWrite(pin_gpio2, LOW);
  }

  delay(300);
  SerialBT.flush();
}

void blinkLed(){
    digitalWrite(pin_gpio2, HIGH);
    delay(500);
    digitalWrite(pin_gpio2, LOW);
    delay(500);

    blinkLed();
}

void showDisplay(){
  if(count == 0){
    count++;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    digitalWrite(pin_gpio4, HIGH);
    digitalWrite(pin_gpio5, HIGH);
    digitalWrite(pin_gpio6, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 1){
    count++;
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 2){
    count++;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio4, HIGH);
    digitalWrite(pin_gpio5, HIGH);
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 3){
    count++;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    digitalWrite(pin_gpio4, HIGH);
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 4){
    count++;
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    digitalWrite(pin_gpio6, HIGH);
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 5){
    count++;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    digitalWrite(pin_gpio4, HIGH);
    digitalWrite(pin_gpio6, HIGH);
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 6){
    count++;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    digitalWrite(pin_gpio4, HIGH);
    digitalWrite(pin_gpio5, HIGH);
    digitalWrite(pin_gpio6, HIGH);
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 7){
    count++;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    delay(1000);
    clearDisplay();
  }
  
  if(count == 8){
    count++;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    digitalWrite(pin_gpio4, HIGH);
    digitalWrite(pin_gpio5, HIGH);
    digitalWrite(pin_gpio6, HIGH);
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 9){
    count = 0;
    digitalWrite(pin_gpio, HIGH);
    digitalWrite(pin_gpio2, HIGH);
    digitalWrite(pin_gpio3, HIGH);
    digitalWrite(pin_gpio6, HIGH);
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }

  showDisplay();
}

void clearDisplay(){
  digitalWrite(pin_gpio, LOW);
  digitalWrite(pin_gpio2, LOW);
  digitalWrite(pin_gpio3, LOW);
  digitalWrite(pin_gpio4, LOW);
  digitalWrite(pin_gpio5, LOW);
  digitalWrite(pin_gpio6, LOW);
  digitalWrite(pin_gpio7, LOW);
  delay(500);
}

void dataReading(){
  buttonState = digitalRead(BUTTON_GPIO);

  if(buttonState == HIGH)
    SerialBT.println('X');
  else
    SerialBT.println('Y');
}
