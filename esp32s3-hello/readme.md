### ESP32-S3-N16R8

#### download info
Connecting....  
Chip is ESP32-S3 (QFN56) (revision v0.2)
Features: WiFi, BLE, Embedded PSRAM 8MB (AP_3v3)
Crystal is 40MHz  
MAC: 98:3d:ae:e6:9d:54  

#### Board Info
BN: Unknown board  
VID: 0x1A86  
PID: 0x55D3   
SN: 58FC045974  

### hardware

#### closest online design
[Espressif ESP32-S3-DevKitC-1-N16R8V (16 MB QD, 8MB PSRAM))](https://github.com/shpegun60/ESP32-S3-N16R8)
has wrong module (no RF conn) but jumpers and layout look correct. 
Includes spiffs info and Platform.io description file.  
RGB LED: driven by GPIO48.  

#### closest Espressif reference design
[ESP32-S3-DevKitC-1-N16R8V](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-devkitc-1/index.html)  
Module: ESP32-S3-WROOM-2-N16R8V  
Boot: GPIO0  
RGB LED driven by GPIO38 (v1.0) or GPIO48 (v1.1)  

### serial output
Chip Model: ESP32-S3  
Chip version: 2  
Number of cores: 2  
Flash Chip Size: 16777216  
Flash Chip Speed: 80000000  
Total heap: 397308
Free heap: 359124
Total PSRAM: 0
Free PSRAM: 0

### commit notes
01/03/2025 MAR
Initial commit with working serial "hello world' project and docs
