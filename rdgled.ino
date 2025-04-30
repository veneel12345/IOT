//d0,d1,d2 pin to any pun in rdg
//ground to ground connector
int RED = 5;
int GREEN = 4;
int BLUE = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // Red
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(1000);

  // Green
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  delay(1000);

  // Blue
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  delay(1000);

  // Yellow (Red + Green)
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
  delay(1000);

  // Cyan (Green + Blue)
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  delay(1000);

  // Magenta (Red + Blue)
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
  delay(1000);

  // White (Red + Green + Blue)
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  delay(1000);
}