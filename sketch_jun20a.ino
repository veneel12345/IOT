//#define BLYNK_TEMPLATE_ID "TMPL3spHE3Jyb"
//#define BLYNK_TEMPLATE_NAME "Krinydhi"
//#define BLYNK_TEMPLATE_ID "TMPL3DuZ2hAON"
//#define BLYNK_TEMPLATE_NAME "home automation using gssist"
#define BLYNK_TEMPLATE_ID "TMPL3_Q0hE4Tk"
#define BLYNK_TEMPLATE_NAME "ENERGY EFFICIENT AND SECURED IOT SOLUTIONS"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#define BLYNK_AUTH_TOKEN "mkv4L5--STZDTBATfBgdXXUB0AGUfv20"

#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ROBOT";//Enter your WIFI name
char pass[] = "123456789";//Enter your WIFI password


#define DHTPIN D1          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float value1 = random(0, 278) / 10.0;
Blynk.virtualWrite(V0, value1);  // or dht.readTemperature(true) for Fahrenheit
  
  //if (isnan(h) || isnan(t)) {
    //Serial.println("Failed to read from DHT sensor!");
  // // return;
 // }

 // Blynk.virtualWrite(V0, 27.5); 
   //delay(60000); // Send temperature to Blynk app Virtual Pin 5
 // Blynk.virtualWrite(V1, 7.2); // Send humidity to Blynk app Virtual Pin 6
    Blynk.virtualWrite(V3,35);
    Blynk.virtualWrite(V2,0.01);
     Blynk.virtualWrite(V1,7.5);
    Blynk.virtualWrite(V4,0.03);
    Blynk.virtualWrite(V5,7);
    Blynk.virtualWrite(V6,5);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(60000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}

