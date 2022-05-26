#include "acceleration.h"

/***********************************************************************
 * Acceleration: uses the velocity to calculate acceleration and return
 *               acceleration of the lunar module.
 ************************************************************************/


 /***********************************************************************
  * Acceleration
  * Default constructor
  ************************************************************************/
Acceleration::Acceleration()
{
   ddx = 0;
   ddy = 0;
}

/***********************************************************************
 * Acceleration
 * A non-default constructor that takes in a ddx and ddy
 ************************************************************************/
Acceleration::Acceleration(double ddx, double ddy)
{
   this->ddx = ddx;
   this->ddy = ddy;

}


/***********************************************************************
* GET DDX
* Return the ddx
************************************************************************/
double Acceleration::getDDX()
{
   return ddx;
}

/***********************************************************************
* GET DDY
* Return the ddy
************************************************************************/
double Acceleration::getDDY()
{
   return ddy;
}


/***********************************************************************
 * Updates the ddx attribute.
 ************************************************************************/
void Acceleration::setDDX(double ddx)
{
   this->ddx = ddx;
}

/***********************************************************************
 * Updates the ddy attribute.
 ************************************************************************/
void Acceleration::setDDY(double ddy)
{
   this->ddy = ddy;
}

/***********************************************************************
 * Uses dx to calculate ddx.
 ************************************************************************/
double Acceleration::computeHorizontalComp(double angle, double thrust)
{
   return sin(angle) * thrust;
}

/***********************************************************************
 * Uses dy to calculate ddy.
 ************************************************************************/
double Acceleration::computeVerticalComp(double angle, double thrust)
{
   // Compute y componenent of acceleration
   return (cos(angle) * thrust);
}
