#include <Arduino.h>

const int analogPin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int analogReadValue = analogRead(analogPin);
  float voltage = (analogReadValue / 1023.0) * 3.3; // Assuming 10-bit ADC, 3.3V reference
  float temp = voltage / 0.01;

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  delay(1000);
}
