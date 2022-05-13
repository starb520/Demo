#pragma once
class Velocity
{
private:
   double dx;
   double dy;

public:
   Velocity();
   Velocity(double dx, double dy);
   double getDX();
   double getDY();
   double getSpeed();
   void setDX(double dx);
   void setDY(double dy);
   double add(double accel, double time);


};

