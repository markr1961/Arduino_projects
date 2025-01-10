#include <Wire.h>
#include "heltec.h" // requires Adafruit GFX lib.
#include <WiFi.h>

void setup() {
  // Initialize the Heltec ESP32 board
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);

  Serial.begin(115200);

  while (!Serial)
    ;
  // Clear the display
  Heltec.display->clear();
  
  // Set the font size
  Heltec.display->setFont(ArialMT_Plain_10);
  
  // Display "Hello, World!" on the screen
  Heltec.display->drawString(0, 0, "Hello, World!");
  
  // Send the buffer to the display
  Heltec.display->display();

  Serial.println("display init'ed");
  
  delay(2000);  // wait 2 seconds
  
  // Start the WiFi scan
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);

  Serial.println("wifi set.");

  delay(100);

}

void loop() {

  Serial.println("scanning...");

  int n = WiFi.scanNetworks();

  Serial.println("scan done.");

  // Clear the display
  Heltec.display->clear();

  Serial.println("displaying...");

  if (n == 0) {
    Heltec.display->drawString(0, 0, "No networks found");
  } else {
    for (int i = 0; i < n; ++i) {
      // Display the SSID of each network found
      Heltec.display->drawString(0, i * 10, WiFi.SSID(i));
    }
  }
  
  // Send the buffer to the display
  Heltec.display->display();

  Serial.println("waiting ...");

  delay(2000);

}
