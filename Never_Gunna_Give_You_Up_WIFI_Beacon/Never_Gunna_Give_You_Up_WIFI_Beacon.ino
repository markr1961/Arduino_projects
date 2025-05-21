// "Never Gunna Give You Up" WIFI Beacon
// code written by NoMoreImFull for the good of humanity
// Lyrics by God Emperor Rick Astley
// https://www.reddit.com/r/arduino/comments/12uy1r2/never_gunna_give_you_up_wifi_beacon/

// Each line of the lyrics in the array
// is 32 characters (including spaces) or less
// to comply with SSID naming limitations.

#include <Arduino.h>
#include <ESP8266WiFi.h>

String never_gunna[] =
{
    "Were no strangers to love",
    "You know the rules and so do I",
    "A full commitments",
    "what Im thinking of",
    "You wouldnt get this from",
    "any other guy",
    "I just wanna tell you",
    "how Im feeling",
    "Gotta make you understand",
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around",
    "and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie",
    "and hurt you",
    "Weve known each other for so long",
    "Your hearts been aching, but",
    "youre too shy to say it",
    "Inside we both know",
    "whats been going on",
    "We know the game ",
    "and were gonna play it",
    "And if you ask me how Im feeling",
    "Dont tell me youre too blind", // to see",
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around",
    "and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie",
    "and hurt you",
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around",
    "and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie",
    "and hurt you",
    "Weve known each other for so long",
    "Your hearts been aching, but",
    "youre too shy to say it",
    "Inside we both know",
    "whats been going on",
    "We know the game ",
    "and were gonna play it",
    "I just wanna tell you",
    "how Im feeling",
    "Gotta make you understand",
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around",
    "and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie",
    "and hurt you",
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around",
    "and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie",
    "and hurt you",
    "Never gonna give you up",
    "Never gonna let you down",
    "Never gonna run around",
    "and desert you",
    "Never gonna make you cry",
    "Never gonna say goodbye",
    "Never gonna tell a lie",
    "and hurt you"
};

const int update_interval = 20000; // SSID Update interval, adjust as needed.

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
    Serial.begin(115200);
    Serial.println("Wait for it...");
    WiFi.softAP(never_gunna[0].c_str());
}

void loop()
{
    static unsigned long last_update_time = 0;
    if (millis() - last_update_time > update_interval)
    {
        static int current_line = 0;
        current_line = (current_line + 1) % (sizeof(never_gunna) / sizeof(String));
        Serial.print("Updating SSID to ");
        Serial.println(never_gunna[current_line]);
        WiFi.softAP(never_gunna[current_line].c_str());
        last_update_time = millis();
    }
    delay(1000);
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)?LOW:HIGH); // toggle LED

}
