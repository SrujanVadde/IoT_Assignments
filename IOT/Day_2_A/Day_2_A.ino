const int LEDR=22,LEDG=23,LEDB=21,ALARAM=19;

void setup() {
  // put your setup code here, to run once:
pinMode(LEDR,OUTPUT);
pinMode(LEDG,OUTPUT);
pinMode(LEDB,OUTPUT);
pinMode(ALARAM,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=0;
for(i=0;i<25;i++)
{
digitalWrite(LEDR,1);
digitalWrite(ALARAM,1);
delay(50);
digitalWrite(LEDR,0);
digitalWrite(ALARAM,0);
delay(50);
i++;
}

delay(1000);
for(i=0;i<25;i++)
{
digitalWrite(LEDG,1);
digitalWrite(ALARAM,1);
delay(50);
digitalWrite(LEDG,0);
digitalWrite(ALARAM,0);
delay(50);
i++;
}
delay(1000);

for(i=0;i<25;i++)
{
digitalWrite(LEDB,1);
digitalWrite(ALARAM,1);
delay(50);
digitalWrite(LEDB,0);
digitalWrite(ALARAM,0);
delay(50);
i++;
}
delay(1000);
}