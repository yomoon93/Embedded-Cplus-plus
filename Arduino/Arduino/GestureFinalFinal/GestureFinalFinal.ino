const int trigPin1 = 11; // the number of the trigger output pin ( sensor 1 )
const int echoPin1 = 10; // the number of the echo input pin ( sensor 1 )     
const int trigPin2 = 6;  // the number of the trigger output pin ( sensor 2 ) 
const int echoPin2 = 5;  // the number of the echo input pin ( sensor 2 ) 
const int red = 3;
const int blue = 2; 
const int green = 1;
long duration;                               

int distance1;
int distance2;
int distanceleft  = constrain( distance1,0,30);
int distanceright = constrain( distance2,0,30);

 





float r;
unsigned long temp=0;
int temp1=0;
int l=0;
////////////////////////////////

//void find_distance (void);

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
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red, red_light_value);
  analogWrite(green, green_light_value);
  analogWrite(blue, blue_light_value);
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
 void loop
 {
  
 }
 
 }
