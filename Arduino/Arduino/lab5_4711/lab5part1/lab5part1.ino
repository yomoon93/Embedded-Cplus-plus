#include <Servo.h>
Servo myservo; // create servo object to control a servo
// a maximum of eight servo objects can be created
int pos = 0; // variable to store the servo position

void setup() {
myservo.attach(9); // attaches the servo on pin 9 to the servo object
Serial.begin(9600);
}
void loop() {
for(pos = 700; pos < 2300; pos += 50) // goes from 0 degrees to 180 degrees
{ // in steps of 1 degree
myservo.writeMicroseconds(pos); // tell servo to go to position in variable 'pos'
delay(15); // waits 15ms for the servo to reach the position
Serial.println(pos);
}
for(pos = 2300; pos>=700; pos-=50) // goes from 180 degrees to 0 degrees
{
myservo.writeMicroseconds(pos); // tell servo to go to position in variable 'pos'
delay(15); // waits 15ms for the servo to reach the position
Serial.println(pos);
}
}
