// Pin connected to the MQ-2 sensor
//connect gnd to gnd
//connect vcc to 3.3V
//connect adc to a0
const int gasSensorPin = A0;  // Analog input pin for gas sensor

// Calibration values
int sensorValue = 0;  // Variable to store the sensor value
int threshold = 300;  // Threshold for gas detection (you can adjust this)

void setup() {
  // Start the serial communication
  Serial.begin(115200);
  delay(1000);  // Allow sensor to warm up
}

void loop() {
  // Read the analog value from the gas sensor
  sensorValue = analogRead(gasSensorPin);
  
  // Print the sensor value to the Serial Monitor
  Serial.print("Gas Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the gas level is above the threshold
  if (sensorValue > threshold) {
    Serial.println("Gas Detected! High levels detected!");
  } else {
    Serial.println("Gas levels normal.");
  }
  
  delay(1000);  // Wait for 1 second before reading again
}
