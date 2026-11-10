# NEXUS System Architecture

## 1. Overview

NEXUS is a portable GPS and inertial measurement system built around an ESP32 microcontroller. It collects positioning and motion data, processes sensor measurements, and distributes telemetry through multiple communication interfaces.

## 2. System Components

The system consists of five primary subsystems:

- **Processing:** ESP32 microcontroller handles sensor communication, data processing, and output management.
- **Positioning:** GPS module provides latitude, longitude, elevation, and satellite information.
- **Motion sensing:** BNO055 IMU provides acceleration, angular velocity, and magnetic field measurements.
- **Data storage:** MicroSD module stores telemetry in CSV format.
- **Communication:** USB serial and HC-05 Bluetooth provide wireless and wired telemetry output.
- **User interface:** OLED displays device status and GPS acquisition information.

## 3. Data Flow

1. The GPS module sends positioning data to the ESP32 through UART.
2. The BNO055 sends motion measurements through I2C.
3. The ESP32 processes the incoming sensor measurements.
4. Measurements are formatted into CSV telemetry records.
5. The ESP32 sends the records to the microSD card, USB serial interface, and Bluetooth module.
6. The OLED displays the current device status.

## 4. Communication Interfaces

| Interface | Connected Devices | Purpose |
|---|---|---|
| UART2 | GPS module | GPS data acquisition |
| I2C | BNO055 and OLED | Sensor communication and display |
| SPI | MicroSD module | Data storage |
| UART | HC-05 | Bluetooth telemetry |
| USB Serial | Computer | Wired telemetry output |

## 5. Telemetry Outputs

NEXUS is designed to support simultaneous operation of three data outputs:

- **MicroSD:** Continuous CSV data logging.
- **USB:** Serial telemetry stream to a connected computer.
- **Bluetooth:** Wireless telemetry stream through the HC-05 module.

Each output receives the same formatted telemetry records.

## 6. Computer Ground-Control Interface

A Python-based ground-control application receives serial telemetry and displays GPS and IMU measurements. The interface includes GPS positioning information, a live map, motion measurements, and real-time plots.

## 7. System Design Goal

The architecture emphasizes portability, modular hardware, continuous data collection, and multiple independent telemetry outputs.
