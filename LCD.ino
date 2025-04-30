#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Encoder.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_I2C_ADDR 0x3C  // Replace with your OLED's I2C address

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Rotary Encoder pins
#define ENCODER_CLK_PIN   D5  // CLK pin
#define ENCODER_DT_PIN    D6  // DT pin
#define ENCODER_SW_PIN    D7  // Switch pin

Encoder enc(ENCODER_CLK_PIN, ENCODER_DT_PIN);

// Gas sensor pin (Analog)
#define GAS_SENSOR_PIN A0  // Connect the sensor analog output to A0 on NodeMCU

long oldPosition  = -999;  // Variable to store the previous encoder position
int switchState = 0;       // Store the encoder button state

void setup() {
  Serial.begin(115200);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);  // Infinite loop if display not found
  }
  display.display();
  delay(2000);  // Wait for 2 seconds
  display.clearDisplay();

  pinMode(ENCODER_SW_PIN, INPUT_PULLUP);  // Encoder switch pin as input with pull-up
}

void loop() {
  // Read the encoder position
  long newPosition = enc.read();

  // Only update the OLED if the position has changed
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    display.clearDisplay();  // Clear the display

    // Display encoder position on line 1
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);  // Position for first line
    display.print("Encoder Pos: ");
    display.println(newPosition);

    // Read gas sensor value (analog) and display on line 2
    int gasValue = analogRead(GAS_SENSOR_PIN);
    display.setCursor(0, 20);  // Position for second line
    display.print("Gas Level: ");
    display.print(gasValue);  // Display raw analog value from the gas sensor

    display.display();
  }

  // Read the button state
  switchState = digitalRead(ENCODER_SW_PIN);
  if (switchState == LOW) {
    display.clearDisplay();  // Clear the display when button is pressed
    display.setCursor(0, 0);
    display.print("Button Pressed!");
    display.display();
    delay(500);  // Debounce delay
  }

  delay(500);  // Delay for stable reading (optional, adjust as needed)
}
