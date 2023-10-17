# First lab day: Learning small things with the Microcontroller.

During the first lab day we started with learning a bit about the microcontroller that we got and started to code some things to put on some lights. We made the code in the Arduino IDE application. I worked together on this with Roan Palm.

We first started with a double light setup to turn on a yellow and a red light. This is the code we used for the program:

```cpp
void setup() {
    pinMode(LED_BUILTIN, OUTPUT); 
    pinMode(D4, OUTPUT); 
    pinMode(D3, OUTPUT); 
}

void loop() { 
    digitalWrite(D4, HIGH); 
    delay(1000); 
    digitalWrite(D3, HIGH); 
}
```
And this was the result of the code being submitted to the microcontroller:


![IMG_9890 thumbnail](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/936bba47-df32-4d7e-8327-caafae94a93c)  



After the previous part was finished, I made the setup to turn on and off a light with a button. This is the code we wrote:

```cpp
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
```
And this is the result after the code was submitted to the microcontroller:


https://github.com/JesperHartsuiker/IoT-module/assets/82671856/0633b656-b006-414f-af31-35fa0c079cc1  





After we finished the assignments for the next day, we started to play around with the microcontroller and a stopping light. So we hooked everything up and made this code to run every LED for the stopping light separately:

```cpp
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
```
After submitting the code, and running the stopping light after pressing the button, this is the result:


https://github.com/JesperHartsuiker/IoT-module/assets/82671856/0e3d5ad1-ae92-4987-a094-dc131720bee5


