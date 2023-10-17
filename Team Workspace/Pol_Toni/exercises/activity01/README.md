# Lab Tasks Description

# Exercise 01

For the first exercise we wrote three small Arduino programs.

## Breadboards, Blink, and Stories

### Example - Breadboard and Electronic Prototyping (Pair)

In this IoT prototyping procedure, we will guide you through the necessary steps to set up and test a Wemos D1 Mini using an Arduino development environment.

#### Procedure

1. Install Arduino Environment:

	Begin by ensuring you have the Arduino IDE installed on your computer, including the necessary packages for the Wemos D1 Mini.

2. Connect Wemos D1 Mini:

	Connect the Wemos D1 Mini board to your computer using a USB cable.

3. Establish Breadboard Connections:

	Use a gray cable to connect the ground (GND) pin of the Wemos D1 Mini to the breadboard. Connect the red cable to the 3-volt (3V3) pin of the Wemos D1 Mini and also to the breadboard.

4. Run Initial Test Script:

	Upload a basic "Blink" script to the Wemos D1 Mini to verify that the board is functioning correctly. This ensures that the communication between your computer and the board is working.

5. Set Up Circuit Flow:

	Create a simple electrical circuit by connecting two cables: a yellow cable running from one positive (+) point to another positive point on the breadboard and an orange cable connecting two negative (-) points. This ensures the flow of electricity in the circuit.

6. Introduce a Resistor:

	Place a resistor in the circuit to control the current flowing through the LEDs. Resistors are crucial for regulating the electrical flow in your IoT project.

7. Connect LEDs:

	Insert the LED (yellow) into the breadboard, ensuring that it lights up as part of the circuit. LEDs play a vital role in visual feedback in your IoT projects.

8. Experiment with Multiple LEDs:

	As an experiment, try connecting two LEDs to the circuit simultaneously. You'll notice that the brightness of the LEDs dims when both are connected. However, when only one LED is connected, it remains bright. This experiment illustrates how components interact in an electrical circuit.

### Example - Blink on the Wemos D1 Mini or ESP32 (Pair)
For this small example we created an Arduino program which makes the onboard LED of the ESP8266 blink every second.


In this IoT device configuration and programming exercise, we will outline the steps to set up and program a Wemos D1 Mini microcontroller, create a basic LED circuit, and experiment with asynchronous LED blinking.

#### Procedure

1. Connect the Wemos D1 Mini:

	Start by connecting the Wemos D1 Mini to your computer using a USB cable. This establishes the communication between the development environment and the IoT device.

2. Wiring the Circuit:

	Establish the circuit connections as follows:
   * Use a grey wire to connect the ground (GND) pin on the Wemos D1 Mini to the ground on the breadboard.
   * Utilize a yellow wire to connect pin D6 on the Wemos D1 Mini to a designated point on the breadboard.
   * Employ a red wire to connect the 3.3-volt (3.3V) output from the Wemos D1 Mini to the breadboard's positive (+) rail.

3. Introduce a Resistor:

	Place a resistor in the circuit, connecting it to the breadboard's negative (-) rail. This resistor serves to regulate the flow of current in the circuit.

4. LED Connection:

	Connect the cathode (negative) end of the LED to the breadboard's negative (-) rail, ensuring it is in line with the resistor. This setup controls the current flow and ensures the LED functions as intended.

5. Blinking LED:

	Upon completing the circuit and power supply, you will observe the LED blinking in synchronization with the Wemos D1 Mini. This indicates that your basic circuit is operational.

6. Programming for Asynchronous Blinking:

	To experiment with asynchronous LED blinking we made a script to do it easily.

### TODO Example - Toggle Led With Button



#### Code for the three types of blinking LED in Wemos D1 Mini

"If you wish to access the entire code, simply press [here](Team%20Workspace/Pol_Toni/exercises/activity01/) to be directed to the page that hosts the complete code for 'activity01'.

Here you can find the code for the Blinking LED -> [example_blink.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_blink.ino)

Here you can find the code for the Sync Blinking LED -> [example_sync_blink.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_sync_blink.ino)

Here you can find the code for the Async Blinking LED -> [example_blink.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_async_blink.ino)

Here you can find the code for the Toggle LED with Button -> [example_toggle_led_with_button.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_toggle_led_with_button.ino)





## Overview
1. [Preparation](/Teamfolder/exercises/exercise01#preparation)
2. [Example - blinking LED](/Teamfolder/exercises/exercise01#example---blinking-led)
	- [How to begin](/Teamfolder/exercises/exercise01#how-to-begin)
	- [Code for the blinking LED](/Teamfolder/exercises/exercise01#code-for-the-blinking-led)
	- [Pictures](/Teamfolder/exercises/exercise01#pictures)
3. [Control an ESP8266 from another ESP8266 via WLAN](/Teamfolder/exercises/exercise01#control-an-esp8266-from-another-esp8266-via-wlan)
	- [Client - ESP8266 with a button which talks to another ESP8266](/Teamfolder/exercises/exercise01#client---esp8266-with-a-button-which-talks-to-another-esp8266)
		- [How to begin](/Teamfolder/exercises/exercise01#how-to-begin-1)
		- [Code for the client](/Teamfolder/exercises/exercise01#code-for-the-client)
		- [Pictures](/Teamfolder/exercises/exercise01#pictures-1)
	- [Server - ESP8266 with a LED which is switched on/off from the client](/Teamfolder/exercises/exercise01#server---esp8266-with-a-led-which-is-switched-onoff-from-the-client)
		- [How to begin](/Teamfolder/exercises/exercise01#how-to-begin-2)
		- [Code for the server](/Teamfolder/exercises/exercise01#code-for-the-server). 
4. [Problems](/Teamfolder/exercises/exercises01#Problems)











#### Pictures
<img src="/Teamfolder/pictures/exercise01/client_button_picture_1.jpg" alt="drawing" width="300"/> <img src="/Teamfolder/pictures/exercise01/client_button_picture_2.jpg" alt="drawing" width="300"/>

## Problems
In the first Lab we had problems especially with the micro USB cables. Some of our cables did not work and that cost us time.
