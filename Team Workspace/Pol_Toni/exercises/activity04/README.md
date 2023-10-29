# Lab Tasks Description

# Exercise 04

For the fourth exercise we wrote five different Node-RED programs.

## Overview
1. [More Hardware and Integration with Node-RED](#more-hardware-and-integration-with-node-red)
   * [Requirements](#requirements)
   * [Procedure](#procedure)
   * [Hardware Setup](#hardware-setup)
   * [Writing Arduino Code for Button](#writing-arduino-code-for-button)
   * [Setting Up Node-RED for Button](#setting-up-node-red-for-button)
   * [Connecting the LED](#connecting-the-led)
   * [Writing Arduino Code for LED Control](#writing-arduino-code-for-led-control)
   * [Setting Up Node-RED for LED](#setting-up-node-red-for-led)
   * [Testing the System](#testing-the-system)

## More Hardware and Integration with Node-RED

### Emergency Button

### Example - Turning a light on and off with a button via Node-RED

In this IoT prototyping procedure, we will explain how to set up a button click to correspond with Node-RED and control an LED using MQTT communication.

#### Requirements
Before you begin, ensure you have the following components:
  * An ESP8266 or ESP32 development board.
  * A button and an LED connected to the board.
  * Access to a Wi-Fi network.
  * Node-RED installed and running.

#### Procedure

1. Hardware Setup
  * Connect a button to a digital pin on your ESP8266 or ESP32. In this example, we will use pin 27. Ensure to use the internal pull-up resistor on the button pin.
  * Connect an LED to a digital pin on your board. In the provided code, we will use pin 27, but you can choose a different pin if needed.

2. Writing Arduino Code for Button
  * Write the Arduino code to read the button state and publish it to an MQTT topic. The code should establish a Wi-Fi connection and connect to your MQTT broker. Here is a breakdown of the code:

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = "Your_WiFi_Name";
const char *password = "Your_WiFi_Password";
const int buttonPin = 27;  // Button pin

WiFiClient espClient;

// MQTT Broker
const char *mqtt_broker = "MQTT_Broker_IP_Address";
const char *topic_interpretor = "button-reader/button1";
PubSubClient client(espClient);

void button_reading();
uint32_t delayMS;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);

  // Connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  delayMS = 250;
}

void loop() {
  if (!client.connected()) {
    client.setServer(mqtt_broker, 1883);
    client.connect("Temperature Sensor");
  }

  button_reading();
  client.loop();
  delay(1);
}

void button_reading() {
  delay(delayMS);

  int buttonState = digitalRead(buttonPin);
  String button = String(buttonState);
  Serial.print("Button state: ");
  Serial.println(button);
  client.publish(topic_interpreter, button.c_str());
}
```

Replace `"Your_WiFi_Name"`, `"Your_WiFi_Password"`, and `"MQTT_Broker_IP_Address"` with your Wi-Fi credentials and MQTT broker information.

3. Setting Up Node-RED for Button
  * Create a Node-RED flow that subscribes to the MQTT topic where button state information is published. Use MQTT nodes available in Node-RED for this purpose.

  ![Node-RED flow for Emergency button](https://github.com/JesperHartsuiker/IoT-module/blob/254683444456181f34c39c8fe41dbdf13fdebad0/Team%20Workspace/Pol_Toni/pictures/activity04/node-red%20flows/emergency_button.png?raw=true)

4. Connecting the LED
  * Connect an LED to a digital pin on your board. In the provided code, we will use pin 27, but you can choose a different pin if needed.

5. Writing Arduino Code for LED Control
  * Write the Arduino code to control the LED's state based on MQTT messages received. The code should establish a Wi-Fi connection, connect to your MQTT broker, and handle incoming messages to control the LED. Here is a breakdown of the code:

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = "Your_WiFi_Name";
const char *password = "Your_WiFi_Password";
const int ledPin = 27;  // LED pin

WiFiClient espClient;

// MQTT Broker
const char *mqtt_broker = "MQTT_Broker_IP_Address";
const char *topic_switch = "light_switch";
PubSubClient client(espClient);

// Onboard LED
const int ledPin = 27; // Change this to the appropriate GPIO pin where the onboard LED is connected

void setup() {
  Serial.begin(115200);

  // Connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize LED pin as an output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Initialize LED as OFF

  // Set the MQTT broker server
  client.setServer(mqtt_broker, 1883);

  // Set the callback function to handle MQTT messages
  client.setCallback(callback);
}

unsigned long lastMsg = 0;

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    Serial.print("Publish message: I am alive! ");
    Serial.println();
  }
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message received on topic [");
  Serial.print(topic);
  Serial.println("]");

  // Handle MQTT messages received on the subscribed topic
  if (strcmp(topic, topic_switch) == 0) {
    Serial.println("Received on the right topic");
    if (strncmp("on", (char *)payload, length) == 0) {
      digitalWrite(ledPin, HIGH); // Turn LED ON
    } else {
      digitalWrite(ledPin, LOW); // Turn LED OFF
    }
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      // ... and resubscribe
      client.subscribe(topic_switch);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
```

Replace `"Your_WiFi_Name"`, `"Your_WiFi_Password"`, and `"MQTT_Broker_IP_Address"` with your Wi-Fi credentials and MQTT broker information.

6. Setting Up Node-RED for LED
  * Create a Node-RED flow that interacts with your ESP8266/ESP32 and MQTT broker. Ensure the flow includes an MQTT input node to subscribe to the `light_switch` topic.

  ![Node-RED flow for Emergency button](https://github.com/JesperHartsuiker/IoT-module/blob/254683444456181f34c39c8fe41dbdf13fdebad0/Team%20Workspace/Pol_Toni/pictures/activity04/node-red%20flows/led_emergency_button.png?raw=true)

7. Testing the System
  * Deploy your Node-RED flows.
  * Press the button connected to your ESP8266/ESP32. The button state changes will be published to the MQTT topic.
  * Observe the changes in Node-RED as it receives the button state updates and controls the LED based on the messages.

In the following video, you can view the evidence related to the `Turning a light on and off with a button via Node-RED`.

VIDEO VIDEO VIDEO

By following these steps, you have successfully set up a button click to correspond with Node-RED and control a LED.
