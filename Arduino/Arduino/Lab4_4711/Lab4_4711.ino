//import processing.serial.*; // create serial port object //
//Serial myPort; 

/* Processing Example: MouseeCircle.pde ********/ 
/* Global variables ****************************/ 
float radius = 50.0; 
int X, Y; 
int nX, nY; 
int delay = 16; 
 
/* Setup the Processing drawing window *********/ 
void setup(){   
  // List all the available serial ports 
  println(Serial.list()); 
  // Change the serial/USB port index number in square 
  // brackets in Serial.list()[0], 
  // depending on whatever port Arduino is connected to. 
  myPort = new Serial(this, Serial.list()[0], 9600); 
  // Don't generate a serialEvent(),  
  // unless you get a newline character: 
  myPort.bufferUntil('\n'); 
 
size(512, 512);   
strokeWeight(10);   
frameRate(16);   
X = width / 2;   
Y = height / 2;   
nX = X;   
nY = Y;  } 
 
/* Main draw loop ******************************/ 
void draw(){   
radius = radius + sin( frameCount / 4 );      
// Track circle to new destination   
X+=(nX-X)/delay;   
Y+=(nY-Y)/delay;      
// Fill canvas grey   
background(169, 255, 0);      
// Set fill-color to blue   
fill(255, 0, 0);      
// Set stroke-color white   
stroke(5);       
// Draw circle   
ellipse(X, Y, radius, radius/2);                   } 
 
/* Set circle's next destination ***************/ 
void mouseMoved(){   
nX = mouseX;   
nY = mouseY;   }   
/* Get potentiometer values from Arduino via USB/COM port */ 
void serialEvent(Serial myPort) {   
  // get the ASCII string:   
  String inString = myPort.readStringUntil('\n'); 
 
  if (inString != null) {     
    // trim off any whitespace:     
    inString = trim(inString);     
    // convert to an int and map to the screen height:     
    float inByte = float(inString);      
    inByte = map(inByte, 0, 1023, 0, height); 
 
    radius = inByte;   
  } 
} 
