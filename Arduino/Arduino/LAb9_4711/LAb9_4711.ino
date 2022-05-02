const int pingTrig = A0;
const int pingEcho = A1;
int LED_Red = 9;
int LED_Green = 10;
int LED_Blue = 11;
void setup() {
  // initialize serial communication
  Serial.begin(9600);
  // initialize sensor pins
  pinMode(pingTrig, OUTPUT);
  pinMode(pingEcho,  INPUT);
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches:
  long duration, inches;

  int led_brightness = 0;

  // The HC-SR04 is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse
  digitalWrite(pingTrig,  LOW);
  delayMicroseconds( 5);
  digitalWrite(pingTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingTrig,  LOW);

  // The Echo pin is used to read the signal from HC-SR04; a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
 
  duration = pulseIn(pingEcho, HIGH);
  
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  inches = constrain(inches, 2, 22);

//  led_brightness = map(inches, 2, 22, 0, 255);

  if (inches >= 2 && inches <= 8) {
     digitalWrite(LED_Red, HIGH);
     digitalWrite(LED_Green, LOW);
  }
  else if (inches >= 9 && inches <= 15) {
     digitalWrite(LED_Green, HIGH);
     digitalWrite(LED_Red, HIGH);
  }
  else if (inches >= 16 && inches <= 22){
     digitalWrite(LED_Green, HIGH);
     digitalWrite(LED_Red, LOW);
  }
  else {
    digitalWrite(LED_Green, LOW);
     digitalWrite(LED_Red, LOW);
  }
//  analogWrite(LED_Red, led_brightness);
  Serial.println(inches);
  
  delay(500);
}

long microsecondsToInches(long microseconds)
{
  // According to datasheet for the Ping sensor, there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second). Dividing by 74 gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.

  return microseconds / 74 / 2;
}
