  
#include <IRremote.h>

int RECV_PIN = 11;
const int red = 8;
const int green = 9;
const int blue = 10;


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");


}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

  }
  switch (results.value)
  {
    case 0XC1AAC936:    // your hand is on the sensor
      Serial.println("RED LED ON");
      digitalWrite(8, HIGH);
      break;
    case 0XC1AA49B6:    // your hand is close to the sensor
      Serial.println("Red LED OFF");
      digitalWrite(8, LOW);
      break;
    case 0XC1AAF906:    // your hand is a few inches from the sensor
      Serial.println("BLUE LED ON");
      digitalWrite(9, HIGH);
      break;
    case 0XC1AA7986:    // your hand is nowhere near the sensor
      Serial.println("BLUE LED OFF");
      digitalWrite(9, LOW);
      break;
    case 0XC1AA51AE:    // your hand is nowhere near the sensor
      Serial.println("GREEN LED ON");
      digitalWrite(10, HIGH);
      break;
    case 0XC1AAF10E:    // your hand is nowhere near the sensor
      Serial.println("GREEN LED OFF");
      digitalWrite(10, LOW);
      break;
  }
  irrecv.resume(); // Receive the next value
  delay(100);
}
