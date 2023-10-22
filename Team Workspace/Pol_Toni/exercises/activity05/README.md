# Lab Tasks Description

# Exercise 05

For the fifth exercise we wrote five different Node-RED programs.

## Overview
1. [Device Control with IoTempower](#device-control-with-iotempower)
2. [Example - Exploring IoTempower Services and Commands](#example---exploring-iotempower-services-and-commands)
	* [Procedure](#procedure)
3. [Example - Blink on the Wemos D1 Mini or ESP32 (Pair)](#example---blink-on-the-wemos-d1-mini-or-esp32-pair)
	* [Procedure](#procedure-1)
	* [Code for the three types of blinking LED in Wemos D1 Mini](#code-for-the-three-types-of-blinking-led-in-wemos-d1-mini)
4. [Example - Toggle LED With Button](#example---toggle-led-with-button)
	* [Procedure](#procedure-2)
	* [Code for the toggle LED with Button](#code-for-the-toggle-led-with-button)

## Device Control with IoTempower

### IoTempower introduction

### Example - Exploring IoTempower Services and Commands

In this IoT prototyping procedure, we will guide you through the necessary steps to search for useful documentation about the RFID reader, PWM, a servo motor, ultrasonic distance sensor (RCWL-1601 or HC-SR04) in IoTempower web portal.

#### Procedure

1. Access the Website:
   * Ensure your device is connected to your configured Wi-Fi network on either your Raspberry Pi or modem.
   * Open a web browser and enter the website URL, which can be either `gw.iotempire.net` or `192.168.12.1` into the address bar.

   ![IoTempower Local Web Portal](https://github.com/JesperHartsuiker/IoT-module/blob/4ab50c59138ede71e3494f7aa3bda28d093577ce/Team%20Workspace/Pol_Toni/pictures/activity05/iotempower_local_web_portal.png?raw=true)

2. Choose Documentation Options:
   * On the main webpage, you have two options:
     * [Local Documentation Table of Contents](#option-1-local-documentation-table-of-contents).
     * [Command Reference for Nodes](#option-2-command-reference-for-nodes).

   #### Option 1: Local Documentation Table of Contents:
   * If you select `Local documentation table of contents`, you will navigate one step further before reaching the documentation.

   ![Local Documentation Table of Contents](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/local_documentation_table_of_contents.png?raw=true)

   #### Option 2: Command Reference for Nodes:
   * If you choose `Command reference for nodes`, you can immediately start searching for specific components within the documentation. The components you can search for are:
     * RFID reader
     * PWM
     * Servo motor
     * Ultrasonic distance sensor (RCWL-1601 or HC-SR04)

   ![Command Reference for Nodes](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/command_reference_for_nodes.png?raw=true)

3. Access Component Documentation:
   * If you went through the first link (Local documentation table of contents), you will be directed to a table of contents webpage.
   * Click on `Command reference` within this webpage.
   * From there, you can search for the components you are interested in (RFID reader, PWM, servo motor, ultrasonic distance sensor).

4. Search for the components in `Command reference for nodes` page:
   * To find this components you need to search for it's components name:
     * RFID Reader Documentation

     ![RFID Reader Documentation](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/documentation/rfid_reader_documentation.png?raw=true)

     * PWM Documentation

     ![PWM Documentation](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/documentation/pwm_documentation.png?raw=true)

     * Servo Motor Documentation

     ![RFID Reader Documentation](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/documentation/servo_motor_documentation.png?raw=true)

     * Ultrasonic Distance Sensor (RCWL-1601 or HC-SR04) Documentation

     ![Ultrasonic Distance Sensor (RCWL-1601 or HC-SR04) Documentation](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/documentation/ultra_sonic_distance_documentation.png?raw=true)

### Example - First node

The first assignment is to make a button with IoTempower and have it post using MQTT.

#### Procedure

To get started, we had to add a new node. These are the steps we followed to make it work:

   * Go to the `F7` section to create a new directory.
   * You should rename the directory, in our case, to `Toni_Pol`.
   * Confirm by pressing OK.
   * Moreover, if you want, you can split the programs in folders, in our case, we splitted it in one folder named `LED` and the other named, `button`.

Next, you can obtain the code from the example dictionary of the IoTempire gateway. This code needs to be placed into the `setup.cpp` files. You can do this by editing the `setup.cpp` files and the final code should look like:

   * LED `setup.cpp` file

   ![LED setup.cpp file](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/code/first_node/led_code.png?raw=true)

   * Button `setup.cpp` file

   ![Button setup.cpp file](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/code/first_node/button_code.png?raw=true)

Following that, you can save the file and then close it. Afterwards, you will need to upload it to the microcontroller. This is done using the `F2` section and, if it is the first time, you need to go to `V - Advanced` menu and once you get there press `Initialize Serial (I)` option. When you have finished that, get to `F2` section another time and use the `D - Deploy` option.

Once you have started the upload, you should wait until the process is complete, and then you can close the window.

In the next video you can see the evidence of the `First node`.

https://github.com/JesperHartsuiker/IoT-module/assets/74074466/82c52a1b-7f06-4ef2-a50d-fc2769c17059

### Example - Second node

In this IoTempower procedure, we will guide you through the necessary steps to set up and test a Wemos D1 Mini for the activity involving the second node, which is designed to activate a light using MQTT on a different ESP32.

#### Procedure

According to this task, you have to establish a second Node to control the activation of a light on a different ESP32 using MQTT. As, in our case, we splitted ways before, you do not need to do it now. Afterwards, you only need to proceed to modify the `setup.cpp` file to manage the on and off functions of the LED that you will connect in the breadboard.

After editing the LED `setup.cpp` file, you should have a code that looks like this:

   ![LED setup.cpp file](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/code/second_node/led_code.png?raw=true)

Following that, let's set up a flow in Node-RED. In this flow, when you press a button, it will control the LED, turning it on and off. The example below demonstrates how it all comes together. Simply click the toggle button once, and the light stays on. Click it again, and the light turns off.

   ![Node-RED flow for second node](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/code/second_node/led_code.png?raw=true)

In the next video you can see the evidence of the `Second node`.

VIDEO VIDEO VIDEO

### Example - Guest Arrival Notifier

#### Button to sound and notification

In this IoTempower guide, we will walk you through the process of configuring a physical button device, which is crucial for creating a device that uses MQTT to trigger sound playback and display notifications on the Node-RED dashboard.

In this project, your goal is to create a simple system that notifies you when a guest arrives at your home. When a guest presses a physical button at your home's entrance, the system will send you a notification via MQTT, and you will receive the notification on both your desktop and mobile devices through the Node-RED dashboard.

#### Components and Hardware Needed

   * Wemos D1 Mini (or another compatible microcontroller).
   * A physical button for the entrance.
   * A breadboard.
   * An enclosure for the button and wiring.
   * An MQTT broker (e.g., Mosquitto) running on the Raspberry Pi.
   * Computer with Node-RED dashboard app installed.

#### Procedure

1. Hardware Setup

   * Connect the Wemos D1 Mini to the breadboard.
   * Connect a push-button to the breadboard.

2. Node-RED Setup

   * Install Node-Red on your computer.
   * Use the MQTT broker that you set up before on your Raspberry Pi.

3. Setting up Node-RED

   * Create a Node-RED flow to proof that you have learned that much about the software.

   ![Node-RED flow for button to sound and notification](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/code/button_to_sound_and_notification/button_to_sound_and_notification.png?raw=true)

4. Testing

   * Run the simulation by pressing the physical button on the breadboard.
   * The Wemos D1 Mini sends an MQTT message to Node-RED.
   * Node-RED receives the message, triggers a notification, and displays it on your computer (simulating a mobile device) using the Node-RED dashboard.

If the button is pressed, it will send a notification to a dashboard that displays `Team Rocked has arrived!` for 5 seconds. Additionally, a sound will be played from the speaker, saying `Team Rocked has arrived!`.

In the following video, you can view the evidence related to the `Button to sound and notification`.

VIDEO VIDEO VIDEO

#### Text receiver

In this IoTempower guide, we will guide you through configuring an OLED I2C display. Your next task is to explore the provided OLED I2C display and set up an MQTT text receiver. This involves sending a brief message and displaying it on the screen.

To achieve that goal, you need to follow the project that we set up before from the `Guest Arrival Notifier`.

#### Procedure

1. Connecting the OLED Screen:
   * To start, we connected the OLED screen to our board. This was the first crucial step.
   * We also created a specific directory to organize the code that would be loaded onto our microcontroller. The code was placed in the directory named `Pol_Toni/guest_arrival_screen/`.

2. Uploading the Code:
   * Similar to our previous tasks, we uploaded the code to our microcontroller. We waited until the process was completed.
   * The code allowed us to send messages to the OLED screen, which would then be displayed.

   ![Node-RED flow for text receiver](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity05/code/text_receiver/text_receiver.png?raw=true)

3. Displaying a Simple Greeting:
   * To test the OLED screen, we sent a message saying "Hello" using MQTT. As a result, the message "Hello" appeared on the screen. In our case, we did not record the example but we have evidence for the improvements that we made in it.

4. Expanding the Assignment:
   * To make the assignment more comprehensive, we decided to include a button.
   * Whenever the button was pressed, it triggered a message to be sent to the OLED screen. Specifically, it sent "Team Rocket has arrived!"

5. Creating the Workflow:
   * To make this happen, you need to expand the workflow from the previous exercise. This should allow the audio message to be displayed on the OLED screen.

In the following video, you can view the evidence related to the `Text receiver`.

VIDEO VIDEO VIDEO