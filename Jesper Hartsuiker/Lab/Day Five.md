# Lab Day Five

## Flashing the Mini D1 esp32 with the gateway

first change node.conf
you can find it in demo01/test01
change the default microcontroller to esp32minikit

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/82e117e1-b867-491f-97a3-3631eda52b89)


next do these steps to flash it:
- f2
- advanced
- initialize serial
- yes run

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/ef9c47ee-5e8a-4fd1-b99a-0eaa1f17f54c)

now it is finished after this shows up:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/f2327638-ccf3-42dd-a8cf-ffcfe672adfa)



## New Node

add new note
- f2
- make new node
- yes
- renamed to test 2

- edit setup.cpp

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/5ba9c37d-5cd9-4f2b-a83f-8b656b930329)

- save file and close it

- f2
- advanced
- initialise serial
- yes

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/41d6d45f-aaa0-4a81-9a6d-cf1084f18a5e)

wait till it is finished



need to change the wifi cause it could not connect:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/2a9c87d7-4801-48fe-ab38-f223ec81e632)


![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/3bba9a3f-87ab-41ed-b570-10c9ccf5ffc6)




![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d1569200-d724-4fb4-bcb9-d959cbbb1fcb)


## Node 2

Made a new node in demo01/LedOnOff/MEGALED/

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/e5d81d99-9b74-4d79-b42f-0ccafb8088ee)



![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/2417b517-d98b-45e7-9e59-05878039d3cf)




## Emergency alarm

Build the emergency alarm based on the button press from the first node. The flow for the emergency text and sound is made in Node-Red for the proof of concept.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d2d06ac7-49fa-4630-a734-7b46622e8661)




## Setting up OLED screen.

First we needed to link up the OLED screen to the board. Then needed to make the put the code on the microcontroller. I put the code in demo01/OLED/Screen_text. See the code below:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/57563349-e119-4029-9734-414a7af1b10f)

Upload the code like the previous times. And wait untill it is powered.
Next I sent Hello to the OLED screen with mqtt send:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/8d1d8251-6c6c-4e38-827a-dac6c02c9b96)

Then hello wil pop up on the screenn.




![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/d2d06ac7-49fa-4630-a734-7b46622e8661)






