/*
  ESP8266 CheckFlashConfig by Markus Sattler

  This sketch tests if the EEPROM settings of the IDE match to the Hardware

*/

void setup(void) {
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  while (!Serial)
    ;
}

int count;
void loop() {

  uint32_t realSize = ESP.getFlashChipRealSize();
  uint32_t ideSize = ESP.getFlashChipSize();
  FlashMode_t ideMode = ESP.getFlashChipMode();

  Serial.println(count++);
  Serial.printf("Flash real id:   %08X\n", ESP.getFlashChipId());
  Serial.printf("Flash real size: %u bytes\n", realSize);

  Serial.printf("Flash ide  size: %u bytes\n", ideSize);
  Serial.printf("Flash ide speed: %u Hz\n", ESP.getFlashChipSpeed());
  Serial.printf("Flash ide mode:  %s\n", (ideMode == FM_QIO ? "QIO" : ideMode == FM_QOUT ? "QOUT"
                                                                    : ideMode == FM_DIO  ? "DIO"
                                                                    : ideMode == FM_DOUT ? "DOUT"
                                                                                         : "UNKNOWN"));

  if (ideSize != realSize) {
    Serial.println("Flash Chip configuration wrong!\n");
  } else {
    Serial.println("Flash Chip configuration ok.\n");
  }

  for (int x=0; x < 10; x++)
  {
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)?LOW:HIGH); // toggle LED
    delay(500);
  }
}
