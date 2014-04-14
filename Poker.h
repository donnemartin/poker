//******************************************************************************
//
// File Name:     Poker.h
//
// File Overview: Represents Poker that generates and ranks hands
//
//******************************************************************************
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//******************************************************************************

#ifndef Poker_h
#define Poker_h

#include "HandGenerator.h"
#include "HandRanker.h"

//******************************************************************************
//
// Class:    Poker
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//
// Notes    : None
//
//******************************************************************************
class Poker
{
public:

   //***************************************************************************
   // Function    : constructor                                   
   // Description : Initializes data members to invalid values              
   // Constraints : None
   //***************************************************************************
   Poker();

   //***************************************************************************
   // Function    : destructor                                   
   // Description : Performs cleanup tasks              
   // Constraints : None
   //***************************************************************************
   virtual ~Poker();   

   //***************************************************************************
   // Function    : runPoker                                   
   // Description : Executes the poker program            
   // Constraints : None
   //***************************************************************************
   void runPoker() const;
   
private:   
   //***************************************************************************
   // Function    : outputCardNumbers                                   
   // Description : Called by runPoker.  Internal use only.            
   // Constraints : None
   //***************************************************************************
   void outputCardNumbers() const;

   // No data members

}; // end class Poker
   
#endif // Poker_h