  
  /*
    Group 7 - Jonas B., Signe, Thomas T & Tim
    Mercantec - Viborg College of Technology
    17/09-2018
  */
  
  //First piece of code for the stepper motor, tested with stepper motor, it works.

  //------------------- Include the Stepper library)--------------------//
  #include <Stepper.h>

  //------------------- A few ints for the motor to use --------------------//
  
  const int stepsPerRev = 200; //steps per revolution
  const int standardSpd = 60; //seconds per revolution
  const int fullRev = 200; //steps
  const int halfRev = 100; //steps

  int stepCount = 0;

  //------------------- Creates a Stepper object. Parameters: (rev, A+, A-, B+, B-) --------------------//
  Stepper myStepper(stepsPerRev, 50, 51, 52, 53);

  //------------------- Everything that needs to be run once, goes here --------------------//
  void setup() {
    myStepper.setSpeed(standardSpd);
    Serial.begin(9600);
  }
  
  //------------------- Everything in here is run once every frame --------------------//
  void loop() {
    int stepLength = 100; //millimeters (placeholder)
    int gearDiameter = 20; //millimeters (placeholder)
    motorStep(stepLength, gearDiameter);
    delay(1000);
  }
  
  void motorStep(int _stepLength, int _gearDiameter) {
    //------------------- Move the motor the given length --------------------//
    int stepLength = _stepLength;
    int gearDiameter = _gearDiameter;
    
    float stepSize = 1.8; //degrees
    int gearCircumf = PI * gearDiameter; //millimeters
    int steps = (stepLength*360)/gearCircumf;
    
    myStepper.step(steps);

    //------------------- Keep track of steps taken --------------------//
    stepCount += steps;
    Serial.print("Steps: ");
    Serial.println(stepCount);
  }


  
