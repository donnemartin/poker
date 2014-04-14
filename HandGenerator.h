//******************************************************************************
//
// File Name:     HandGenerator.h
//
// File Overview: Represents a Hand Generator to generate hands of cards
//                Test harness to evaluate the ranking behavior
//
//******************************************************************************
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//******************************************************************************

#ifndef HandGenerator_h
#define HandGenerator_h

#include "Hand.h"

//******************************************************************************
//
// Class:    HandGenerator
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//
// Notes    : None
//
//******************************************************************************
class HandGenerator
{
public:

   //***************************************************************************
   // Function    : constructor                                   
   // Description : None              
   // Constraints : None
   //***************************************************************************
   HandGenerator();

   //***************************************************************************
   // Function    : destructor                                   
   // Description : Performs cleanup tasks              
   // Constraints : None
   //***************************************************************************
   virtual ~HandGenerator();   

   // Member functions in alphabetical order
   
   //***************************************************************************
   // Function    : addHand                                   
   // Description : Adds the specified hand      
   //                Optionally prints the cards in the hand (default true)
   // Constraints : None
   //***************************************************************************
   void addHand(const Hand& hand, const bool printCards = true);
   
   //***************************************************************************
   // Function    : generateFlush                                   
   // Description : Generates the flush hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateFlush();
   
   //***************************************************************************
   // Function    : generateFourOfAKind                                   
   // Description : Generates the four of a kind hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateFourOfAKind();
   
   //***************************************************************************
   // Function    : generateFullHouse                                   
   // Description : Generates the full house hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateFullHouse();

   //***************************************************************************
   // Function    : generateHands                                   
   // Description : Generates the hands by calling other generate- functions            
   // Constraints : None
   //***************************************************************************
   void generateHands();
   
   //***************************************************************************
   // Function    : generateHighCard                                   
   // Description : Generates the high card hands lissted in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateHighCard();
   
   //***************************************************************************
   // Function    : generateOnePair                                   
   // Description : Generates the pair hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateOnePair();
   
   //***************************************************************************
   // Function    : generateStraight                                   
   // Description : Generates the straight hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateStraight();
   
   //***************************************************************************
   // Function    : generateStraightFlush                                   
   // Description : Generates the straight flush hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateStraightFlush();
   
   //***************************************************************************
   // Function    : generateStraightFlushAndFourOfAKind                                   
   // Description : Generates straight flush vs four of a kind hands            
   // Constraints : None
   //***************************************************************************
   void generateStraightFlushAndFourOfAKind();
   
   //***************************************************************************
   // Function    : generateThreeOfAKind                                   
   // Description : Generates the three of a kind hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateThreeOfAKind();
   
   //***************************************************************************
   // Function    : generateTwoPair                                   
   // Description : Generates the two pair hands listed in wikipedia            
   // Constraints : None
   //***************************************************************************
   void generateTwoPair();
   
   //***************************************************************************
   // Function    : getHand                                   
   // Description : Retrieves the specified hand given the index            
   // Constraints : Throws an exception if the index is invalid
   //***************************************************************************
   inline void getHand(int index, Hand& hand) const;
   
   //***************************************************************************
   // Function    : getHands                                   
   // Description : Retrieves all hands            
   // Constraints : None
   //***************************************************************************
   inline void getHands(vector<Hand>& hands) const;
   
   //***************************************************************************
   // Function    : setHands                                   
   // Description : Sets the hands            
   // Constraints : None
   //***************************************************************************
   inline void setHands(const vector<Hand>& hands);
   
private:   
   vector<Hand> hands;
}; // end class HandGenerator

//***************************************************************************
// Function : getHand                                   
// Process  : Retrieve the specified hand given the index            
// Notes    : Throw an exception if the index is invalid
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void HandGenerator::getHand(int index, Hand& hand) const
{
   hand = this->hands.at(index);
} // end HandGenerator::getHand

//***************************************************************************
// Function : getHands                                   
// Process  : Retrieve all hands            
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void HandGenerator::getHands(vector<Hand>& hands) const
{
   hands = this->hands;
} // end HandGenerator::getHands

//***************************************************************************
// Function : setHands                                   
// Process  : Set the hands            
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void HandGenerator::setHands(const vector<Hand>& hands)
{
   this->hands = hands;
} // end HandGenerator::setHands

#endif // HandGenerator_h