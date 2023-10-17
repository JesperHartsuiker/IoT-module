
![IMG_9890 thumbnail](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/936bba47-df32-4d7e-8327-caafae94a93c)



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




https://github.com/JesperHartsuiker/IoT-module/assets/82671856/5a8d1bae-ffc0-4a6a-8ff9-b5bea3ad829a





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


https://github.com/JesperHartsuiker/IoT-module/assets/82671856/9c24a943-1c7c-4d04-aed1-0c00353f6c3b

