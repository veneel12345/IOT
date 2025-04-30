#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN   D2    // Pin for RFID SDA (SS)
#define RST_PIN  D1    // Pin for RFID RST

MFRC522 rfid(SS_PIN, RST_PIN);  // Create MFRC522 instance
MFRC522::MIFARE_Key key;

String tag;

void setup() {
  // Start serial communication
  Serial.begin(9600);
  SPI.begin();//init SPI bus
  rfid.PCD_Init();// Init MFRC522
}

void loop() {
  // Check if a new RFID tag is present
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
    // Select one of the RFID tags
    if (rfid.PICC_ReadCardSerial()) {
      
      
      // Print the UID of the RFID tag
      for (byte i = 0; i < 4; i++) {
        tag+=rfid.uid.uidByte[i];
      }
      Serial.println(tag);
      tag="";
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  }
}
