/*
* Example code for ESP32-S3-DEVkit evaluation board made by laskakit.cz
* Firmware sends message through serial com port (UART)
* "laskakit.cz" 
* "ESP32-S3-DEVkit"
* The message is sent every second
*
* Created by (c) laskakit.cz 2023
*
* Libraries:
* -
*/
 
void setup() {
  Serial.begin(115200);
  while (!Serial) 
  {
    ; // waiting for serial com port
  }
}
 
void loop() {
  Serial.println("laskakit.cz");
  Serial.println("ESP32-S3-DEVkit");
  delay(1000);
}
