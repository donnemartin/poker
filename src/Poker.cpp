// COPYRIGHT © 2011, Donne Martin
// All Rights Reserved.
//
//******************************************************************************
//
// File Name:     Poker.cpp
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

#include "stdafx.h"
#include <exception>
#include <iostream>
#include "Poker.h"

//******************************************************************************
// File scope (static) variable definitions
//******************************************************************************

// None

//******************************************************************************
// Function : main             
// Process  : Runs Poker                                                    
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************   
int _tmain(int argc, _TCHAR* argv[])
{
   Poker poker;
   poker.runPoker();
   
	return 0;
} // end _tmain

//******************************************************************************
// Function : constructor                                   
// Process  : None                   
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************                    
Poker::Poker() 
{

} // end Poker::Poker

//******************************************************************************
// Function : destructor                                   
// Process  : None           
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
Poker::~Poker()
{
} // end Poker::~Poker

//***************************************************************************
// Function : outputCardNumbers                                   
// Process  : Output the card number values of each hand (ie Ace = 14)
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void Poker::outputCardNumbers() const
{
   cout << "---Card Number Values For Comparing Hands---" << endl;
   cout << Card::TWO    << "  Two "    << endl;
   cout << Card::THREE  << "  Three "  << endl;
   cout << Card::FOUR   << "  Four "   << endl;
   cout << Card::FIVE   << "  Five "   << endl;
   cout << Card::SIX    << "  Six "    << endl;
   cout << Card::SEVEN  << "  Seven "  << endl;
   cout << Card::EIGHT  << "  Eight "  << endl;
   cout << Card::NINE   << "  Nine "   << endl;
   cout << Card::TEN    << " Ten "     << endl;
   cout << Card::JACK   << " Jack "    << endl;
   cout << Card::QUEEN  << " Queen "   << endl;
   cout << Card::KING   << " King "    << endl;
   cout << Card::ACE    << " Ace "     << endl << endl;
}

//***************************************************************************
// Function : runPoker                                   
// Process  : Run the poker program
//             Generate the set of hands and output them
//             Output the card number legend for ranking
//             Create the poker ranker
//             Rank the hands and output the results
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void Poker::runPoker() const
{
   // Generate the set of hands and ouputs each hand
   HandGenerator generator;
   generator.generateHands();

   // Output our legend for card numbers
   this->outputCardNumbers();

   // Obtain the hands for use
   vector<Hand> hands;
   generator.getHands(hands);

   // Create our ranker and set its hands
   HandRanker ranker(hands);

   // Rank each hand
   ranker.rankHands();

   // Compare hands and output results
   ranker.compareAllHands();
   
   // Don't let the game terminate by itself
   char pauseBeforeTerminate = ' '; 
   cin >> pauseBeforeTerminate;
}
      