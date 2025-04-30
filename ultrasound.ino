#define TRIG_PIN D5
#define ECHO_PIN D6

long duration;
float distanceCm;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send 10 microsecond pulse to TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance (speed of sound is ~343 m/s)
  distanceCm = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  delay(500); // Wait half a second
}