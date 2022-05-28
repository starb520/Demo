#include "star.h"
#include "point.h"
#include "uiDraw.h"  // for ogstream

using namespace std;

/************************************
* Star Class
* Stores the position and phase of 
* a star and displays it
**************************************/

/************************************
* Star constructor.
**************************************/
Star::Star() 
{
   reset();
   phase = random(0, 255);
}

/************************************
* Star RESET
* Resets a star position
**************************************/
void Star::reset()
{
   pt.setX(random(0.0, 400.0));
   pt.setY(random(0.0, 400.0));
}

/**********************************************
* Star DRAW
* Uses the uiDraw drawStar method to put a star
* on the screen.
***********************************************/
void Star::draw(ogstream& gout) 
{
   gout.drawStar(pt, phase++);
}
