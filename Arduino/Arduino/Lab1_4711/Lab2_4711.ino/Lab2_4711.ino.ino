int led=9;
int brightness=0;
int fadeAmount=5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorValue=analogRead(A0);
Serial.println(sensorValue);

delay(1000);
brightness = sensorValue >> 2;
analogWrite(led,brightness);
//brightness=brightness+fadeAmount;

//if(brightness==0||brightness==255) {
  //fadeAmount=-fadeAmount;
  
//}
//brightness = sensorValue >> 2;
delay (30);
}
