//#include <HCSR04.h> 
#include <math.h>
#include <Wire.h>
//#include <rgb_lcd.h>
//rgb_lcd lcd;
const int moisturePin = A0;
const int motorPin = 2;
int outputValue;
float soilmoisture;
const int B = 4275;

const int R0 = 10000;



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

  pinMode(2, OUTPUT);
  
 /* lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);*/
  Serial.println("Reading From Sensor ");
  pinMode(motorPin, OUTPUT);
  pinMode(soilmoisture, OUTPUT);


  delay(1000);
}
void loop()
{
   

 

  
 /* 
lcd.setCursor(0, 1);
  lcd.println("Temp= ");
  lcd.print(temperature);*/

  
   outputValue = analogRead(moisturePin);
  outputValue = map(outputValue, 550, 0, 0, 100);
  Serial.print("Moisture : ");
  Serial.print(outputValue);
  Serial.print(" & ");
  delay(1000);

 soilmoisture = readSoil();
  if (soilmoisture >= 450 )
{
  digitalWrite(2, HIGH);

  
}
else  
(digitalWrite(2, LOW));
 }
  
