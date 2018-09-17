  
  /*
    Group 7 - Jonas B., Signe, Thomas T & Tim
    Mercantec - Viborg College of Technology
    17/09-2018
  */
  
  //First piece of code for the stepper motor, tested with stepper motor, it works.

  // Includes the Stepper Library 
  #include <Stepper.h>

  // A few variables that might be useful later on
  const int stepsPerRev = 200;
  const int standardSpeed = 60;
  const int fullRev = 200;
  const int halfRev = 100;

  // Creates a Stepper object. Parameters: (rev, A+, A-, B+, B-)
  Stepper myStepper(stepsPerRev, 50, 51, 52, 53);

  // Variable for counting amount of steps taken
  int stepCount = 0;
  
  void setup() {
    // Set the speed of the stepper motor, and start the serial.
    myStepper.setSpeed(standardSpeed);
    Serial.begin(9600);
  }
  
  void loop() {
    //motorStep(fullRev);
    delay(1000);
  }
  
  void motorStep(int steps) {
    // Function for stepping a given amount of steps, and print in Serial how many  in total.
    int _steps = steps;

    myStepper.step(_steps);
    
    stepCount += _steps;
    Serial.print("Steps: ");
    Serial.println(stepCount);
  }
