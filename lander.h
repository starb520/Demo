#pragma once
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/

class Lander
{
private:
   bool status;
   Point pt;
   double angle;
   Point ptUpperRight;
   double fuel;
   double weight;
   double thrust;
   double g;
   
public:
   // constructor
   Lander(Point ptUpperRight);

   // resets the lander after crash/land
   void reset();

   // stats of the ships condition
   bool isDead();
   bool isLanded();
   bool isFlying();
   Point getPosition();

   // returns the fuel
   int getFuel();

   // draws Lander
   void draw(double thrust, ogstream gout);

   // converts the input into thrust
   void input(double thrust);

   // condition updates
   void coast();
   void land();
   void crash();

};

