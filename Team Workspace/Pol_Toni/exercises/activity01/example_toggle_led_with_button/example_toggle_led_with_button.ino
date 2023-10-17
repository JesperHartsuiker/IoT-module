byte lastButtonState = LOW;
byte ledState = LOW;

void setup() {
  // initialize digital pin D1 as an output.
  pinMode(D1, OUTPUT);
  // initialize digital pin D2 as an input.
  pinMode(D2, INPUT); 
}

// the loop function runs over and over again forever
void loop() {
    
  byte buttonState = digitalRead(D2);

  if (buttonState != lastButtonState) {
    // Check if the 'buttonState' has changed since the last loop iteration.
    lastButtonState = buttonState;
    // Check if the button is pressed (LOW state).
    if (buttonState == LOW) {
        // Toggle the 'ledState' between HIGH and LOW.
        ledState = (ledState == HIGH) ? LOW : HIGH;
        digitalWrite(D1, ledState);
    }
  }
}
