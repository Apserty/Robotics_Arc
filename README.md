# Robotics_Arc

# ⚡ Robotics with Arduino Nano

This branch focuses on low-level robotics prototyping, sensor integration, and motor actuation using the **Arduino Nano (ATmega328P)**.

## 📌 Focus & Objectives
* Interfacing analog/digital sensors and motor controllers.
* Implementing low-level control loops (PID, state machines) without an OS.
* Managing resource constraints (32 KB Flash, 2 KB SRAM).
* Working with hardware interrupts, PWM signals, and communication protocols (I2C, SPI, UART).

---

## 🛠️ Hardware & Pinout Reference

| Specification | Detail |
| :--- | :--- |
| **Microcontroller** | ATmega328P (8-bit AVR @ 16 MHz) |
| **Operating Voltage** | 5V (Input: 7–12V via `VIN`) |
| **Digital I/O Pins** | 14 (6 provide hardware PWM: `D3, D5, D6, D9, D10, D11`) |
| **Analog Inputs** | 8 (`A0` – `A7`, 10-bit ADC) |
| **I2C Bus** | `A4` (SDA), `A5` (SCL) |
| **SPI Bus** | `D10` (SS), `D11` (MOSI), `D12` (MISO), `D13` (SCK) |
| **External Interrupts**| `D2` (INT0), `D3` (INT1) — *ideal for rotary encoders* |

---
