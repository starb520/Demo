/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "point.h"
#include <cassert>

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(double x, double y) : x(0.0), y(0.0)
{
   setX(x);
   setY(y);
}


/*******************************************
 * POINT Add 
 *       Updates both X and Y of the position.
 ********************************************/
void Point::add(Acceleration accel, Velocity vel, double time)
{
   setX(x + (vel.getDX() * time) + (.5 * accel.getDDX() * (time * time)));
   setY(y + (vel.getDY() * time) + (.5 * accel.getDDY() * (time * time)));

}

/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}
   

