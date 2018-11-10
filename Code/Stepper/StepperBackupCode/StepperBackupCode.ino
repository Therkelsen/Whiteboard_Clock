  
  /*
    Group 7 - Jonas B., Signe, Thomas T & Tim
    Mercantec - Viborg College of Technology
    27/09-2018
  */
  
  //First piece of code for the stepper motor, tested with stepper motor, it works.
  
  //------------------- Include the Stepper library --------------------//
  #include <Stepper.h>
  
  //------------------- A few ints for the motor to use --------------------//
  const int stepsPerRev = 200; //steps per revolution
  const int standardSpd = 60; //seconds per revolution
  const int fullRev = 200; //steps
  const int halfRev = 100; //steps

  int xAxisStepCount = 0;
  int yAxisStepCount = 0;
  int eraserStepCount = 0;
  int penStepCount = 0;
  
  //------------------- Creates a Stepper object for each needed stepper motor. Parameters: (rev, A+, A-, B+, B-) --------------------//
  Stepper xAxis(stepsPerRev, 29, 27, 25, 23); //Stepper 1
  Stepper yAxis(stepsPerRev, 37, 35, 33, 31); //Stepper 2
  Stepper eraser(stepsPerRev, 45, 43, 41, 39);  //Stepper 3
  Stepper pen(stepsPerRev, 53, 51, 49, 47); //Stepper 4
  
  //------------------- Everything that needs to be run once, goes here --------------------//
  void setup() {
    xAxis.setSpeed(standardSpd);
    yAxis.setSpeed(standardSpd);
    eraser.setSpeed(standardSpd);
    pen.setSpeed(standardSpd);
  }
  
  //------------------- Everything in here is run once every frame --------------------//
  void loop() {
    int stepLength = 100; //millimeters (placeholder)
    int gearDiameter = 20; //millimeters (placeholder)
    motorStep(stepLength, gearDiameter, 1);
    delay(1000);
  }
  
  void motorStep(int _stepLength, int _gearDiameter, int _stepper) {
    //------------------- Move chosen stepper a given length, and keep track of steps taken --------------------//
    int stepLength = _stepLength;
    int gearDiameter = _gearDiameter;
    int stepper = _stepper;
  
    float stepSize = 1.8; //degrees
    int gearCircumf = PI * gearDiameter; //millimeters
    int steps = (stepLength * 360) / gearCircumf;
    
    if (stepper == 1) { 
      xAxis.step(steps);
      xAxisStepCount += steps;
    } else if (stepper == 2) {  
      yAxis.step(steps);
      yAxisStepCount += steps;
    } else if (stepper == 3) {  
      eraser.step(steps);
      eraserStepCount += steps;
    } else if (stepper == 4) {  
      pen.step(steps);
      penStepCount += steps;
    }
  }

  void motorReset(int _stepper) {
  //------------------- Reset chosen stepper --------------------//
    int stepper = _stepper;
    
    if (stepper == 1) { 
      xAxis.step(-xAxisStepCount);
      xAxisStepCount = 0;
    } else if (stepper == 2) {  
      yAxis.step(-yAxisStepCount);
      yAxisStepCount = 0;
    } else if (stepper == 3) {  
      eraser.step(-eraserStepCount);
      eraserStepCount = 0;
    } else if (stepper == 4) {  
      pen.step(-penStepCount);
      penStepCount = 0;
    }
  }
  
  

