#pragma once

/***********************************************************************
 * Acceleration
 ************************************************************************/

class Acceleration

{
private:
   double ddx;
   double ddy;
   
public:
   Acceleration();
   Acceleration(double ddx, double ddy);

   // return the acceleration
   double getDDX();
   double getDDY();

   // use the change in velocity to calculate acceleration
   void setDDX(double dx);
   void setDDY(double dy);

};

