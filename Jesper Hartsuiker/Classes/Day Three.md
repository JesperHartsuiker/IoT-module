# Day Three

## Exchange Formats/Data Serialization. How to speak IoT?

Text:
- **Explenation:** Simple, human-readable format, suitable for data transmission, but less efficient for machine processing.
- **Suitability:** Text-based formats are human-readable and can be easily interpreted by a variety of systems. They are suitable for data transmission in less resource-constrained environments within the IoT architecture, such as at the application layer or for configuration files.
- **Unsuitability:** However, text-based formats can consume more bandwidth and require more processing power for encoding and decoding, making them less suitable for resource-constrained IoT devices.

XML (focus on SOAP):
- **Explenation:** Markup language for data storage and transport, often used for defining complex data structures. SOAP is a protocol built on XML for exchanging structured information in web services.
- **Suitability:** XML is suitable for IoT systems where data needs to be structured hierarchically, allowing for complex data models. SOAP (Simple Object Access Protocol) built on XML is suitable for larger, enterprise-level IoT applications where there is a need for standardized communication and security.
- **Unsuitability:** XML can be verbose and, therefore, requires more bandwidth and processing power. This can be unsuitable for resource-constrained IoT devices, especially in scenarios where data transfer speed and efficiency are crucial.

JSON:
- **Explenation:** Lightweight, text-based data interchange format known for its simplicity and ease of representing complex data structures. Commonly used for data exchange in web applications, including IoT systems.
- **Suitability:** JSON is lightweight, easy to read, and has a simpler structure compared to XML. It is particularly suitable for resource-constrained IoT devices and is often used for transmitting data between IoT devices and servers, making it a popular choice for IoT applications.
- **Unsuitability:** JSON may not be the best choice for transmitting large volumes of data or complex data structures due to its relatively simplistic design.

YAML:
- **Explenation:** Human-readable data serialization format used for configuration files and data exchange between applications, designed for human-friendly representation of complex data structures.
- **Suitability:** YAML is a human-readable data serialization format that allows for more complex data structures. It is suitable for configuration files, and its readability makes it convenient for defining data in IoT applications.
- **Unsuitability:** YAML, similar to XML, can be more verbose and consume additional bandwidth, making it less ideal for resource-constrained devices and scenarios where efficiency is crucial.

Binary (e.g., Python's pickle and CBOR):
- **Explenation:** Compact binary serialization formats used for efficient representation and transmission of data. Not human-readable but efficient for resource-constrained environments and high-performance data serialization requirements.
- **Suitability:** Binary formats like CBOR (Concise Binary Object Representation) are more compact, efficient, and faster to serialize and deserialize. They are suitable for resource-constrained IoT devices and can be used in communication protocols that require high performance and reduced bandwidth usage.
- **Unsuitability:** Binary formats are not human-readable, making them less suitable for scenarios where human readability and debugging are essential. They might be challenging to work with in systems requiring human intervention or analysis.



## MQTT - M2M Communication

**MQ Telemetry Transport or Message Queue Telemetry Transport (MQTT):** MQTT is a lightweight messaging protocol designed for constrained devices and low-bandwidth, high-latency, or unreliable networks. It is used to send messages between devices in remote locations, making it suitable for Internet of Things (IoT) and Machine-to-Machine (M2M) applications.

**MQTT Gateway/Broker, star topology:** MQTT uses a star topology where a central message broker acts as a hub, receiving all messages from devices and forwarding them to their intended destinations. The broker is responsible for receiving all messages, filtering them, and then distributing them to the relevant subscribers.

**Publish Subscribe:** MQTT operates on the publish-subscribe messaging pattern. In this pattern, senders of messages, called publishers, do not program the messages to be sent directly to specific receivers, known as subscribers. Instead, published messages are characterized into categories without knowledge of which subscribers, if any, there may be.

**ISO standard, invented in 1999:** MQTT is an ISO standard (ISO/IEC PRF 20922) and was invented by Dr. Andy Stanford-Clark of IBM and Arlen Nipper of Arcom Control Systems in 1999.

**Runs over TCP/any other stream-based protocol:** MQTT runs over the Transmission Control Protocol (TCP) but can also be implemented over other reliable stream-based communication protocols.

**Very Lightweight:** MQTT is designed to be extremely lightweight and is suitable for running on devices with limited resources, such as single-board computers like Raspberry Pi and low-power routers, making it well-suited for IoT applications.

**Many Implementations:** There are numerous open-source and commercial implementations of MQTT, making it widely supported and easy to integrate into various IoT systems and applications.

**Built-in Security:**
- **Allows Layered Security/Stacked Gateways:** MQTT allows for layered security protocols, enabling the use of multiple security mechanisms to protect the network and devices.
- **User Access Management:** It supports user access management, allowing administrators to control and restrict access to various topics and messages.
- **End-to-End Encryption:** MQTT supports end-to-end encryption, ensuring that data remains confidential and secure during transmission between devices and the broker.
