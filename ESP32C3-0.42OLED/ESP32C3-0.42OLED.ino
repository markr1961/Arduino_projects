// https://emalliab.wordpress.com/2025/02/12/esp32-c3-0-42-oled/
// draws a line around the edge and shows screen size in middle.

// use XIAO ESP32C3 or Lolin min for USB serial.

#include <U8g2lib.h>  // https://github.com/olikraus/u8g2/wiki/u8g2reference
#include <Wire.h>
#include <WiFi.h>

#define LED 8

// there is no 72x40 constructor in u8g2 hence the 72x40 screen is
// mapped in the middle of the 132x64 pixel buffer of the SSD1306 controller
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);
int width = 72;
int height = 40;
int xOffset = 30; // = (132-w)/2
int yOffset = 12; // = (64-h)/2

void setup(void)
{
    Serial.begin(115200);
    
    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);

    do
    {
        delay(100);
        digitalWrite(LED, digitalRead(LED) ? LOW : HIGH); // toggle the LED
    } while (!Serial);

    Serial.println("Setup done");

    digitalWrite(LED, HIGH);

    delay(1000);
    u8g2.begin();
    u8g2.setContrast(255); // set contrast to maximum 
    u8g2.setBusClock(400000); //400kHz I2C 
    u8g2.setFont(u8g2_font_ncenB10_tr);
}

int count;

void loop(void)
{
    Serial.print("scan start: ");
    Serial.println(count++);
    digitalWrite(LED, LOW);
    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    digitalWrite(LED, HIGH);

    if (n == 0)
    {
        Serial.println("no networks found");
    }
    else
    {
        Serial.print(n);
        Serial.println(" networks found");

        // Print SSID and RSSI for each network found
        for (int i = 0; i < n; i++)
        {
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
            delay(10);
        }
    }
    Serial.println("");

    u8g2.clearBuffer(); // clear the internal memory
    u8g2.drawFrame(xOffset+0, yOffset+0, width, height); //draw a frame around the border
    u8g2.setCursor(xOffset+15, yOffset+25);
    u8g2.printf("%d", n);
    u8g2.sendBuffer(); // transfer internal memory to the display

    // Wait a bit before scanning again
    for (int i = 0; i < 20; i++)
    {
        digitalWrite(LED, digitalRead(LED) ? LOW : HIGH); // toggle the LED
        delay(250);
//        Serial.print(i);
    }
}
