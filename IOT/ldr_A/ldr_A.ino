const int ldr=13;
const int led=21;
int val;
void setup() {
Serial.begin(115200);
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(ldr);
Serial.println(val);
//delay(1000);

if(val<=2000)
{
  digitalWrite(led,0);
  delay(1000);
}
else
{
  digitalWrite(led,1);
  delay(1000);
}

}
