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

   void rotation();
   void mainEngineThrust();
   bool isMain();
   bool isClock();
   bool isCounter();

   // updates a member variable
   void set(double UI);
};

