#include "lander.h"

/***********************************************************************
 * Moon Lander: has all the details for the moon lander
 ************************************************************************/



Lander::Lander(Point ptUpperRight)
{
}

void Lander::reset()
{
}


bool Lander::isDead()
{
   return false;
}


bool Lander::isLanded()
{
   return false;
}

bool Lander::isFlying()
{
   return false;
}

// keep track of the position of the moon lander
Point Lander::getPosition()
{
   return Point();
}

// fuel status LM
int Lander::getFuel()
{
   return 0;
}

void Lander::draw(double thrust, ogstream gout)
{
}

void Lander::input(double thrust)
{
}

void Lander::coast()
{
}

void Lander::land()
{
}

// detect collision
void Lander::crash()
{
}
