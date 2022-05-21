#include "lander.h"
#include "acceleration.h"

/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/
Lander::Lander(Point ptUpperRight)
{
   status = FLYING;
   pt.setX(200);
   pt.setY(350);
   angle = 0.0;
   this->ptUpperRight = ptUpperRight;
   fuel = 1000.00;
   v.setDX(-1);
   v.setDY(0);
}

/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/
void Lander::reset()
{
}


/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/
bool Lander::isDead(Ground ground)
{
   
   if (ground.getElevation(pt) <= 0) {
      status = CRASHED;
      v.setDX(0);
      v.setDY(0);
      angle = M_PI;
      return true;
   }
   else
   {
      return false;
   }
}


/***********************************************************************
 * Returns if the lunar module has landed.
 ************************************************************************/
bool Lander::isLanded()
{
   return false;
}

/***********************************************************************
 * Returns if the lunar module is in the air.
 ************************************************************************/
bool Lander::isFlying()
{
   return false;
}


/***********************************************************************
 *  Returns the position of the moon lander.
 ************************************************************************/
Point Lander::getPosition()
{
   return pt;
}


/***********************************************************************
 *  Returns the fuel status of LM.
 ************************************************************************/
int Lander::getFuel()
{
   return fuel;
}


/***********************************************************************
 * Draws the lunar module.
 ************************************************************************/
void Lander::draw(double thrust, ogstream gout)
{
}

/***********************************************************************
 * Lander input.
 ************************************************************************/
void Lander::input(const Interface& pUI, Acceleration a)
{
   

   if (fuel > 0 && status == FLYING ) {
      if (pUI.isRight())
      {
         angle -= 0.1;
         angle = angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI);
         fuel -= 1;
      }
      //pDemo->angle -= 0.1;
      if (pUI.isLeft())
      {
         fuel -= 1;
         angle += 0.1;
         angle = angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI);
      }
      if (pUI.isDown())
      {
         //Acceleration aThrust;
         //aThrust.setDDX(sin(angle) * v.getDY());
         //aThrust.setDDY(cos(angle) * v.getDX());
         //v.add(aThrust, 0.1);
         //pt.addY(cos(angle) * v.getDX());
         //pt.addX(sin(angle) * v.getDY());
         a.setDDX(a.computeHorizontalComp(-angle, tThrust));
         a.setDDY(a.computeVerticalComp(angle, tThrust));
         fuel -= 10;
      }
   }
   else
   {
      fuel = 0;
   }
   v.add(a, 0.1);
   pt.add(a, v, 0.1);
   // create gravity (this is what if feels like to be a god)
   //Acceleration aGravity;
   //aGravity.setDDX(0.0);
  // aGravity.setDDY(-1.6);
   
   // update velocity according to acceleration
  // v.add(aGravity, 0.1);
   //v.setDX(v.add(aGravity.getDDX(), 0.1));
   //v.setDY(v.add(aGravity.getDDY(), 0.1));
   //v.setDX(v.getDX() + aGravity.getDDX() * 0.1);
   //v.setDY(v.getDY() + aGravity.getDDY() * 0.1);
   
   
}
/***********************************************************************
 * Returns velocity
 ************************************************************************/
Velocity Lander::getVelocity()
{
   return v;
}

double Lander::getAngle()
{
   return angle;
}

/***********************************************************************
 * Lander coast.
 ************************************************************************/
void Lander::coast(Acceleration a)
{
   if (status == FLYING)
   {
      a.setDDY(a.getDDY() + GRAVITY);

      v.add(a, 0.1);
      // update position according to velocity
      //pt.addX(v.getDX());
      //pt.addY(v.getDY());

      pt.add(a, v, 0.1);
   }
}

/***********************************************************************
 * Lander land.
 ************************************************************************/
void Lander::land()
{
}

 
/***********************************************************************
 *  Detect collision.
 ************************************************************************/
void Lander::crash()
{
}
