#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire connected to digital pin 2
#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// LCD setup (0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Clock variables
int hours = 10;
int minutes = 30;
int seconds = 0;

unsigned long lastClockTick = 0;
unsigned long lastTempRead = 0;
float currentTemp = 0.0;

void setup() {
  lcd.init();
  lcd.backlight();
  
  sensors.begin();
  
  // Quick initial reading
  sensors.requestTemperatures();
  currentTemp = sensors.getTempCByIndex(0);
}

void loop() {
  // Update Clock every 1 second
  if (millis() - lastClockTick >= 1000) {
    lastClockTick += 1000;
    seconds++;
    
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
    }
    if (minutes >= 60) {
      minutes = 0;
      hours++;
    }
    if (hours >= 24) {
      hours = 0;
    }

    // Display Time on Line 0
    lcd.setCursor(0, 0);
    lcd.print("Time: ");
    if (hours < 10) lcd.print("0");
    lcd.print(hours);
    lcd.print(":");
    if (minutes < 10) lcd.print("0");
    lcd.print(minutes);
    lcd.print(":");
    if (seconds < 10) lcd.print("0");
    lcd.print(seconds);
  }

  // Update Temperature every 2 seconds (DS18B20 conversion takes up to 750ms)
  if (millis() - lastTempRead >= 2000) {
    lastTempRead = millis();
    
    sensors.requestTemperatures();
    float t = sensors.getTempCByIndex(0);

    // Filter out error values (-127C means disconnected or missing pull-up resistor)
    if (t != DEVICE_DISCONNECTED_C) {
      currentTemp = t;
      
      // Display Temperature on Line 1
      lcd.setCursor(0, 1);
      lcd.print("Temp: ");
      lcd.print(currentTemp, 1);
      lcd.print((char)223); // Degree symbol
      lcd.print("C    ");
    }
  }
}