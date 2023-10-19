# Research records 03

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://drive.google.com/file/d/1RDNF21yAlu9yf71ilP0qkRYE549gjxs3/view?usp=sharing).

## How to speak IoT? (Exchange Formats / Data Serialization)

Answer the following questions:

### What is especially suitable for IoT systems (where in architecture)? Why?
### What is especially unsuitable? Why?

* Text:
   * Description: Text format represents data in plain text, often using characters like letters and numbers.
   * Suitability for IoT:
     * *Suitable*: Text formats are lightweight and human-readable, making them suitable for IoT devices where memory and processing power are limited. They can be used for configuration settings and simple data exchange.
     * *Unsuitable*: However, text formats may not be efficient for transmitting large volumes of data or real-time sensor data due to their verbosity.

* XML (focus on SOAP):
   * Description: XML (Extensible Markup Language) is a markup language that uses tags to structure data.
   * Suitability for IoT:
     * *Suitable*: XML can be used for IoT systems, particularly in cases where well-defined data structures are necessary. SOAP (Simple Object Access Protocol) is a protocol that uses XML for communication. It is suitable when you need to ensure data integrity and support complex transactions.
     * *Unsuitable*: XML can be verbose and may consume more bandwidth and processing power, which can be problematic for resource-constrained IoT devices.

* JSON:
   * Description: JSON (JavaScript Object Notation) is a lightweight, human-readable data interchange format.
   * Suitability for IoT:
     * *Suitable*: JSON is commonly used in IoT systems for data exchange. It is more compact than XML, making it suitable for transmitting data between IoT devices and servers. JSON is easy for both humans and machines to read and write.
     * *Unsuitable*: JSON might still be too verbose for extremely constrained IoT devices.

* YAML:
   * Description: YAML (YAML Ain't Markup Language) is a human-readable data serialization format.
   * Suitability for IoT:
     * *Suitable*: YAML is like a simplified version of XML and can be used for IoT configurations and data exchange, especially when human readability is a priority. It's easy to understand and write.
     * *Unsuitable*: Similar to text-based formats, YAML can be verbose when handling large datasets.

* Binary (e.g., Python's pickle and CBOR):
   * Description: Binary formats are not human-readable and represent data using binary code.
   * Suitability for IoT:
     * *Suitable*: Binary formats like CBOR (Concise Binary Object Representation) are highly efficient for IoT systems. They are space-saving, making them suitable for resource-constrained devices and for transmitting large volumes of data.
     * *Unsuitable*: They are unsuitable when you need data to be human-readable for debugging or when interoperability with systems that don't support binary formats is required.

For IoT systems there are different approaches.

Text is suitable for configuration data in IoT systems where human readability and simplicity are essential, like setting the device's name or location. It's less suitable for real-time sensor data.

XML (SOAP) can be suitable for IoT systems when complex transactional data exchange with data integrity and structure is needed. It's less suitable for resource-constrained devices.

JSON is commonly used for IoT data exchange due to its efficiency and human-readability. It's a good choice for most IoT applications.

YAML is a simplified and human-readable format that is suitable for IoT configurations and simple data exchanges.

Binary formats like CBOR are suitable for IoT systems with resource constraints or those transmitting large data volumes. However, they lack human-readability.

In simple terms, choose the format that matches the needs of your IoT system. If you want easy-to-read data, use Text or YAML. If you need efficiency, JSON is a good option. For complex transactions, consider XML (SOAP). For resource-constrained devices or large data, Binary formats like CBOR are the way to go.

### MQTT - M2M Communication

MQTT (Message Queuing Telemetry Transport) is a lightweight and efficient messaging protocol designed for Machine-to-Machine (M2M) communication. It's widely used in IoT (Internet of Things) applications and other scenarios where efficient and low-overhead communication is crucial.

#### What are the main CLI commands for MQTT?

Here are some key points and CLI commands related to MQTT:

* mosquitto: Mosquitto is a popular open-source MQTT broker implementation. You can use Mosquitto's command-line tools to interact with the MQTT broker. Some common commands include:
  * mosquitto_pub: This command-line tool is used to publish messages to an MQTT broker. It allows you to specify the topic and message payload to be published. For example:
   ```
   mosquitto_pub -h <broker_host> -t <topic> -m "Hello, MQTT"
   ```

  * mosquitto_sub: This tool is used to subscribe to MQTT topics and receive messages from the broker. You specify the topic to subscribe to, and it will display messages as they arrive. For example:
   ```
   mosquitto_sub -h <broker_host> -t <topic>
   ```

  * mosquitto_passwd**: This tool is used for managing username and password authentication on an MQTT broker. You can add, remove, or modify user credentials. For example, to add a new user:
   ```
   mosquitto_passwd -c <password_file> <username>
   ```

  * mosquitto_ctrl: This is a versatile command-line utility for interacting with an MQTT broker, allowing you to perform various administrative tasks such as querying broker status, sending specific control messages, and more.

5. **mosquitto_sub and mosquitto_pub with QoS settings**: MQTT allows you to specify the Quality of Service (QoS) level for messages, which can be set using the `-q` option with the `mosquitto_pub` and `mosquitto_sub` commands.

* mqtt-cli: Some MQTT clients and libraries offer their own command-line tools for MQTT communication. These tools vary depending on the client/library you are using. For instance, the Paho MQTT library provides a command-line tool for MQTT testing and scripting.


#### What stands out for you/question?

Here are the key points and questions that stand out when considering MQTT for M2M communication:

* Lightweight: MQTT is designed to be very lightweight, making it suitable for resource-constrained devices and low-bandwidth networks. This efficiency is particularly important for IoT and M2M communication.

* Publish-Subscribe Pattern: The publish-subscribe pattern used in MQTT is a scalable and efficient way to distribute messages to multiple subscribers. It's similar to the Observer pattern in software design, which promotes loose coupling between components.

* ISO Standard: MQTT is an ISO standard (ISO/IEC 20922:2016) and is well-established in the industry, providing a solid foundation for IoT and M2M communication.

* Runs Over Various Protocols: MQTT can run over TCP/IP and other stream-based protocols, making it versatile in terms of network compatibility.

* Many Implementations: There are numerous MQTT broker and client implementations available for various platforms, which fosters interoperability and adoption.

* Built-in Security: MQTT supports built-in security features, including user access management, authentication, and the potential for end-to-end encryption, making it suitable for secure IoT applications.

Overall, MQTT's lightweight and efficient nature, along with its suitability for various devices and networks, makes it a standout choice for M2M and IoT communication. Its simple CLI commands, as listed above, allow easy interaction with MQTT brokers for testing and administration.


MQTT (MQ Telemetry Transport), originally known as Message Queue Telemetry Transport, is a lightweight and efficient messaging protocol designed for machine-to-machine (M2M) communication and IoT (Internet of Things) applications. It follows a publish-subscribe communication pattern and is widely used for its simplicity and suitability for low-bandwidth and unreliable networks. Here are some of the key aspects of MQTT and the main CLI commands associated with it:

**Main MQTT CLI Commands:**



**What Stands Out for MQTT:**

1. **Lightweight:** MQTT is designed to be very lightweight, making it suitable for resource-constrained devices and low-bandwidth networks. This efficiency is particularly important for IoT and M2M communication.

2. **Publish-Subscribe Pattern:** The publish-subscribe pattern used in MQTT is a scalable and efficient way to distribute messages to multiple subscribers. It's similar to the Observer pattern in software design, which promotes loose coupling between components.

3. **ISO Standard:** MQTT is an ISO standard (ISO/IEC 20922:2016) and is well-established in the industry, providing a solid foundation for IoT and M2M communication.

4. **Runs Over Various Protocols:** MQTT can run over TCP/IP and other stream-based protocols, making it versatile in terms of network compatibility.

5. **Many Implementations:** There are numerous MQTT broker and client implementations available for various platforms, which fosters interoperability and adoption.

6. **Built-in Security:** MQTT supports built-in security features, including user access management, authentication, and the potential for end-to-end encryption, making it suitable for secure IoT applications.

Overall, MQTT's lightweight and efficient nature, along with its suitability for various devices and networks, makes it a standout choice for M2M and IoT communication. Its simple CLI commands, as listed above, allow easy interaction with MQTT brokers for testing and administration.




