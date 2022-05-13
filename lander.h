#pragma once
#include "point.h"
#include "velocity.h"

class Lander
{
private:
   double status;
   Point pt;
   double angle;
   Point ptUpperRight;
   double fuel;
   double weight;
   double thrust;
   double g;
   
public:
   Lander(Point ptUpperRight);
   void reset();
   bool isDead();
   bool isLanded();
   bool isFlying();
   Point getPosition();
   int getFuel();
   void draw(double thrust, ogstream gout);
   void input(double thrust);
   void coast();
   void land();
   void crash();

};

