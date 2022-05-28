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
   Acceleration() : ddx(0.0), ddy(0.0) {};
   Acceleration(double ddx, double ddy);

   // return acceleration
   double getDDX() const { return ddx; };
   double getDDY() const { return ddy; };

   // updates the ddX and ddY attributes 
   void setDDX(double ddx) { this->ddx = ddx; };
   void setDDY(double ddy) { this->ddy = ddy; };

   // use the change in velocity to calculate acceleration
   double computeHorizontalComp(double angle, double thrust);
   double computeVerticalComp(double angle, double thrust);
};

