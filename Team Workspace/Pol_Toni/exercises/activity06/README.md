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
