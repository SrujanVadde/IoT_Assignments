const int LED=22;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED,HIGH);
Serial.print("LED ON\n");
delay(200);

digitalWrite(LED,LOW);
Serial.print("LED OFF\n");
delay(200);
}
