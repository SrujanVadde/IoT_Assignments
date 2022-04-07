const int ALARAM=23;
void setup() {
  // put your setup code here, to run once:
pinMode(ALARAM,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ALARAM,HIGH);
delay(50);
digitalWrite(ALARAM,LOW);
delay(50);
}
