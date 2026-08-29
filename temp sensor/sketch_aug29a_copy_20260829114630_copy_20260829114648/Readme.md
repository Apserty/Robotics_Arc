# DS18B20 Digital Thermometer with Arduino Nano & I2C LCD

A compact digital temperature monitoring system built with an **Arduino Nano**, a **DS18B20 waterproof temperature probe**, and a **16x2 I2C Liquid Crystal Display (LCD)**[cite: 1]. The project reads high-precision digital temperature data using the Maxim 1-Wire protocol and displays real-time readings in both Celsius (°C) and Fahrenheit (°F)[cite: 1].

---

## Features

- **High Precision Sensing:** Digital readout from -55°C to +125°C (-67°F to +257°F) with ±0.5°C accuracy (from -10°C to +85°C)[cite: 1].
- **Dual Unit Display:** Displays temperature simultaneously in °C and °F on a standard 16x2 character LCD[cite: 1].
- **Minimal Pin Footprint:** Uses I2C communication (2 analog pins) for the LCD and a single digital pin for the 1-Wire sensor[cite: 1].
- **Robust Error Handling:** Built-in disconnected sensor / hardware error detection (`-127.0°C` fault handling)[cite: 1].
- **Waterproof Probe:** Suitable for liquid immersion, outdoor weather stations, or aquariums[cite: 1].

---

## Hardware Requirements

| Component | Specification / Notes | Quantity |
| :--- | :--- | :---: |
| **Microcontroller** | Arduino Nano (ATmega328P) | 1 |
| **Temperature Sensor** | DS18B20 (Waterproof probe or TO-92 package) | 1 |
| **Display** | 16x2 Character LCD with PCF8574 I2C Backpack | 1 |
| **Resistor** | 4.7 kΩ (Pull-up resistor for 1-Wire data line) | 1 |
| **Prototyping** | Half-size Breadboard & Male-to-Male / Male-to-Female Jumper Wires | 1 set |
| **Power Supply** | 5V USB (Mini-B cable) or external 7–12V DC via `VIN` | 1 |[cite: 1]

---

## Wiring & Pinout Configuration

> **IMPORTANT:** The DS18B20 requires a **4.7 kΩ pull-up resistor** connected between the **Data line** and **5V (VCC)**[cite: 1]. Without this resistor, the sensor bus will float and return a disconnected error (`-127.0°C`)[cite: 1].

### 1. DS18B20 Sensor to Arduino Nano
| DS18B20 Wire Color | Pin Function | Arduino Nano Pin | Note |
| :--- | :--- | :--- | :--- |
| **Red** | VCC | **5V** | Power rail |
| **Black** | GND | **GND** | Ground rail |
| **Yellow / White** | DATA | **D2** | Connect **4.7 kΩ** resistor between D2 & 5V |[cite: 1]

### 2. 16x2 I2C LCD to Arduino Nano
| I2C Backpack Pin | Arduino Nano Pin | Note |
| :--- | :--- | :--- |
| **GND** | **GND** | Common ground |
| **VCC** | **5V** | Display logic & backlight power |
| **SDA** | **A4** | I2C Data line |
| **SCL** | **A5** | I2C Clock line |[cite: 1]

---

## Software Prerequisites & Libraries

To compile and upload the sketch, ensure you have the [Arduino IDE](https://www.arduino.cc/en/software) installed along with the following libraries[cite: 1]:

1. **OneWire** (by Jim Studt, Paul Stoffregen)[cite: 1]
2. **DallasTemperature** (by Miles Burton)[cite: 1]
3. **LiquidCrystal I2C** (by Frank de Brabander or Marco Schwartz)[cite: 1]

### Installation via Arduino IDE:
1. Open the Arduino IDE[cite: 1].
2. Navigate to **Sketch** &rarr; **Include Library** &rarr; **Manage Libraries...**[cite: 1]
3. Search for each library name in the search bar and click **Install**[cite: 1].

---

## Firmware Code

Create a new sketch in Arduino IDE (e.g. `DS18B20_Nano_LCD.ino`) and paste the following code[cite: 1]:

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// 1-Wire Data bus pin
#define ONE_WIRE_BUS 2

// Initialize 1-Wire and Dallas Temperature instances
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// LCD configuration: default I2C address is usually 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize DS18B20 sensor
  sensors.begin();
  
  // Initialize LCD display
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Welcome Splash Screen
  lcd.setCursor(0, 0);
  lcd.print(" Temp Monitor  ");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Send temperature measurement command
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);

  // Line 1: Celsius reading
  lcd.setCursor(0, 0);
  lcd.
