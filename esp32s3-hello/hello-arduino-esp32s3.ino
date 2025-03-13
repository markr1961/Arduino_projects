

#define BOOTLOG( ... ) { char buf[120]; sprintf( buf, __VA_ARGS__ ) ; Serial.print("##[BOOT]#\t"); Serial.println(buf); }


void setup() {
  int numTries=0;

  Serial.begin(115200);
  while (!Serial)
  {
    delay(1); // wait for serial port to connect. Needed for native USB
    numTries++;
  }
  Serial.println("\n\n  === connected ===  ");
  Serial.print("after ");
  Serial.print(numTries);
  Serial.println(" ms delays.");
}

int loopCount;

void loop() {

  Serial.println("\n\n================================");
  Serial.print("Chip Model: ");
  Serial.println(ESP.getChipModel());
  Serial.print("Chip version: ");
  Serial.println(ESP.getChipRevision());
  Serial.print("Number of cores: ");
  Serial.println(ESP.getChipCores());
  Serial.print("Flash Chip Size: ");
  Serial.println(ESP.getFlashChipSize());
  Serial.print("Flash Chip Speed: ");
  Serial.println(ESP.getFlashChipSpeed());

  Serial.println("================================");
  BOOTLOG("Total heap: %d", ESP.getHeapSize());
  BOOTLOG("Free heap: %d", ESP.getFreeHeap());
  BOOTLOG("Total PSRAM: %d", ESP.getPsramSize());
  BOOTLOG("Free PSRAM: %d", ESP.getFreePsram());
  Serial.println("================================");

  Serial.print("loop count: ");
  Serial.println(loopCount++);

  for (int x=0; x<10; x++)
    delay(1000);

}
