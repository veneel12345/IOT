#define RELAY_PIN D1  // GPIO5

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Relay OFF (active LOW for many modules)
  Serial.begin(9600);
}

void loop() {
  Serial.println("Relay ON");
  digitalWrite(RELAY_PIN, HIGH); // Relay ON (or LOW depending on module)
  delay(2000);

  Serial.println("Relay OFF");
  digitalWrite(RELAY_PIN, LOW); // Relay OFF
  delay(2000);
}