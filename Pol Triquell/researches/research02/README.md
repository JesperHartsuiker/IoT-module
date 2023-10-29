# Research records 02

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://drive.google.com/file/d/1PAqJoWg5NkgtXSZ5D4Dpb6QUUzFrST0W/view?usp=sharing).

# IoT (Internet of Things) Architecture and Terminology

IoT architecture involves the interconnection of various components and technologies to enable seamless communication and data exchange between "Things." Below, we explain how these concepts are related and provide examples for each group, along with a simplified architecture sketch.

## Components of IoT Architecture

1. Internet:
   The Internet serves as the backbone for IoT, enabling Things to connect to each other and external services. It provides the global communication infrastructure.
   * *Example:* Smart thermostats communicating with a weather service over the Internet to adjust heating and cooling based on weather forecasts.

2. **Server:**
   Servers in IoT architecture are responsible for receiving and processing data from Things and often serve as intermediaries between Things and the cloud.
   * *Example:* A server collecting sensor data from multiple smart streetlights to optimize energy usage and monitor their status.

3. **Cloud Computing:**
   Cloud computing resources are used for storage, processing, and analysis of large amounts of IoT data. It offers scalability and accessibility.
   * *Example:* A cloud platform storing and analyzing data from a fleet of autonomous delivery drones.

4. **Edge Computing:**
   Edge computing involves processing data closer to where it's generated (e.g., at the device or gateway), reducing latency and conserving bandwidth.
   * *Example:* A smart security camera using edge computing to identify intruders and send alerts without sending video data to the cloud.

5. **Fog Computing:**
   Fog computing extends edge computing by incorporating more intelligence and processing power at the network's edge.
   * *Example:* An industrial robot in a manufacturing facility using fog computing for real-time monitoring and decision-making.

6. **Swarm:**
   Swarm computing refers to a group of interconnected Things that collaborate to achieve a common goal. It's often used in robotics and distributed systems.
   * *Example:* A swarm of autonomous drones working together for search and rescue missions.

7. **Things:**
   Things are the devices and sensors that collect and transmit data, such as sensors, smart appliances, wearables, and more.
   * *Example:* Smart wearable devices monitoring a person's health and sending data to their healthcare provider.

8. **Gateway:**
   Gateways act as intermediaries between Things and the rest of the IoT architecture, translating between different communication protocols.
   * *Example:* A smart home hub that connects various smart devices (lights, locks, thermostats) and controls them through a single interface.

9. Nodes:
   Nodes are individual devices within the IoT network, including both the Things and other components like gateways and servers.
   * *Example:* In an agricultural IoT system, nodes include soil moisture sensors, drones for crop monitoring, and a central control node for decision-making.

## Architecture Sketch

This simplified architecture sketch represents a basic IoT architecture:

   Internet
      |
   Server
      |
   Gateway
   /  |  \
Thing Thing Thing
   |   |   |
 Edge Fog Cloud



In this architecture, Things connect to gateways, which can use edge or fog computing for data processing. Data is then transmitted to servers, which can further communicate with the cloud for storage and analysis over the Internet. This interconnected system allows for efficient data collection, processing, and utilization in IoT applications.
