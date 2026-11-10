# NEXUS Hardware Components

NEXUS uses a collection of embedded hardware modules connected to an ESP32 microcontroller to provide GPS localization, inertial sensing, wireless communication, and onboard data storage.

## Main Processing Unit

**ESP32 DevKit (ESP32-WROOM-32)**

The ESP32 serves as the central processing unit, coordinating sensor acquisition, data processing, display updates, and communication with external devices.

## GPS Module

**MikroElektronika GPS Click — u-blox LEA-6S**

Provides satellite-based positioning information, including:
- Latitude
- Longitude
- Elevation
- Number of satellites

## Inertial Measurement Unit

**Adafruit BNO055**

A 9-axis IMU used to measure:
- Acceleration along X, Y, and Z axes.
- Angular velocity along X, Y, and Z axes.
- Magnetic field along X, Y, and Z axes.

## Wireless Communication

**HC-05 Bluetooth Module**

Provides wireless serial communication between NEXUS and an external computer.

## Data Storage

**MicroSD SPI Module**

Provides local storage for continuous CSV telemetry logging.

## Display

**2.42-inch SSD1309 OLED Display**

Provides local device status information, including GPS acquisition status and satellite information.

## Power and Enclosure

NEXUS uses a portable battery power system and a fitted enclosure to support standalone operation.

## Hardware Integration

The ESP32 communicates with the peripherals through UART, I2C, and SPI interfaces. The system is designed to support simultaneous sensor acquisition, onboard data logging, and external telemetry transmission.
