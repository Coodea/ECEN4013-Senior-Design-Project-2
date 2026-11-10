# NEXUS Hardware Pinout

This document describes the GPIO connections between the ESP32-WROOM-32 and the NEXUS peripheral modules.

## ESP32 GPIO Configuration

| Peripheral | Module Pin | ESP32 GPIO | Interface |
|---|---|---:|---|
| GPS | TX | GPIO 16 | UART RX |
| GPS | RX | GPIO 17 | UART TX |
| BNO055 | SDA | GPIO 21 | I2C |
| BNO055 | SCL | GPIO 22 | I2C |
| OLED | SDA | GPIO 21 | I2C |
| OLED | SCL | GPIO 22 | I2C |
| HC-05 | TXD | GPIO 26 | UART RX |
| HC-05 | RXD | GPIO 27 | UART TX |
| MicroSD | CS | GPIO 25 | SPI |
| MicroSD | SCK | GPIO 18 | SPI |
| MicroSD | MOSI | GPIO 23 | SPI |
| MicroSD | MISO | GPIO 19 | SPI |

## Shared Communication Interfaces

### I2C

The BNO055 and SSD1309 OLED share the same I2C bus.

- SDA: GPIO 21
- SCL: GPIO 22

### GPS UART

The GPS module communicates through ESP32 UART2.

- ESP32 RX2: GPIO 16
- ESP32 TX2: GPIO 17
- Baud rate: 9600

### Bluetooth UART

The HC-05 communicates through a separate ESP32 hardware UART.

- ESP32 RX: GPIO 26
- ESP32 TX: GPIO 27
- Baud rate: 9600

### MicroSD SPI

The MicroSD module uses the ESP32 SPI interface.

- CS: GPIO 25
- SCK: GPIO 18
- MOSI: GPIO 23
- MISO: GPIO 19

## Power and Ground

All peripheral modules share a common ground reference with the ESP32.

Power connections follow the voltage requirements of each individual module and the established NEXUS power distribution design.

## Notes

- GPIO assignments correspond to the working NEXUS prototype.
- The BNO055 and OLED share the I2C bus.
- The GPS and HC-05 use separate UART interfaces.
- The MicroSD module uses SPI communication.
- Verify the pin assignments against the physical hardware before making modifications.

