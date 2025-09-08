// walking LED pattern
// uses ESP32-S3-matrix from Waveshare.

#include <FastLED.h>

#define LED_PIN     14
#define NUM_LEDS    64
#define BRIGHTNESS  50  // 100
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

CRGB color;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  fill_solid(leds, NUM_LEDS, CRGB::Black);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x = 0; x < 64; x++)
  {
    leds[x].setHue(0);
    for (int bright = 0; bright < 256 ; bright++)
    {
      leds[x].setHSV(0, 255, bright);
      FastLED.show();
    }
    leds[x].setHSV(0, 255, BRIGHTNESS);
    for (int hue = 0; hue < 128; hue++)
    {
      leds[x].setHue(hue);
      FastLED.show();
    }
    for (int bright = 255; bright >= 0 ; bright--)
    {
      leds[x].setHSV(128, 255, bright);
      FastLED.show();
    }
    leds[x] = CRGB::Black;
  }

}
