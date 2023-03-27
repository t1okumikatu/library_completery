#include "motor.h"

Motor motor = Motor();

// ** setup ****************************
void setup() {
  
}
// *************************************

// ** Loop *****************************
void loop() {
  motor.forward(1200);
  delay(500);
  motor.brake(0);
  delay(500);  
  motor.Rforward(1200);
  delay(1000);
  motor.Lforward(1200);
  delay(500);  
  motor.brake(0);
  delay(500);  
  motor.back(1200);
  delay(500);
  motor.brake(0);
  delay(500);  
 
}
// *************************************
