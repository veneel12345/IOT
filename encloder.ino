void setup() {
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(A0);  // Reads 0 to 1023
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  delay(400);
}