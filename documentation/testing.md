# NEXUS Testing and Validation

## 1. Purpose

This document records the testing and validation performed on the NEXUS GPS and IMU localization system.

## 2. Hardware Testing

| Component | Test | Result |
|---|---|---|
| ESP32 | USB connection and firmware upload | Passed |
| OLED Display | Startup message and status display | Passed |
| GPS Module | Satellite acquisition and position readings | Passed |
| BNO055 IMU | Acceleration, angular velocity, and magnetic field readings | Passed |
| MicroSD Module | Card detection, file creation, and CSV logging | Passed |
| HC-05 Bluetooth | Wireless serial connection and telemetry | Passed |
| Battery | Portable power operation | Implemented |
| Enclosure | Physical enclosure completed | Completed |

## 3. Data Logging Testing

The microSD module was tested by initializing the card, creating a CSV file, and writing telemetry records.

The resulting CSV file was retrieved from the card and inspected to verify that data was being recorded.

## 4. Communication Testing

### Bluetooth
The HC-05 module was paired with a computer. Incoming telemetry was verified through a serial terminal using the configured outgoing COM port.

### USB Serial
The ESP32 firmware includes USB serial telemetry output. Computer-side ground-control operation through USB remains to be validated.

### Simultaneous Outputs
The firmware is designed to send telemetry to the microSD card, USB serial connection, and Bluetooth module simultaneously. A final simultaneous-operation test remains necessary.

## 5. Ground-Control Software Testing

The Python ground-control application was tested for:

- Serial communication with the NEXUS device.
- Real-time GPS data display.
- GPS location visualization on a live map.
- IMU measurement display.
- Real-time plotting.
- Start Display and End Display controls.

The application was successfully tested using the Bluetooth serial connection.

## 6. Remaining Validation

The following tests remain to be completed:

- Verify simultaneous microSD, USB, and Bluetooth data output.
- Verify computer ground-control operation through USB.
- Confirm the elevation reference used in the CSV output.
- Perform a battery runtime test to verify at least one hour of operation.
- Complete and test the fabricated PCB.
- Perform a final full-system test in the completed enclosure.

## 7. Conclusion

Initial testing confirms that the primary NEXUS hardware modules, sensor acquisition, microSD logging, Bluetooth telemetry, OLED display, and Python ground-control interface are operational.

Additional validation is required to verify all project requirements under full-system operating conditions.
