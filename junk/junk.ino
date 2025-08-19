
char displayStrings[][4] {{"Prg"},{"rEd"},{"Grn"},{"Blu"},{"Int"},{"All"},{"xxx"}};
char printBuffer[64];
int count;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  digitalWrite(LED_BUILTIN, HIGH); // turn on LED

}

void loop() {
  // put your main code here, to run repeatedly:
 for (int x = 0; x < sizeof(displayStrings) / 4; x++)
 {
  sprintf(printBuffer, "string %d = %4s", x, &displayStrings[x]);
  Serial.println(printBuffer);
 }

  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // toggle the LED

  Serial.println(count++);

  delay(1000);                      // wait for a second

}
