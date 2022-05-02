int redPin = 11;
int greenPin = 12;
int bluePin = 13;
int pushbutton = 2;

void setup() {

  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(pushbutton, INPUT);
}


void loop() {
  int buttonstate = digitalRead(pushbutton);
  if (buttonstate == 1)
  {
    digitalWrite(greenPin, HIGH);
    delay(5000);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(1000);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, HIGH);
    delay(5000);
    digitalWrite(redPin, LOW);

  }
  else
  { digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    Serial.println(buttonstate);
    delay(1000);

  }

}
