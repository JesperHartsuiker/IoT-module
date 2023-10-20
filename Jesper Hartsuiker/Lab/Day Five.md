# Lab Day Five

## Flashing the Mini D1 esp32 with the gateway
We started the day with all the esp32's not working. So we had to flash them from the templates that were online. These were the steps we took:
- First we needed to change node.conf.
- It is located in the directory: demo01/test01.
- We changed the default microcontroller to esp32minikit.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/82e117e1-b867-491f-97a3-3631eda52b89)

After it was saved we needed to flash the microcontrollers. These are the steps we took to flash the esp32's:
- Go to F2.
- Click on Advanced.
- Next initialize serial.
- Click on yes and start the flashing process.

Now the flashing process wil start automatically.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/ef9c47ee-5e8a-4fd1-b99a-0eaa1f17f54c)

If the flashing process is finished you will see this:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/f2327638-ccf3-42dd-a8cf-ffcfe672adfa)



## New Node
The first assignment of the day was to make a button with IoTempower and it would post with MQTT.

In the start we need to add a new node. These are the steps we took to make it work:
- Go to F2,
- Click on make new Node folder.
- Press YES.
- We renamed our directory to ButtonLED.

Next we got our code from the example dictionary of IoTempire gateway. This code needed to be put into the setup.cpp file. We can do this by editing the setup.cpp file.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/5ba9c37d-5cd9-4f2b-a83f-8b656b930329)

Next we can save the file and close it. Then we need to upload it to the microcontroller again. This is done the same way as in Flashing the Mini D1 esp32 with the gateway.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/41d6d45f-aaa0-4a81-9a6d-cf1084f18a5e)

Once started it, wait till the upload is complete and close the window.

When we tried to pickup some MQTT signals we found out that it wasn't sending anything to the MQTT broker because of the WiFi. We found out in a SSH session:
![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/2a9c87d7-4801-48fe-ab38-f223ec81e632)

So we changed the wifi settings to our WiFi and the MQTT broker IP. This was done in the directory demo01/system.conf.

![Alt text](Images/image.png)

After we saved the file and resubmitted the code, and now we get MQTT signals when we press the button.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d1569200-d724-4fb4-bcb9-d959cbbb1fcb)


## Node 2
Next we needed to make a second Node that will turn on a light via MQTT on a different esp32. So we made a new node. We made it in a new directory: demo01/LedOnOff/MEGALED/.
Next we edited the setup.cpp file to turn on and off a light on a breadboard.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/e5d81d99-9b74-4d79-b42f-0ccafb8088ee)

Next we needed to make a flow in Node-Red, where the input should switch the LED on or off when the button is pressed. The flow below showcases how this wil work. The toggle button will keep the light on after one press and then turn it off after another button press.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/2417b517-d98b-45e7-9e59-05878039d3cf)

This video will showcase this:

![Alt text](videos/IMG_9913.mp4)

## Emergency alarm
The next assigment was to play a sound and a notification if the button is pressed. We build the emergency alarm based on the button press from the first node.

Flow for the emergency text and sound is made in Node-Red for the proof of concept. Part d: Button to Sound Notification is the part of this assignment in the flow below.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d2d06ac7-49fa-4630-a734-7b46622e8661)

If the button is pressed, it wil send a notification to a dashboard which will say Emergency for 5 seconds. Also a sound will be played: "Emergency!" From the speaker.


## Setting up OLED screen.
The last assignment was to use the OLED screen we got and print a message on the screen.

First we needed to link up the OLED screen to the board. And needed to make the directory to put the code on the microcontroller. we put the code in demo01/OLED/Screen_text. See the code below:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/57563349-e119-4029-9734-414a7af1b10f)

Upload the code like the previous times. And wait untill it is powered.
Next we sent Hello to the OLED screen with mqtt send:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/8d1d8251-6c6c-4e38-827a-dac6c02c9b96)

Then hello wil pop up on the screen.

![IMG_9917](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/a948b3f3-4a7f-481a-b061-e573086a1783)

We also made the assignment a bit bigger than needed and we added the button from the first node to the assignment. So if the button was pressed it will sent Emergency! to the OLED screen. In the flow below at e: Text Receiver, you can see the flow we made to sent Emergency! to the OLED screen.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d2d06ac7-49fa-4630-a734-7b46622e8661)

Look at the picture below that it says Emergency! on the screen multiple times.

![IMG_9916](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/df599e3c-d33d-4a61-9394-1e50f08a8662)

In this video you can also see the result if the button is pressed.

<video src="videos/IMG_9914.mp4" controls title="Title"></video>
