#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "It_Burns_When_IP";
const char* password = "Namreh7256";
const char* mqtt_server = "192.168.12.1";
const char* buzzer_mqtt_topic = "Toni_Pol/megaled/frequency";
const char* led_mqtt_topic = "Toni_Pol/megaled";

const int buzzerPin = 33; // Your buzzer's pin
const int ledPin = 4; // Your LED's pin

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0'; // Null-terminate the payload

  if (strcmp(topic, buzzer_mqtt_topic) == 0) {
    // If the message is on the buzzer topic, adjust the buzzer frequency
    int frequency = atoi((char*)payload);
    tone(buzzerPin, frequency);
  } else if (strcmp(topic, led_mqtt_topic) == 0) {
    // If the message is on the LED topic, adjust the LED brightness
    int brightness = atoi((char*)payload);
    analogWrite(ledPin, brightness);
  }
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
    client.subscribe(buzzer_mqtt_topic);
    client.subscribe(led_mqtt_topic);
    Serial.println("Subscribed to MQTT topics");
  }
  
  // Initialize the LED pin
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 0); // Start with LED off
}

void loop() {
  if (!client.connected()) {
    if (client.connect("esp32-client")) {
      client.subscribe(buzzer_mqtt_topic);
      client.subscribe(led_mqtt_topic);
    }
  }
  client.loop();
}
