Markdown
# Arduino Nano Digital Clock

A standalone digital clock built using an **Arduino Nano** and an **I2C 16x2 LCD display**. The system tracks real-time hours, minutes, and seconds using the microcontroller's internal timer without requiring an external RTC module.

---

## Features

- **24-Hour Digital Clock:** Continuously tracks and formats time as `HH:MM:SS`.
- **Non-Blocking Timer:** Uses `millis()` tracking to prevent timing drift and keep the loop responsive.
- **I2C Interface:** Reduces wiring to only 4 pins (two power lines and two analog I2C lines).

---

## Hardware Requirements

| Component | Description |
| :--- | :--- |
| **Arduino Nano** | ATmega328P microcontroller |
| **16x2 LCD Display** | HD44780 LCD with PCF8574 I2C backpack |
| **Jumper Wires** | Female-to-male / breadboard wires |
| **Power Source** | Standard 5V USB power adapter or cable |

---

## Circuit Schematic & Wiring

Connect the 4 pins of the I2C module directly to the Arduino Nano as follows:

| LCD Pin | Arduino Nano Pin | Function |
| :--- | :--- | :--- |
| **GND** | **GND** | Ground reference |
| **VCC** | **5V** | 5V DC power supply |
| **SDA** | **A4** | I2C Data line |
| **SCL** | **A5** | I2C Clock line |

---

## Required Library

Install the LCD driver library via the Arduino IDE:
1. Open the Arduino IDE.
2. Navigate to **Tools > Manage Libraries...** (or press `Ctrl + Shift + I`).
3. Search for **`LiquidCrystal I2C`** (authored by Frank de Brabander or Marco Schwartz).
4. Click **Install**.

---
