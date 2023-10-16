void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(D4, HIGH);
  delay(1000);
  digitalWrite(D3, HIGH);
}
