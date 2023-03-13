const int vcc = 12;
const int LED_GPIO = 32;
const int BUTTON_GPIO = 36;

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(vcc, OUTPUT);
  pinMode(LED_GPIO, OUTPUT);
  pinMode(BUTTON_GPIO, INPUT);

  digitalWrite(vcc, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(BUTTON_GPIO);

  if(buttonState == HIGH)
    digitalWrite(LED_GPIO, HIGH);
  else
    digitalWrite(LED_GPIO, LOW);
}
