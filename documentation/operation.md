# NEXUS Operating Instructions

## 1. Purpose

This document describes how to power on, operate, and collect data using the NEXUS GPS and IMU localization system.

## 2. System Startup

1. Ensure the battery is charged and connected.
2. Turn on the NEXUS device.
3. Wait for the ESP32 to initialize the connected modules.
4. Observe the OLED display for the NEXUS startup message.
5. Allow the GPS module time to acquire satellite signals.

## 3. GPS Status

The OLED provides information about the GPS acquisition state.

- **Searching:** The GPS module is attempting to acquire satellite signals.
- **Locked:** The GPS module has acquired satellite signals and is providing positioning information.

GPS acquisition time depends on satellite visibility and environmental conditions.

## 4. Data Collection

NEXUS collects the following measurements:

### GPS Measurements
- Latitude
- Longitude
- Elevation
- Number of locked satellites

### IMU Measurements
- Angular velocity along X, Y, and Z axes (rad/s)
- Acceleration along X, Y, and Z axes (m/s²)
- Magnetic field along X, Y, and Z axes (µT)

## 5. Data Outputs

NEXUS supports three telemetry outputs:

### MicroSD Card
The device continuously writes telemetry records to a CSV file on the microSD card. The file can be opened and analyzed using spreadsheet or data-processing software.

### USB Serial
The ESP32 transmits telemetry records through its USB serial connection to a connected computer.

### Bluetooth
The HC-05 Bluetooth module provides a wireless serial telemetry stream to a paired computer.

The three outputs are designed to operate simultaneously.

## 6. Ground-Control Software

The Python ground-control application provides a computer interface for monitoring NEXUS.

1. Connect the computer to the device using the configured serial connection.
2. Launch the Python ground-control application.
3. Select **Start Display** to begin displaying incoming telemetry.
4. Monitor GPS information, the live map, IMU measurements, and real-time plots.
5. Select **End Display** to stop the display.

The application requires Python and the packages listed in `software/ground_control/requirements.txt`.

## 7. Data Retrieval

1. Turn off the NEXUS device before removing the microSD card.
2. Remove the card from its module.
3. Connect the card to a computer using a compatible card reader.
4. Locate the NEXUS CSV log file.
5. Copy the file to the computer for analysis.

## 8. Shutdown

1. Stop the ground-control display if it is running.
2. Turn off the NEXUS device.
3. Remove the microSD card only after the device has been powered down.

## 9. Operating Notes

- GPS performance may be reduced indoors or in areas with limited sky visibility.
- Keep the antenna positioned for good satellite reception.
- Ensure the microSD card is installed before starting a data-logging session.
- Verify the selected serial port before starting the ground-control application.
- Confirm that the battery is adequately charged before portable operation.
