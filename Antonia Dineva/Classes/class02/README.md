# Class 02

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://drive.google.com/file/d/1PAqJoWg5NkgtXSZ5D4Dpb6QUUzFrST0W/view?usp=sharing).

# IoT (Internet of Things) Architecture and Terminology

IoT structure encompasses the linkage of diverse elements and technologies to facilitate seamless communication and data interchange among interconnected devices. Below, we elaborate on the correlation between these concepts, presenting instances for each category, along with a simplified diagram of the architectural framework.

## Components of IoT Architecture
1. Internet:
The Internet serves as the foundation for IoT, enabling the interconnection of devices and external services. It acts as the global communication infrastructure.

* Illustration: Smart thermostats adjusting heating and cooling based on weather forecasts by communicating with a weather service over the Internet.
2. Server:
Servers in the IoT structure are responsible for receiving and processing data from devices, often serving as intermediaries between devices and the cloud.

* Illustration: A server gathering sensor data from multiple smart streetlights to optimize energy usage and monitor their status.
3. Cloud Computing:
Cloud computing resources are utilized for the storage, processing, and analysis of extensive IoT data, offering scalability and accessibility.

* Illustration: A cloud platform storing and analyzing data from a fleet of autonomous delivery drones.
4. Edge Computing:
Edge computing involves processing data closer to its source, reducing latency and conserving bandwidth, often at the device or gateway level.

* Illustration: A smart security camera employing edge computing to identify intruders and send alerts without transmitting video data to the cloud.
5. Fog Computing:
Fog computing expands upon edge computing by incorporating greater intelligence and processing power at the network's edge.

* Illustration: An industrial robot in a manufacturing facility utilizing fog computing for real-time monitoring and decision-making.
6. Swarm:
Swarm computing signifies a network of interconnected devices collaborating to achieve a shared objective, commonly employed in robotics and distributed systems.

* Illustration: A swarm of autonomous drones working collectively for search and rescue missions.
7. Devices (Things):
Devices or Things encompass sensors, smart appliances, wearables, and similar gadgets that collect and transmit data within the IoT network.

* Illustration: Smart wearable devices transmitting health data to a person's healthcare provider for monitoring.
8. Gateway:
Gateways serve as intermediaries between devices and the broader IoT structure, facilitating communication between different protocols.

* Illustration: A smart home hub connecting various smart devices and controlling them through a unified interface.
9. Nodes:
Nodes refer to individual devices within the IoT network, including both Things and other components such as gateways and servers.

* Illustration: In an agricultural IoT system, nodes consist of soil moisture sensors, crop monitoring drones, and a central control node for decision-making.

## Architecture Sketch

In the diagram, devices connect to gateways, which utilize edge or fog computing for data processing. Subsequently, data is transmitted to servers, which can further communicate with the cloud for storage and analysis via the Internet. This interconnected system facilitates efficient data collection, processing, and utilization in various IoT applications.