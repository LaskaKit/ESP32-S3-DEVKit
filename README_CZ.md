# ESP32-S3 DEVkit

![TOP](https://github.com/LaskaKit/ESP32-S3-DEVKit/blob/main/img/LaskaKit-esp32-s3-devkit-2.jpg)

Dvojitý procesor, takt až 240 MHz, 512 kB RAM, 2.4 GHz, 802.11 b/g/n Wi-Fi and Bluetooth 5 (LE) - to je ESP32 S3. Mezi podporované periférie nechybí GPIOs, SPI, I2S, I2C, PWM, RMT, ADC a UART, SD/MMC host a TWAI. Ano, je toho opravdu hodně, navíc má ESP32 S3 AI akcelerátor sloužící pro učení neuronových sítí. 

A nejen díky těmto vlastnostem jsme se rozhodli navrhnout jednoduchý vývojový kit, který jde jednoduše připojit ke stávajícím zařízením nebo vytvořit úplně nové, ke kterému se dá připojit spousta čidel. 

Vývojový kit ESP32 S DEVkit má dvě USB-C konektory. USB-C konektor označený UART slouží k programování ESP32-S3 skrze převodník USB-UART CH9102F. Druhý USB-C konektor je pak připojený přímo do ESP32 S3 čipu. 

Samozřejmostí je i uŠup I2C konektor pro připojení nejrůznějších čidel - [SCD41 Senzor CO2, teploty a vlhkosti vzduchu](https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/), [BME688 Senzor tlaku, teploty, vlhkosti a kvalitu vzduchu](https://www.laskakit.cz/laskakit-bme688-senzor-tlaku--teploty--vlhkosti-a-kvalitu-vzduchu/), [BH1750 Snímač intenzity osvětlení](https://www.laskakit.cz/laskakit-bh1750-snimac-intenzity-osvetleni/) a zobrazit data můžete na [OLED displej 128x64 1.3" I²C](https://www.laskakit.cz/laskakit-oled-displej-128x64-1-3--i2c/?variantId=11903).

K uŠup I2C konektoru jsme přidali i uŠup SPI konektor pro připojení [microSD reader](https://github.com/LaskaKit/microSD-Reader).
Napájení uŠup I2C nebo SPI konektoru je řízeno GPIO pine 47. Ten povoluje LDO stabilizátor - HIGH - povolený výstup, LOW - zakázaný výstup.

Nechybí integrovaný obvod pro nabíjení Li-Ion akumulátorů s možností nastavení maximálního nabíjecího proudu - 260mA nebo 400mA. Když jsou propájeny oba pájecí mosty navzájem, nabíjecí proud je 500mA. 
Na desce je ještě adresovatelná RGB LED a je řízena pinem GPIO45. 
Měření akumulátoru je měřeno ADC GPIO 9 a rezistory v děliči mají hodnotu 1M a 1.3M.

## Desku můžete zakoupit na https://www.laskakit.cz/laskakit-esp32-s3-devkit/?variantId=13145

![TOP](https://github.com/LaskaKit/ESP32-S3-DEVKit/blob/main/img/LaskaKit-esp32-s3-devkit-3.jpg)
