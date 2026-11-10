# NEXUS Firmware — Libraries & Dependencies

The NEXUS firmware is developed using the Arduino IDE and runs on the ESP32-WROOM-32 microcontroller.

## Development Environment

- Arduino IDE 2.x
- ESP32 board package by Espressif Systems
- Board selection: ESP32 Dev Module
- Framework: Arduino

## Required Arduino Libraries

| Library | Purpose |
|---|---|
| TinyGPSPlus | GPS NMEA data parsing |
| Adafruit BNO055 | IMU communication and sensor readings |
| Adafruit Unified Sensor | Unified sensor interface |
| Adafruit BusIO | Hardware communication support |
| U8g2 | OLED display control |

## Built-in ESP32 Libraries

| Library | Purpose |
|---|---|
| Wire.h | I2C communication |
| SPI.h | SPI communication |
| SD.h | MicroSD card access |
| HardwareSerial.h | UART communication |

## Installation

Install the external libraries through:

**Arduino IDE → Library Manager**

Search for and install:

1. TinyGPSPlus
2. Adafruit BNO055
3. Adafruit Unified Sensor
4. Adafruit BusIO
5. U8g2

The ESP32 board package must also be installed through the Arduino IDE Boards Manager.

## Hardware Interfaces

The firmware uses the following communication protocols:

- UART: GPS and HC-05 Bluetooth.
- I2C: BNO055 IMU and SSD1309 OLED.
- SPI: MicroSD card module.
- USB Serial: Computer telemetry output.

## Notes

The firmware is designed to acquire GPS and IMU measurements, format them into CSV records, and distribute the data through the device's available output interfaces.
