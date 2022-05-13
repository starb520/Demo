#include "star.h"
#include "point.h"

using namespace std;

/************************************
* Star Class
**************************************/

Star::Star()
{

}


Star::Star(Point pt) :
   pt(pt)
{
   phase = random(0, 255);  // this is high so the brightness of the star is high, once its working we can change it back to (0,255)
   
}
 
void Star::reset(double width, double height)
{

}

void Star::draw(ogstream& gout) 
{
   ogstream d; 
   d.drawStar(pt, phase++);

}
