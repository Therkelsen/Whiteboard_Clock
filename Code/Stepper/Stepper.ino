
  /*
  Group 7 - Jonas B., Signe, Thomas T & Tim
  Mercantec - Viborg College of Technology
  06/09-2018
  */

  //First piece of code for the stepper motor, not tested yet.
  
  #include <Stepper.h>
  
  Stepper myStepper(100,8,9,10,11);
  
  void setup() {
    // put your setup code here, to run once:
    myStepper.setSpeed(60);
    Serial.begin(9600);
  }
  
  void loop() {
    // put your main code here, to run repeatedly:
    myStepper.step(100);
  }
