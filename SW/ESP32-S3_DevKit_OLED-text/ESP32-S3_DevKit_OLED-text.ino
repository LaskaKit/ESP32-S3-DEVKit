#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>    // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SH110X.h> // https://github.com/adafruit/Adafruit_SH110X

#define I2C_SDA 42
#define I2C_SCL 2
#define SENSOR_SUPPLY 47
#define i2c_Address 0x3c

TwoWire I2C_OLED = TwoWire(0);
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &I2C_OLED, -1); // Nastaví display

void setup()
{
  Serial.begin(115200);
  while (!Serial); // time to get serial running

  pinMode(SENSOR_SUPPLY, OUTPUT);
  digitalWrite(SENSOR_SUPPLY, HIGH);

  I2C_OLED.begin(I2C_SDA, I2C_SCL, 400000); // Nastaví I2C

  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
}

void loop()
{
  // put your main code here, to run repeatedly:
  display.setCursor(0, 0);
  display.println("Teplota: 25C");
  display.println("Tlak: 950hPa");
  display.println("Vlhkost: 65%");
  display.println("Nadmorska vyska: 554m");
  display.display();
  delay(500);
  display.clearDisplay();
}