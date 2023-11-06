# Class 03

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://drive.google.com/file/d/1RDNF21yAlu9yf71ilP0qkRYE549gjxs3/view?usp=sharing).

## How to speak IoT? (Exchange Formats / Data Serialization)

Answer the following questions:

### What is especially suitable for IoT systems (where in architecture)? Why?

### What is especially unsuitable? Why?

* Plain Text:

    * Description: Plain text format represents data using characters like letters and numbers.
    * Suitability for IoT:
* Appropriate: Text formats are lightweight and easily readable, making them suitable for IoT devices with limited memory and processing power, particularly for simple data exchange and configuration settings.
* Inappropriate: However, text formats can be inefficient for transmitting significant data volumes or real-time sensor data due to their verbosity.
* XML (Focus on SOAP):

    * Description: XML (Extensible Markup Language) is a markup language that organizes data using tags.
    * Suitability for IoT:
* Appropriate: XML is suitable for IoT systems, especially when well-structured data is required. SOAP (Simple Object Access Protocol) uses XML for communication and ensures data integrity, making it suitable for complex transactions.
* Inappropriate: XML's verbosity can lead to higher bandwidth consumption and processing demands, posing challenges for resource-constrained IoT devices.
* JSON:

    * Description: JSON (JavaScript Object Notation) is a lightweight, readable data interchange format.
    * Suitability for IoT:
* Appropriate: JSON is frequently used in IoT systems due to its efficiency and human readability. Its compactness makes it suitable for transmitting data between IoT devices and servers, catering to both human and machine readers.
* Inappropriate: JSON might still be too verbose for extremely limited IoT devices.
* YAML:

    * Description: YAML (YAML Ain't Markup Language) is a readable data serialization format.
    * Suitability for IoT:
* Appropriate: YAML, resembling a simplified version of XML, is suitable for IoT configurations and data exchanges, emphasizing human readability. It's user-friendly and simple to interpret.
* Inappropriate: Similar to text-based formats, YAML can become verbose when handling substantial datasets.
* Binary (e.g., Python's pickle and CBOR):

    * Description: Binary formats represent data in binary code, lacking human readability.
    * Suitability for IoT:
* Appropriate: Binary formats like CBOR are highly efficient for IoT systems, being space-saving and suitable for transmitting large data volumes, especially on resource-constrained devices.
* Inappropriate: These formats are unsuitable when human readability is necessary for debugging or when interoperability with non-binary systems is required.

Considering these approaches for IoT systems, it's essential to select a format that aligns with the specific requirements of the system. For data that requires easy interpretation, opting for Text or YAML would be suitable. JSON is efficient for various IoT applications. XML (SOAP) is recommended for complex transactions, and Binary formats like CBOR are ideal for resource-constrained devices and large data transmission.

### MQTT - M2M Communication

MQTT (Message Queuing Telemetry Transport) is a lightweight and efficient messaging protocol designed for Machine-to-Machine (M2M) communication, extensively used in IoT applications and scenarios where efficient and low-overhead communication is crucial.

#### What are the main CLI commands for MQTT?

Here are some key points and CLI commands related to MQTT:

Mosquitto: An open-source MQTT broker implementation offering command-line tools for interacting with the MQTT broker. Common commands include:

Mosquitto_pub: Used to publish messages to an MQTT broker, allowing users to specify the topic and message payload. For example:
php
mosquitto_pub -h <broker_host> -t <topic> -m "Hello, MQTT"
Mosquitto_sub: Subscribes to MQTT topics and receives messages from the broker, displaying messages as they arrive. For example:
php
mosquitto_sub -h <broker_host> -t <topic>
Mosquitto_passwd: Manages username and password authentication on an MQTT broker, facilitating user credential addition, removal, or modification. For instance, adding a new user:
php
mosquitto_passwd -c <password_file> <username>
Mosquitto_ctrl: A versatile command-line utility for interacting with an MQTT broker, performing various administrative tasks like querying broker status and sending specific control messages.

5. **mosquitto_sub and mosquitto_pub with QoS settings**: MQTT allows you to specify the Quality of Service (QoS) level for messages, which can be set using the `-q` option with the `mosquitto_pub` and `mosquitto_sub` commands.

* mqtt-cli: Some MQTT clients and libraries offer their command-line tools for MQTT communication. These tools vary depending on the client or library in use, providing users with specific functionalities for MQTT testing and scripting, such as the Paho MQTT library's command-line tool.


#### What stands out for you/question?

Considering MQTT for M2M communication, the following points and questions are noteworthy:

* Lightweight: MQTT is designed to be highly lightweight, catering to resource-constrained devices and low-bandwidth networks, thus being ideal for IoT and M2M communication.

* Publish-Subscribe Pattern: MQTT's use of the publish-subscribe pattern ensures scalable and efficient distribution of messages to multiple subscribers, promoting loose coupling between components similar to the Observer pattern in software design.

* ISO Standard: MQTT is an established ISO standard (ISO/IEC 20922:2016) widely recognized in the industry, providing a strong foundation for IoT and M2M communication.

* Protocol Compatibility: MQTT operates over various protocols such as TCP/IP, enhancing its versatility in terms of network compatibility.

* Diverse Implementations: There is a myriad of MQTT broker and client implementations available for multiple platforms, fostering interoperability and widespread adoption.

* Built-in Security: MQTT supports built-in security features, including user access management, authentication, and the potential for end-to-end encryption, making it suitable for secure IoT applications.

Overall, MQTT's lightweight and efficient nature, coupled with its adaptability to various devices and networks, positions it as an outstanding choice for M2M and IoT communication. Its straightforward CLI commands facilitate easy interaction with MQTT brokers for testing and administrative purposes.





