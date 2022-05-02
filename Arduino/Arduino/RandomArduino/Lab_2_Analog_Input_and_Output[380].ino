/*** header block ***
   code file name
   code description
   hardware required
   IDE version used to test code
   programmer(s) name
   date when code is created/modified
   code version
 ***/

// pre-processor directives

// pin name definitions
#define led 9
// class/object declarations

// global variables


void setup () {
  // configure hardware peripherals
pinMode(led, OUTPUT);
  // configure data communication
Serial.begin(9600);
  // code that runs only once

}

void loop () {
  // data input  and storage
  int sensorValue = analogRead(A0);


  // data processing

  int brightness = sensorValue >> 2;

  // data output
  analogWrite(led, brightness);
  // data communication
  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.println(brightness);
}

// user defined functions
