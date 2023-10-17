# Lab Tasks Description

# Exercise 01

For the first exercise we wrote three small Arduino programs.

## Overview
1. [Breadboards, Blink, and Stories](#breadboards-blink-and-stories)
2. [Example - Breadboard and Electronic Prototyping (Pair)](#example---breadboard-and-electronic-prototyping-pair)
	* [Procedure](#procedure)
3. [Example - Blink on the Wemos D1 Mini or ESP32 (Pair)](#example---blink-on-the-wemos-d1-mini-or-esp32-pair)
	* [Procedure](#procedure-1)
	* [Code for the three types of blinking LED in Wemos D1 Mini](#code-for-the-three-types-of-blinking-led-in-wemos-d1-mini)
4. [Example - Toggle LED With Button](#example---toggle-led-with-button)
	* [Procedure](#procedure-2)
	* [Code for the toggle LED with Button](#code-for-the-toggle-led-with-button).

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

#### Code for the three types of blinking LED in Wemos D1 Mini

Here you can find the code for the Blinking LED -> [example_blink.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_blink.ino)

Here you can find the code for the Sync Blinking LED -> [example_sync_blink.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_sync_blink.ino)

Here you can find the code for the Async Blinking LED -> [example_blink.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_async_blink.ino)

### Example - Toggle LED With Button

In this task, we'll guide you through the process of adding a button to your breadboard, testing digital input with Arduino, and creating an Arduino sketch to toggle an LED using the button.

#### Procedure

1. Adding the Button:
   * Connect one leg of the push-button to the ground (GND) on the breadboard.
   * Attach the other leg of the push-button to a GPIO port, e.g., D2.
   * Ensure your wiring is secure, and the push-button is placed properly.

2. Testing Digital Input:
   * Open the Arduino IDE.
   * Load the "DigitalReadSerial" example (File > Examples > 02.Digital > DigitalReadSerial).
   * Adjust the code to read from the same GPIO port where you connected the push-button (D2 in this case).

3. Adding INPUT:
   * Modify the code by changing `pinMode` for the push-button to use `INPUT_PULLUP` instead of `INPUT`.
   * To understand why this change is beneficial, explore how INPUT_PULLUP uses an internal pull-up resistor to make reading button presses more reliable.

4. Uploading and Testing:
   * Upload the modified code to your Arduino board.
   * Open the Serial Monitor to check the button's state.
   * When the button is pressed, you should see changes in the Serial Monitor. Take a screenshot for your portfolio to showcase your successful setup.

5. Creating the LED Toggle Sketch:
   * Write an Arduino sketch that toggles an LED (connected to D2) when the button is pressed.
   * Use a variable to track the LED state (on/off) and update it with each button press.

#### Code for the toggle LED with Button

Here you can find the code for the Toggle LED with Button -> [example_toggle_led_with_button.ino](Team%20Workspace/Pol_Toni/exercises/activity01/example_toggle_led_with_button.ino)












#### Pictures
<img src="/Teamfolder/pictures/exercise01/client_button_picture_1.jpg" alt="drawing" width="300"/> <img src="/Teamfolder/pictures/exercise01/client_button_picture_2.jpg" alt="drawing" width="300"/>

## Problems
In the first Lab we had problems especially with the micro USB cables. Some of our cables did not work and that cost us time.
