#include <FiniteStateMachine.h>
#include <Button.h>
#include <LED.h>

// function declarations
void ledOn();
void ledOff();
void ledFadeIn();
void ledFadeOut();
void buzzerOn();
void buzzerOff();

const byte NUMBER_OF_STATES = 6;      //how many states are we cycling through?
const int buzzer = 10;
//initialize states
State On = State(ledOn);
State Off = State(ledOff);
State FadeIn = State(ledFadeIn);
State FadeOut = State(ledFadeOut);
State BuzzOn = State(buzzerOn);
State BuzzOff = State(buzzerOff);

FSM ledStateMachine = FSM(On);        //initialize state machine, start in state: On

Button button = Button(12, PULLDOWN); //initialize the button (wire between pin 12 and ground)
LED led = LED(11);                    //initialize the LED
byte buttonPresses = 0;               //counter variable, holds number of button presses

/********************************************************************************************/

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

/********************************************************************************************/

void loop() {
  if (button.uniquePress()) {
    //increment buttonPresses and constrain it to [ 0, 1, 2, 3 ]
    buttonPresses = ++buttonPresses % NUMBER_OF_STATES;
    switch (buttonPresses) {
      case 0: ledStateMachine.transitionTo(On); break;
      case 1: ledStateMachine.transitionTo(Off); break;
      case 2: ledStateMachine.transitionTo(FadeIn); break;
      case 3: ledStateMachine.transitionTo(FadeOut); break;
      case 4: ledStateMachine.transitionTo(BuzzOn); break;
      case 5: ledStateMachine.transitionTo(BuzzOff); break;
    }
  }
  ledStateMachine.update();
}

/********************************************************************************************/

//state functions

void ledOn() {
  led.on();
  Serial.println("led.On");
}

void ledOff() {
  led.off();
  Serial.println("led.Off");
}

void ledFadeIn() {
  led.fadeIn(250);
  Serial.println("led.fadeIn");
}

void ledFadeOut() {
  led.fadeOut(500);
  Serial.println("led.fadeOut");
}

void buzzerOn()
{
  digitalWrite(buzzer, HIGH);
  Serial.println("buzzer.on");

}
void buzzerOff()
{
  digitalWrite(buzzer, LOW);
  Serial.println("buzzer.off");
}
