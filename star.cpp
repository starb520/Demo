#include "star.h"
#include "point.h"
#include "uiDraw.h"  // for ogstream

using namespace std;

/************************************
* Star Class
**************************************/


/************************************
* Star constructor.
**************************************/
Star::Star(Point ptUpperRight) 
{
   reset(ptUpperRight);
}


 
/************************************
* Resets a star.
**************************************/
void Star::reset(Point ptUpperRight)
{
   pt.setX(random(0.0, ptUpperRight.getX()));
   pt.setY(random(0.0, ptUpperRight.getY()));
   phase = random(0, 255);
}

/**********************************************
* Uses the uiDraw drawStar method to put a star
* on the screen.
***********************************************/
void Star::draw(ogstream& gout) 
{

   gout.drawStar(pt, phase++);

}
