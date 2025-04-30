#define LED_PIN D7 // Define the LED pin (D7 is GPIO13)

void setup() {
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as an output
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn the LED on (HIGH is active low on ESP8266)
  delay(1000);                 // Wait for 1 second
  digitalWrite(LED_PIN, LOW);  // Turn the LED off (LOW is active on)
  delay(1000);                 // Wait for 1 second
}