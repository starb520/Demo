#include "lander.h"
#include <cassert>

/***********************************************************************
 * LANDER
 * Calls reset to initialize all attributes of lander
 ************************************************************************/
Lander::Lander(const Point ptUpperRight)
{
   reset(ptUpperRight);
}

/***********************************************************************
 * Lander RESET
 * Resets all the values of the lander
 ************************************************************************/
void Lander::reset(const Point ptUpperRight)
{
   status = FLYING;
   pt.setX(400.0);
   pt.setY(400.0);
   angle = 0.0;
   this->ptUpperRight = ptUpperRight;
   fuel = 5000.00;
   v.setDX(-5.0);
   v.setDY(1.0);
   tThrust = THRUST / WEIGHT;
}


/***********************************************************************
 * Lander IS DEAD
 * Returns if the lunar module has crashed
 ************************************************************************/
bool Lander::isDead(const Ground ground)
{
   if (ground.getElevation(pt) <= 0.0)
      return true;
   else
      return false;
}


/***********************************************************************
 * Lander IS LANDED
 * Returns if the lunar module has landed.
 ************************************************************************/
bool Lander::isLanded(const Ground ground)
{
   if (ground.onPlatform(pt, 20) && v.getSpeed() <= 4.0 && (angle > 5.78 || angle < 0.5))
      return true;
   else 
      return false;
}

/***********************************************************************
 * Lander IS FLYING
 * Returns if the lunar module is in the air.
 ************************************************************************/
bool Lander::isFlying()
{
   if (status == FLYING)
      return true;
   else
      return false;
}

/***********************************************************************
 * Lander DRAW
 * Draws the lunar module.
 ************************************************************************/
void Lander::draw(const Interface& pUI, ogstream& gout)
{
   gout.drawLander(pt, angle);
   if (fuel > 0 && status == FLYING) // checking fuel and status before drawing flames
      gout.drawLanderFlames(pt, angle, 
                            pUI.isDown(), pUI.isLeft(), pUI.isRight());
}



/***********************************************************************
 * Lander INPUT
 * Takes the user input and adjusts the lander
 * according to what was pressed.
 ************************************************************************/
void Lander::input(const Interface& pUI,  Acceleration& a)
{
   if (fuel > 0.0 && status == FLYING ) 
   {
      assert(fuel >= 0.0);
      if (pUI.isRight())
      {
         fuel -= 1.0;
         angle -= 0.1;

         // normalize angle
         angle = angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI);
         assert(angle >= 0 && angle <= (2.00 * M_PI)); // checking for normalized angle
      }
      if (pUI.isLeft())
      {
         fuel -= 1.0;
         angle += 0.1;

         // normalize angle
         angle = angle - floor(angle / (2.00 * M_PI)) * (2.00 * M_PI);
         assert(angle >= 0 && angle <= (2.00 * M_PI)); // checking for normalized angle
      }
      if (pUI.isDown())
      {
         assert(a.getDDX() == 0.0);
         assert(a.getDDY() == 0.0);
         a.setDDX(a.computeHorizontalComp(-angle, tThrust));
         a.setDDY(a.computeVerticalComp(angle, tThrust));
         fuel -= 10.0;
      }
   }
   else
   {
      fuel = 0.0; // setting fuel to be zero if fuel runs out
   }   
}

/***********************************************************************
 * Lander COAST
 * Updates the position according to the 
 * speed of the lander.
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
 * Lander LAND
 * Checks if the lander has landed and updates
 * the status if landing was a success.
 ************************************************************************/
void Lander::land(const Ground ground)
{
   if (isLanded(ground))
   {
      // stopping all movement and sets the lander up right
      status = LANDED;
      v.setDX(0.0);
      v.setDY(0.0);
      angle = 0.0;
   }

}

 
/***********************************************************************
 * Lander CRASH
 * Checks if the lander has hit the ground 
 * and updates the status.
 ************************************************************************/
void Lander::crash(const Ground ground)
{
   if (isDead(ground))
   {
      // stopping all movement and flipping lander upside down
      status = CRASHED;
      v.setDX(0.0);
      v.setDY(0.0);
      angle = M_PI;
   }
}
