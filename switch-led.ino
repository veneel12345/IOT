#define BUTTON_PIN D1  // GPIO5

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Use internal pull-up resistor
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    Serial.println("Button Pressed");
  } else {
    Serial.println("Button Released");
  }

  delay(200);  // Debounce / readability
}