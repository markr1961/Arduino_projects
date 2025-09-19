// SimpleRotary.ino
// A simple sketch showing use of a KY-040 rotary encoder board with button
// This board includes pull-ups on the switch and encoder lines, so +5v is required.
//
// based on examples by Matthias Hertel, http://www.mathertel.de/Arduino
// This work is licensed under a BSD 3-Clause License.
// -----
// Requires Matthias Hertel's libraries for
// rotary encoder: https://github.com/mathertel/RotaryEncoder
// one button: https://github.com/mathertel/OneButton

// Checks the state of the rotary encoder in the loop() function.
// The current position and direction is printed on output when changed.
// A double tap on the switch toggles the built-in LED.

#include <Arduino.h>
#include <RotaryEncoder.h>
#include <OneButton.h>

// Hardware setup:
// Attach rotary encoder output pins to:
// * D2 and D3 for encoder 
// * D4 for switch 
#define EN_PIN_IN1 2
#define EN_PIN_IN2 3
#define SWITCH_IN  4

// Setup a RotaryEncoder with 4 steps per latch for the 2 signal input pins:
// RotaryEncoder encoder(EN_PIN_IN1, EN_PIN_IN2, RotaryEncoder::LatchMode::FOUR3);
// Setup a RotaryEncoder with 2 steps per latch for the 2 signal input pins:
RotaryEncoder encoder(EN_PIN_IN1, EN_PIN_IN2, RotaryEncoder::LatchMode::TWO03);

OneButton button(SWITCH_IN); // Setup a new OneButton on pin A1.  


inline void toggle(int pin)
{
   digitalWrite(pin, digitalRead(pin) ? false : true);
}

void setup()
{
  Serial.begin(115200);
  
   // enable the standard led on pin 13.
  pinMode(LED_BUILTIN, OUTPUT);      // sets the digital pin as output
  // link the double-click function to be called on a double-click event.
  button.attachDoubleClick(doubleclick);

  while (! Serial)
    ;
  
  Serial.println("ready");
} // setup()


// Read the current position of the encoder and print out when changed.
void loop()
{
  static int lastPos = 0;
  encoder.tick();

  // watch the push button:
  button.tick();

  int newPos = encoder.getPosition();
  if (lastPos != newPos) {
    Serial.print("pos:");
    Serial.print(newPos);
    Serial.print(" dir:");
    Serial.println((int)(encoder.getDirection()));
    lastPos = newPos;
  }
} // loop ()

// called when the button was pressed twice in a short time inteval.
void doubleclick()
{
  // toggle the LED
  toggle(LED_BUILTIN);

} // doubleclick
