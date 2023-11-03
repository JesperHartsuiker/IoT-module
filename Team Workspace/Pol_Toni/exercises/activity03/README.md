Before we started the exercises, we had to fix the raspberry pi that was crashing a lot with sending the WIFI network. We could not work fully until it was fixed. So after a talk with the teacher, we decided to turn off the WiFi part from the raspberry. This is how we did it after Ulrich was done with changing the raspberry pi settings:

1. Shut down the Raspberry Pi router and then powered it back on.

2. After that, I modified the router LAN address to 192.168.12.254.

3. Upon restarting the Raspberry Pi, I went into the router settings and assigned a static IP address (192.168.12.1) for the Raspberry Pi.

4. I accessed the Raspberry Pi via SSH and used the command "sudo reboot".

5. Now, the Raspberry Pi is assigned the IP address 192.168.12.1.

![Alt text](../../pictures/activity03/raspberrypi_fix.png)

First exercise

After completing the configuration of the Raspberry Pi, it now has an assigned IP address, which is 192.168.12.1. This IP address is like a unique identifier that allows us to connect to and communicate with the Raspberry Pi on our network.

To set up the MQTT Mosquitto settings on our Raspberry Pi, we need to use SSH. SSH enables us to access our Raspberry Pi remotely, so we can configure the MQTT Mosquitto settings.


![Alt text](../../pictures/activity03/mosquitto1.png)

To access the message subscription options of Mosquitto, simply use the following command in your terminal:

To access the message subscription options of Mosquitto, simply use the following command in your terminal:

```bash
mosquitto_sub --help
```

Executing this command will present a comprehensive list of available parameters and usage guidelines, facilitating the effective subscription to MQTT messages.

![Alt text](../../pictures/activity03/mosquitto2.png)

To access Mosquitto's message publishing options, you can employ the following command in your terminal:

```bash
mosquitto_pub --help
```

Running this command will provide a detailed list of available parameters and usage instructions, making it straightforward to publish messages using MQTT.

