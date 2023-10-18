# Day Three

## Exchange Formats/Data Serialization: Speaking the Language of IoT

### Text
- **Explanation:** A straightforward, human-readable format suitable for data transmission but less efficient for machine processing.
- **Suitability:** Text-based formats are easily understood by both humans and various systems. They work well for data transmission in IoT, especially in less resource-constrained environments like the application layer or for configuration files.
- **Unsuitability:** Text-based formats can consume more bandwidth and processing power for encoding and decoding, which can be a drawback for resource-constrained IoT devices.

### XML (with a focus on SOAP)
- **Explanation:** XML is a markup language used for data storage and transport, often for complex data structures. SOAP, built on XML, is a protocol for structured information exchange in web services.
- **Suitability:** XML is a good fit for IoT systems that require hierarchical data structures, such as complex data models. SOAP, based on XML, suits larger, enterprise-level IoT applications demanding standardized communication and security.
- **Unsuitability:** XML can be verbose, demanding more bandwidth and processing power. This makes it less suitable for resource-constrained IoT devices, especially in scenarios where speed and efficiency are critical.

### JSON
- **Explanation:** A lightweight, text-based data interchange format known for simplicity and the ability to represent complex data structures. Commonly used for data exchange in web applications, including IoT systems.
- **Suitability:** JSON is lightweight, easy to read, and has a simpler structure compared to XML. It's particularly well-suited for resource-constrained IoT devices and is often used for data exchange between IoT devices and servers, making it a popular choice for IoT applications.
- **Unsuitability:** Transmitting large volumes of data or complex data structures may not be ideal due to JSON's relatively simplistic design.

### YAML
- **Explanation:** A human-readable data serialization format used for configuration files and data exchange between applications. It's designed for human-friendly representation of complex data structures.
- **Suitability:** YAML, being human-readable, allows for more complex data structures and is well-suited for configuration files. Its readability makes it convenient for defining data in IoT applications.
- **Unsuitability:** Similar to XML, YAML can be more verbose and consume additional bandwidth, making it less ideal for resource-constrained devices and scenarios prioritizing efficiency.

### Binary (e.g., Python's pickle and CBOR)
- **Explanation:** Compact binary serialization formats used for efficient data representation and transmission. Not human-readable but efficient for resource-constrained environments and high-performance data serialization requirements.
- **Suitability:** Binary formats like CBOR (Concise Binary Object Representation) are compact, efficient, and faster for serialization and deserialization. They suit resource-constrained IoT devices and communication protocols requiring high performance and reduced bandwidth usage.
- **Unsuitability:** Binary formats lack human readability, making them less appropriate for scenarios where human intervention or analysis is essential.

## MQTT - M2M Communication

**MQ Telemetry Transport or Message Queue Telemetry Transport (MQTT):** MQTT is a lightweight messaging protocol designed for devices with limitations and networks with low bandwidth, high latency, or unreliable connections. It's used for sending messages between devices in remote locations, making it suitable for IoT and Machine-to-Machine (M2M) applications.

**MQTT Gateway/Broker, star topology:** MQTT uses a star topology where a central message broker acts as a hub, receiving all messages from devices and forwarding them to their intended destinations. The broker receives, filters, and distributes messages to relevant subscribers.

**Publish Subscribe:** MQTT operates using the publish-subscribe messaging pattern. In this pattern, senders of messages (publishers) don't send messages directly to specific receivers (subscribers). Instead, published messages are categorized without knowledge of potential subscribers.

**ISO standard, invented in 1999:** MQTT is an ISO standard (ISO/IEC PRF 20922) and was created by Dr. Andy Stanford-Clark of IBM and Arlen Nipper of Arcom Control Systems in 1999.

**Runs over TCP/any other stream-based protocol:** MQTT runs over the Transmission Control Protocol (TCP) but can be implemented over other reliable stream-based communication protocols.

**Very Lightweight:** MQTT is designed to be extremely lightweight and suitable for devices with limited resources, such as single-board computers like Raspberry Pi and low-power routers, making it ideal for IoT applications.

**Many Implementations:** There are numerous open-source and commercial MQTT implementations, making it widely supported and easy to integrate into various IoT systems and applications.

**Built-in Security:**
- **Allows Layered Security/Stacked Gateways:** MQTT supports layered security protocols, allowing the use of multiple security mechanisms to protect the network and devices.
- **User Access Management:** It enables user access management, letting administrators control and restrict access to various topics and messages.
- **End-to-End Encryption:** MQTT supports end-to-end encryption, ensuring data remains confidential and secure during transmission between devices and the broker.
