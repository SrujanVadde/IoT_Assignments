
const int trigpin=5;
const int echopin=18;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCM;
float distanceINCH;
int count=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.print("Intially the value of count is :");
Serial.println(count);
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
if(distanceCM<=10&&distanceCM>=2)
{
  count++;
}
if(distanceCM>10&&distanceCM<30)
{
  count--;
}
Serial.print("The number of persons in the room are :");
Serial.println(count);
delay(3000);
}
