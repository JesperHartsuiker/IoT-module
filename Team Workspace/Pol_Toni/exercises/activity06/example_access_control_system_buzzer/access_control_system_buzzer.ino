#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "It_Burns_When_IP";
const char* password = "Namreh7256";
const char* mqtt_server = "192.168.12.1";
const char* mqtt_topic = "Toni_Pol/megaled/frequency";

const int buzzerPin = 33; // Your buzzer's pin

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0'; // Null-terminate the payload

  // Convert the payload to an integer
  int frequency = atoi((char*)payload);

  // Adjust the buzzer beep based on the received frequency
  tone(buzzerPin, frequency); // Use the tone function to set the buzzer frequency
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  if (client.connect("esp32-client")) {
    client.subscribe(mqtt_topic);
    Serial.println("Subscribed to MQTT topic");
  }
}

void loop() {
  if (!client.connected()) {
    if (client.connect("esp32-client")) {
      client.subscribe(mqtt_topic);
    }
  }
  client.loop();
}
