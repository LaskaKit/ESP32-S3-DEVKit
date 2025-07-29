/*
* This example code is used for LaskaKit ESP32-S3-DevKit board  https://www.laskakit.cz/laskakit-esp32-s3-devkit/
*
* ESP32-S3-DevKit board reads voltage of Battery  
* and sends every 0.5 seconds through UART and LaskaKit 0.91" SSD1306 (SSD1315) OLED i2c display
*
* Made by (c) laskakit.cz 2025
*
* Board: ESP32-S3 Dev Module
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>     // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h>

//For LaskaKit ESP32-S3 DEVKit
#define ADCBpin 9
#define bDeviderRatio 1.7693877551  // Voltage devider ratio on ADC pin 1MOhm + 1.3MOhm
#define PIN_ON 47
#define PIN_SCL 2
#define PIN_SDA 42

#define i2c_Address 0x3c

Adafruit_SSD1306 display(128, 32, &Wire, -1);

void setup() {
 Serial.begin(115200);
  pinMode(PIN_ON, OUTPUT);
  digitalWrite(PIN_ON, HIGH);
  delay(50); // Pause, wait to turn on
  Wire.begin(PIN_SDA, PIN_SCL);

  while(!Serial);    // time to get serial running
           
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, i2c_Address)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(1000); // Pause for 1 second

  display.clearDisplay(); 
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setTextSize(1); 
}

void loop() {

  float bat_voltage = analogReadMilliVolts(ADCBpin) * bDeviderRatio / 1000;
  Serial.print("Battery Voltage = " );
  Serial.print(bat_voltage);
  Serial.println("V");

  display.setCursor(0,0);
  display.println((String)"Battery voltage: ");
  display.print(bat_voltage);
  display.println((String)" V");
  display.display(); 
  delay(500);
  display.clearDisplay();
}
