const int trigPin1 = 11; // the number of the trigger output pin ( sensor 1 )
const int echoPin1 = 10; // the number of the echo input pin ( sensor 1 )
const int trigPin2 = 6;  // the number of the trigger output pin ( sensor 2 )
const int echoPin2 = 5;  // the number of the echo input pin ( sensor 2 )
const int red = 3;
const int blue = 2;
const int green = 1;

////////////////////////////////// variables used for distance calculation
long duration;

int distance1 = constrain(distance1, 0, 30);
int distance2 = constrain(distance2, 0, 30);
float r;
unsigned long temp = 0;
int temp1 = 0;
int L = 0;
////////////////////////////////

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
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  delay (1000);

}

void loop()
{
  find_distance(); // this function will stores the current distance measured by the ultrasonic sensor in the global variable "distance1 and distance2"
  // no matter what, the program has to call this "find_distance" function continuously to get the distance value at all time.

  if (distance2 <= 15 && distance2 >= 1) // once if we placed our hands in front of the right sensor in the range between 15 to 35cm this condition becomes true.
  {
    temp = millis();                 // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while (millis() <= (temp + 300)) // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
      find_distance();
    if (distance2 <= 15 && distance2 >= 1) // this condition will true if we place our hand in front of the right sensor for more then 300 milli seconds.
    {
      temp = distance2;                       // store the current position of our hand in the variable temp.
      while (distance2 <= 15 || distance2 == 1) // this loop will run untill we removes our hand in front of the right sensor.
      {
        find_distance();                      // call this function continuously to get the live data.
        if ((temp + 6) < distance2)           // this condition becomes true if we moves our hand away from the right sensor (**but in front of it ). here " temp+6 " is for calibration.
        {
          Serial.println("playpause");               // send "play" serially.
          RGB_color(0, 255, 0); //Green
          delay(1000);
          RGB_color(0, 0, 0);
          delay(50);

        }
        else if ((temp - 6) > distance2)      // this condition becomes true if we moves our hand closer to the right sensor.
        {
          Serial.println("up");                // send "Next" serially.
          RGB_color(0, 0, 255); //Blue
          delay(1000);
          RGB_color(0, 0, 0);
          delay(50);
        }
      }
    }
    else                                     // this condition becomes true, if we only swipe in front of the right sensor .
    {
      Serial.println("down");                // send "captions" serially.
      RGB_color(255, 0, 0); //red
      delay(1000);
      RGB_color(0, 0, 0);
      delay(50);

    }
  }

  else if (distance1 <= 15 && distance1 >= 1) // once if we placed our hands in front of the left sensor in the range between 15 to 60cm this condition becomes true.
  {
    temp = millis();                 // store the current time in the variable temp. (" millis " Returns the number of milliseconds since the Arduino board began running the current program )
    while (millis() <= (temp + 300)) // this loop measures the distance for another 300 milliseconds. ( it helps to find the difference between the swipe and stay of our hand in front of the right sensor )
      find_distance();
    if (distance1 <= 15 && distance1 >= 1) // this condition will true if we place our hand in front of the right sensor for more then 300 milli seconds.
    {
      temp = distance2;                       // store the current position of our hand in the variable temp.
      while (distance1 <= 15 || distance1 == 1) // this loop will run untill we removes our hand in front of the right sensor.
      {
        find_distance();                      // call this function continuously to get the live data.
        if ((temp + 6) < distance1)           // this condition becomes true if we moves our hand away from the right sensor (**but in front of it ). here " temp+6 " is for calibration.
        {
          Serial.println("expand");               // send "r" serially.
          RGB_color(100, 21, 100); // orange
          delay(1000);
          RGB_color(0, 0, 0);
          delay(50);

        }
        else if ((temp - 6) > distance1)      // this condition becomes true if we moves our hand closer to the right sensor.
        {
          Serial.println("rewind");                // send "Next" serially.
          RGB_color(255, 255, 0); //yellow
          delay(1000);
          RGB_color(0, 0, 0);
          delay(50);

        }
      }
    }
    else if (distance1 >= 1 && distance1 <= 15)                            // this condition becomes true, if we only swipe in front of the right sensor .
    {
      Serial.println("fastfoward");                // send "captions" serially.
      RGB_color(106, 13, 173); // purple
      delay(1000);
      RGB_color(0, 0, 0);
      delay(50);


    }
    else  //(0==distance1 && 0==distance2)
    {
      Serial.println("idle");
      RGB_color(0, 0, 0);
      delay(1000);
    }
  }
}
