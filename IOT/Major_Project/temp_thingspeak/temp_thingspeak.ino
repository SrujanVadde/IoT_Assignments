#include<WiFi.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include"ThingSpeak.h"



char ssid[]="Sai_Srujan";
char pass[]="15951a0230";

Adafruit_MLX90614 mlx = Adafruit_MLX90614();




WiFiClient client;

unsigned long myChannelNumber=1688880;
const char * myWriteAPIKey="F2JSSKOGN97HX1W1";
const int ChannelField1=3;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
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
mlx.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

int tempc=0,tempf=0;
tempc=mlx.readObjectTempC();
tempf=mlx.readObjectTempF();
Serial.print("Object = ");
Serial.print(mlx.readObjectTempC());
Serial.println("*C");

Serial.print("*F\tObject = ");
Serial.print(mlx.readObjectTempF());
Serial.println("*F");

Serial.println();
Serial.println(tempc);
Serial.println(tempf);

//ThingSpeak.writeField(myChannelNumber,ChannelField1,tempc,myWriteAPIKey);
//delay(1000);
ThingSpeak.writeField(myChannelNumber,ChannelField1,tempf,myWriteAPIKey);
delay(1000);
}
