#include "thrust.h"

/***********************************************************************
 * Thrust
 ************************************************************************/

// constructor
Thrust::Thrust()
{

}

/***********************************************************************
 * Thrust rotation.
 ************************************************************************/
void Thrust::rotation()
{

}

/***********************************************************************
 * Thrust main engine.
 ************************************************************************/
void Thrust::mainEngineThrust()
{

}

/***********************************************************************
 * Returns main engine state.
 ************************************************************************/
bool Thrust::isMain()
{
   return mainEngine;
}

/***********************************************************************
 * Thrust clock.
 ************************************************************************/
bool Thrust::isClock()
{
   return clockwise;
}

/***********************************************************************
 * Thrust is counter.
 ************************************************************************/
bool Thrust::isCounter()
{
   return counterClockwise;
}

/***********************************************************************
 * Updates a member variable?
 ************************************************************************/
void Thrust::set(const Interface & pUI) 
{
   if (pUI.isRight())
    { }
      //pDemo->angle -= 0.1;
   if (pUI.isLeft())
   { }
      //pDemo->angle += 0.1;
   //if (pUI->isUp())
      //pDemo->lander.getPosition().addY(-1.0);
   if (pUI.isDown())
    { }
}