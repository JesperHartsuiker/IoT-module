# Research records 10

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://discord.com/channels/1064132619735928932/1163216523062689862/1168288756017668187).

# Exploring SSL/TLS Configuration Options for mqttbroker

In this guide, we will investigate SSL/TLS configuration options for `mqttbroker`. Ensure that you have `mqttbroker` installed and accessible via the command line.

## How to Request a Full "Template" Command Line for `mqttbroker`?

To obtain a full command line template and usage information for `mqttbroker`, run the following command:

```bash
mqttbroker --help
```

This command will provide a comprehensive list of available options and instructions for using `mqttbroker`.

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
To access SSL/TLS configuration for instances, use the `mqqtbroker -a` command. In the `Sections` list, you will find the `tls` section, which provides configuration options for SSL/TLS. These options include settings for X.509 certificates, cipher lists, initialization and shutdown timeouts, and Server Name Indication (SNI) certificates.

For specific configuration details, refer to the `echoserver echo tls --help` command.

Please note that this information is based on the provided data and error messages and may vary depending on your specific MQTT Broker setup.

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

   ```shell
   sudo apt-get install xca
   ```

2. Alternatively, you can download and compile the source code from the XCA website.

## Creating a Certificate in XCA

This guide offers a step-by-step walkthrough for creating a certificate using XCA, an essential tool for certificate management. We will cover the process of setting up a Root Certificate Authority (CA) and generating an End Entity certificate for MQTT Broker.

## Step 1: Launch XCA
Begin by opening the XCA application on your system.

## Step 2: Create a New Database
1. Access the `File` menu.
2. Choose the `Create a new Database` option.

## Step 3: Generate a New Certificate
1. Click the `New Certificate` button.

## Step 4: Configure Certificate Template
1. In the `Template for the new certificate` section, select `[default] CA`.
2. Confirm your choice by clicking `Apply all`.

![Configure Certificate Template](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_1.png?raw=true)

## Step 5: Define Subject Information
1. Navigate to the `Subject` section.
2. Configure the subject details as per your requirements.

![Subject Configuration](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_2.png?raw=true)

## Step 6: Generate a New Key
1. In the same menu, locate the `Generate a new key` button.
2. Set the `Keysize` to a secure 8192 bits.
3. Initiate the key generation process by clicking `Create`.

![Key Generation](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_3.png?raw=true)

## Step 7: Confirmation of Private Key Generation
1. A pop-up notification should appear, confirming the successful creation of the RSA private key, e.g., `'Root CA - GA in IT'`.
2. Acknowledge this confirmation by pressing `OK`.

![Private Key Confirmation](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_success_4.png?raw=true)

## Step 8: Select the Private Key
1. Opt to `Use keys too`.
2. The private key, such as `'Root CA - GA in IT'` should be visible in the list.

![Select the Private Key](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_5.png?raw=true)

## Step 9: Configure Certificate Extensions
![Extensions Configuration](image_url_for_step_9)
1. Verify that your `Extensions` menu resembles the provided image.
2. Ensure that the `Critical` and `X509v3 Subject Key Identifier` options are selected.

![Configure Certificate Extensions](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_6.png?raw=true)

## Step 10: Key Usage and Advanced Configuration
1. Confirm that your `Key Usage` menu matches the image provided.

![Key Usage Configuration](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_7.png?raw=true)

2. Confirm that your `Advanced` menu matches the image provided.

![Advanced Configuration](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_8.png?raw=true)

## Step 11: Confirm and Save
1. Verify the configured settings.
2. Press `OK`.
3. Expect a pop-up message affirming the successful creation of the certificate (e.g., `'Root CA - GA in IT'`). Acknowledge it by pressing `OK`.

![Configure Certificate Extensions](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_9.png?raw=true)

## Step 12: Export the Certificate
1. Navigate to the `Private Keys` menu and confirm the presence of your private key.

![Export the Certificate](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_10.png?raw=true)

## Step 13: Create an End Entity Certificate
1. Return to the `Certificates` menu.

![Certificates List Menu](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_11.png?raw=true)

2. Choose the `Export` option in the right menu.

## Step 14: Configure the Export Settings
1. Configure the export settings, as demonstrated in the image.
2. If `Export Format` is not available, set it to `PEM (*.crt)`.
3. Indicate the file's destination.
4. Confirm your selections by clicking `OK`.

![Export the Certificate Settings](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_12.png?raw=true)

## Step 15: Close the Export Menu
1. The export menu should close.

## Step 16: Generate a New Certificate (End Entity)
1. Select `New Certificate` from the right menu.
2. Replicate the properties established in the previous certificate.
3. Modify the Internal Name to `'End Entity - GA in IT - MQTT Broker'`.

![Generate a New Certificate (End Entity)](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_13.png?raw=true)

## Step 17: Generate a New Key
1. Click the `Generate a new key` button.
2. Set the `Keysize` to a secure 8192 bits.
3. Initiate the key creation process by clicking `Create`.

![Generate a New Key](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_14.png?raw=true)

## Step 18: Confirmation of Private Key Generation
1. Anticipate a confirmation pop-up, indicating the successful creation of the RSA private key (e.g., `'End Entity - GA in IT - MQTT Broker'`). Confirm this notification by pressing `OK.`

![Private Key Confirmation (End Entity)](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_15.png?raw=true)

## Step 19: Configure Extensions
1. Validate that your `Extensions` menu matches the provided image.
2. Select both the `Critical` and `X509v3 Subject Key Identifier` options.
3. Adjust the `Time Range` to a secure 365 Days.
4. Customize the `X509v3 Subject Alternative Name` to `DNS:copycn`.

![Extensions Configuration (End Entity)](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_17.png?raw=true)

![Advanced Configuration (End Entity)](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_18.png?raw=true)

## Step 20: Advanced Configuration

1. Confirm that your `Advanced` menu corresponds to the demonstrated image.

![Advanced Configuration (End Entity) 1](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_19.png?raw=true)

![Advanced Configuration (End Entity) 2](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_20.png?raw=true)

## Step 21: Confirm and Save (End Entity)
1. Verify the configured settings.
2. Press `OK.`
3. Expect a pop-up message confirming the successful creation of the certificate (e.g., `'End Entity - GA in IT - MQTT Broker'`). Acknowledge it by pressing `OK.`

![Confirm and Save (End Entity)](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_21.png?raw=true)

## Step 22: Verify the New Certificate
1. An additional certificate should appear in the `Certificates` menu.

![Verify the New Certificate](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_22.png?raw=true)

## Step 23: Export the Certificate
1. Click the `Export` button in the right menu.

![Export the Certificate](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_23.png?raw=true)

## Step 24: Configure the Export Settings for the Certificate
1. Configure the export settings, as demonstrated in the image.
2. Ensure the export format is `PEM chain (*.pem)`.
3. Indicate the file's destination.
4. Confirm your selections by clicking `OK`.

## Step 25: Export Private Key
1. Visit the `Private Keys` menu.
2. Click the `Export` button in the right menu.

![Export Private Key](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_24.png?raw=true)

## Step 26: Configure the Export Settings for the Private Key
1. Configure the export settings, as demonstrated in the image.
2. Ensure the export format is `PEM encrypted (*.pem)`.
3. Indicate the file's destination.
4. Confirm your selections by clicking `OK.`

![Export the Certificate](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_25.png?raw=true)

## Step 27: Set a Password for the Private Key
1. A password prompt will appear.
2. Enter a secure password.
3. Confirm your password choice by clicking `OK.`

![Set a Password for the Private Key](https://github.com/JesperHartsuiker/IoT-module/blob/main/Team%20Workspace/Pol_Toni/pictures/activity10/create_certificate/create_certificate_menu_26.png?raw=true)

## Step 28: Completion of the Process
You now possess the three essential files required for creating a certificate.

Congratulations! You have successfully created the Root CA and an End Entity certificate for MQTT Broker using XCA.

Please note that these instructions are provided as a general guide. The specific steps may vary depending on your requirements and the version of XCA you are using, in our case, 2.5.0 version. For more detailed information and advanced configurations, refer to the official XCA documentation and resources.



# Use the Certificates to Secure Communication with the mqttbroker

## Secure the communication with the mqttbroker
For a comprehensive and detailed exposition of this section, please refer to the dedicated section located within [linked here](../../../Jesper%20Hartsuiker/Lab/31-10-2023.md#install-cert-on-firefox).
