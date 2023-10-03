/*
* This example code is used for LaskaKit ESP32-S3-DEVKit board 
* with our Temperature and Humidity SHT40 module https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/
* ESP32-S3-DEVKit board reads temperature and humidity from SHT40 sensor 
* and sends every second through UART
* 
*
* Made by (c) laskakit.cz 2023
*
* Libraries: https://github.com/Sensirion/arduino-i2c-sht4x
* 
*/

#include <SensirionI2CSht4x.h>

#define PIN_ON 47

SensirionI2CSht4x sht4x;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_ON, OUTPUT);      // Set EN pin for second stabilisator as output
  digitalWrite(PIN_ON, HIGH);   // Turn on the second stabilisator

  Wire.begin(42, 2);            // set dedicated I2C pins 42 - SDA, 2 - SCL for ESP32-S3-DEVKit

  uint16_t error;
  char errorMessage[256];

  sht4x.begin(Wire);

  uint32_t serialNumber;
  error = sht4x.serialNumber(serialNumber);
  if (error) {
      Serial.print("Error trying to execute serialNumber(): ");
      errorToString(error, errorMessage, 256);
      Serial.println(errorMessage);
  } else {
      Serial.print("Serial Number: ");
      Serial.println(serialNumber);
  }
}

void loop() {
  uint16_t error;
  char errorMessage[256];
  float temperature;
  float humidity;
  
  error = sht4x.measureHighPrecision(temperature, humidity);
  if (error) {
      Serial.print("Error trying to execute measureHighPrecision(): ");
      errorToString(error, errorMessage, 256);
      Serial.println(errorMessage);
  } else {
      Serial.print("Temperature:");
      Serial.print(temperature);
      Serial.print("\t");
      Serial.print("Humidity:");
      Serial.println(humidity);
  }
  
  delay(1000);

}
