  

  /*

    Group 7 - Jonas B., Signe, Thomas T & Tim

    Mercantec - Viborg College of Technology

    27/09-2018

  */

  

  //First piece of code for the stepper motor, tested with stepper motor, it works.
  #ifndef Step_h
  #define Step_h

  class Step {
  
  //------------------- Include the Stepper library--------------------//

  #include <Stepper.h>
  #include "Arduino.h"
  
  //------------------- A few ints for the motor to use --------------------//

  const int stepsPerRev = 200; //steps per revolution
  const int standardSpd = 60; //seconds per revolution
  const int fullRev = 200; //steps
  const int halfRev = 100; //steps

  float gearDiameter = 12.22; //millimeters (placeholder)

  int xAxisStepCount = 0;
  int yAxisStepCount = 0;
  int eraserStepCount = 0;
  int penStepCount = 0;

  const int penDown = 10;
  const int r2Digit = 0;  //Placeholder
  const int r4Digit = 0;  //Placeholder

  int draw1;
  int draw2;
  int draw3;
  int draw4;
  int draw5;
  int draw6;
  int draw7;
  
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
    draw(4,1);
    draw(1,2);
    draw(8,3);
  }

  void motorStep(int _stepLength, float _gearDiameter, int _stepper) {

    //------------------- Move chosen stepper a given length, and keep track of steps taken --------------------//
    int stepLength = _stepLength;
    float gearDiameter = _gearDiameter;
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
    } else {
      
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
    } else {
      
    }  
  }

void wipe (int len) {
  if (len == 1) {
    motorStep(r2Digit, gearDiameter, 4);
    motorReset(4);
  } else {
    motorStep(r4Digit, gearDiameter, 4);
    motorReset(4);
  }
}





  
//------------------- Set draw-values for number given in "tal", draws in digitplace for number giving in "digit" --------------------//
void draw (int tal, int digittt) {
  if(tal == 0) {
   draw1 = 1;
   draw2 = 1;
   draw3 = 1;
   draw4 = 0;
   draw5 = 1;
   draw6 = 1;
   draw7 = 1;

   digit(digittt);
   
  } else if(tal == 1) {
   draw1 = 1;
   draw2 = 0;
   draw3 = 0;
   draw4 = 0;
   draw5 = 1;
   draw6 = 0;
   draw7 = 0;

   digit(digittt);
   
  } else if (tal == 2) {
    
   draw1 = 1;
   draw2 = 1;
   draw3 = 0;
   draw4 = 1;
   draw5 = 0;
   draw6 = 1;
   draw7 = 1;  

   digit(digittt);
      
  } else if (tal == 3) {
   draw1 = 1;
   draw2 = 1;
   draw3 = 0;
   draw4 = 1;
   draw5 = 1;
   draw6 = 1;
   draw7 = 0;

   digit(digittt);
   
  } else if (tal == 4) {
   draw1 = 1;
   draw2 = 0;
   draw3 = 1;
   draw4 = 1;
   draw5 = 1;
   draw6 = 0;
   draw7 = 0;

   digit(digittt);
    
  } else if (tal == 5) {
   draw1 = 0;
   draw2 = 1;
   draw3 = 1;
   draw4 = 1;
   draw5 = 1;
   draw6 = 1;
   draw7 = 0;

   digit(digittt);
   
  } else if (tal == 6) {
   draw1 = 0;
   draw2 = 1;
   draw3 = 1;
   draw4 = 1;
   draw5 = 1;
   draw6 = 1;
   draw7 = 1;

   digit(digittt);
   
  } else if (tal == 7) {
   draw1 = 1;
   draw2 = 1;
   draw3 = 0;
   draw4 = 0;
   draw5 = 1;
   draw6 = 0;
   draw7 = 0;

   digit(digittt);
   
  } else if (tal == 8) {
   draw1 = 1;
   draw2 = 1;
   draw3 = 1;
   draw4 = 1;
   draw5 = 1;
   draw6 = 1;
   draw7 = 1;

   digit(digittt);
   
  } else if (tal == 9)
   draw1 = 1;
   draw2 = 1;
   draw3 = 1;
   draw4 = 1;
   draw5 = 1;
   draw6 = 1;
   draw7 = 0;

   digit(digittt);
   
}

//------------------- Moves the pen to the place were the digit suppose to be --------------------//
void digit(int digitt) {
  if (digitt == 1) {
  motorStep(15,gearDiameter,1);
  motorStep(75,gearDiameter,2);

  lines ();
  
  } else if (digitt == 2) {
  motorStep(10,gearDiameter,1);

  lines ();
  
  } else if (digitt == 3) {
  motorStep(30,gearDiameter,1);

  lines ();
  
  } else if (digitt == 4) {
  motorStep(10,gearDiameter,1);

  lines ();
  }
}

//------------------- Move the pen, deciding if to draw or not by the giving draw-values --------------------//
void lines () {
  if(draw1 == 1) {
    motorStep(penDown,gearDiameter, 3);
  }

  motorStep(-50,gearDiameter,2);
 
  if(draw2 == 0) {
    motorStep(-penDown,gearDiameter, 3);
  } 
  else if(draw2 == 1 && draw1 == 0) {
    motorStep(penDown,gearDiameter, 3);
  }

  motorStep(50,gearDiameter,1);
 
  if(draw3 == 0) {
    motorStep(-penDown,gearDiameter, 3);
  } 
  else if(draw3 == 1 && draw2 == 0) {
    motorStep(penDown,gearDiameter, 3);
  }

  motorStep(50,gearDiameter,2);
 
  if(draw4 == 0) {
    motorStep(-penDown,gearDiameter, 3);
  } 
  else if(draw4 == 1 && draw3 == 0) {
    motorStep(penDown,gearDiameter, 3);
  }

  motorStep(-50,gearDiameter,1);
 
  if(draw5 == 0) {
    motorStep(-penDown,gearDiameter, 3);
  } 
  else if(draw5 == 1 && draw4 == 0) {
    motorStep(penDown,gearDiameter, 3);
  }

  motorStep(50,gearDiameter,2);
 
  if(draw6 == 0) {
    motorStep(-penDown,gearDiameter, 3);
  } 
  else if(draw6 == 1 && draw5 == 0) {
    motorStep(penDown,gearDiameter, 3);
  }

  motorStep(50,gearDiameter,1);
 
  if(draw7 == 0) {
    motorStep(-penDown,gearDiameter, 3);
  } 
  else if(draw7 == 1 && draw6 == 0) {
    motorStep(penDown,gearDiameter, 3);
  }

  motorStep(-50,gearDiameter,2);
 
  if(draw7 == 1) {
    motorStep(penDown,gearDiameter, 3);
  }
}
}

#endif




















  
