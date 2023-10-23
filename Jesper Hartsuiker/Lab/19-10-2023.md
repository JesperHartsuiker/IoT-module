# Lab 19-10-2023

## Starting Node-Red
I downloaded the Node-Red installation for windows, so I could host the Node-Red page on my own laptop.  

I downloaded the Node-Red installer from this link: https://nodejs.org/en  

Next I opened my cmd in Windows and used this command to finish the Node-Red installation: npm install -g --unsafe-perm node-red  

After the installation is finished to start Node-Red I used the command: node-red. This will now start up Node-Red, and the cmd should not be closed, otherwise the Node-Red session will end. 

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/8464b3b2-4233-40a3-be4f-d6678ffd08d3)

To open Node-Red in the webbrowser, use localhost:1880. This will open the Node-Red gui and here you can make the flows. 
The Node-Red gui is an interactive programmer and I used it to rebuild the same thing I made on day three with Python, but then with no code. In the picture below you can see this code:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/351fdc32-4a95-4cbd-b5f8-6681bb463cee)

- The first pink block is the MQTT reciever. This receives the temperature data from the temperature sensor.
- The switch it up block looks at the temps and spits it up if it is 27 or higher and the other side is lower than 27.
- The turn on and off blocks change the integreter to an on or off command.
- The last pink block is the MQTT sender. This block sends the on or off command to the light switch in the way we made it.

##Sending the Emergency message in Discord using a Bot.

We a Discord bot who would sent emergency in the sandbox channel of the IoTempire channel. This bot is called Emergency Bot - TeamRocket.

Next we started making the flow in Node-Red to sent the message:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/8eecb9f3-fb30-4a2a-935e-c68f260b0b32)

- The pink MQTT receiver is now disconnected, the reason for this is to test if it would work with a virtual button.
- The blue button uses the Node-Red ui to simulate the button presses, this would be done with the pink block if it was connected.
- The yellow filter block makes shure that only one signal is send thru and not multiple signals.
- The purple Discord block sends the emergency message to discord.

In the image below you can see the result if the button was pressed.

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/45b51bc7-a658-4e3e-9842-e5199c76f185)

## Turning a light on and off via Discord with Node-Red.

Next we made a flow that will turn on or off a connected light based on a Discord message. The flow we first made for only the message is seen here:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/ff609bbd-0d62-4aa2-8378-99b9a8579ebb)

- The purple Discord block is to receive messages that are sent in Discord. It responsed to the command "team-rocket-on" or "team-rocket-off".
- The yellow switch block switches the two different command so it can sent on or off to the light, depending on the command.
- The yellow blocks Light set on or Light set off are to change the command to only "on" or "off".
- The pink MQTT sender block sends the message to the microcontroller with the light attached.

## Combining the Discord messages and button input.

Next we combined the sending emergency text flow and turning the light on and off flow. So the Discord bot would say emergency and the light would turn on. Also the commands "team-rocket-on" and "team-rocket-off" can still be used. In the picture below you can see the whole flow:

![image](https://github.com/JesperHartsuiker/IoT-module/assets/82671856/78406615-bf02-4d5e-9c15-5dc971c85b09)

We also recorded the whole interaction of pressing the button, you can see it below:

https://github.com/JesperHartsuiker/IoT-module/assets/82671856/a9573076-f511-4c09-b88a-4ce71d00ab78


















