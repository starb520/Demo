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
   Star();
   //Star(Point pt);

   // resets the stars after crash/land
   void reset(double width, double height);

   // draws the star
   void draw(ogstream& gout) ;

};

