#include "lander.h"
#include "acceleration.h"

/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/
Lander::Lander(Point ptUpperRight)
{
   reset(ptUpperRight);
}

/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/
void Lander::reset(Point ptUpperRight)
{
   status = FLYING;
   pt.setX(400);
   pt.setY(400);
   angle = 0.0;
   this->ptUpperRight = ptUpperRight;
   fuel = 5000.00;
   v.setDX(-5);
   v.setDY(0);
   tThrust = THRUST / WEIGHT;
}


/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/
bool Lander::isDead(Ground ground)
{
   
   if (ground.getElevation(pt) <= 0) 
      return true;
   else
      return false;
}


/***********************************************************************
 * Returns if the lunar module has landed.
 ************************************************************************/
bool Lander::isLanded(Ground ground)
{
   if (ground.onPlatform(pt, 20) && v.getSpeed() <= 4 && (angle > 5.78 || angle < .5))
      return true;
   else 
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
 * Draws the lunar module.
 ************************************************************************/
void Lander::draw(const Interface& pUI, ogstream& gout)
{
   gout.drawLander(pt, angle);
   if (fuel > 0 && status == FLYING)
      gout.drawLanderFlames(pt, angle, 
                            pUI.isDown(), pUI.isLeft(), pUI.isRight());
}

#include <cassert>

/***********************************************************************
 * Lander input.
 ************************************************************************/
void Lander::input(const Interface& pUI,  Acceleration& a)
{
   

   if (fuel > 0 && status == FLYING ) 
   {
      if (pUI.isRight())
      {
         angle -= 0.1;
         angle = angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI);
         fuel -= 1;
      }

      if (pUI.isLeft())
      {
         fuel -= 1;
         angle += 0.1;
         angle = angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI);
      }
      if (pUI.isDown())
      {
         assert(a.getDDX() == 0.0);
         assert(a.getDDY() == 0.0);
         a.setDDX(a.computeHorizontalComp(-angle, tThrust));
         a.setDDY(a.computeVerticalComp(angle, tThrust));
         fuel -= 10;
      }
   }
   else
   {
      fuel = 0;
   }

//   v.add(a, 0.1);
//   pt.add(a, v, 0.1);  
   
}

/***********************************************************************
 * Lander coast.
 ************************************************************************/
void Lander::coast(Acceleration & a)
{
   if (status == FLYING)
   {
      a.setDDY(a.getDDY() + GRAVITY);

      v.add(a, 0.1);

      pt.add(a, v, 0.1);
   }
}

/***********************************************************************
 * Lander land.
 ************************************************************************/
void Lander::land(Ground ground)
{
   if (isLanded(ground))
   {
      status = LANDED;
      v.setDX(0);
      v.setDY(0);
      angle = 0;
   }

}

 
/***********************************************************************
 *  Detect collision.
 ************************************************************************/
void Lander::crash(Ground ground)
{
   if (isDead(ground))
   {
      status = CRASHED;
      v.setDX(0);
      v.setDY(0);
      angle = M_PI;
   }
}
