
// ESP32-S3-Matrix LED Spectrum
// from https://www.hackster.io/waveshare_electronics/esp32-s3-matrix-waterfall-and-effect-light-with-fastled-90ff01
// demo sources are reversed on page. Demo labeled "LED blink" is really "LED Spectrum"
#include <FastLED.h>
#define LED_PIN     14
#define NUM_LEDS    64
#define BRIGHTNESS  10
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
const uint16_t bands = 8; // Number of frequency bands
uint8_t bar_values[bands]; // Store the height of each band
CRGB colors[bands]; // Store the color of each band
void setup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}
void loop()
{
    static uint8_t lastBarValues[bands]; // Store the last height of the bands
    fill_solid(leds, NUM_LEDS, CRGB::Black); // Turn off all LEDs first
    // Generate new band heights and colors
    for (int i = 0; i < bands; i++)
    {
        bar_values[i] = random(0, 9); // Generate a random value between 0 and 8
        colors[i] = CHSV(random8(), 255, 255); // Generate a random color
    }
    // Draw each band
    for (int i = 0; i < bands; i++)
    {
        for (int j = 0; j < bar_values[i]; j++)
        {
            leds[i * 8 + j] = colors[i]; // Light up each bar of the band
        }
    }
    // Draw the descending effect
    for (int i = 0; i < bands; i++)
    {
        if (bar_values[i] < lastBarValues[i])
        {
            for (int j = bar_values[i]; j < lastBarValues[i]; j++)
            {
                leds[i * 8 + j] = CRGB::Black; // Turn off each bar of the band
            }
            lastBarValues[i] = bar_values[i]; // Update the last band height
        }
        else
        {
            lastBarValues[i] = bar_values[i]; // If there is no change, update directly
        }
    }
    FastLED.show(); // Update the LED display
    delay(50); // Delay for 50 milliseconds
    // Update the last band height
    for (int i = 0; i < bands; i++)
    {
        lastBarValues[i] = bar_values[i];
    }
}
