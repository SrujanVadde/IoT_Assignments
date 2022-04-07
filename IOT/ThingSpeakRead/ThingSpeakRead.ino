#include<WiFi.h>
#include"ThingSpeak.h"


const int ledRED=19;
char ssid[]="Sai_Srujan";
char pass[]="15951a0230";


float data=0;

WiFiClient client;

unsigned long myChannelNumber=1653917;
const char * myreadAPIKey="M87HIERN5FCXHVVV";
const int ChannelField1=1;
const int ChannelField2=2;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ledRED,OUTPUT);
ThingSpeak.begin(client);
WiFi.mode(WIFI_STA);
WiFi.begin(ssid,pass);
if(WiFi.status()!=WL_CONNECTED)
{
  Serial.println("Connecting to Network");
  Serial.println(ssid);
  while(WiFi.status()!=WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected");
}
}

void loop() {
  // put your main code here, to run repeatedly:
data = ThingSpeak.readFloatField(myChannelNumber,ChannelField1,myreadAPIKey); 
Serial.print("Data read from ThingSpeak is:");
Serial.println(data);
if(data<40)
{
  digitalWrite(ledRED,1);
}
else
{
  digitalWrite(ledRED,0);
}

}
