## ESP32-C3 With 0.42 OLED

This project is for the "ABrobot" ESP32-C3 board with 0.42" OLED form AliExpress
- https://www.aliexpress.com/item/3256807670573244.html or https://www.aliexpress.com/item/3256807156068355.html  
In many ways this board is similar to the ESP32C3 "Super Mini" boards with an 0.42" 72x40 OLED.

A good source of information is [Kevin’s Blog: ESP32-C3 0.42 OLED](https://emalliab.wordpress.com/2025/02/12/esp32-c3-0-42-oled/)
His blog includes pinouts, schematics, and example code to test pins and UART. This project is directly based on his Arduino code.

A git repo to explore: https://github.com/zhuhai-esp/ESP32-C3-ABrobot-OLED/tree/main 
Includes schematics, pinout and platformio example code.

### pins
5   I2C
6   I2C
8   LED (active low)

### Arduino settings
"ESP32C3 Dev Module" works.  
print to USB probably requires "XIAO ESP32C3" but this is as yet untested.

### To Do 
- is it possible to rotate fonts 90 degrees? yes: https://forum.seeedstudio.com/t/change-text-orientation-on-oled-display/6805/3
