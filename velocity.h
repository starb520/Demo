#pragma once

#include "acceleration.h"


/***********************************************************************
 * Velocity: change in position divided by time
 ************************************************************************/
class Velocity
{
private:
   double dx;
   double dy;

public:
   // constructors
   Velocity();
   Velocity(double dx, double dy);

   // returns the change in x and change in y
   double getDX();
   double getDY();
   double getSpeed();

   // updates the dx and dy attributes
   void setDX(double dx);
   void setDY(double dy);

   // calculates the velocity
   double add(double accel, double time);


};

