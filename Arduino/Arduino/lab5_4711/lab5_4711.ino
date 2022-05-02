#include <Servo.h>    // include Servo library functions 
Servo myservo;        // create servo object to control a servo

int pot_pin = 0;      // analog pin used to connect the potentiometer
int pot_val;          // variable to read the value from the analog pin
int servo_pos;        // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9
  Serial.begin(9600); // initialize serial port
}

void loop() {
  pot_val   = analogRead(pot_pin);           // read value of potentiometer (value from 0 to 1023)
  servo_pos = map(pot_val, 10, 900 , 0, 180); // scale it to control the servo (value from 0 to 180)
  myservo.write(servo_pos);                  // set the servo position according to the scaled value
  delay(250);                                // wait for the servo to get there
  Serial.print(pot_val);                     // print values in serial monitor window
  Serial.print("   ");
  Serial.println(servo_pos);
}
