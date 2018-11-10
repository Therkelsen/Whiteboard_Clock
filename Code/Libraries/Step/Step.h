#ifndef Step_h
#define Step_h

//#include "Arduino_h"
#include "Stepper.h"

class Step {
  public:
    Step();
    void motorStep ();
    void motorReset ();
    void wipe ();
    void draw ();
    void digit ();
    void lines ();

  private:
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

    Stepper xAxis(stepsPerRev, 29, 27, 25, 23); //Stepper 1
    Stepper yAxis(stepsPerRev, 37, 35, 33, 31); //Stepper 2
    Stepper eraser(stepsPerRev, 45, 43, 41, 39);  //Stepper 3
    Stepper pen(stepsPerRev, 53, 51, 49, 47); //Stepper 4
}



#endif
