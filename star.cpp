#include "star.h"
#include "point.h"

using namespace std;

/************************************
* Star Class
**************************************/

Star::Star (const Point& ptUpperRight) : 
   pt(ptUpperRight.getX() - random(20, 300), ptUpperRight.getY() - random(20, 300))

{
   phase = random(245, 255);
   
}
 
void Star::reset(double width, double height)
{

}

void Star::draw(ogstream& gout) const
{
   ogstream d;
   
   for (int i = 0; i < 40; i++) 
   {
      
      d.drawStar(pt, phase);
      /*gout.drawStar(pt, phase);*/
   }

}
