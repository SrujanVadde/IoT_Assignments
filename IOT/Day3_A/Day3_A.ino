
#include"DHT.h"
#define DHTPIN 21
const int LEDB=22;
const int LEDG=23;
const int LEDR=19;

float temp;
float humi;

DHT dht(DHTPIN,DHT11);


void setup() {
  // put your setup code here, to run once:
pinMode(LEDB,OUTPUT);
pinMode(LEDG,OUTPUT);
pinMode(LEDR,OUTPUT);

Serial.begin(115200);
dht.begin();
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
if(temp<=30)
{
digitalWrite(LEDR,0);
digitalWrite(LEDB,1);
}
if(temp>30)
{
digitalWrite(LEDR,1);
digitalWrite(LEDB,0);
}
if(humi>=60)
{
digitalWrite(LEDG,0); 
}
else if (humi<59)
{
digitalWrite(LEDG,1); 
}
delay(1000);

}
