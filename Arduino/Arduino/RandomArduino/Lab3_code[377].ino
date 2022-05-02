void setup() { 
   
   Serial.begin(9600);      // initialize serial port 
  
   pinMode(9, OUTPUT);      // initialize pin 9 as output pin    
   pinMode(13, OUTPUT);    // initialize pin 13 for heartbeat LED 
}  
void loop() { 
      int  sensor;    
      char command; // Read sensor input value, send sensor value to PC 
    sensor = analogRead(0);       // read sensor value from analog pin A0    
    sensor = sensor >> 2;         // convert sensor value from 10-bits to 8bits 
   
   Serial.println(sensor);       // send sensor value to PC 
 
// Read command from PC, control output device 
 
   if (Serial.available())  
      command = Serial.read();   // read command character from PC 
 
   switch (command) {            // activate output according to command value       
      case  '0':          digitalWrite(9, LOW);   // turn output device OFF          
      break; 
       case  '1':          digitalWrite(9, HIGH);  // turn output device ON         
       break;              
       case  '2':          digitalWrite(10, LOW);   // turn output device OFF         
       break; 
       case  '3':          digitalWrite(10, HIGH);  // turn output device ON         
       break; 
       case  '4':          digitalWrite(11, LOW);   // turn output device OFF         
       break; 
       case  '5':          digitalWrite(11, HIGH);  // turn output device ON         
       break; 
       default: 
         // do nothing for other command values          
         break; 
   } 
 
// toggle pin 13 LED to show that the program is running (heartbeat) 
 
   digitalWrite(13, HIGH); delay(100);    
   digitalWrite(13, LOW);  delay(100); 
} 
 
