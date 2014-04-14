//******************************************************************************
//
// File Name:     HandRanker.h
//
// File Overview: Represents a Hand Ranker to rank a hand of cards
//
//******************************************************************************
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//******************************************************************************

#ifndef HandRanker_h
#define HandRanker_h

#include "Hand.h"

//******************************************************************************
//
// Class:    HandRanker
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class         
//
// Notes    : Relies on the hands to be sorted from highest to lowest
//
//******************************************************************************
class HandRanker
{
public:

   // Forward declaration for Hand enum used in member function params
   enum CompareResult;

   //***************************************************************************
   // Function    : constructor                                   
   // Description : None    
   //                Not the recommended constructor        
   // Constraints : Need to set hands afterwards
   //***************************************************************************
   HandRanker();

   //***************************************************************************
   // Function    : constructor                                   
   // Description : Initializes hands to input value      
   //                Recommended constructor       
   // Constraints : None
   //***************************************************************************
   HandRanker(const vector<Hand>& hands);

   //***************************************************************************
   // Function    : destructor                                   
   // Description : Performs cleanup tasks              
   // Constraints : None
   //***************************************************************************
   virtual ~HandRanker();   

   // Member functions in alphabetical order
   
   //***************************************************************************
   // Function    : addHand                                   
   // Description : Adds the specified hand to list of hands to be ranked            
   // Constraints : None
   //***************************************************************************
   inline void addHand(const Hand& hand);
   
   //***************************************************************************
   // Function    : compareAllHands                                 
   // Description : Compares hands, [i vs i + 1], [i + 2 vs i + 3], etc
   //                Consider changing this algorithm to make it cleaner
   // Constraints : None
   //***************************************************************************
   void compareAllHands() const;
   
   //***************************************************************************
   // Function    : compareCardHandNumbers                                 
   // Description : Compares the input card hand's numbers  
   //                Determines which is larger             
   // Constraints : None
   //***************************************************************************
   HandRanker::CompareResult compareCardHandNumbers(
      const Hand& firstHand,
      const Hand& secondHand,
      const int   cardIndex) const;
   
   //***************************************************************************
   // Function    : compareCardNumbers                                 
   // Description : Compares the input card numbers
   //                Determines which is larger             
   // Constraints : None
   //***************************************************************************
   HandRanker::CompareResult HandRanker::compareCardNumbers(
      const Card::CardNumber firstCardNumber,
      const Card::CardNumber secondCardNumber) const;
   
   //***************************************************************************
   // Function    : compareFourOfAKind                                 
   // Description : Compares the two four of a kind hands             
   // Constraints : The input hands must be four of a kind hands
   //***************************************************************************
   HandRanker::CompareResult compareFourOfAKind(
      const Hand& firstHand, 
      const Hand& secondHand) const;
   
   //***************************************************************************
   // Function    : compareFullHouse                                 
   // Description : Compares the two full house hands             
   // Constraints : The input hands must be full house hands
   //***************************************************************************
   HandRanker::CompareResult compareFullHouse(
      const Hand& firstHand, 
      const Hand& secondHand) const;

   //***************************************************************************
   // Function    : compareHands                                 
   // Description : Compares the hands       
   // Constraints : None
   //***************************************************************************
   void compareHands(
      const Hand& firstHand, 
      const Hand& secondHand) const;
   
   //***************************************************************************
   // Function    : compareHandsOfSameType                                 
   // Description : Compares hands of same type (ie straight vs straight)             
   // Constraints : The input hands must be of the same type
   //***************************************************************************
   HandRanker::CompareResult compareHandsOfSameType(
      const Hand& firstHand, 
      const Hand& secondHand) const;
   
   //***************************************************************************
   // Function    : compareHighCards                                 
   // Description : Compares the hands by determining the high cards     
   //                Called when comparing straight flush, straight,
   //                flush, and high card types
   // Constraints : None
   //***************************************************************************
   HandRanker::CompareResult compareHighCards(
      const Hand& firstHand, 
      const Hand& secondHand) const;
   
   //***************************************************************************
   // Function    : compareOneOrTwoPair                                 
   // Description : Compares the hands by determining the pairs then high cards  
   //                Called when comparing pair or two pair types              
   // Constraints : The input hands must be pair or two pair hands
   //***************************************************************************
   HandRanker::CompareResult compareOneOrTwoPair(
      const Hand& firstHand, 
      const Hand& secondHand) const;
   
   //***************************************************************************
   // Function    : compareThreeOfAKind                                 
   // Description : Compares the two three of a kind hands             
   // Constraints : The input hands must be three of a kind hands
   //***************************************************************************
   HandRanker::CompareResult compareThreeOfAKind(
      const Hand& firstHand, 
      const Hand& secondHand) const;
   
   //***************************************************************************
   // Function    : fixSortOrderIfLowAce                                 
   // Description : Calls isLowAceStraight
   //                Calls fixLowAceStraightSort if needed            
   // Constraints : Consider making private
   //***************************************************************************
   void fixSortOrderIfLowAce(Hand& hand) const;
   
   //***************************************************************************
   // Function    : getHand                                   
   // Description : Accessor for hand            
   // Constraints : None
   //***************************************************************************
   inline void getHand(const int index, Hand& hand) const;
   
   //***************************************************************************
   // Function    : getHands                                   
   // Description : Accessor for hands            
   // Constraints : None
   //***************************************************************************
   inline void getHands(vector<Hand>& hands) const;
      
   //***************************************************************************
   // Function    : getHandsSize                                   
   // Description : Retrieves the size of Hands            
   // Constraints : None
   //***************************************************************************
   inline int getHandsSize() const;
   
   //***************************************************************************
   // Function    : isFlush                                   
   // Description : Determines if the input hand is a flush            
   // Constraints : None
   //***************************************************************************
   bool isFlush(const Hand& hand) const;
   
   //***************************************************************************
   // Function    : isLowAceStraight                                 
   // Description : Determines if the input hand is a low ace straight (5 to A)             
   // Constraints : None
   //***************************************************************************
   bool isLowAceStraight(const Hand& hand) const;
   
   //***************************************************************************
   // Function    : isStraight                                   
   // Description : Determines if the input hand is a straight              
   // Constraints : None
   //***************************************************************************
   bool isStraight(const Hand& hand) const;
   
   //***************************************************************************
   // Function    : isStraightFlush                                   
   // Description : Determines if the input hand is a straight flush              
   // Constraints : None
   //***************************************************************************
   bool isStraightFlush(const Hand& hand) const;
   
   //***************************************************************************
   // Function    : printHandComparisonHeader                                   
   // Description : Prints the header showing hand vs hand           
   // Constraints : None
   //***************************************************************************
   void printHandComparisonHeader(
      const Hand& firstHand, 
      const Hand& secondHand) const;
   
   //***************************************************************************
   // Function    : printWinningHand                                 
   // Description : Prints the winning hand based on the result parameter             
   // Constraints : None
   //***************************************************************************
   void printWinningHand(
      const Hand& firstHand,
      const Hand& secondHand,
      const HandRanker::CompareResult result) const;
      
   //***************************************************************************
   // Function    : rankHand                                   
   // Description : Ranks the hand to determine its type (ie Straight)            
   // Constraints : None
   //***************************************************************************
   void rankHand(Hand& hand) const;
      
   //***************************************************************************
   // Function    : rankHands                                   
   // Description : Ranks all hands in the data member hands            
   // Constraints : None
   //***************************************************************************
   void rankHands();
   
   //***************************************************************************
   // Function    : setHands                                   
   // Description : Mutator for hands            
   // Constraints : None
   //***************************************************************************
   inline void setHands(const vector<Hand>& hands);
   
   //***************************************************************************
   // public Class Attributes.
   //***************************************************************************

   // Represents the result of hand comparison
   enum CompareResult
   {
      TIE,
      FIRSTWINNER,
      SECONDWINNER,
      INVALIDRESULT
   };   

private:   
   //***************************************************************************
   // Function    : buildHandRepetitionLists                                 
   // Description : Builds the hand's repetition lists which include
   //                singles, pairs, trips, and quads
   //                Returns the number of unique card numbers in the hand
   // Constraints : Private, called by rankHand
   //***************************************************************************
   int HandRanker::buildHandRepetitionLists(Hand& hand) const;

   //***************************************************************************
   // Function    : fixLowAceStraightSort                                 
   // Description : Puts the Ace at low end if we have a low straight             
   //                For example: 5, 4, 3, 2, 1 since the Ace = 14
   // Constraints : Does not determine if the input hand is a low straight
   //                Private, call fixSortOrderIfLowAce instead
   //***************************************************************************
   void fixLowAceStraightSort(Hand& hand) const;

   //***************************************************************************
   // Function    : rankHandRepetitions                                   
   // Description : Ranks the input hands based on the input card repetitions   
   //                Calls rankHandRepetitions
   //                Used for optimized hand ranking
   // Constraints : Private 
   //                Call the appropriate comparison function instead
   //                based on your hand and your needs, for example:
   //                   -compareHands
   //                   -compareHandsOfSameType
   //                   -compareFourOfAKind
   //***************************************************************************
   HandRanker::CompareResult HandRanker::rankHandRepetitions(
      const Hand& firstHand, 
      const Hand& secondHand,
      const Hand::CardRepetition repetition) const;
   
   //***************************************************************************
   // Function    : rankHandRepetitionVectors                                 
   // Description : Ranks the input hands based on the input card repetitions
   //                Called by rankHandRepetitions
   //                Used for optimized hand ranking
   // Constraints : Private 
   //                Call the appropriate comparison function instead
   //                based on your hand and your needs, for example:
   //                   -compareHands
   //                   -compareHandsOfSameType
   //                   -compareFourOfAKind
   //***************************************************************************
   HandRanker::CompareResult HandRanker::rankHandRepetitionVectors(
      const vector<Card::CardNumber>& firstVector,
      const vector<Card::CardNumber>& secondVector) const;

   vector<Hand>  hands; // List of hands to be ranked
}; // end class HandRanker
   
//***************************************************************************
// Function : addHand                                   
// Process  : Adds the specified hand to list of hands to be ranked   
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void HandRanker::addHand(const Hand& hand)
{
   this->hands.push_back(hand);
} // end HandRanker::addHand

//***************************************************************************
// Function : getHand                                   
// Process  : Accessor for hand
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void HandRanker::getHand(const int index, Hand& hand) const
{
   hand = this->hands.at(index);
} // end HandRanker::getHand

//***************************************************************************
// Function : getHands                                   
// Process  : Accessor for hands
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void HandRanker::getHands(vector<Hand>& hands) const
{
   hands = this->hands;
} // end HandRanker::getHands

//***************************************************************************
// Function : getHandsSize                                   
// Process  : Retrieves the size of hands
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline int HandRanker::getHandsSize() const
{
   return this->hands.size();
} // end HandRanker::getHandsSize

//***************************************************************************
// Function : setHands                                   
// Process  : Mutator for hands
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void HandRanker::setHands(const vector<Hand>& hands)
{
   this->hands = hands;
} // end HandRanker::setHands

#endif // HandRanker_h