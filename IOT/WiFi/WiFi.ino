	#include <WiFi.h>
  const char* ssid = "Sai_Srujan";
  const char* password =  "15951a0230";

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
}

void loop() {
  // put your main code here, to run repeatedly:

}
