# Lab Day Three

## Getting the rasberry pi ready by changing settings

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


## Mosquitto send messages

mosquitto_sub --help

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/00fcb56c-2624-4c58-8361-c9bc28b72f4f)

mosquitto_pub --help

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/cc52bc06-8230-4b18-ab5b-aaeb035adb4e)

sending hello world to other client

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/11971cf5-7a61-4a25-9c9d-44ebdef4d613)

receiving hello world on other client

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/cd90102a-da18-463e-8fcc-ee204aae99b2)


## mqtt send messages

listening to mqtt messages:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/2fccaea9-11f9-4a1f-9901-c4d72c7a2797)

sending the message:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d5d52172-f2d3-4a52-a829-e8cb051ec730)

receiving the message:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/14b22983-2904-49c2-b01b-68728fef1209)





## Testing lights on off


```css
from iotknit import *

led1Status = False

init("192.168.12.1")  # use a MQTT broker on localhost

prefix("led")  # all actors below are prefixed with /led

led1 = publisher("led1")  # create a Thingi interface that publishes to led/led1

def button1Callback(msg):
   global led1Status

   print("received: [button]", msg)

   if (msg == "down"):
      led1Status = not led1Status  # toggle status of led

      if (led1Status):
            led1.publish("set", "on")  # publish updated state
            print("sending: [led1]", "on")
      else:
            led1.publish("set", "off")
            print("sending: [led1]", "of")


prefix("button")  # all sensors below are prefixed with /button

button1 = subscriber("button1")  # create a Thingi interface that can have
                                 # subscribes only to button/button1
button1.subscribe_change(callback=button1Callback)

run()  # you can also do a while loop here call process() instead
```
## sending lights off

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/e58b4de3-3146-4441-a64b-eddfa44b1ed3)


![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/768d4f1e-ed69-4ac2-9088-52e29d558850)


![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/7abecf64-9846-4cd3-ba20-08d029f056bf)


## turning ac on and off
```css
from iotknit import *

init("192.168.12.1")  # use a MQTT broker on localhost

prefix("switch")  # all actors below are prefixed with /led

switch = publisher("rl")  # create a Thingi interface that publishes to led/led1

def tempCallback(msg):

    print("received: [temp]", msg)

    try:
        t = int(msg)
    except ValueError:
       return

    if (t >= 25):
        switch.publish("set", "on")  # publish updated state
        print("sending: [rl]", "on")
    elif (t <= 20):
        switch.publish("set", "off")
        print("sending: [rl]", "off")
    else:
        return


prefix("temp-measure")  # all sensors below are prefixed with /button

temp1 = subscriber("temp1")  # create a Thingi interface that can have
                                 # subscribes only to button/button1
temp1.subscribe_change(callback=tempCallback)

run()  # you can also do a while loop here call process() instead
```

## sending high temps

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/7593765e-b8ee-4207-8fe9-0c0b580abfd5)


![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/6f87ecd4-052b-49f7-b59e-0946e597e6e5)


![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/1358d6b6-f175-422c-b6d5-c67073fb325b)




## sending lower temps

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/561d6df1-9bb7-4c61-a5b7-65984ae279ea)


![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/7c5b71a2-3e98-4766-8909-f8539efea6cd)


![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/989c9a36-ee2e-4cd4-8c88-24e82bf9a42f)


## making random temps

make a bash script: sudo nano random_temps.sh
add this code to the script
```css
#!/bin/bash

while true
do
    number=$((RANDOM % 16 + 15))  # Generate random integer between 15 and 30
    mosquitto_pub -h 192.1678.12.1 -t temp-measure/temp1 -m "$number" 
    sleep 10  # Sleep for 10 seconds
done
```
then give the script executable permissions with the command: sudo chmod +x random_temps.sh
to run the script use ./random_temps.sh

then the random number will start to come every 10 seconds:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/237d983c-e058-463f-8429-b9192cbac8e2)

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/b8b0af5e-ef8e-4794-a773-c6230762a015)


