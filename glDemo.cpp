/*************************************************************
 * 1. Name:
 *      Ben Painter and Star Balls
 * 2. Assignment Name:
 *      Lab 04: Apollo 11 Visuals
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      The most difficult part for us was adding 50 stars to the simulation.
 *      We were able to create a Star class and create an instance of it in 
 *      the Demo main file, but it took a bit of troubleshooting to add fifty
 *      of the stars. We're still a bit confused about the pDemo and ->.
 * 5. How long did it take for you to complete the assignment?
 *     It took us about 7 hours. We spent four hours using Zoom to talk about
 *     the different things we needed to do and troubleshooting the stars. 
 *     we both spent a lot of time individually working on the stars. 
 *****************************************************************/

/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "star.h"
#include "lander.h"
#include "thrust.h"
#include <list>
#include <math.h> 


using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(const Point& ptUpperRight) :
          angle(0.0),
          lander(ptUpperRight),
          //lander.getPosition()(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
          ground(ptUpperRight)     
   { 
      for (int i = 0; i < 50; i++)
      {
         Point pt;
         bool onGround = true;
         while (onGround)
         {
            Point  pt(random(0.0, 400.0), random(0.0, 400.0)); 
            if (ground.getElevation(pt) > 0)
            {
               Star starTest(pt);
               starList.push_back(starTest);
               onGround = false;
            }
         }
      }      
   }

   // this is just for test purposes.  Don't make member variables public!
   //Point lander.getPosition();           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   Ground ground;
   Lander lander;
   Thrust thrust;
   list<Star> starList;  
};

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

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo * pDemo = (Demo *)p;  

   pDemo->thrust.set(*pUI);
   pDemo->lander.input(*pUI);
   // move the ship around
  // pDemo->lander.getPosition().addY(-1.625);// is a constant gravity
      

   // draw the ground
   pDemo->ground.draw(gout);

   // draw the lander and its flames
   gout.drawLander(pDemo->lander.getPosition() /*position*/, pDemo->angle /*angle*/);
   gout.drawLanderFlames(pDemo->lander.getPosition(), pDemo->angle, /*angle*/
                    pUI->isDown(), pUI->isLeft(), pUI->isRight());

   // put some text on the screen
   gout.setPosition(Point(25.0, 380.0));
   gout << "Fuel (" << (int)pDemo->lander.getPosition().getX() << ", " << (int)pDemo->lander.getPosition().getY() << ")" << "\n";

   // put some text on the screen
   gout.setPosition(Point(25.0, 360.0));
   gout << "Altitude (" << (int)pDemo->lander.getPosition().getY() << ")" << "\n";

   // put some text on the screen
   gout.setPosition(Point(25.0, 340.0));
   gout << "Speed (" << (int)pDemo->lander.getPosition().getX() << ", " << (int)pDemo->lander.getPosition().getY() << ")" << "\n";

   // draw our little stars
   list<Star>::iterator it = pDemo->starList.begin();
   for (it = pDemo->starList.begin(); it != pDemo->starList.end(); ++it)
   {
      it->draw(gout);
   }

  
}



/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
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
                "Open GL Demo", 
                 ptUpperRight);

   // Initialize the game class
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}
