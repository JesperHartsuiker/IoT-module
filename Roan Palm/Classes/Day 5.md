# Class 20-10-2023

## System Structure in Folders

The system structure is organized into a hierarchy of folders and devices as follows:

- **myhouse**
  - **living_room**
    - **leds1 (rgb_strip)**
    - **leds2 (rgb_strip)**
  - **kitchen**
    - **Toaster**
      - **Consumption (i2c_dev returning power)**
      - **Switch (output)**
    - **Coffee-machine**
      - **coffee_left (ultrasonic distance)**
      - **milk_left (swimmer with reed switch - contact)**
      - **switch (output)**
  - **Main**
    - **switch (output)**
  - **system.conf**

## Assignments (with peer)

1. **Which topic needs to be called with what to:**
    - **Switch on the coffee machine?**  
      Topic: `kitchen/coffee-machine/switch/set` with the payload "on".
    - **Set all lights in the living room to blue?**  
      Topic: `living_room/#/rgb/set` with the payload "blue".
    - **Turn the main power off?**  
      Topic: `main/switch/set` with the payload "off".

2. **What is the general rule for forming topics in IoTempower?**  
    The general rule is to start with the directory that represents the location and then go down through the folders to the specific device. In most cases, the topic ends with an action like "set" to indicate that you are setting a value.

3. **When does it make sense to change something in system.conf?**  
    It makes sense to change something in `system.conf` when there are changes in parameters like Wi-Fi or MQTT broker configuration, such as a password or IP address change.

4. **What role does the location of system.conf play? (What if it would be one level higher and there is also yourhouse)**  
    The location of `system.conf` determines the highest level of the system hierarchy. If there was a "yourhouse" directory one level higher, `system.conf` would still define the configuration for "myhouse" and not interfere with "yourhouse."

## Nodes

### During Demonstration Add to Portfolio

- **What needs to/can go into node.conf?**  
  In `node.conf`, the type of microcontroller used in the system needs to be specified.

- **How do [optional config.txt,] etc/iotempower.conf, system.conf, and node.conf influence environment variables for compiling? Give examples for when to change.**  
  These configuration files influence environment variables for compiling by specifying essential parameters for the compilation process. For example:
  - `config.txt` can specify compiler flags and options.
  - `iotempower.conf` can define global configurations like network settings.
  - `system.conf` may contain information about the MQTT broker or other system-wide settings.
  - `node.conf` specifies the microcontroller type for a specific node.
  
  When you need to change these files depends on system requirements, hardware changes, or network modifications. For instance, if you switch to a different microcontroller for a node, you would update `node.conf` to reflect this change. Similarly, if your MQTT broker's IP address changes, you would modify the settings in `system.conf` to ensure proper communication.
