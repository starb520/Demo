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
   fuel = 10000.00;
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
bool Lander::isDead()
{
   return false;
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
   return 0;
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
void Lander::input(const Interface& pUI)
{
   if (pUI.isRight())
   {
      angle -= 0.1;
   }
   //pDemo->angle -= 0.1;
   if (pUI.isLeft())
   {
      angle += 0.1;
   }
   if (pUI.isDown())
   {
      pt.addY(cos(angle) * 3);
      pt.addX(sin(angle) * -1);
   }
   
   // create gravity (this is what if feels like to be a god)
   Acceleration aGravity;
   aGravity.setDDX(0.0);
   aGravity.setDDY(-1.6);
   
   // update velocity according to acceleration
   v.setDX(v.getDX() + aGravity.getDDX() * 0.1);
   v.setDY(v.getDY() + aGravity.getDDY() * 0.1);

   // update position according to velocity
   pt.addX(v.getDX());
   pt.addY(v.getDY());

}

/***********************************************************************
 * Lander coast.
 ************************************************************************/
void Lander::coast()
{
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
