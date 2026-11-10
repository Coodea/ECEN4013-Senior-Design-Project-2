#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <U8g2lib.h>

// GPS
TinyGPSPlus gps;
HardwareSerial GPS(2);

// Bluetooth
HardwareSerial Bluetooth(1);

// IMU
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

// OLED
U8G2_SSD1309_128X64_NONAME0_F_HW_I2C display(
  U8G2_R0, U8X8_PIN_NONE
);

// SD CARD
#define SD_CS 25
#define SD_SCK 18
#define SD_MISO 19
#define SD_MOSI 23

bool sdOK = false;
bool imuOK = false;

unsigned long lastSample = 0;

const char* csvHeader =
"millis,latitude_deg,longitude_deg,altitude_m_MSL,satellites,"
"accel_x_m_s2,accel_y_m_s2,accel_z_m_s2,"
"gyro_x_rad_s,gyro_y_rad_s,gyro_z_rad_s,"
"mag_x_uT,mag_y_uT,mag_z_uT";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // I2C
  Wire.begin(21, 22);

  // OLED
  display.begin();
  display.setFont(u8g2_font_6x12_tr);
  display.clearBuffer();
  display.drawStr(10, 25, "NEXUS STARTING");
  display.drawStr(10, 45, "Please wait...");
  display.sendBuffer();

  // GPS
  GPS.begin(9600, SERIAL_8N1, 16, 17);

  // Bluetooth HC-05
  Bluetooth.begin(9600, SERIAL_8N1, 26, 27);

  // BNO055
  imuOK = bno.begin();

  if (imuOK) {
    bno.setExtCrystalUse(true);
  }

  // SD CARD
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

  sdOK = SD.begin(SD_CS, SPI, 1000000);

  if (sdOK) {
    File file = SD.open("/NEXUS.CSV", FILE_APPEND);

    if (file) {
      if (file.size() == 0) {
        file.println(csvHeader);
      }
      file.close();
    } else {
      sdOK = false;
    }
  }

  Serial.println("NEXUS SYSTEM ONLINE");
  Serial.println(csvHeader);

  Bluetooth.println("NEXUS SYSTEM ONLINE");
  Bluetooth.println(csvHeader);
}

void loop() {

  // Read GPS continuously
  while (GPS.available()) {
    gps.encode(GPS.read());
  }

  // Take measurements once per second
  if (millis() - lastSample >= 1000) {
    lastSample = millis();

    sensors_event_t acceleration;
    sensors_event_t gyroscope;
    sensors_event_t magnetometer;

    if (imuOK) {
      bno.getEvent(
        &acceleration,
        Adafruit_BNO055::VECTOR_ACCELEROMETER
      );

      bno.getEvent(
        &gyroscope,
        Adafruit_BNO055::VECTOR_GYROSCOPE
      );

      bno.getEvent(
        &magnetometer,
        Adafruit_BNO055::VECTOR_MAGNETOMETER
      );
    }

    // Build CSV row
    String line = String(millis());

    line += ",";

    if (gps.location.isValid()) {
      line += String(gps.location.lat(), 6);
    }

    line += ",";

    if (gps.location.isValid()) {
      line += String(gps.location.lng(), 6);
    }

    line += ",";

    if (gps.altitude.isValid()) {
      line += String(gps.altitude.meters(), 2);
    }

    line += ",";
    line += String(gps.satellites.value());

    // Acceleration
    line += ",";

    if (imuOK) {
      line += String(acceleration.acceleration.x, 3);
      line += "," + String(acceleration.acceleration.y, 3);
      line += "," + String(acceleration.acceleration.z, 3);

      // Gyroscope
      line += "," + String(gyroscope.gyro.x, 4);
      line += "," + String(gyroscope.gyro.y, 4);
      line += "," + String(gyroscope.gyro.z, 4);

      // Magnetometer
      line += "," + String(magnetometer.magnetic.x, 3);
      line += "," + String(magnetometer.magnetic.y, 3);
      line += "," + String(magnetometer.magnetic.z, 3);
    } else {
      line += ",,,,,,,,";
    }

    // USB data stream
    Serial.println(line);

    // Bluetooth data stream
    Bluetooth.println(line);

    // SD card logging
    if (sdOK) {
      File file = SD.open("/NEXUS.CSV", FILE_APPEND);

      if (file) {
        file.println(line);
        file.close();
      } else {
        sdOK = false;
      }
    }

    // OLED display
    display.clearBuffer();

    display.drawStr(0, 12, "NEXUS ONLINE");

    if (gps.location.isValid()) {
      display.drawStr(0, 26, "GPS: LOCKED");
    } else {
      display.drawStr(0, 26, "GPS: SEARCHING");
    }

    String sats = "Satellites: " +
                  String(gps.satellites.value());

    display.drawStr(0, 39, sats.c_str());

    display.drawStr(
      0, 52,
      sdOK ? "SD: RECORDING" : "SD: ERROR"
    );

    display.drawStr(
      0, 63,
      imuOK ? "IMU: ONLINE" : "IMU: ERROR"
    );

    display.sendBuffer();
  }
}
