#pragma once
#include "point.h"
#include "uiDraw.h"  // for ogstream

class Star
{
private:

   Point pt;
   char phase;
   Point ptUpperRight;

public:
   Star();
   Star(Point pt);
   void reset(double width, double height);
   void draw(ogstream& gout) ;

};

