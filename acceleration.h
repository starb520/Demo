#pragma once
#include <math.h> // Sin and Cos

/***********************************************************************
 * Acceleration
 ************************************************************************/

class Acceleration

{
private:
   double ddx;
   double ddy;
   
public:
   // constructors
   Acceleration();
   Acceleration(double ddx, double ddy);

   // return the acceleration
   double getDDX();
   double getDDY();

   // use the change in velocity to calculate acceleration
   void setDDX(double ddx);
   void setDDY(double ddy);
   double computeHorizontalComp(double angle, double thrust);
   double computeVerticalComp(double angle, double thrust);
};

