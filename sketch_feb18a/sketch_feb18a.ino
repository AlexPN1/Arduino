#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// --- LCD Setup ---
LiquidCrystal_I2C lcd(0x27, 16, 2);

// --- RFID Setup ---
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// --- Servo Setup ---
#define SERVO_PIN 6  // moved to D6
Servo servo;
int angle = 0;

// --- Authorized RFID UID ---
byte authorizedUID[4] = { 0xB3, 0x6C, 0x0B, 0xF7 };

void setup() {
  Serial.begin(9600);
  SPI.begin();      // Init SPI bus for RFID
  rfid.PCD_Init();  // Init MFRC522
  servo.attach(SERVO_PIN);
  servo.write(angle);  // start at 0°

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Scan RFID Tag");  // initial message
}

void loop() {
  // Check for new RFID card
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      // Compare UID
      bool authorized = true;
      for (int i = 0; i < 4; i++) {
        if (rfid.uid.uidByte[i] != authorizedUID[i]) {
          authorized = false;
          break;
        }
      }

      lcd.clear();  // clear previous message

      if (authorized) {
        lcd.setCursor(0, 0);
        lcd.print("Correct Tag!");
        Serial.println("Authorized Tag");

        // Rotate servo 0° <-> 95°
        angle = (angle == 0) ? 95 : 0;
        servo.write(angle);
      } else {
        lcd.setCursor(0, 0);
        lcd.print("Wrong Tag!");
        Serial.print("Unauthorized Tag UID:");
        for (int i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();
      }

      delay(1500);  // show message for 1.5 seconds
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Scan RFID Tag");  // reset message
      rfid.PICC_HaltA();           // halt PICC
      rfid.PCD_StopCrypto1();      // stop encryption
    }
  }
}
