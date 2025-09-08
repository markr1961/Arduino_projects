
// ESP32-S3-Matrix BlinkRGB
// from https://www.hackster.io/waveshare_electronics/esp32-s3-matrix-waterfall-and-effect-light-with-fastled-90ff01
// demo sources are reversed on page. Demo labeled "LED blink" is really "LED Spectrum"
#include <FastLED.h>
#define LED_PIN     14
#define NUM_LEDS    64
#define BRIGHTNESS  50  // 100
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
const uint8_t matrixWidth = 8;
const uint8_t matrixHeight = 8;
int radius = matrixWidth / 2; // Initial radius set to maximum value
bool expanding = false; // Initial state is contracting
CRGB historyColor[matrixHeight][matrixWidth];

void setup()
{
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    // Update radius based on expanding state
    if (!expanding)
    {
        radius--;
        if (radius < 1)   // When contracted to 1, prepare to expand
        {
            radius = 1;
            expanding = true; // Switch to expanding state
        }
    }
    else
    {
        radius++;
        if (radius > matrixWidth / 2)
        {
            radius = matrixWidth / 2;
            expanding = false; // Switch to contracting state
        }
    }
    uint8_t hue = 0;
    for (int i = 0; i < matrixHeight; i++)
    {
        for (int j = 0; j < matrixWidth; j++)
        {
            int dx = abs(j - matrixWidth / 2);
            int dy = abs(i - matrixHeight / 2);
            int dist = max(dx, dy); // Manhattan distance
            // Light up LEDs based on distance and expanding state
            if ((expanding && dist == radius) || (!expanding && dist <= radius))
            {
                hue = (millis() / 10 + i * matrixWidth + j) % 360; // Color changes over time
                CRGB color = CHSV(hue, 255, BRIGHTNESS);
                if (expanding)
                {
                    leds[matrixWidth * i + j] = color;
                    historyColor[i][j] = color;
                }
                else
                {
                    leds[matrixWidth * i + j] = historyColor[i][j];
                }
            }
        }
    }
    FastLED.show();
    delay(100);
}
