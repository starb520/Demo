#include "velocity.h"
#include <cmath> // for sqrt

/***********************************************************************
 * Velocity: change in position divided by time
 ************************************************************************/

Velocity::Velocity()
{
   dx = 0.0;;
   dy = 0.0;
}

Velocity::Velocity(double dx, double dy)
{
   this->dx = dx;
   this->dy = dy;

}
/***********************************************************************
 * Returns the dx value
 ************************************************************************/
double Velocity::getDX()
{
   return dx;
}


/***********************************************************************
 * Returns the dy value
 ************************************************************************/
double Velocity::getDY()
{
   return dy;
}


/***********************************************************************
 * GetSpeed
 * 
 ************************************************************************/
double Velocity::getSpeed()
{
   return sqrt((dx * dx) + (dy * dy));
}

/***********************************************************************
 * Updates the dx attribute
 ************************************************************************/
void Velocity::setDX(double dx)
{
   this->dx = dx;
}

/***********************************************************************
 * Updates the dy attribute
 ************************************************************************/
void Velocity::setDY(double dy)
{
   this->dy = dy;
}

/***********************************************************************
 * Velocity, add
 ************************************************************************/
void Velocity::add(Acceleration accel, double time)
{
   //return getSpeed() + (accel * time);
   dx = (dx + accel.getDDX() * time);
   dy = (dy + accel.getDDY() * time);
}
