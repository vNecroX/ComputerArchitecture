#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "INFINITUM0F03_2.4";
const char* password = "5327435555";

void setup() {
  Serial.begin(115200);
  delay(10);
  
  // Connect to Wi-Fi network with SSID and password
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop(){

}
