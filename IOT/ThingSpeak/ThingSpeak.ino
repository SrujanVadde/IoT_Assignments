#include<WiFi.h>
#include"DHT.h"
#include"ThingSpeak.h"



char ssid[]="Sai_Srujan";
char pass[]="15951a0230";

#define DHTPIN 21

float temp;
float humi;

DHT dht(DHTPIN,DHT11);
WiFiClient client;

unsigned long myChannelNumber=1644743;
const char * myWriteAPIKey="ZIF8M8YBD14929RF";
const int ChannelField1=1;
const int ChannelField2=2;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
dht.begin();
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


temp=dht.readTemperature();
humi=dht.readHumidity();

if(isnan(temp)||isnan(humi))
{
  Serial.println("Failed to read the values");
}
Serial.print(F("Temperature : "));
Serial.print(temp);

Serial.print(F("   Humidity: "));
Serial.print(humi);
Serial.println("%");
//delay(10000);
ThingSpeak.writeField(myChannelNumber,ChannelField1,temp,myWriteAPIKey);
delay(1000);
ThingSpeak.writeField(myChannelNumber,ChannelField2,humi,myWriteAPIKey);
delay(1000);
}
