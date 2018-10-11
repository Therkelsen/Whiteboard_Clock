
#include "Arduino.h"
#include "Step.h"

  Step::Step() {
    xAxis.setSpeed(standardSpd);
    yAxis.setSpeed(standardSpd);
    eraser.setSpeed(standardSpd);
    pen.setSpeed(standardSpd);
  }

  void Step::motorstep (int _stepLength, float _gearDiameter, int _stepper) {
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

  void Step::motorReset(int _stepper) {

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

  void Step::wipe (int len) {
    if (len == 1) {
      motorStep(r2Digit, gearDiameter, 4);
      motorReset(4);
    } else {
      motorStep(r4Digit, gearDiameter, 4);
      motorReset(4);
    }
  }

  void Step::draw (int tal, int digittt) {
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

void Step::digit(int digitt) {
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

void Step::lines () {
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

