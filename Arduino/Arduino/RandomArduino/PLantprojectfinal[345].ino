//#include <HCSR04.h>
#include <math.h>
#include <Wire.h>
//#include <rgb_lcd.h>
//rgb_lcd lcd;
const int moisturePin = A2;
const int motorPin = 7;
int outputValue;
float soilmoisture;
const int B = 4275;

const int R0 = 100000;
//const int pinTempSensor = A2;
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const int trigPin = A0;
const int echoPin = A1;
float duration, distance;
int readSoil()
{
  soilmoisture = 0;
  delay(10);
  soilmoisture = analogRead(moisturePin);
  Serial.println(soilmoisture);
  return soilmoisture;
}
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, OUTPUT);

  //  lcd.begin(16, 2);
  //  lcd.setRGB(colorR, colorG, colorB);
  Serial.println("Reading From Sensor ");
  pinMode(motorPin, OUTPUT);
  pinMode(soilmoisture, OUTPUT);


  delay(1000);
}
void loop()
{
  //   int a = analogRead(pinTempSensor);

  //  float R = 1023.0/a-1.0;
  //  R = R0*R;
  //
  //  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  //
  //lcd.setCursor(0, 1);
  //  lcd.println("Temp= ");
  //  lcd.print(temperature);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.println("The distance to Water in front of us is: ");
  Serial.println(distance);
  delay(1000);

  outputValue = analogRead(moisturePin);
  Serial.println(outputValue);
  Serial.println("Moisture : ");
  outputValue = map(outputValue, 710, 0, 0,1000 );
  //  Serial.print(outputValue);
//  Serial.println("Moisture : ");
  //  Serial.print(outputValue);
//  Serial.println("& ");
  delay(1000);

  soilmoisture = readSoil();
  if (soilmoisture >= 700)
  {
    digitalWrite(7, HIGH);


  }
  else (digitalWrite(7, LOW));
}
