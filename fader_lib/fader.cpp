/**
  *
  * !!!!! A work in progress !!!!!!
  *
  * A fader library function derived from fadeTo()
  * by Matt Jenkins of Majenko Technologies
  * https://majenko.co.uk/blog/our-blog-1/flexible-led-fading-14
  *
  */

#include "" //ledc library

class:

 private:
    // These store the current brightness values
    uint8_t     redCurrent;
    uint8_t     greenCurrent;
    uint8_t     blueCurrent;
    uint8_t     redPin;
    uint8_t     greenPin;
    uint8_t     bluePin;
    uint32_t    delayTime = 0;
    uint8_t     resolution = 8;
    uint32_t    frequency = 4092;

void fader::Init(uint8_t redPinInit, uint8_t greenPinInit, uint8_t bluePinInit, uint32_t del = 0, uint8_t res = 8, uint32_t freq = 4092)
{
    redCurrent = 0;
    greenCurrent = 0;
    blueCurrent = 0;
    redPin = redPinInit;
    greenPin = greenPinInit;
    bluePin =  bluePinInit;

    delayTime = del;
    resolution = res;
    frequency = freq;

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    digitalWrite(redPin, 0);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
#ifdef ESP32
    ledcAttach(redPin, frequency, resolution);
    ledcAttach(greenPin, frequency, resolution);
    ledcAttach(bluePin, frequency, resolution);
#endif

}

bool fader::fadeTo(uint8_t redVal, uint8_t greenVal, uint8_t blueVal, uint32_t del = 0)
{
    // Keep track of if any color has faded or not
    bool finished = true;

    // Adjust the red ...
    if (redCurrent > redVal) {
        redCurrent--;
        finished = false;
    } else if (redCurrent < redVal) {
        redCurrent++;
        finished = false;
    }

    // ... green ...
    if (greenCurrent > greenVal) {
        greenCurrent--;
        finished = false;
    } else if (greenCurrent < greenVal) {
        greenCurrent++;
        finished = false;
    }

    // ... and blue values.
    if (blueCurrent > blueVal) {
        blueCurrent--;
        finished = false;
    } else if (blueCurrent < blueVal) {
        blueCurrent++;
        finished = false;
    }

    // Update the outputs with the new values
#ifdef ESP32
    ledcWrite(redPin, redCurrent);
    ledcWrite(greenPin, greenCurrent);
    ledcWrite(bluePin, blueCurrent);
#else
    analogWrite(redPin, redCurrent);
    analogWrite(greenPin, greenCurrent);
    analogWrite(bluePin, blueCurrent);
#endif

   // Pause as long as is requested
   if (del) {
       delayTime = del;
   }
   if (delayTime) {
       delay(delayTime);
   }
}