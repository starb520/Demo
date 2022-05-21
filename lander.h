#pragma once
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "uiInteract.h"
#define _USE_MATH_DEFINES //Pi and Sqrt
#include <cmath> // Pi and Sqrt
#include <math.h> // Floor
#include "ground.h"
#define WEIGHT 15103.00   // Weight in KG
#define GRAVITY -1.625    // Vertical acceleration due to gravity, in m/s^2
#define THRUST 45000.00   // Thrust of main engine, in Newtons (kg m/s^2)

/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/

 

class Lander
{
private:
   enum FlightStatus { FLYING, CRASHED, LANDED};
   FlightStatus status;
   Point pt;
   double angle;
   Point ptUpperRight;
   double fuel;
   Velocity v;
   double tThrust = THRUST / WEIGHT;
   
public:
   // constructor
   Lander(Point ptUpperRight);

   // resets the lander after crash/land
   void reset();

   // stats of the ships condition
   bool isDead(Ground ground);
   bool isLanded();
   bool isFlying();
   Point getPosition();
   Velocity getVelocity();
   double getAngle();

   // returns the fuel
   int getFuel();

   // draws Lander
   void draw(double thrust, ogstream gout);

   // converts the input into thrust
   void input(const Interface& pUI, Acceleration a);

   // condition updates
   void coast(Acceleration a);
   void land();
   void crash();

};

