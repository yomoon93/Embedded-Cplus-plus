//const int sensorMin = 0;      // sensor minimum, discovered through experiment
//const int sensorMax = 600;    // sensor maximum, discovered through experiment
const int trigPin1 = 11; // the number of the trigger output pin ( sensor 1 )
const int echoPin1 = 10; // the number of the echo input pin ( sensor 1 )     
const int trigPin2 = 6;  // the number of the trigger output pin ( sensor 2 ) 
const int echoPin2 = 5;  // the number of the echo input pin ( sensor 2 ) 
const int red = 3;
const int blue = 2; 
const int green = 1;

////////////////////////////////// variables used for distance calculation 
long duration;                               
 
int distance1= constrain(distance1,0,30);
int distance2= constrain(distance2,0,30);
float r;
unsigned long temp=0;
int temp1=0;
int L=0;
////////////////////////////////
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red, red_light_value);
  analogWrite(green, green_light_value);
  analogWrite(blue, blue_light_value);
}
void find_distance (void);

// this function returns the value in cm.
/*we should not trigger the both ultrasonic sensor at the same time. 
it might cause error result due to the intraction of the both soundswaves.*/ 
void find_distance (void)                   
{ 
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin1, HIGH, 5000);// here this pulsein function wont wait more then 5000us for the ultrasonic sound to came back. (due to this it wont measure more than 60cm)
                                           // it helps this project to use the gesture control in the defined space. 
                                           // so that, it will return zero if distance greater then 60m. ( it helps usually if we remove our hands infront of the sensors ).
 
  r = 3.4 * duration / 2;                  // calculation to get the measurement in cm using the time returned by the pulsein function.     
  distance1 = r / 100.00;
  Serial.print(distance1);
  Serial.print("   ");
  /////////////////////////////////////////upper part for left sensor and lower part for right sensor
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  

  duration = pulseIn(echoPin2, HIGH, 5000);
  r = 3.4 * duration / 2;     
  distance2 = r / 100.00;
  delay(100);
  
  Serial.println(distance2);
}
void setup() 
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT); // initialize the trigger and echo pins of both the sensor as input and output:
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  delay (1000);
    
}


void loop() {
//  // read the sensor:
//  int sensorReading = analogRead(A0);
//  // map the sensor range to a range of four options:
//  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  // do something different depending on the range value:
  switch (distance1, distance2) {
    case 0:    (distance1 >= 1 && distance1 <= 15);// your hand is on the sensor
     temp=millis();                   // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while(millis()<=(temp+300))      // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
    find_distance();
      Serial.println("play");
      RGB_color(0, 255, 0); //Green
      delay(1000);
      break;
    case 1:    ((temp-6) > distance1);// your hand is close to the sensor
  temp=millis();                   // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while(millis()<=(temp+300))      // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
    find_distance();
      Serial.println("rewind");
      RGB_color(255, 255, 0);
      delay(1000);
      break;
    case 2:  ((temp+6) > distance1);  // your hand is a few inches from the sensor
      temp=millis();                   // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while(millis()<=(temp+300))      // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
    find_distance();
      Serial.println("fastfoward");
      RGB_color(106, 13, 173);
      delay(1000);
      break;
    case 3:  (distance2 >= 1 && distance2 <= 15);  // your hand is nowhere near the sensor
     temp=millis();                   // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while(millis()<=(temp+300))      // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
    find_distance();

      Serial.println("expand");
      RGB_color(100, 21, 100);
      delay(1000);
      break;
      case 4: ((temp-6)>distance2);
       temp=millis();                   // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while(millis()<=(temp+300))      // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
    find_distance();
      Serial.println("down");
       RGB_color(255, 0, 0);
       delay(1000);
      break;
      case 5: ((temp+6)<distance2) ;
       temp=millis();                   // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while(millis()<=(temp+300))      // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
    find_distance();
      Serial.println("up");
       RGB_color(0, 0, 255); 
       delay(1000);
      break;
  }
  delay(1000);        // delay in between reads for stability
}
