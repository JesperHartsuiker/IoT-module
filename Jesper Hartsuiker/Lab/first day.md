
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


![IMG_9890 thumbnail](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/936bba47-df32-4d7e-8327-caafae94a93c)




byte lastButtonState = LOW;
byte ledState = LOW;

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, INPUT);
}

void loop() {
  byte buttonState = digitalRead(D2);
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      ledState = (ledState == HIGH) ? LOW: HIGH;
      digitalWrite(D1, ledState);
    }
  }
}


https://github.com/JesperHartsuiker/IoT-module/assets/82671856/0633b656-b006-414f-af31-35fa0c079cc1




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


https://github.com/JesperHartsuiker/IoT-module/assets/82671856/0e3d5ad1-ae92-4987-a094-dc131720bee5


