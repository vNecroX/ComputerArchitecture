int pin_gpio = 13;
int pin_gpio2 = 12; 
int pin_gpio3 = 14;
int pin_gpio4 = 27;
int pin_gpio5 = 26; 
int pin_gpio6 = 25;      
int pin_gpio7 = 33;    
int brightness = 0;   
int fadeAmount = 5;    

void setup() {
  ledcAttachPin(pin_gpio, 0);
  ledcAttachPin(pin_gpio2, 0);
  ledcAttachPin(pin_gpio3, 0);
  ledcAttachPin(pin_gpio4, 0);
  ledcAttachPin(pin_gpio5, 0);
  ledcAttachPin(pin_gpio6, 0);
  ledcAttachPin(pin_gpio7, 0);
  ledcSetup(0, 400, 8);
}

void loop() {
  ledcWrite(0, brightness);
 
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
