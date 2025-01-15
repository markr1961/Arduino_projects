
/******************************************************************************
servo-skatch.ino
Example sketch for connecting a hobby servo to a sparkfun redboard
  (https://www.sparkfun.com/products/9065)
  (https://www.sparkfun.com/products/12757)
Byron Jacquot@ SparkFun Electronics   May 17, 2016
**SparkFun code, firmware, and software is released under the MIT License(http://opensource.org/licenses/MIT).**
Development environment specifics:  Arduino 1.6.5
******************************************************************************/

#include <Servo.h>
Servo testservo;
uint32_t next;

void setup()
{
    // the 1000 & 2000 set the pulse width
    // mix & max limits, in microseconds.
    // Be careful with shorter or longer pulses.
    testservo.attach(9, 1000, 2000);

    next = millis() + 500;
}

void loop()
{
    static bool rising = true;

    if(millis() > next)
    {
        if(rising)
        {
            testservo.write(180); // degrees
            rising = false;
        }
        else
        {
            testservo.write(0); // degrees
            rising = true;
        }

        // repeat again in 3 seconds.
        next += 3000;
    }
}
