#pragma once
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "acceleration.h"
#include "ground.h"
#define _USE_MATH_DEFINES //Pi and Sqrt
#include <cmath> // Pi and Sqrt
#include <math.h> // Floor
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
   Point pt;      // point
   double angle;
   Point ptUpperRight;
   double fuel;
   Velocity v;     // velocity
   double tThrust; // total thrust
   
public:
   // constructor
   Lander(const Point ptUpperRight);

   // resets the lander after crash/land
   void reset(const Point ptUpperRight);

   // stats of the ships condition
   bool isDead(const Ground ground);
   bool isLanded(const Ground ground);
   bool isFlying();


   // return methods
   Point getPosition()    { return pt;     }
   Velocity getVelocity() { return v;      }
   double getAngle()      { return angle;  }
   double getFuel()       { return fuel;   }

   // draws Lander
   void draw(const Interface& pUI, ogstream& gout);

   // converts the input into thrust
   void input(const Interface& pUI, Acceleration& a);

   // condition updates
   void coast(Acceleration & a);
   void land(const Ground ground);
   void crash(const Ground ground);

};

