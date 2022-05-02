const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
float potVoltage;
float dutyCycle;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  potVoltage = (5.0*sensorValue) / 1023.0;
  dutyCycle = (100.0*outputValue) / 255.0;
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:

  Serial.print(potVoltage);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.print(outputValue);
  Serial.print(",");
  Serial.println(dutyCycle);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
