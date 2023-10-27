# Lab 17-10-2023

## Control Led with Web Request

The first assignment is to run a webserver on a microcontroller and send a HTTP request to turn on and off the builtin light of the esp32. I hooked a esp32 up to my laptop and started coding. To run let a HTTP server run on a esp32 I used this code:

```css
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char* ssid = "It_Burns_When_IP";
const char* password = "Namreh7256";

WebServer server(80);

const int led = 2;

void handleRoot() {
  //digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp32!");
  //digitalWrite(led, 0);
}

void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/on", [](){
    digitalWrite(led, HIGH);
    server.send(200, "text/plain", "LED ON");
  });

  server.on("/off", [](){
    digitalWrite(led, LOW);
    server.send(200, "text/plain", "LED OFF");
  });

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks
}
```
Next I compiled the code and uploaded it to the esp32. And this showed up on the serial monitor:

![Alt text](Images/Connect_HTTP.png)

Now the HTTP website should be running and when I go to 192.168.12.189 in my webbrowser I get this:

![Alt text](Images/HelloESP32.png)

Next I tried to send 192.168.12.189/on. This is what the browser said:

![Alt text](Images/ledonhttp.png)

And this happened on the arduino board:

![Alt text](Images/IMG_9999.jpg)

Next I wanted to turn off the led. So I send 192.168.12.189/off in the browser. This is wat came on in the browser:

![Alt text](Images/ledonhttp.png)

And the esp32 looked like this:

![Alt text](Images/IMG_0001.jpg)

## Turning the light on and off with a button.

The next assignment was to turn on and off the buitlin LED of the board with a button hooked to another board. So I hooked up the button to the esp32 and then started coding everything. This is the code I made to turn on the light on another esp32 with the use of a button an HTTP:

```css
#include <Arduino.h>
#include <String.h>
#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

#define USE_SERIAL Serial
#define LED 2
#define LEDEXT 18
#define BUTTON 21

int currentButtonState;
int lastButtonState;
int ledState;
WiFiMulti wifiMulti;



/*
  const char* ca = \
  "-----BEGIN CERTIFICATE-----\n" \
  "MIIEkjCCA3qgAwIBAgIQCgFBQgAAAVOFc2oLheynCDANBgkqhkiG9w0BAQsFADA/\n" \
  "MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n" \
  "DkRTVCBSb290IENBIFgzMB4XDTE2MDMxNzE2NDA0NloXDTIxMDMxNzE2NDA0Nlow\n" \
  "SjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxIzAhBgNVBAMT\n" \
  "GkxldCdzIEVuY3J5cHQgQXV0aG9yaXR5IFgzMIIBIjANBgkqhkiG9w0BAQEFAAOC\n" \
  "AQ8AMIIBCgKCAQEAnNMM8FrlLke3cl03g7NoYzDq1zUmGSXhvb418XCSL7e4S0EF\n" \
  "q6meNQhY7LEqxGiHC6PjdeTm86dicbp5gWAf15Gan/PQeGdxyGkOlZHP/uaZ6WA8\n" \
  "SMx+yk13EiSdRxta67nsHjcAHJyse6cF6s5K671B5TaYucv9bTyWaN8jKkKQDIZ0\n" \
  "Z8h/pZq4UmEUEz9l6YKHy9v6Dlb2honzhT+Xhq+w3Brvaw2VFn3EK6BlspkENnWA\n" \
  "a6xK8xuQSXgvopZPKiAlKQTGdMDQMc2PMTiVFrqoM7hD8bEfwzB/onkxEz0tNvjj\n" \
  "/PIzark5McWvxI0NHWQWM6r6hCm21AvA2H3DkwIDAQABo4IBfTCCAXkwEgYDVR0T\n" \
  "AQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8EBAMCAYYwfwYIKwYBBQUHAQEEczBxMDIG\n" \
  "CCsGAQUFBzABhiZodHRwOi8vaXNyZy50cnVzdGlkLm9jc3AuaWRlbnRydXN0LmNv\n" \
  "bTA7BggrBgEFBQcwAoYvaHR0cDovL2FwcHMuaWRlbnRydXN0LmNvbS9yb290cy9k\n" \
  "c3Ryb290Y2F4My5wN2MwHwYDVR0jBBgwFoAUxKexpHsscfrb4UuQdf/EFWCFiRAw\n" \
  "VAYDVR0gBE0wSzAIBgZngQwBAgEwPwYLKwYBBAGC3xMBAQEwMDAuBggrBgEFBQcC\n" \
  "ARYiaHR0cDovL2Nwcy5yb290LXgxLmxldHNlbmNyeXB0Lm9yZzA8BgNVHR8ENTAz\n" \
  "MDGgL6AthitodHRwOi8vY3JsLmlkZW50cnVzdC5jb20vRFNUUk9PVENBWDNDUkwu\n" \
  "Y3JsMB0GA1UdDgQWBBSoSmpjBH3duubRObemRWXv86jsoTANBgkqhkiG9w0BAQsF\n" \
  "AAOCAQEA3TPXEfNjWDjdGBX7CVW+dla5cEilaUcne8IkCJLxWh9KEik3JHRRHGJo\n" \
  "uM2VcGfl96S8TihRzZvoroed6ti6WqEBmtzw3Wodatg+VyOeph4EYpr/1wXKtx8/\n" \
  "wApIvJSwtmVi4MFU5aMqrSDE6ea73Mj2tcMyo5jMd6jmeWUHK8so/joWUoHOUgwu\n" \
  "X4Po1QYz+3dszkDqMp4fklxBwXRsW10KXzPMTZ+sOPAveyxindmjkW8lGy+QsRlG\n" \
  "PfZ+G6Z6h7mjem0Y+iWlkYcV4PIWL1iwBi8saCbGS5jN2p8M+X+Q7UNKEkROb3N6\n" \
  "KOqkqm57TH2H3eDJAkSnh6/DNFu0Qg==\n" \
  "-----END CERTIFICATE-----\n";
*/
void onFunction();
void offFunction();
void setup() {

  USE_SERIAL.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(LEDEXT, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for (uint8_t t = 4; t > 0; t--) {
    USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
    USE_SERIAL.flush();
    delay(1000);
  }

  wifiMulti.addAP("It_Burns_When_IP", "Namreh7256");

}

void loop() {
  // wait for WiFi connection
  if ((wifiMulti.run() == WL_CONNECTED)) {
  }
  lastButtonState    = currentButtonState;                // save the last state
  currentButtonState = digitalRead(BUTTON); // read new state

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    delay(50);
    if (lastButtonState == HIGH && currentButtonState == LOW) {
      Serial.print("The button is pressed: ");

      // toggle state of LED
      if (ledState == LOW) {
        ledState = HIGH;
        Serial.println("Turning LED on");
        onFunction();
      }
      else {
        ledState = LOW;
        Serial.println("Turning LED off");
        offFunction();
      }
    }
    digitalWrite(LEDEXT, ledState);
  }
}

void onFunction() {
  HTTPClient http;

  USE_SERIAL.print("[HTTP] begin...\n");
  // configure traged server and url
  //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
  http.begin("http://192.168.12.189/on"); //HTTP

  USE_SERIAL.print("[HTTP] GET...\n");
  // start connection and send HTTP header
  int httpCode = http.GET();

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      USE_SERIAL.println(payload);
    }
  } else {
    USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}

void offFunction() {
  HTTPClient http;
  USE_SERIAL.print("[HTTP] begin...\n");
  // configure traged server and url
  //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
  http.begin("http://192.168.12.189/off"); //HTTP

  USE_SERIAL.print("[HTTP] GET...\n");
  // start connection and send HTTP header
  int httpCode = http.GET();

  // httpCode will be negative on error
  if (httpCode > 0) {
    // HTTP header has been send and Server response header has been handled
    USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      USE_SERIAL.println(payload);
    }
  } else {
    USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}
```

https://github.com/JesperHartsuiker/IoT-module/assets/82671856/8f4be86e-28a5-4ecc-ac2c-eb1fd84396d3

Next I uploaded this code and started pressing the button. When the button is pressed it will turn on the light and keep the light on until the button is pressed again, then it will turn off. In the video below you can see that it works:



Also in the picture below you can see the serial monitor while pressing the button:

![Alt text](Images/serialmonitorbutton.png)
