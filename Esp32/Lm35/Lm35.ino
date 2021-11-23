#include "esp_adc_cal.h"
#define ADC_VREF_mV    3300.0 // in millivolt
#define ADC_RESOLUTION 4095.0
const int PIN_LM35 = GPIO_NUM_39;


void setup() {
  Serial.begin(9600);
}

void loop() {
  // get the ADC value from the temperature sensor
  int adcVal = analogRead(PIN_LM35);
  // convert the ADC value to voltage in millivolt
  //float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  float milliVolt = readADC_Cal(adcVal);
  // convert the voltage to the temperature in Celsius
  float tempC = milliVolt / 10;


  // print the temperature in the Serial Monitor:
  Serial.print("Temperature: ");
  Serial.print(tempC);   // print the temperature in Celsius
  Serial.print(" °C");
  Serial.print("  ~  "); // separator between Celsius and Fahrenheit
  Serial.print(milliVolt);   // print the temperature in Fahrenheit
  Serial.println(" mv");
   Serial.print("  ~  "); // separator between Celsius and Fahrenheit
  Serial.print(adcVal);   // print the temperature in Fahrenheit
  Serial.println(" adc");

  delay(1000);
}
