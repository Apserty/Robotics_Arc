# Robotics_Arc

# ⚡ Robotics with ESP32

This branch focuses on high-performance embedded robotics, wireless telemetry, real-time multitasking with FreeRTOS, and IoT integration using the **ESP32 (WROOM-32 / Dual-Core Tensilica Xtensa LX6)**.

## 📌 Focus & Objectives
* Leveraging dual-core processing for task segregation (e.g., Core 0 for Wi-Fi/telemetry, Core 1 for motor control loops).
* Implementing low-latency wireless communication via **ESP-NOW**, WebSockets, and Bluetooth LE.
* Precision hardware PWM using the ESP32 `LEDC` peripheral for motor drivers and servos.
* Interfacing with ROS 2 systems using **micro-ROS**.
* Handling 3.3V logic considerations, ADC non-linearities, and level shifting.

---

## 🛠️ Hardware & Architecture Reference

| Specification | Detail |
| :--- | :--- |
| **Microcontroller** | ESP32 (32-bit Dual-Core @ up to 240 MHz) |
| **Operating Logic** | 3.3V *(Inputs are NOT 5V tolerant — use level shifters)* |
| **Memory** | 520 KB SRAM, 4 MB Flash |
| **Wireless** | 2.4 GHz Wi-Fi (802.11 b/g/n), Bluetooth v4.2 BR/EDR & BLE |
| **Default I2C** | `GPIO 21` (SDA), `GPIO 22` (SCL) |
| **Default SPI** | `GPIO 23` (MOSI), `GPIO 19` (MISO), `GPIO 18` (SCK), `GPIO 5` (CS) |
| **Motor PWM** | Dedicated `LEDC` hardware peripheral (up to 16 independent channels) |
| **ADC** | ADC1 (`GPIO 32–39`), ADC2 (*disabled when Wi-Fi is active*) |

> **⚠️ Strapping Pins Warning:** Avoid using `GPIO 0, 2, 5, 12, 15` for critical inputs to prevent bootloader hang or flash read errors on startup.

---
