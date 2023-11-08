# Research records 10

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://discord.com/channels/1064132619735928932/1163216523062689862/1168288756017668187).

# Exploring SSL/TLS Configuration Options for mqttbroker

In this guide, we will examine SSL/TLS configuration options for `mqttbroker`. Ensure that you have `mqttbroker` installed and accessible via the command line.

## How to Request a Full "Template" Command Line for `mqttbroker`?

To obtain a complete command line template and usage information for `mqttbroker`, execute the following command:

```bash
mqttbroker --help
```

## How to Retrieve the Current Configuration of `mqttbroker`?

To retrieve the current configuration of `mqttbroker`, use the following command:

```bash
mqttbroker --show-config
```

This command will display the existing configuration settings used by `mqttbroker`.

## How to Write Current Configuration to a Config File?

To save the current configuration to a configuration file, execute the following command:

```bash
mqttbroker --show-config > config_file.conf
```

This command will create a file named `config_file.conf` containing the current configuration settings.

## How Many Server Instances Does MQTT Broker Provide?

### Number of Server Instances
MQTT Broker offers a total of five server instances. These instances are:

1. **legacyin**
   * This is the configuration for the `legacyin` server instance.

2. **tlsin**
   * The `tlsin` server instance configuration is for encrypted communication.

3. **legacyun**
   * The `legacyun` server instance configuration pertains to `legacyun`.

4. **mqtttlswebview**
   * This is the configuration for the `mqtttlswebview` server instance, which involves TLS encryption.

5. **mqttlegacywebview**
   * The `mqttlegacywebview` server instance configuration is for legacy web views.

## What Type of Service Do the Individual Instances Offer?

### Service Types
According to [SNodeC library](https://github.com/SNodeC/snode.c#important-configuration-sections), all individual instances utilize the OpenSSL protocol for secure communication.

## Via Which Protocol Are the Individual Instances Accessible?

### Protocol Utilized
All individual instances rely on the TLS protocol in conjunction with SSL for secure communication.

## Do All Server Instances Offer the Same Configuration Sections (Cathegories)?

### Configuration Consistency
It is challenging to determine if all server instances offer the same configuration sections due to the following error:

```shell
2023-10-31 09:09:51 0000000000001: legacyin: 0.0.0.0:1883: a non-critical error occurred
2023-10-31 09:09:51 0000000000001:     snode.c-0.90/src/core/socket/stream/SocketAcceptor.hpp:87: Address in use [98]
2023-10-31 09:09:51 0000000000001: tlsin: 0.0.0.0:8883: a non-critical error occurred
2023-10-31 09:09:51 0000000000001:     snode.c-0.90/src/core/socket/stream/SocketAcceptor.hpp:87: Address in use [98]
2023-10-31 09:09:51 0000000000001: legacyun: /tmp/mqttbroker: a non-critical error occurred
2023-10-31 09:09:51 0000000000001:     snode.c-0.90/src/core/socket/stream/SocketAcceptor.hpp:87: Address in use [98]
2023-10-31 09:09:51 0000000000001: mqtttlswebview: 0.0.0.0:8088: a non-critical error occurred
2023-10-31 09:09:51 0000000000001:     snode.c-0.90/src/core/socket/stream/SocketAcceptor.hpp:87: Address in use [98]
2023-10-31 09:09:51 0000000000001: mqttlegacywebview: 0.0.0.0:8080: a non-critical error occurred
2023-10-31 09:09:51 0000000000001:     snode.c-0.90/src/core/socket/stream/SocketAcceptor.hpp:87: Address in use [98]
```

## Which Section of the Instances Providing Encrypted Communication, Provides the Configuration Option for SSL/TLS?

### SSL/TLS Configuration


To access SSL/TLS configuration for instances, use the `mqttbroker -a` command. In the `Sections` list, you will find the `tls` section, which provides configuration options for SSL/TLS. These options include settings for X.509 certificates, cipher lists, initialization and shutdown timeouts, and Server Name Indication (SNI) certificates.

For specific configuration details, refer to the `echoserver echo tls --help` command.

Please note that this information is based on the provided data and error messages and may vary depending on your specific MQTT Broker setup.

## What Options Can Be Configured for SSL/TLS Encryption?

The options for configuring SSL/TLS encryption should be documented or can be found using the `mqttbroker --help` command within relevant sections related to SSL/TLS or security configuration.

Please note that the specific commands and options may vary depending on the version and implementation of `mqttbroker`. Always refer to the documentation or utilize the `--help` option for the most up-to-date information.

## What Options Can Be Configured for SSL/TLS Encryption?

The options for configuring SSL/TLS encryption should be documented or can be found using the `mqttbroker --help` command within relevant sections related to SSL/TLS or security configuration.

Please note that the specific commands and options may vary depending on the version and implementation of `mqttbroker`. Always refer to the documentation or utilize the `--help` option for the most up-to-date information.

# Reconfigure the IoT System to use mqttbroker

## Port IoT Scenarios to mqttbroker

For a comprehensive and detailed exposition of this section, please refer to the dedicated section located within [linked here](../../../Jesper%20Hartsuiker/Lab/30-10-2023.md#group-task-add-package-repository-to-openwrt).



# Install XCA on your PC for Certificate Management

This guide will walk you through the process of installing XCA, a certificate management tool, and creating a certificate. XCA is available for various systems, so we will cover the installation steps for Windows, macOS, and Linux.

## Installing XCA

### Windows:
1. Download the XCA installer for Windows from the official website: [XCA for Windows](https://hohnstaedt.de/xca/).
2. Run the installer and follow the on-screen instructions to complete the installation.
3. Start XCA.

### macOS:
1. Download the XCA installer for macOS from the official website: [XCA for macOS](https://hohnstaedt.de/xca/).
2. Open the downloaded DMG file, drag the XCA application to the Applications folder, and then launch it from the Applications folder.
3. Start XCA.

### Linux:
1. XCA may be available in your distribution's software repository. Install it using your package manager. For example, on Ubuntu, you can use the following command:

   ```
   shell
   sudo apt-get install xca
   ```

2. Alternatively, you can download and compile the source code from the XCA website.

## Creating a Certificate in XCA

I followed the steps in the slides. 
After installation of XCA for Certificate Management I created the certificate: 

![Set a Password for the Private Key](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_26.png?raw=true)


# Use the Certificates to Secure Communication with the mqttbroker

## Secure the communication with the mqttbroker
For a comprehensive and detailed exposition of this section, please refer to the dedicated section located within [linked here](../../../Jesper%20Hartsuiker/Lab/31-10-2023.md#install-cert-on-firefox).
gi