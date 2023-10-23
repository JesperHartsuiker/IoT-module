import time
import random
import paho.mqtt.client as mqtt

led1Status = False
acStatus = None
broker_address = "192.168.12.1"

# Initialize MQTT client
client = mqtt.Client("Simulator")

def on_connect(client, userdata, flags, rc):
    print("Connected with result code: " + str(rc))
    client.subscribe("switch")  # Subscribe to the topic "switch"

def on_message(client, userdata, msg):
    global acStatus
    payload = msg.payload.decode("utf-8")
    try:
        acStatus = bool(payload)
    except ValueError:
        print("Received non-boolean value:", payload)

client.on_connect = on_connect
client.on_message = on_message
client.connect(broker_address)
client.loop_start()

def temp_simulator():
    return random.randint(15, 35)

while True:
    random_temp = temp_simulator()

    if acStatus is not None: 
        print(f"Current Temperature: {random_temp}°C, AC is {'On' if acStatus else 'Off'}")
    else: 
        print(f"Current Temperature: {random_temp}°C, AC status is not available.")

    time.sleep(5)
