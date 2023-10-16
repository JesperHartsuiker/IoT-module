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




byte lastButtonState = LOW;
byte ledState = LOW;

void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D2, INPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
}

void loop() {
  byte buttonState = digitalRead(D2);
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    digitalWrite(D3, HIGH);
    delay(1000);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    delay(1000);
    digitalWrite(D4, LOW);
    digitalWrite(D5, HIGH); 
    delay(1000);
    digitalWrite(D5, LOW);  
    
  }
}
