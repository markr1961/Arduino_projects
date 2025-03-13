// compiles MAR 01/03/2025

#include <Wire.h>
#include <WiFi.h>

#include <PubSubClient.h> // "PubSubClient" or https://github.com/knolleary/pubsubclient

#define BOOTLOG( ... ) { char buf[120]; sprintf( buf, __VA_ARGS__ ) ; Serial.print("##[BOOT]#\t"); Serial.println(buf); }

#include "..\..\my_wifi.h"
//const char *ssid = "YOUR WIFI SSID";
//const char *password = "YOUR WIFI PASSWORD";
//const char *mqtt_server = "YOUR MQTT HOST";
const char *mqtt_sub_channel = "temp";
const char *mqtt_pub_channel = "test";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup_wifi()
{
    delay(10);
    // Connect to WiFi network
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length)
{
    String publish;

    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i=0;i<length;i++)
    {
        Serial.print((char)payload[i]);
        publish += (char)payload[i];
    }
  client.publish(mqtt_pub_channel, (char*)&publish, length);
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP32Client"))
        {
            Serial.println("connected");
            client.subscribe(mqtt_sub_channel);
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void setup()
{
    Serial.begin(115200);

    while(!Serial)
        delay(1);
    Serial.println("  === serial connected ===  ");

    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);

}

void loop()
{
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();
}
