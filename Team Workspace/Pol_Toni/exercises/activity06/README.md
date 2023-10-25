# Lab Tasks Description

# Exercise 06

For the sixth exercise we wrote five different Node-RED programs.

## Overview
1. [Device Control with IoTempower](#device-control-with-iotempower)
2. [Example - RFID reader](#example---rfid-reader)
	* [Procedure](#procedure)

## Device Control with IoTempower

### IoTempower introduction

### Example - RFID reader

In this IoT prototyping procedure, we will guide you through the necessary steps to evaluate the UID of the tag in Node-RED (checking at least two RFID tags).

#### Procedure

1. Establish Hardware Connection:
   * Ensure the RFID reader is connected according to the following wiring structure:
   
   | Wemos D1 Mini/NodeMCU | mfrc522/rfid-rc522 board  |
   | --------------------- | ------------------------- |
   | 3V3                   | 3.3V                      |
   | D8                    | sda                       |
   | D7                    | MOSI                      |
   | D6                    | MISO                      |
   | D5                    | SCK                       |
   | D0                    | RST                       |
   | G                     | GND                       |
   | N/C                   | IRQ (IRQ is not connected for use in IoTempower) |

2. Access the IoTempower Website:
   * Ensure your device is connected to your configured Wi-Fi network using either your Raspberry Pi or modem.
   * Open a web browser and enter the website URL, which can be either `gw.iotempire.net` or `192.168.12.1` into the address bar.

3. Access RFID Documentation:
   * On the main webpage, select the option for `Local Documentation Table of Contents`.

   ![Local Documentation Table of Contents](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/local_documentation_table_of_contents.png?raw=true)

   * Within the table of contents webpage, click on `Command reference`.
   * Find the RFID reader documentation.

   ![RFID Reader Documentation](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/documentation/rfid_reader_documentation.png?raw=true)

4. Implement RFID Code:
   * Copy the necessary RFID code from the documentation.
   * Paste the code into your microcontroller RFID reader `setup.cpp` file and make sure it is configured correctly.

   ![RFID reader `setup.cpp` file](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity06/code/rfid_reader_code.png?raw=true)

5. Create Node-RED Flow:
   * Create a Node-RED flow to proof that you have learned that much about the software.

   ![Node-RED flow for RFID reader](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity06/node-red%20flows/rfid_reader.png?raw=true)

6. Testing:
   * Run a simulation by bringing a card or badge near the RFID reader.
   * Verify if the RFID code is displayed in the Node-RED dashboard.

   https://github.com/JesperHartsuiker/IoT-module/assets/74074466/4e21bc32-a008-4743-873d-f0a5bad8a287

7. Access Control Integration:
   * Implement a button on the dashboard to indicate access status.
   * Configure the button to display "Access Denied" in red or "Access Granted" in green based on the RFID verification result.

   ![Node-RED flow for accessing RFID reader](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity06/node-red%20flows/access_rfid_reader.png?raw=true)

8. Completion:
   * Verify that the RFID system is working as expected, granting or denying access based on the RFID card.

In the following video, you can view the evidence related to the `RFID reader`.

https://github.com/JesperHartsuiker/IoT-module/assets/74074466/b2aac299-46d4-49d9-97b9-022d60810bb8

## Access Control System

### New Actors

### Example - Controlling LED Brightness with PWM

In this IoT prototype, we will demonstrate how to set up PWM control for a LED. You'll learn how to adjust the PWM duty cycle, allowing you to control LED brightness with a slider.

#### Procedure

1. Hardware Setup:

   * Connect an LED with a current-limiting resistor to a breadboard or directly to the ESP32.
   * Wire the anode (longer lead) of the LED to pin 4 on the ESP32, and the cathode (shorter lead) to ground (GND) on the ESP32.
   * Ensure that the ESP32 is properly powered and connected to your computer for programming.

2. Code Implementation:

   * Copy the code provided earlier and paste it into your Arduino IDE.
   * Modify the code to include your Wi-Fi credentials, MQTT broker details, and adjust the LED behavior if needed.

   * You can see the code in [here](example_access_control_system_led/access_control_system_led.ino).

   ```cpp
   #include <WiFi.h>
   #include <PubSubClient.h>

   const char* ssid = "It_Burns_When_IP";
   const char* password = "Namreh7256";
   const char* mqtt_server = "192.168.12.1";


   WiFiClient espClient;
   PubSubClient client(espClient);

   int ledPin = 4;

   void setup_wifi() {
   delay(10);
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);

   WiFi.begin(ssid, password);

   while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
   }

   Serial.println("");
   Serial.println("WiFi connected");
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP());
   }

   void callback(char* topic, byte* payload, unsigned int length) {
   Serial.print("Message arrived [");
   Serial.print(topic);
   Serial.print("] ");

   String message;
   for (int i = 0; i < length; i++) {
      message += (char)payload[i];
   }
   Serial.println(message);

   int brightness = message.toInt();
   if (brightness >= 0 && brightness <= 1000) {
      int output = map(brightness, 0, 1000, 0, 255); // Mapping the range from 0-1000 to 0-255 for LED brightness control
      analogWrite(ledPin, output);
   }
   }

   void reconnect() {
   while (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
      if (client.connect("ESP32Client")) {
         Serial.println("connected");
         client.subscribe("Toni_Pol/megaled");
      } else {
         Serial.print("failed, rc=");
         Serial.print(client.state());
         Serial.println(" try again in 5 seconds");
         delay(5000);
      }
   }
   }

   void setup() {
   pinMode(ledPin, OUTPUT);
   Serial.begin(115200);
   setup_wifi();
   client.setServer(mqtt_server, 1883);
   client.setCallback(callback);
   }

   void loop() {
   if (!client.connected()) {
      reconnect();
   }
   client.loop();
   }
   ```

3. Node-RED Flow Creation:

   * Create a Node-RED flow to interact with your ESP32 and MQTT broker.
   * Ensure that the flow includes an MQTT input node to subscribe to the `Toni_Pol/megaled` topic.

   ![Node-RED flow for controlling LED brightness with PWM](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity06/node-red%20flows/controlling_LED_brightness_with_PWM.png?raw=true)

4. Testing:

   * Test the setup by sending MQTT messages with values between 0 and 100 to the `Toni_Pol/megaled` topic using an MQTT client.
   * Observe that the LED responds to the incoming messages by adjusting its state (ON or OFF) based on the values received.

5. Completion:

   * Verify that the entire system is working as expected.
   * Ensure that the LED responds correctly to the MQTT messages, and any additional features are functioning as desired.

In the following video, you can view the evidence related to the `Controlling LED Brightness with PWM`.

https://github.com/JesperHartsuiker/IoT-module/assets/74074466/7bf78823-0f32-4846-b653-157ed2c05aea

### Example - Creating a Buzzer Sound Generator

In this IoT prototyping procedure, we will replace the LED and register with a buzzer. You can have some fun and experiment with different tones by moving a slider (including a second slider for adjusting frequency), while keeping the tones short to avoid disturbing your neighbors.

#### Procedure

1. Hardware Setup:

   * Connect the buzzer to a breadboard or directly to the ESP32. Wire the buzzer to pin 33 on the ESP32.
   * Ensure that the ESP32 is properly powered and connected to your computer for programming.

2. Code Implementation:

   * Copy the code provided earlier and paste it into your Arduino IDE.
   * Modify the code to include your Wi-Fi credentials, MQTT broker details, and adjust the buzzer behavior if needed.


   * You can see the code in [here](example_access_control_system_buzzer/access_control_system_buzzer.ino).

   ```cpp
   #include <WiFi.h>
   #include <PubSubClient.h>

   const char* ssid = "It_Burns_When_IP";
   const char* password = "Namreh7256";
   const char* mqtt_server = "192.168.12.1";
   const char* mqtt_topic = "Toni_Pol/megaled/frequency";

   const int buzzerPin = 33; // Your buzzer's pin

   WiFiClient espClient;
   PubSubClient client(espClient);

   void callback(char* topic, byte* payload, unsigned int length) {
   payload[length] = '\0'; // Null-terminate the payload

   // Convert the payload to an integer
   int frequency = atoi((char*)payload);

   // Adjust the buzzer beep based on the received frequency
   tone(buzzerPin, frequency); // Use the tone function to set the buzzer frequency
   }

   void setup() {
   Serial.begin(115200);
   WiFi.begin(ssid, password);

   while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
   }
   Serial.println("Connected to WiFi");

   client.setServer(mqtt_server, 1883);
   client.setCallback(callback);

   if (client.connect("esp32-client")) {
      client.subscribe(mqtt_topic);
      Serial.println("Subscribed to MQTT topic");
   }
   }

   void loop() {
   if (!client.connected()) {
      if (client.connect("esp32-client")) {
         client.subscribe(mqtt_topic);
      }
   }
   client.loop();
   }
   ```

3. Node-RED Flow Creation:

   * Create a Node-RED flow to interact with your ESP32 and MQTT broker.
   * Ensure that the flow includes an MQTT input node to subscribe to the `Toni_Pol/megaled/frequency` topic.

   ![Node-RED flow for creating a buzzer sound generator](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity06/node-red%20flows/creating_a_buzzer_sound_generator.png?raw=true)

4. Testing:

   * Test the setup by sending MQTT messages with values between 0 and 100 to the `Toni_Pol/megaled/frequency` topic using an MQTT client.
   * Observe that the buzzer responds to the incoming messages by adjusting its beep frequency.

5. Completion:

   * Verify that the entire system is working as expected.
   * Ensure that the buzzer responds correctly to the MQTT messages, and any access control features are functioning as desired.

In the following video, you can view the evidence related to the `Creating a Buzzer Sound Generator`.

https://github.com/JesperHartsuiker/IoT-module/assets/74074466/1ecc7a89-969b-4c18-b9f5-75a19406a346

## Lock Project 1

For a comprehensive and detailed exposition of this project, please refer to the dedicated section located within [linked here](../../../../Jesper%20Hartsuiker/Lab/23-10-2023.md#lock-project).

