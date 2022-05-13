#pragma once
class Acceleration
{
private:
   double ddx;
   double ddy;
   
public:
   Acceleration();
   Acceleration(double ddx, double ddy);
   double getDDX();
   double getDDY();
   void setDDX(double dx);
   void setDDY(double dy);

};

