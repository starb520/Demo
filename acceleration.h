#pragma once
#include <math.h> // Sin and Cos

/***********************************************************************
 * Acceleration
 * Uses dX and dY to calculate the vertical 
 * and horizontal components of the Lander.
 ************************************************************************/

class Acceleration

{
private:
   double ddx; // horizontal acceleration
   double ddy; // vertical acceleration
   
public:
   // constructors
   Acceleration();
   Acceleration(double ddx, double ddy);

   // return acceleration
   double getDDX();
   double getDDY();

   // updates the ddX and ddY attributes 
   void setDDX(double ddx);
   void setDDY(double ddy);

   // use the change in velocity to calculate acceleration
   double computeHorizontalComp(double angle, double thrust);
   double computeVerticalComp(double angle, double thrust);
};

