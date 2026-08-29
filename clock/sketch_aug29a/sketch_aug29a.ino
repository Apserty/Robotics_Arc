#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change 0x27 to 0x3F if your I2C scanner detects a different address
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ready to Stream!");
}

void loop() {
  // Wait until a complete 32-character frame arrives (16 chars x 2 lines)
  if (Serial.available() >= 32) {
    char frame[32];
    Serial.readBytes(frame, 32);

    // Line 1
    lcd.setCursor(0, 0);
    for (int i = 0; i < 16; i++) {
      lcd.write(frame[i]);
    }

    // Line 2
    lcd.setCursor(0, 1);
    for (int i = 16; i < 32; i++) {
      lcd.write(frame[i]);
    }

    // Send single-byte ACK to prompt the laptop for the next frame
    Serial.write('K');
  }
}