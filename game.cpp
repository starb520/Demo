/*************************************************************
 * 1. Name:
 *      Ben Painter and Star Balls
 * 2. Assignment Name:
 *      Lab 06: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      Since this "simulator" took weeks to complete we feel
 *      that the most difficult part, overall, was understanding
 *      velocity, acceleration, thrust, and angle. All of these 
 *      components work together and understanding when to apply 
 *      the formulas to calculate the needed values was difficult
 *      to figure out.
 * 5. How long did it take for you to complete the assignment?
 *      5 Hours 
 *****************************************************************/

/**********************************************************************
 * Game
 * Just a simple program to Gamenstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "star.h"
#include "lander.h"
#include <iomanip>   // presicion
#include <cassert>   // asserts


using namespace std;


/*************************************************************************
 * Game
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Game
{
public:
   Game(const Point& ptUpperRight) :
          lander(ptUpperRight),
          ground(ptUpperRight)     
   {}

   Point ptUpperRight;   // size of the screen
   Ground ground;
   Lander lander;
   Star   starArray[80]; // an array of stars
};

void resetGame(Game* pGame, const int lengthStars);

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;
   Acceleration a;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Game * pGame = (Game *)p;  

   // finding length of array to be used for looping through the array of stars
   int lengthStars = sizeof(pGame->starArray) / sizeof(pGame->starArray[0]);

   // move the ship around
   pGame->lander.input(*pUI, a);
   pGame->lander.coast(a);

   // check for updates
   pGame->lander.land(pGame->ground);
   pGame->lander.crash(pGame->ground);
   


   // draw our little stars
   for (int i = 0; i < lengthStars; i++)
      pGame->starArray[i].draw(gout);

   // draw the ground
   pGame->ground.draw(gout);

   // draw the lander and its flames
   pGame->lander.draw(*pUI, gout);

   // put some text on the screen
   gout.setPosition(Point(25.0, 380.0));
   gout << "Fuel:     " << pGame->lander.getFuel() << " lbs" << "\n";

   // put some text on the screen
   gout.setPosition(Point(25.0, 360.0));
   gout << "Altitude: " << (int)pGame->ground.getElevation(pGame->lander.getPosition()) << " meters" << "\n";

   // put some text on the screen
   gout.setPosition(Point(25.0, 340.0));
   gout << setprecision(3) << "Speed:   "<<pGame->lander.getVelocity().getSpeed() << " m/s" << "\n";



   // put some text if lander lands
   if (pGame->lander.isLanded(pGame->ground))
   {
      gout.setPosition(Point(140.0, 300.0));
      gout << "The Eagle has landed!\n";
   }

   // put some text if lander crashed
   if (pGame->lander.isDead(pGame->ground))
   {
      gout.setPosition(Point(130.0, 300.0));
      gout << "Houston, we have a problem!\n";  
   }  


   // checking for reset
   if (pGame->lander.isFlying() == false && (*pUI).isUp())
   {
      resetGame(pGame, lengthStars);
   }
}


/**********************************
* RESET GAME
* Resets all the values for Ground,
* Lander, and Stars
*************************************/

void resetGame(Game *pGame,const int lengthStars)
{
   pGame->ground.reset();
   pGame->lander.reset(pGame->ptUpperRight);
   assert(pGame->lander.getAngle() == 0.0);   // checking that angle was reset
   assert(pGame->lander.getFuel() == 5000.0); // checking that fuel was reset
   for (int i = 0; i < lengthStars; i++)
      pGame->starArray[i].reset();
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my Game type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL, 
                "Open GL Game", 
                 ptUpperRight);

   // Initialize the game class
   Game Game(ptUpperRight);

   // set everything into action
   ui.run(callBack, &Game);             

   return 0;
}
