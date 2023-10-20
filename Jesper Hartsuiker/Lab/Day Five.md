# Lab Day Five


making iot documentation an serving it with the commands

```css
iot doc make
iot doc serve
```
look at the picture below for the commands:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/4fd87916-b409-468a-af35-22cb2d7880ea)


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
