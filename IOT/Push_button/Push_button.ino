const int push_button=22;
const int buzzer=21;
void setup() {
  // put your setup code here, to run once:
pinMode(push_button,INPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int i,val=0;
val=digitalRead(push_button);
Serial.println(val);
if(val==1)
{
  for(i=0;i<20;i++)
  {
    digitalWrite(buzzer,1);
    delay(250);
    digitalWrite(buzzer,0);
    delay(250);
  }

}
delay(1000);
}
