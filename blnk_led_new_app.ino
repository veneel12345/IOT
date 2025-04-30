/*New blynk app project
 * https://srituhobby.com
 */
 
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "yAX0irar65Hmy13315pJ3h6mfxdKUVQ0" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Dialog 4G 025";//Enter your WIFI name
char pass[] = "b2016ee3";//Enter your WIFI password


BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}

void setup() {
  pinMode(D0, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}
