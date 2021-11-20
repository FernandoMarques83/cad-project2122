#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_Si7021.h"

Adafruit_BMP280 bme; // I2C
Adafruit_Si7021 sensor = Adafruit_Si7021();

void setup()
{
Serial.begin(9600);
Serial.println("BMP280 and SI7021 (GY-21p) test");

if (!bme.begin())
{
Serial.println("Could not find a valid BMP280 sensor, check wiring!");
while (1);
}

if (!sensor.begin())
{
Serial.println("Did not find Si7021 sensor!");
while (true);
}
}

void loop()
{
Serial.println("BMP280 results");
Serial.print("Temperature = ");
Serial.print(bme.readTemperature());
Serial.println(" *C");
Serial.print("Pressure = ");
Serial.print(bme.readPressure());
Serial.println(" Pa");
Serial.print("Approx altitude = ");
Serial.print(bme.readAltitude(1013.25)); // this should be adjusted to your local forcase
Serial.println(" m");
Serial.println();

Serial.println("SI7021 results");
Serial.print("Humidity: ");
Serial.println(sensor.readHumidity(), 2);
Serial.print("Temperature: ");
Serial.println(sensor.readTemperature(), 2);
Serial.println();
delay(2000);
}
