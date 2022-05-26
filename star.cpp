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
Star::Star() 
{
   pt.setX(random(0.0, 400.0));
   pt.setY(random(0.0, 400.0));
   phase = random(0, 255);
}


 
/************************************
* Resets a star.
**************************************/
void Star::reset(Point ptUpperRight)
{
   pt.setX(random(0.0, ptUpperRight.getX()));
   pt.setY(random(0.0, ptUpperRight.getY()));
}

/**********************************************
* Uses the uiDraw drawStar method to put a star
* on the screen.
***********************************************/
void Star::draw(ogstream& gout) 
{

   gout.drawStar(pt, phase++);

}
