#include "star.h"
#include "point.h"
#include "uiDraw.h"  // for ogstream

using namespace std;

/************************************
* Star Class
**************************************/

Star::Star() 
{
   //this->pt = (random(0.0, 400.0), random(0.0, 400.0))
   pt.setX(random(0.0, 400.0));
   pt.setY(random(0.0, 400.0));
   phase = random(0, 255);
}

/************************************
* Star constructor.
**************************************/
Star::Star(Point pt)  

{
   this->pt = pt;
   phase = random(0, 255);
}
 
/************************************
* Resets a star.
**************************************/
void Star::reset(double width, double height)
{

}

/**********************************************
* Uses the uiDraw drawStar method to put a star
* on the screen.
***********************************************/
void Star::draw(ogstream& gout) 
{

   gout.drawStar(pt, phase++);

}
