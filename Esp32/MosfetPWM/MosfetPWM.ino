// the number of the LED pin
const int ledPin = GPIO_NUM_2;  // 16 corresponds to GPIO16
const int relayPin = GPIO_NUM_25;

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);

  pinMode(relayPin, OUTPUT);
  delay(1000);
}

void loop() {
  // increase the LED brightness
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  digitalWrite(relayPin, HIGH);

  // decrease the LED brightness
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  digitalWrite(relayPin, LOW);
}
