#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#include "esp_adc_cal.h"

#define WIFI_SSID "Mia2"
#define WIFI_PASSWORD "12345678"
#define API_KEY "AIzaSyBVp7AbG9vujk7RIu-q9fgIuSYkXCAdXHI"
#define USER_EMAIL "2202578@my.ipleiria.pt"
#define USER_PASSWORD "projetoDAM"
#define DATABASE_URL "https://projeto-dam-4bcc6-default-rtdb.europe-west1.firebasedatabase.app/"

const int LM35_Sensor1 = 33;
const int relayPin = GPIO_NUM_27;


FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long dataMillis = 0;
int count = 0;

float estufaTemp = 0;
float estufaHumidAr = 0;
float estufaHumidSolo = 0;
int estufaFanSpeed = 0;
int estufaHighTemp = 0;

float jardimTemp = 0;
float jardimSolar = 0;
float jardimHumidSolo = 0;
int jardimIrrigadores = 0;
int jardimHighTemp = 0;

int LM35_Raw_Sensor1 = 0;
float LM35_TempC_Sensor1 = 0.0;
float LM35_TempF_Sensor1 = 0.0;
float Voltage = 0.0;

void setup()
{

  Serial.begin(115200);

  pinMode(LM35_Sensor1, INPUT);
  pinMode(relayPin, OUTPUT);

  setupWifi();
  setupFirebase();

}

void loop()
{

  readLm35();

  if (millis() - dataMillis > 1000 && Firebase.ready()) {
    dataMillis = millis();

    estufaTemp = Firebase.RTDB.getFloat(&fbdo, "estufa/sensores/temperatura");
    estufaTemp = fbdo.floatData();

    Firebase.RTDB.setFloat(&fbdo, "estufa/sensores/temperatura", LM35_TempC_Sensor1);


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

void readLm35()
{

  LM35_Raw_Sensor1 = analogRead(LM35_Sensor1);
  Voltage = readADC_Cal(LM35_Raw_Sensor1);
  LM35_TempC_Sensor1 = Voltage / 10;

  Serial.printf("Temperatura %f : \n", LM35_TempC_Sensor1);

}

void readLDR()
{

}

void readGy21()
{


}
