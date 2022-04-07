#include<WiFi.h>
#include"ThingSpeak.h"

char ssid[]="Sai_Srujan";
char pass[]="15951a0230";

const int ledRED=19;
const int ledGREEN=21;
const int ledBLUE=22;
const int buzzer=23;
int pirinput = 25;             
int pirState = LOW;             
int val = 0;  



const int trigpin=5;
const int echopin=18;
int i=0;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCM;
float distanceINCH;

WiFiClient client;

unsigned long myChannelNumber=1644743;
const char * myWriteAPIKey="ZIF8M8YBD14929RF";
const int ChannelField1=1;
const int ChannelField2=2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
pinMode(ledRED,OUTPUT);
pinMode(ledBLUE,OUTPUT);
pinMode(ledGREEN,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(pirinput, INPUT);

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
if(distanceCM>=100)
{
  digitalWrite(ledGREEN,1);
  digitalWrite(ledRED,0);
  digitalWrite(ledBLUE,0);
}
else if(distanceCM>40&&distanceCM<100)
{
  digitalWrite(ledGREEN,0);
  digitalWrite(ledRED,0);
  digitalWrite(ledBLUE,1);

}
else if(distanceCM<=40)
{
  digitalWrite(ledGREEN,0);
  digitalWrite(ledRED,1);
  digitalWrite(ledBLUE,0);
  for(i=0;i<=5;i++)
  {
    digitalWrite(buzzer,1);
    delay(30);
    digitalWrite(buzzer,0);
    delay(30);

  }
  
}
val=digitalRead(pirinput);
if(val==HIGH)
{
  Serial.println("Motion detected!");
}

if(distanceCM<=40&&val==HIGH)
{
ThingSpeak.writeField(myChannelNumber,ChannelField1,distanceCM,myWriteAPIKey);
//delay(1000);  
}

delay(3000);


}
