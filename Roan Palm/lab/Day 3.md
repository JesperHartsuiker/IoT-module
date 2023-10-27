# Lab 18-10-2023

## Getting the rasberry pi ready by changing settings

Our raspberry pi was crashing a lot with sending out a WiFi network. We could not work fully until it was fixed. So after a talk with the teacher we decided to turn off the WiFi part from the raspberry. This is how we did it after Ulrich was done with changing the raspberry pi settings:
- I shut down the Raspberry Pi router and then powered it back on. 
- After that, I modified the router LAN address to 192.168.12.254. 
- Upon restarting the Raspberry Pi, I went into the router settings and assigned a static IP address (192.168.12.1) for - the Raspberry Pi. 
- I accessed the Raspberry Pi via SSH and used the command "sudo reboot". 
- Now, the Raspberry Pi is assigned the IP address 192.168.12.1.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/357fd639-5e94-4b62-93b2-a21bccd7d7d4)

After the settings has been changed, we need to ssh into the raspberri pi to setup a mosquitto session. Below you will see the ssh session.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/b5cf1568-c924-4b98-946c-7529974d2674)


## Mosquitto send messages

After the ssh session has been started, I tried to lookup the help page in command line of mosquitto_sub and mosquitto_pub.
mosquitto_sub --help

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/00fcb56c-2624-4c58-8361-c9bc28b72f4f)

mosquitto_pub --help

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/cc52bc06-8230-4b18-ab5b-aaeb035adb4e)

Now I sent Hello World to Roan, to test if it would work. Below you will see the results.
sending hello world to other client

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/11971cf5-7a61-4a25-9c9d-44ebdef4d613)

Receiving hello world on other client

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/cd90102a-da18-463e-8fcc-ee204aae99b2)


## MQTT send messages

Now we will do the same for MQTT. We setup my ssh session as a listening port, and Roan's ssh session as a sending port.
Listening to mqtt messages:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/2fccaea9-11f9-4a1f-9901-c4d72c7a2797)

Sending the message:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d5d52172-f2d3-4a52-a829-e8cb051ec730)

Receiving the message:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/14b22983-2904-49c2-b01b-68728fef1209)





## Testing lights on off

The next tast was to simulate a small IoT network. Where we needed to make a 'temperature sensor' which would sent the temperature to the MQTT broker. The MQTT broker would next sent a message to the 'ac' to turn it on or off. Before I started to make it that way, I made it so it would turn on or off a light with code that came with the iotknit library github page. This is the code I used:
```css
from iotknit import *

led1Status = False

init("192.168.12.1")  # use a MQTT broker on localhost

prefix("led")  # all actors below are prefixed with /led

led1 = publisher("led1")  # create a Thingi interface that publishes to led/led1

def button1Callback(msg):
   global led1Status

   print("received: [button]", msg)

   if (msg == "down"):
      led1Status = not led1Status  # toggle status of led

      if (led1Status):
            led1.publish("set", "on")  # publish updated state
            print("sending: [led1]", "on")
      else:
            led1.publish("set", "off")
            print("sending: [led1]", "of")


prefix("button")  # all sensors below are prefixed with /button

button1 = subscriber("button1")  # create a Thingi interface that can have
                                 # subscribes only to button/button1
button1.subscribe_change(callback=button1Callback)

run()  # you can also do a while loop here call process() instead
```
  
Next I sent with the mosquitto publisher a message down. It would sent a turn on command to the receiver. The first picture is the mosquitto publisher:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/e58b4de3-3146-4441-a64b-eddfa44b1ed3)

The output in VSCode:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/768d4f1e-ed69-4ac2-9088-52e29d558850)

The output in the mosquitto listener:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/7abecf64-9846-4cd3-ba20-08d029f056bf)


## Turning ac on and off
Next I changed the code up so it would be the example as listed below, where there is a temperature sensor and the ac. This is the code after I changed it:
```css
from iotknit import *

init("192.168.12.1")  # use a MQTT broker on localhost

prefix("switch")  # all actors below are prefixed with /led

switch = publisher("rl")  # create a Thingi interface that publishes to led/led1

def tempCallback(msg):

    print("received: [temp]", msg)

    try:
        t = int(msg)
    except ValueError:
       return

    if (t >= 25):
        switch.publish("set", "on")  # publish updated state
        print("sending: [rl]", "on")
    elif (t <= 20):
        switch.publish("set", "off")
        print("sending: [rl]", "off")
    else:
        return


prefix("temp-measure")  # all sensors below are prefixed with /button

temp1 = subscriber("temp1")  # create a Thingi interface that can have
                                 # subscribes only to button/button1
temp1.subscribe_change(callback=tempCallback)

run()  # you can also do a while loop here call process() instead
```

### Sending high temps
To simulate it, I sent an integer of 26 to the MQTT broker, so it would be 'hot' in the room. This is the result that I got:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/7593765e-b8ee-4207-8fe9-0c0b580abfd5)

VSCode terminal output:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/6f87ecd4-052b-49f7-b59e-0946e597e6e5)

Mosquitto output:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/1358d6b6-f175-422c-b6d5-c67073fb325b)


### Sending lower temps
Next to simulate if the temperature would drop below 20, I put in the integeter 18 in. As predicted the 'ac' should turn off, if it was below 20 degrees. 

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/561d6df1-9bb7-4c61-a5b7-65984ae279ea)

VSCode terminal output:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/7c5b71a2-3e98-4766-8909-f8539efea6cd)

Mosquitto output:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/989c9a36-ee2e-4cd4-8c88-24e82bf9a42f)


### Making random temps
Next I needed to make the integeters random that had to be sent to the MQTT broker. I chose to make a bash script that does this.  

To make a bash script, run this command: sudo nano random_temps.sh  

Next I put this code in the script:

```css
#!/bin/bash

while true
do
    number=$((RANDOM % 16 + 15))  # Generate random integer between 15 and 30
    mosquitto_pub -h 192.1678.12.1 -t temp-measure/temp1 -m "$number" 
    sleep 10  # Sleep for 10 seconds
done
```
When the script is saved it needs executable permissions to be able to be used. I used this command to give the permissions:  

sudo chmod +x random_temps.sh  

To run the script use this command: ./random_temps.sh  

If the script runs, it will sent a random number every 10 seconds. The output into VSCode is shown here:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/237d983c-e058-463f-8429-b9192cbac8e2)

The output for the mosquitto session is seen here:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/b8b0af5e-ef8e-4794-a773-c6230762a015)


## Hardware
After the 'simulation' of the temperature sensor and the 'ac' was completed, we needed to make it with hardware, so we used a temperature sensor, 2 esp32's and a light as turn on or off.  

First I changed the code to turn on and off the 'ac' otherwise it would be to low, because the server only picked up temperatures above 26, so it would only turn on the 'ac'. So I changed it that everyting under 27 was off and over 27 it would be on. In that way we could test if it would work. The most important thing was to change the t = int(msg) to t = float(msg). Otherwise the code would be errorous. This is the code now:

```css
from iotknit import *

init("192.168.12.1")  # use a MQTT broker on localhost

prefix("switch")  # all actors below are prefixed with /led

switch = publisher("rl")  # create a Thingi interface that publishes to led/led1

def tempCallback(msg):
    print("received: [temp]", msg)

    try:
        t = float(msg)
    except ValueError:
       print("test")
       print(ValueError)
       return

    if t >= 27:
        switch.publish("set", "on")  # publish updated state
        print("sending: [rl]", "on")
    #elif t <= 20:
     #   switch.publish("set", "off")
      #  print("sending: [rl]", "off")
    else:
        switch.publish("set", "off")
        print("sending: [rl]", "off")
        #return


prefix("temp-measure")  # change prefix to temp-measure

temp1 = subscriber("temp1")  # subscribe to the top-level topic "temp-measure" without any sub-topic
temp1.subscribe_change(callback=tempCallback)

run()  # you can also do a while loop here call process() instead
```
Next we made the code for the sender, so this esp32 had the temperature sensor that would sent the temperatures to the MQTT broker. This is the code that we made for it:
```css
#include <WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// WiFi
const char ssid = *"It_Burns_When_IP"; // Enter your Wi-Fi name
const charpassword = *"Namreh7256";  // Enter Wi-Fi password
WiFiClient espClient;

// MQTT Broker
const char mqtt_broker = *"192.168.12.1";

const chartopic_interpretor = "temp-measure/temp1";
PubSubClient client(espClient);

// Temperature sensor
#define DHTPIN 4    // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);
void temp_reading();

uint32_t delayMS;

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

    // Initialize device.
    dht.begin();
    // Print temperature sensor details.
    sensor_t sensor;
    delayMS = sensor.min_delay / 1000;
}

void loop() {
    if (!client.connected()) {
        client.setServer(mqtt_broker, 1883);
        client.connect("Temperature Sensor");

    }

    temp_reading();

    client.loop();
    delay(5000);
}

void temp_reading() {
    // Delay between measurements.
    delay(delayMS);
    // Get temperature event and print its value.
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    if (isnan(event.temperature)) {

    }
    else {
        String temperature = String(event.temperature);

        client.publish(topic_interpretor, temperature.c_str());
    }
}
```
Next we made the code for the reciever, this would be the other esp32 with the light that would turn on or off, depends on the temperature of course. This is the code that we have written for it:
```css
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char ssid = *"It_Burns_When_IP"; // Enter your Wi-Fi name
const charpassword = *"Namreh7256";  // Enter Wi-Fi password

// MQTT Broker
const char mqtt_broker = *"192.168.12.1";
const chartopic_switch = "switch/rl/set";

WiFiClient espClient;
PubSubClient client(espClient);

// Onboard LED
const int ledPin = 2; // Change this to the appropriate GPIO pin where the onboard LED is connected

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

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void callback(char topic, bytepayload, unsigned int length) {
  // Handle MQTT messages received on the subscribed topic
  if (strcmp(topic, topic_switch) == 0) {
    String message = "";
    for (int i = 0; i < length; i++) {
      message += (char)payload[i];
    }

    if (message == "on") {
      digitalWrite(ledPin, HIGH); // Turn LED ON
    } else if (message == "off") {
      digitalWrite(ledPin, LOW); // Turn LED OFF
    }
  }
}

void reconnect() {
  // Reconnect to the MQTT broker
  while (!client.connected()) {
    if (client.connect("LED Control")) {
      // Subscribe to the switch/rl/set topic
      client.subscribe(topic_switch);
    } else {
      delay(5000);
    }
  }
}
```
### Temperature is to high.
The first video we made is the temperature sensor who would pick up a temperature above 27 degrees. So it would need to turn on the ac. To test it we put our hands over the sensor to warm it up. This is the result for it (it is hard to see, the videos have been made with only the on board light of the esp32, this is the same for the temperature is to low.):

https://github.com/JesperHartsuiker/IoT-module/assets/82671856/819e1c66-d8a2-401c-932a-39b43844d503

### Temperature is to low.
Next we let the temperature lower down, to go under the 27 degrees, by stopping to hold it with our fingers. This is the result:

https://github.com/JesperHartsuiker/IoT-module/assets/82671856/ec507ccc-12a9-44a0-832d-3b4e94490f26

