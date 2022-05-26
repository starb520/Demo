#pragma once
#include "point.h"
#include "uiDraw.h"  // for ogstream


/***********************************************************************
 * Star
 * Holds the position and phase of one star
 ************************************************************************/
class Star
{
private:

   Point pt;
   char phase;

public:
   //constructors
   Star(Point ptUpperRight);

   // resets the stars after crash/land
   void reset(Point ptUpperRight);

   // draws the star
   void draw(ogstream& gout) ;

};

