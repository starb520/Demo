#include "velocity.h"
#include <cmath> // for sqrt

/***********************************************************************
 * Velocity: change in position divided by time
 ************************************************************************/
 
 /***********************************************************************
  * Velocity
  * A non-default constructor that takes in a dx and dy
  ************************************************************************/
Velocity::Velocity(double dx, double dy)
{
   this->dx = dx;
   this->dy = dy;
}

/***********************************************************************
 * Velocity GET SPEED
 * Calculate total speed
 ************************************************************************/
double Velocity::getSpeed()
{
   return sqrt((dx * dx) + (dy * dy));
}

/***********************************************************************
 * Velocity ADD
 * Adds acceleration to the velocity
 ************************************************************************/
void Velocity::add(Acceleration accel, double time)
{
   dx = (dx + accel.getDDX() * time);
   dy = (dy + accel.getDDY() * time);
}
