//----------------------------------------- Bibliotecas -----------------------------------------
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "Adafruit_Si7021.h"
#include <Wire.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include "esp_adc_cal.h"

//---------------------------------------- Configurações -----------------------------------------
#define WIFI_SSID "Pombo2020"
#define WIFI_PASSWORD "pombo2018"
#define API_KEY "AIzaSyBVp7AbG9vujk7RIu-q9fgIuSYkXCAdXHI"
#define USER_EMAIL "2202578@my.ipleiria.pt"
#define USER_PASSWORD "projetoDAM"
#define DATABASE_URL "https://projeto-dam-4bcc6-default-rtdb.europe-west1.firebasedatabase.app/"

Adafruit_BMP280 bme; // I2C
Adafruit_Si7021 sensor = Adafruit_Si7021();

//------------------------------------- Definição dos Pinos --------------------------------------
const int LM35_Sensor1 = GPIO_NUM_36;
const int relayPin = GPIO_NUM_25;
const int portaLDR = GPIO_NUM_38 ;
const int fanPin = GPIO_NUM_2;

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long dataMillis = 0;
int count = 0;

//------------------------------- Definição das variaveis da estufa ------------------------------
float estufaTemp = 0;
float estufaHumidAr = 0;
float estufaHumidSolo = 0;
int estufaHighTemp = 0;
String fanSpeed = "";
int Speed = 0;
int dutyCycle = 0;
//-------------------------------- Definição das variaveis do jardim ------------------------------
float jardimTemp = 0;
float jardimSolar = 0;
float jardimHumidSolo = 0;
String jardimIrrigadores = "";
int jardimHighTemp = 0;

//----------------------------- Definição das variaveis do sensor Lm35 ----------------------------
int LM35_Raw_Sensor1 = 0;
float Voltage = 0.0;

//----------------------------- Definição das variaveis do sensor LDR -----------------------------
const float MAX_ADC_READING = 4095.0 ;
const float ADC_REF_VOLTAGE = 3.30 ;
const int REF_RESISTANCE = 10000;
const long LUX_CALC_SCALAR = 12518931 ;
const int LUX_CALC_EXPONENT = -1.405 ;

float leitura = 0;
float resistorVoltage = 0;
float ldrVoltage = 0;
float ldrResistance = 0;

//----------------------------- Definição das variaveis do sensor GY21 -----------------------------

float bmeTemp = 0.0;
float siHumid = 0.0;


//------------------------------------- Propiedades do PWM ------------------------------------
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup()
{

  Serial.begin(115200);

  // Configuração dos pinos
  pinMode(LM35_Sensor1, INPUT);
  pinMode(portaLDR, INPUT);
  pinMode(relayPin, OUTPUT);

  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(fanPin, ledChannel);


  // Configuração do Wifi e Firebase
  setupWifi();
  setupFirebase();
  setupGY21();

}

void loop()
{

  readLm35();
  readLDR();
  readGY21();
  getRanValue();


  if (millis() - dataMillis > 500 && Firebase.ready()) {
    dataMillis = millis();
    writeFirebase();
    readFirebase();
  }
}


uint32_t readADC_Cal(int ADC_Raw)
{
  esp_adc_cal_characteristics_t adc_chars;

  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, 1100, &adc_chars);
  return (esp_adc_cal_raw_to_voltage(ADC_Raw, &adc_chars));
}

void setupWifi()
{

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

}

void setupFirebase()
{

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);


  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);

  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  config.max_token_generation_retry = 5;

  Firebase.begin(&config, &auth);

}

void setupGY21()
{

  if (!bme.begin())
  {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }

  if (!sensor.begin())
  {
    Serial.println("Could not find a valid Si7021 sensor, check wiring!");
    while (true);
  }
}

void readLm35()
{

  LM35_Raw_Sensor1 = analogRead(LM35_Sensor1);
  Voltage = readADC_Cal(LM35_Raw_Sensor1);
  jardimTemp = Voltage / 10;

  Serial.printf("Temperatura do Jardim: %f \n", jardimTemp);

}

void readLDR()
{
  leitura = analogRead(portaLDR);
  resistorVoltage = leitura / MAX_ADC_READING * ADC_REF_VOLTAGE ;
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage ;
  ldrResistance = ldrVoltage / resistorVoltage * REF_RESISTANCE ;
  jardimSolar = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);

  Serial.printf("Lux do Jardim : %f\n", jardimSolar);

}

void readGY21()
{

  estufaTemp = bme.readTemperature();
  estufaHumidAr = sensor.readHumidity();

  Serial.printf("Temperatura da Estufa : %f \n", estufaTemp);
  Serial.printf("Humidade do ar da Estufa : %f \n", estufaHumidAr);

}

void getRanValue()
{
  estufaHumidSolo = random(0,10000)/100.0;
  jardimHumidSolo = random(0,10000)/100.0;
  Serial.printf("Humidade do solo da Estufa : %f \n", estufaHumidSolo);
  Serial.printf("Humidade do solo do Jardim : %f \n", jardimHumidSolo);
}

void updateFan()
{
  dutyCycle = map(Speed, 0, 100, 0, 255);
  ledcWrite(ledChannel, dutyCycle);
  Serial.printf("Ventoinha a funcionar a %d %%", Speed);
}

void updateIrrigadores()
{

if (jardimIrrigadores == "true")
{
  digitalWrite(relayPin, HIGH);
  Serial.printf("Irrigadores ligados");
}

else if (jardimIrrigadores == "false")
{
  digitalWrite(relayPin, LOW);
  Serial.printf("Irrigadores desligados");
}
  
}

void readFirebase()
{
  fanSpeed = Firebase.RTDB.getString(&fbdo, "actuator1");
  fanSpeed = fbdo.stringData();
  fanSpeed.remove(fanSpeed.length()-1,1);
  fanSpeed.remove(0,1);
  Speed = fanSpeed.toInt();

  jardimIrrigadores = Firebase.RTDB.getString(&fbdo, "actuator2");
  jardimIrrigadores = fbdo.stringData();

  updateFan();
  updateIrrigadores();
 
}

void writeFirebase()
{
  Firebase.RTDB.setFloat(&fbdo, "sensor1/value", estufaTemp);
  Firebase.RTDB.setFloat(&fbdo, "sensor2/value", estufaHumidAr);
  Firebase.RTDB.setFloat(&fbdo, "sensor3/value", estufaHumidSolo);
  Firebase.RTDB.setFloat(&fbdo, "sensor4/value", jardimTemp);
  Firebase.RTDB.setFloat(&fbdo, "sensor5/value", jardimSolar);
  Firebase.RTDB.setFloat(&fbdo, "sensor6/value", jardimHumidSolo);
}
