// use XIAO ESP32C3 or Lolin min for USB serial.

#include "WiFi.h"
#define LED 8

void setup()
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
}

int count;
void loop()
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

    // Wait a bit before scanning again
    for (int i = 0; i < 20; i++)
    {
        digitalWrite(LED, digitalRead(LED) ? LOW : HIGH); // toggle the LED
        delay(250);
//        Serial.print(i);
    }
}
