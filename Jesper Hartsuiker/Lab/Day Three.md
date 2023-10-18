
turned off the raspberry pi router
poweroff on raspberry pi
changed the router LAN adress to 192.168.12.254
powered the raspberry pi on again
in the router settings added a static IP adress for the raspberry pi (192.168.12.1)
via ssh in the raspberry pi used sudo reboot.
now the raspberry pi has a IP address to (192.168.12.1)

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/357fd639-5e94-4b62-93b2-a21bccd7d7d4)


to get in the raspberry pi for the mqtt mosquitto settings, we need to have ssh.
below you can see the ssh session

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/b5cf1568-c924-4b98-946c-7529974d2674)


mosquitto_sub --help

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/00fcb56c-2624-4c58-8361-c9bc28b72f4f)

mosquitto_pub --help

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/cc52bc06-8230-4b18-ab5b-aaeb035adb4e)

sending hello world to other client

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/11971cf5-7a61-4a25-9c9d-44ebdef4d613)

receiving hello world on other client

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/cd90102a-da18-463e-8fcc-ee204aae99b2)


#mqtt send messages

listening to mqtt messages:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/2fccaea9-11f9-4a1f-9901-c4d72c7a2797)

sending the message:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d5d52172-f2d3-4a52-a829-e8cb051ec730)

receiving the message:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/14b22983-2904-49c2-b01b-68728fef1209)
