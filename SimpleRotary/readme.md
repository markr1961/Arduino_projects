## SimpleRotary.ino
A simple sketch showing use of a KY-040 rotary encoder board with button
This board includes pull-ups on the switch and encoder lines, so +5v is required.

based on examples by Matthias Hertel, http://www.mathertel.de/Arduino
His work is licensed under a BSD 3-Clause License.

Requires Matthias Hertel's libraries for
rotary encoder: https://github.com/mathertel/RotaryEncoder
one button: https://github.com/mathertel/OneButton

#### Hardware setup
Attach rotary encoder output pins to:
- D2 and D3 for encoder
- D4 for switch
