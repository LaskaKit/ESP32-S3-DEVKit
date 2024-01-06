# ESP32-S3 DEVkit

![TOP](https://github.com/LaskaKit/ESP32-S3-DEVKit/blob/main/img/LaskaKit-esp32-s3-devkit-2.jpg)

Dual processors, up to 240 MHz, 512 kB RAM, 2.4 GHz, 802.11 b/g/n Wi-Fi and Bluetooth 5 (LE) - that's the ESP32 S3. Supported peripherals include GPIOs, SPI, I2S, I2C, PWM, RMT, ADC and UART, SD/MMC host and TWAI. Yes, it's a lot, plus the ESP32 S3 has an AI accelerator used for neural network learning. 

And it's not only because of these features that we decided to design a simple development kit that can be easily connected to existing devices or create a brand new one to which a lot of sensors can be connected. 

The ESP32 S DEVkit has two USB-C connectors. The USB-C connector labeled UART is used to program the ESP32-S3 via the USB-to-UART converter CH9102F. The second USB-C connector is then connected directly to the ESP32 S3 chip. 

Of course there is also a USB I2C connector for connecting various sensors - [SCD41 Sensor of CO2, temperature and humidity](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/), [BME688 Sensor of pressure, temperature, humidity and air quality](https://www.laskakit.cz/laskakit-bme688-senzor-tlaku--teploty--vlhkosti-a-kvalitu-vzduchu/), [BH1750 Sensor of light](https://www.laskakit.cz/laskakit-bh1750-snimac-intenzity-osvetleni/) and data can be shown on [OLED display 128x64 1.3" I²C](https://www.laskakit.cz/laskakit-oled-displej-128x64-1-3--i2c/?variantId=11903).

We have added an uŠup I2C connector and an uŠup SPI connector for connecting [microSD reader](https://github.com/LaskaKit/microSD-Reader).
The power supply of the uŠup I2C or SPI connector is controlled by GPIO pin 47. It enables LDO stabilizer - HIGH - enabled output, LOW - disabled output.

![Pinout](https://github.com/LaskaKit/ESP32-S3-DEVKit/blob/main/img/ESP32-S3-Devkit_pinout.JPG)

There is an integrated circuit for charging Li-Ion batteries with the possibility of setting the maximum charging current - 260mA or 400mA. When both solder bridges are soldered to each other, the charging current is 500mA. 
There is still an addressable RGB LED on the board and it is controlled by the GPIO45 pin. 
The battery measurement is measured by ADC GPIO 9 and the resistors in the divider are 1M and 1.3M.

## The board is available on https://www.laskakit.cz/laskakit-esp32-s3-devkit/?variantId=13145

![TOP](https://github.com/LaskaKit/ESP32-S3-DEVKit/blob/main/img/LaskaKit-esp32-s3-devkit-3.jpg)
