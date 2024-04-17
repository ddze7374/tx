#include <WiFi.h>
#include <PubSubClient.h>
const char *ssid = "SSID";						// change this
const char *password = "wi-fi_password";		// change this
const char *mqtt_broker = "broker.hivemq.com";	// you may change this 
const char *topic = "my/test";					// you need to change this too
const char *mqtt_username = "";
const char *mqtt_password = "";
const int mqtt_port = 1883;						// use other port (8883) if TLS secure connection
const char* ca_cert="";							// change this whenusing TLS
WiFiClient espClient;
PubSubClient client(espClient);

// you need to arrange the behaviour of your device here when it receives the message from sensor or other clients
void cbReceiveMsg(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {Serial.print((char) payload[i]);}
    Serial.println("\n-----------------------");
}
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(cbReceiveMsg);
  while (!client.connected()) {
    String client_id = "test-client";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
        Serial.println("MQTT broker connected");
    } else {
        Serial.print("failed with state ");
        Serial.print(client.state());
        delay(2000);
    }
  }
    // example how to publishing a message
    client.publish(topic, "Hello there.");
    client.subscribe(topic);
}
void loop() {
  client.loop();
  // here you will need to add instruction when sending (publishing) data to subscribers
}
