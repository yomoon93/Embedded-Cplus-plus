int pushbutton = 2;
int led = 13;
int light = 9;
int potPin = A1;

//Push button

int brightness;

void setup
() {
  Serial.begin(9600);
  pinMode(pushbutton, INPUT);
  pinMode(led, OUTPUT);
  pinMode(light, OUTPUT);


}
void loop()
{
  int buttonState = digitalRead(pushbutton);
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite (led, LOW);
  }

  int sensorvalue = analogRead(potPin);
  Serial.println(sensorvalue);
  delay(100);

  brightness = sensorvalue >> 2;
  analogWrite(light, brightness);


}




