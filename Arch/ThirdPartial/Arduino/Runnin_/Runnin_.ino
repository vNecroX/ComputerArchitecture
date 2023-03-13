int pin_gpio = 13;  //a
int pin_gpio2 = 12; //b
int pin_gpio3 = 14; //c
int pin_gpio4 = 27; //d
int pin_gpio5 = 26; //e
int pin_gpio6 = 25; //f     
int pin_gpio7 = 33; //g   

int count = 0;

void setup() {
  pinMode(pin_gpio, OUTPUT);
  pinMode(pin_gpio2, OUTPUT);
  pinMode(pin_gpio3, OUTPUT);
  pinMode(pin_gpio4, OUTPUT);
  pinMode(pin_gpio5, OUTPUT);
  pinMode(pin_gpio6, OUTPUT);
  pinMode(pin_gpio7, OUTPUT);
}

void loop() {
  if(count == 0){
    count++;
    digitalWrite(pin_gpio, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 1){
    count++;
    digitalWrite(pin_gpio2, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 2){
    count++;
    digitalWrite(pin_gpio3, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 3){
    count++;
    digitalWrite(pin_gpio4, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 4){
    count++;
    digitalWrite(pin_gpio5, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 5){
    count++;
    digitalWrite(pin_gpio6, HIGH);
    delay(1000);
    clearDisplay();
  }

  if(count == 6){
    count = 0;
    digitalWrite(pin_gpio7, HIGH);
    delay(1000);
    clearDisplay();
  }
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
