#include <FiniteStateMachine.h>
#include <Button.h>

const byte NUMBER_OF_STATES = 5;   //how many states are we cycling through?

//state function declarations
void One_fn();
void Two_fn();
void Three_fn();
void Four_fn();
void Five_fn();

//initialize states
State One    = State(One_fn);
State Two    = State(Two_fn);
State Three  = State(Three_fn);
State Four   = State(Four_fn);
State Five   = State(Five_fn);

FSM FSM_RGB_LED = FSM(One);           //initialize state machine, start in state: One

Button button = Button(A3, PULLDOWN); //initialize the button (or touch sensor)
byte buttonPresses = 0;               //counter variable, holds number of button presses

// define LED pins
#define ledRed    9
#define ledGreen 10
#define ledBlue  11

const int analogInPin1 = A0;
const int analogInPin2 = A1;
const int analogInPin3 = A2;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

int outputValue1 = 0;
int outputValue2 = 0;
int outputValue3 = 0;

void setup() {
  pinMode(ledRed,   OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue,  OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  sensorValue3 = analogRead(analogInPin3);

  outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
  outputValue2 = map(sensorValue2, 0, 1023, 0, 255);
  outputValue3 = map(sensorValue3, 0, 1023, 0, 255);

  if (button.uniquePress()) {
    //increment buttonPresses and constrain it to [ 0, 1, 2, 3 ]
    buttonPresses = ++buttonPresses % NUMBER_OF_STATES;

    switch (buttonPresses) {
      case 0: FSM_RGB_LED.transitionTo(One);   break;
      case 1: FSM_RGB_LED.transitionTo(Two);   break;
      case 2: FSM_RGB_LED.transitionTo(Three); break;
      case 3: FSM_RGB_LED.transitionTo(Four);  break;
      case 4: FSM_RGB_LED.transitionTo(Five);  break;
    }
  }
  FSM_RGB_LED.update();
}

//state functions
void One_fn()   {
  analogWrite(ledRed,   outputValue1);
  analogWrite(ledGreen,   outputValue2);
  analogWrite(ledBlue, LOW);
  Serial.println("State: One");
}

void Two_fn()   {
  analogWrite(ledGreen,   outputValue2);
  analogWrite(ledRed, LOW);
  analogWrite(ledBlue, outputValue3);
  Serial.println("State: Two");
}

void Three_fn() {
  analogWrite(ledRed,  outputValue1);
  analogWrite(ledGreen,   LOW);
  analogWrite(ledBlue, outputValue3);
  Serial.println("State: Three");
}

void Four_fn()  {
  analogWrite(ledRed,   outputValue1);
  analogWrite(ledGreen, outputValue2);
  analogWrite(ledBlue,  outputValue3);
  Serial.println("State: Four");
}
void Five_fn()
{
  digitalWrite(ledRed,   LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue,  LOW);
  Serial.println("State: Five");
}
