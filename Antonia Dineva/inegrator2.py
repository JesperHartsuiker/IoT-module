from iotknit import *
import time
import random
import paho.mqtt.client as mqtt


led1Status = False
# acStatus = False
acStatus = None


# init("192.168.12.1")  # Connect to the MQTT broker with the appropriate IP address

broker_address = "192.168.12.1"

prefix("switch")  # all actors below are prefixed with /led

switch = publisher("rl")  # create a Thingi interface that publishes to led/led1

def on_connect(client, userdata, flags, rc):
    print("Connected with result code: " + bool(rc))
    client.subscribe(prefix)

def on_message(client, userdata, msg):
    global acStatus  
    payload = msg.payload.decode("utf-8")
    try:
        acStatus = bool(payload)  
    except ValueError:
        print("Received non-boolean value:", payload)


client = mqtt.Client("Simulator")
client.on_connect = on_connect
client.on_message = on_message

client.connect(broker_address)
client.loop_start()


# def tempCallback(msg):
#     # global acStatus

#     print(f"temp-measure/temp1 {msg}")

#     try:
#         t = float(msg)
#     except ValueError:
#         return

#     if t >= 25 and not acStatus:
#         switch.publish("set", "on")  # publish updated state
#         print(f"switch/rl/set on")
#         acStatus = True
#     elif t <= 20 and acStatus:
#         switch.publish("set", "off")
#         print(f"switch/rl/set off")
#         acStatus = False
#     else:
#         return

def temp_simulator():
    random_temp = random.randint(15, 35)

    message = "The current temperature is: " + str(random_temp)
    client.publish("r1", message.c_str())
    time.sleep(5)

# prefix("temp-measure")  # all sensors below are prefixed with /button

# temp1 = subscriber("temp1")  # create a Thingi interface that can have
#                              # subscribes only to button/button1
# temp1.subscribe_change(callback=tempCallback)

# Simulating temperature change from command prompt
while True:
    # if acStatus is not None:
    #     print(f"{random_temp}/on")
    # else:
    #     print(f"{random_temp}/off")

    if acStatus is not None: 
        print("Air conditioning is: " + acStatus)
    else: 
        print("Air conditioning is: " + acStatus)


    # user_input = input("Enter the current temperature or 'exit' to quit: ")
    # if user_input.lower() == 'exit':
    #     break
    # try:
    #     tempCallback(user_input)  # Simulate the received temperature message
    # except ValueError:
    #     print("Please enter a valid temperature value.")
    # sleep(2)

    # Simulating random temperature change

    # random_temp = random.randint(15, 35)  # Set the random number between 15 and 35
    # print(f"temp-measure/temp1 {random_temp}")
    # tempCallback(str(random_temp))  # Simulate the received temperature message

    run()  # You can also do a while loop here; call process() instead
