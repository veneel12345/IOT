

#define BUZZER D0 //connect input pin of nusser
// the setup function runs once when you pass rest
void setup() {
  // initialize digital pin 0 as an output
pinMode(BUZZER,OUTPUT);
}
//the loop function runs over and over again forever
void loop() {
  // switching buzzer on and of rapidly
  digitalWrite(BUZZER,HIGH);//turn on buzzer
  delay(100);
  digitalWrite(BUZZER,LOW);//turn off buzzer
 delay(100);
}
