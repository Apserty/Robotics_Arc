# Arduino ASCII Video Player (1602 LCD + Python)

Stream real-time video clips from your computer directly to a standard 16x2 character LCD connected to an Arduino Nano. 

Because an Arduino Nano lacks the processing power to decode video files and the 1602 LCD lacks a true pixel grid, this project offloads video processing to a Python script running on your laptop. The laptop samples frames into a 16×2 brightness matrix, converts pixel values into ASCII visual-density glyphs (`" .:-=+*#%@"`), and streams the 32-byte frames over USB Serial.

---

## 🛠️ Hardware Requirements

* **Arduino Nano** (or Uno)
* **1602 Character LCD** (HD44780 controller, 64.5 mm × 16 mm viewing area)
* **I2C Backpack module** (PCF8574) or standard direct wiring (10kΩ potentiometer + 220Ω resistor)
* **USB Mini-B / Type-C cable** (for computer connection)
* **Breadboard and jumper wires**

---

## 🔌 Wiring Diagram (I2C Backpack)

| LCD Pin | Arduino Nano Pin | Notes |
| :--- | :--- | :--- |
| **GND** | `GND` | Ground |
| **VCC** | `5V` | Power |
| **SDA** | `A4` | I2C Serial Data |
| **SCL** | `A5` | I2C Serial Clock |

*(If using direct 16-pin parallel wiring instead of I2C, adjust pins in the sketch accordingly.)*

---

## 💻 Software Dependencies

### Arduino IDE
* **LiquidCrystal_I2C** library (Install via **Tools** → **Manage Libraries...**)

### Laptop / Host Environment
* **Python 3.8+**
* Required packages:
  ```bash
  pip install opencv-python pyserial numpy
