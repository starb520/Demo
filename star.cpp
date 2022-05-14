#include "star.h"
#include "point.h"
#include "uiDraw.h"  // for ogstream

using namespace std;

/************************************
* Star Class
**************************************/

Star::Star()
{

}


Star::Star(const Point& ptUpperRight) : pt(random(20.0, 400.0), random(20.0, 400.0))
   

{
   
   phase = random(0, 255);  // this is high so the brightness of the star is high, once its working we can change it back to (0,255)
   
}
 
void Star::reset(double width, double height)
{

}

void Star::draw(ogstream& gout) 
{
  /* gout.drawStar(Point(random(0, 255), random(0, 255)), phase);*/
  
   //pt = Point(random(0, 255), random(0, 255));
   //for (int i = 0; i < 2; i++)
   //{    
   //   gout.drawStar(pt, phase);   
   //}

   gout.drawStar(pt, phase++);

}
