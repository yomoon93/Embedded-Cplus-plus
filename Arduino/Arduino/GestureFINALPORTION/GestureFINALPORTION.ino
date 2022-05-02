const int trigger1 = 11; //Trigger pin of 1st Sesnor
const int echo1 = 10; //Echo pin of 1st Sesnor
const int trigger2 = 6; //Trigger pin of 2nd Sesnor
const int echo2 = 5;//Echo pin of 2nd Sesnor
const int red = 3;
const int blue = 2;
const int green = 1;

long time_taken;
int dist,distL,distR;      

 

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(red, red_light_value);
  analogWrite(green, green_light_value);
  analogWrite(blue, blue_light_value);
}

/*###Function to calculate distance###*/
void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
dist= time_taken*0.034/2;
if (dist>50)
dist = 50;
}

void loop() { //infinite loopy
calculate_distance(trigger1,echo1);
distL =dist; //get distance of left sensor

calculate_distance(trigger2,echo2);
distR =dist; //get distance of right sensor

//Uncomment for debudding
/*Serial.print("L=");
Serial.println(distL);
Serial.print("R=");
Serial.println(distR);
*/

//Pause Modes -Hold
if ((distL >40 && distR>40) && (distL <50 && distR<50)) //Detect both hands
{Serial.println("Playpause");   delay (500);  RGB_color(0, 255, 0);//Green
}if ((distL >10 && distR>10) && (distL <30 && distR<30))
{Serial.println("Expand"); delay(500);}

calculate_distance(trigger1,echo1);
distL =dist;

calculate_distance(trigger2,echo2);
distR =dist;

 

//Control Modes
//Lock Left - Control Mode
if (distL>=13 && distL<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger1,echo1);
  distL =dist;
  if (distL>=13 && distL<=17)
  {
    Serial.println("Left Locked");
    while(distL<=40)
    {
      calculate_distance(trigger1,echo1);
      distL =dist;
      if (distL<10) //Hand pushed in 
      {Serial.println ("Volumeup"); delay (300);    RGB_color(0, 0, 255);} //Blue
      if (distL>20) //Hand pulled out
      {Serial.println ("Volumedown"); delay (300); RGB_color(255, 0, 0);} //red
    }
  }
}

//Lock Right - Control Mode
if (distR>=13 && distR<=17)
{
  delay(100); //Hand Hold Time
  calculate_distance(trigger2,echo2);
  distR =dist;
  if (distR>=13 && distR<=17)
  {
    Serial.println("Right Locked");
    while(distR<=40)
    {
      calculate_distance(trigger2,echo2);
      distR =dist;
      if (distR<10) //Right hand pushed in
      {Serial.println ("Rewind"); delay (300);  RGB_color(106, 13, 173);} // purple
      if (distR> 20) //Right hand pulled out
      {Serial.println ("Fastforward"); delay (300); RGB_color(255, 255, 0);} //yellow
  }
}
}

delay(200);
  }
