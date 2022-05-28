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
   Velocity() : dx(0.0), dy(0.0) {};
   Velocity(double dx, double dy);

   // returns the change in x and change in y
   double getDX() const { return dx; };
   double getDY() const { return dy; };
   double getSpeed();

   // updates the dx and dy attributes
   void setDX(double dx) { this->dx = dx; };
   void setDY(double dy) { this->dy = dy; };

   // calculates the velocity
   void add(Acceleration accel, double time);
   

};

