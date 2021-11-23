
/**
   Created by K. Suwatchai (Mobizt)
   Email: k_suwatchai@hotmail.com
   Github: https://github.com/mobizt
   Copyright (c) 2021 mobizt
*/

/** This example will show how to authenticate as a user with Email and password.
   You need to enable Email/Password provider.
   In Firebase console, select Authentication, select Sign-in method tab,
   under the Sign-in providers list, enable Email/Password provider.
   From this example, the user will be granted to access the specific location that matches
   the user uid.
   This example will modify the database rules to set up the security rule which need to
   guard the unauthorized access with the user Email.
*/

#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include <addons/TokenHelper.h>

//Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "Mia2"
#define WIFI_PASSWORD "12345678"

/** 2. Define the API key
   The API key (required) can be obtained since you created the project and set up
   the Authentication in Firebase console. Then you will get the API key from
   Firebase project Web API key in Project settings, on General tab should show the
   Web API Key.
   You may need to enable the Identity provider at https://console.cloud.google.com/customer-identity/providers
   Select your project, click at ENABLE IDENTITY PLATFORM button.
   The API key also available by click at the link APPLICATION SETUP DETAILS.
*/
#define API_KEY "AIzaSyBVp7AbG9vujk7RIu-q9fgIuSYkXCAdXHI"

/* 3. Define the user Email and password that already registerd or added in your project */
#define USER_EMAIL "2202578@my.ipleiria.pt"
#define USER_PASSWORD "projetoDAM"

/* 4. If work with RTDB, define the RTDB URL */

#define DATABASE_URL "https://projeto-dam-4bcc6-default-rtdb.europe-west1.firebasedatabase.app/"


/* 5. Define the Firebase Data object */
FirebaseData fbdo;

/* 6. Define the FirebaseAuth data for authentication data */
FirebaseAuth auth;

/* 7. Define the FirebaseConfig data for config data */
FirebaseConfig config;

unsigned long dataMillis = 0;
int count = 0;

void setup()
{

  Serial.begin(115200);

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

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL */
  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  /** Assign the maximum retry of token generation */
  config.max_token_generation_retry = 5;

  /* Initialize the library with the Firebase authen and config */
  Firebase.begin(&config, &auth);
}

  void loop()
  {
    int actuator1Status;
    int tempValue = 20;
    
    if (millis() - dataMillis > 5000 && Firebase.ready())
    {
      dataMillis = millis();
      
      Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, "actuators/actuator1/value") ? String(fbdo.to<int>()).c_str() : fbdo.errorReason().c_str());
      actuator1Status = fbdo.to<int>();

      Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, "sensors/sensor1/value", tempValue) ? "ok" : fbdo.errorReason().c_str());
    }
}
