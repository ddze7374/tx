#include <WiFi.h>

const char *ssid = "TEST_AP";    
const char *password = "test1234";
WiFiClient espClient;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // Connecting to a Wi-Fi network
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected with an IP: ");
  Serial.println(WiFi.localIP()); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
