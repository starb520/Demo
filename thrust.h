#pragma once

/***********************************************************************
 * Thrust
 ************************************************************************/

class Thrust
{
private:
   bool mainEngine;
   bool clockwise;
   bool counterClockwise;

public:
   // constructor
   Thrust();

   // updates the rotation
   void rotation();

   // runs the main engine
   void mainEngineThrust();

   // boolean of which engines are on
   bool isMain();
   bool isClock();
   bool isCounter();

   // updates a member variable
   void set(double UI);
};

