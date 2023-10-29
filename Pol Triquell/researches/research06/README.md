# Research records 06

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://drive.google.com/file/d/12243nB3_DEKPjK8-pF10iIH0UYjZj0nq/view?usp=sharing).

# IoTempower README

Welcome to IoTempower, an IoT framework for managing your devices and home automation. This README provides you with essential information on using IoTempower effectively, including device management, configuration files, and topic formation.

## Basic Features

IoTempower offers the following key features:

1. **Device Management**: Easily configure and control your IoT devices.
2. **Data Visualization**: Monitor and analyze device data for informed decision-making.
3. **Remote Control Capabilities**: Manage your devices from anywhere, providing flexibility and convenience.
4. **User Authentication and Authorization**: Ensure secure access to your IoT system.
5. **Data Logging and Analytics**: Keep track of historical data for analysis and optimization.

## System Configuration

In IoTempower, the system is organized into folders, allowing you to structure and manage your devices effectively. Here's how to interact with your devices and some insights into configuration:

### Topics for Device Control

To interact with your devices, use MQTT topics in the following format:

- To switch on the coffee machine: `kitchen/coffee-machine/switch/set "on"`
- To set all lights in the living room to blue:
  - For `leds1`: `myhouse/living_room/leds1/set_color` with payload "blue"
  - For `leds2`: `myhouse/living_room/leds2/set_color` with payload "blue"
- To turn off the main power: `myhouse/main/switch/set "off"`

### General Rule for Topics

IoTempower follows a specific topic formation rule to maintain consistency:

```
<root_topic>/<location>/<device_type>/<device_name>/<data_point>
```

For example:
- `<root_topic>` is the top-level topic in your IoT system, which could be your house name or a general category.
- `<location>` refers to the physical location of the device.
- `<device_type>` specifies the type of device, such as "coffee-machine" or "leds."
- `<device_name>` is the unique identifier for the device.
- `<data_point>` represents the specific data you want to interact with, like "switch" or "set_color."

### Configuration Files

IoTempower relies on several configuration files that influence compilation and operation. Here's what each file is used for:

- **`node.conf`**: This file configures individual hardware nodes or devices. It's crucial for specifying the type of microcontroller your hardware node uses.

  Example `node.conf`:
  ```ini
  board="esp32"
  ```

- **`config.txt` (optional)**: This file can contain additional configuration settings specific to your project or hardware. It may include board-specific or project-specific settings.

  Example `config.txt`:
  ```ini
  wifi_ssid="YourWiFiNetwork"
  wifi_password="YourWiFiPassword"
  ```

- **`iotempower.conf`**: Contains system-wide configuration settings common to all nodes. It may include settings related to MQTT brokers, data storage, and other system-wide parameters.

  Example `iotempower.conf`:
  ```ini
  mqtt_broker="mqtt.example.com"
  data_storage_path="/data"
  ```

- **`system.conf`**: Used for system-level configurations that apply to multiple nodes. It can include network configuration and other system-wide settings.

  Example `system.conf`:
  ```ini
  network_ip="192.168.1.100"
  network_gateway="192.168.1.1"
  ```

These configuration files impact the compilation and operation of your IoT devices, ensuring they work seamlessly within the IoTempower framework.

## System.conf Location

The location of `system.conf` is significant because it determines the system's highest level. If you had a "yourhouse" directory, placing `system.conf` one level higher would make "yourhouse" the highest-level entity in your system. The location of `system.conf` affects system access and organization, making it a crucial aspect of your IoT setup.

## When to Change Configuration Files

To make the most of IoTempower, you should know when and how to change these configuration files:

- **Change `system.conf`**: When you need to configure network settings, security, resource management, service integrations, debugging and logging, or scaling and load balancing. For example, if the Wi-Fi or MQTT broker information changes, update `system.conf`.

- **Change `iotempower.conf`**: When you want to set system-wide parameters common to all nodes.

- **Change `config.txt`**: Add project-specific settings that are not covered by other configuration files.

Customize these files based on your project's requirements and hardware specifications for a smooth IoTempower experience.

Feel free to explore IoTempower's features and enjoy efficient device management and automation. If you have further questions, consult the documentation or community support.
