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

### What are the main CLI commands for MQTT?
### What stands out for you/question?