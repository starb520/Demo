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
 * Another constructor
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
 * Uses the change in x to calculate and update the ddx attribute.
 ************************************************************************/
void Acceleration::setDDX(double ddx)
{
   this->ddx = ddx;
}

/***********************************************************************
 * Uses the change in y to calculate and update the ddy attribute.
 ************************************************************************/
void Acceleration::setDDY(double ddy)
{
   this->ddy = ddy;
}