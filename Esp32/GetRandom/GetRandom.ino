#include <math.h>
float randome = 0;
float newi = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  randome = random(0,10000)/100.0;
  newi = roundf(randome * 1000)/1000;
  Serial.printf("Random :%f\n", newi);
  delay(500);
}
