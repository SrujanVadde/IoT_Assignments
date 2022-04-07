#include<WiFi.h>
#include"ThingSpeak.h"

const char* ssid="Sai_Srujan";
const char* pass="15951a0230";

WiFiClient client;

unsigned long myChannelNumber=1644743;
const char * myWriteAPIKey="ZIF8M8YBD14929RF";
const int ChannelField1=3;

const int trigpin=5;
const int echopin=18;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCM;
float distanceINCH;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
ThingSpeak.begin(client);
WiFi.mode(WIFI_STA);
WiFi.begin(ssid,pass);
if(WiFi.status()!=WL_CONNECTED)
{
  Serial.println("Connecting to Network");
  Serial.println(ssid);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Connected");
}
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin,0);
delay(1);
digitalWrite(trigpin,1);
delayMicroseconds(10);
digitalWrite(trigpin,0);

duration=pulseIn(echopin,1);

distanceCM=duration*SOUND_SPEED/2;
distanceINCH=distanceCM*CM_TO_INCH;

Serial.print("Distance(cm)= ");
Serial.println(distanceCM);
Serial.print("Distance(inch)= ");
Serial.println(distanceINCH);
delay(3000);

ThingSpeak.writeField(myChannelNumber,ChannelField1,distanceCM,myWriteAPIKey);
delay(1000);
}
