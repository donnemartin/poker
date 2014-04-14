// COPYRIGHT © 2011, Donne Martin
// All Rights Reserved.
//
//******************************************************************************
//
// File Name:     HandRanker.cpp
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

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "HandRanker.h"

//******************************************************************************
// File scope (static) variable definitions
//******************************************************************************

// None

//******************************************************************************
// Function : constructor                                   
// Process  : None  
// Notes    : Not the recommended constructor
//             Need to set hands afterwards
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************                    
HandRanker::HandRanker()
{

} // end HandRanker::HandRanker

//******************************************************************************
// Function : constructor                                   
// Process  : Initialize hands to input value      
// Notes    : Recommended constructor
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::HandRanker(const vector<Hand>& hands)
{
   this->setHands(hands);
} // end HandRanker::HandRanker

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
HandRanker::~HandRanker()
{
} // end HandRanker::~HandRanker

//******************************************************************************
// Function : buildHandRepetitionLists                                   
// Process  : Builds the hand's repetition lists which include
//             singles, pairs, trips, and quads
//             Returns the number of unique card numbers in the hand
//             For each card, get the card number
//                Keep track of numbers in a map containing 
//                unique numbers and counts
//             I then realized I could optimize comparison by storing 
//             a list of singles, pairs, trips, and quads in each hand
//                Loop through map with an iterator
//                   if (*iter).second is 1
//                      Add to list of singles
//                   if (*iter).second is 2
//                      Add to list of pairs
//                   if (*iter).second is 3
//                      Add to list of trips
//                   if (*iter).second is 4
//                      Add to list of quads
//                Sort the repetition lists
//                Return the map size for use in rankHand
// Notes    : Private
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
int HandRanker::buildHandRepetitionLists(Hand& hand) const
{   
   map<Card::CardNumber, int> handMap; // Hand map to keep track of 
                                       // repetitions in the hand

   static const int INITMAPVALUE = 1;                    // Initial map value
   Card::CardNumber cardNumber   = Card::INVALIDNUMBER;  // Sentinel

   for (int cardIndex = 0; cardIndex < Hand::MAXCARDS; ++cardIndex)
   {
      // For each card, get the card number
      cardNumber = hand.getCardNumber(cardIndex);

      // If value does not exist in map, add it
      if (handMap.find(cardNumber) == handMap.end())
      {
         handMap[cardNumber] = INITMAPVALUE;
      }
      // Else, increment the count
      else
      {
         handMap[cardNumber]++;
      }
   }
      
   map<Card::CardNumber, int>::iterator mapIter;   // Iterator to loop 
                                                   // through map elements

   for (mapIter = handMap.begin(); mapIter != handMap.end(); mapIter++)
   {
      switch ((*mapIter).second)
      {
         case Hand::SINGLES:
         {
            hand.addToSingles((*mapIter).first);
            break;
         }
         case Hand::PAIRS:
         {
            hand.addToPairs((*mapIter).first);
            break;
         }
         case Hand::TRIPS:
         {
            hand.addToTrips((*mapIter).first);
            break;
         }
         case Hand::QUADS:
         {
            hand.addToQuads((*mapIter).first);
            break;
         }
         default:
         {
            throw exception("Unexpected repetition in buildHandRepetitionLists");
            break;
         }
      }
   }

   // Sort the repetition lists
   hand.sortSingles();   
   hand.sortPairs();  
   hand.sortTrips();  
   hand.sortQuads();  

   // Return the map size for use in rankHand
   return handMap.size();
}


//******************************************************************************
// Function : compareAllHands                                   
// Process  : Compare hands
//             For each pair of hands [i vs i + 1], [i + 2 vs i + 3], etc
//                Call compareHands on each pair
// Notes    : Consider changing this algorithm to make it cleaner
//             Perhaps a pair of vectors to compare?
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
void HandRanker::compareAllHands() const
{
   int               numHands          = this->getHandsSize(); 
   static const int  PAIRINCREMENT     = 2;  // Inc by 2 to compare pairs
   static const int  NEXTHANDINCREMENT = 1;  // Compare curr with enxt hand

   // Increment hand by two since we are comparing pairs of hands
   // For each pair of hands [i vs i + 1], [i + 2 vs i + 3], etc
   for (int hand = 0; hand < numHands; hand += PAIRINCREMENT) 
   {
      // Compare each pair of hands
      this->compareHands(hands[hand], 
         hands[hand + NEXTHANDINCREMENT]);
   }
} // end HandRanker::compareAllHands

//******************************************************************************
// Function : compareCardHandNumbers                                   
// Process  : Compare the input card hand's numbers  
//             Get the card numbers for each card specified by the index
//             Call compareCardNumbers to determine which is greater
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareCardHandNumbers(
   const Hand& firstHand,
   const Hand& secondHand,
   const int   cardIndex) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   // Get the card numbers for each card specified by the index
   Card::CardNumber firstHandCardNumber  = firstHand.getCardNumber(cardIndex);
   Card::CardNumber secondHandCardNumber = secondHand.getCardNumber(cardIndex);

   // Compare these two numbers to determine which is greater
   result = this->compareCardNumbers(firstHandCardNumber, secondHandCardNumber);

   return result;
} // end HandRanker::compareCardHandNumbers

//******************************************************************************
// Function : compareCardNumbers                                   
// Process  : Compare the input card numbers
//             Output the card numbers we are about to compare
//             Determine which number is greater
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareCardNumbers(
   const Card::CardNumber firstCardNumber,
   const Card::CardNumber secondCardNumber) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;
   
   // Output the card numbers we are about to compare
   cout << "Comparing card number values " 
        << firstCardNumber << " and " 
        << secondCardNumber << endl;

   // Determine which number is greater
   if (firstCardNumber > secondCardNumber)
   {
      result = HandRanker::FIRSTWINNER;
   }
   else if (firstCardNumber < secondCardNumber)
   {
      result = HandRanker::SECONDWINNER;
   }
   else
   {
      result = HandRanker::TIE;
   }

   return result;
} // end HandRanker::compareCardNumbers

//******************************************************************************
// Function : compareFourOfAKind                                   
// Process  : Compare the two four of a kind hands  
//             Compare quads first to see if we can determine the winner
//             If we have a tie check the high card
// Notes    : The input hands must be four of a kind hands
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareFourOfAKind(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   // Compare quads first to see if we can determine the winner
   result = this->rankHandRepetitions(firstHand, secondHand, Hand::QUADS);
   
   if (result == HandRanker::TIE)
   {
      // If we have a tie compare the high card
      result = this->rankHandRepetitions(firstHand, secondHand, Hand::SINGLES);
   }

   return result;
} // end HandRanker::compareFourOfAKind

//******************************************************************************
// Function : compareFullHouse                                   
// Process  : Compare trips first to see if we can determine the winner
//             If we have a tie compare the pair
// Notes    : The input hands must be full house hands
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareFullHouse(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   // Compare trips first to see if we can determine the winner
   result = this->rankHandRepetitions(firstHand, secondHand, Hand::TRIPS);   

   if (result == HandRanker::TIE)
   {
      // If we have a tie compare the pair
      result = this->rankHandRepetitions(firstHand, secondHand, Hand::PAIRS);      
   }

   return result;
} // end HandRanker::compareFullHouse

//******************************************************************************
// Function : compareHands                                   
// Process  : Compare the hands
//             Get the types for each hand (straight, flush, etc)
//             Check hand types
//             If they differ, the winner is the higher hand type
//             Else, we need to compare hands of the same type
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
void HandRanker::compareHands(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   // Get the types for each hand (straight, flush, etc)
   Hand::HandType             firstHandType  = firstHand.getType();
   Hand::HandType             secondHandType = secondHand.getType();
   HandRanker::CompareResult  result         = HandRanker::INVALIDRESULT;

   this->printHandComparisonHeader(firstHand, secondHand);
   
   // Check hand types.  If they differ, the winner is the higher hand type
   if (firstHandType > secondHandType)
   {
      result = HandRanker::FIRSTWINNER;
   }
   else if (firstHandType < secondHandType)
   {
      result = HandRanker::SECONDWINNER;
   }
   else if (firstHandType == secondHandType)
   {
      // Otherwise, we need to compare hands of the same type
      result = this->compareHandsOfSameType(firstHand, secondHand);
   }
   
   this->printWinningHand(firstHand, secondHand, result);

   cout << endl;
} // end HandRanker::compareHands

//******************************************************************************
// Function : compareHandsOfSameType                                   
// Process  : Compare hands of same type (ie straight vs straight) 
//             Depending on the type, call the appropriate comparison function
//             Straight flush, flush, straight, high card
//                Call compareHighCards
//             Four of a kind
//                Call compareFourOfAKind
//             Full house
//                Call compareFullHouse
//             Three of a kind
//                Call compareThreeOfAKind
//             One or two pair
//                Call compareOneOrTwoPair
// Notes    : The input hands must be of the same type
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareHandsOfSameType(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   HandRanker::CompareResult  result   = HandRanker::INVALIDRESULT;
   Hand::HandType             type     = firstHand.getType();       // Pair, etc

   switch (type) 
   {
      case Hand::STRAIGHTFLUSH:
      {
         // Could optimize further by comparing only the highest card
         // as opposed to comparing all high cards
         result = this->compareHighCards(firstHand, secondHand);
         break;
      }
      case Hand::FOUROFAKIND:
      {
         result = this->compareFourOfAKind(firstHand, secondHand);
         break;
      }
      case Hand::FULLHOUSE:
      {
         result = this->compareFullHouse(firstHand, secondHand);
         break;
      }
      case Hand::FLUSH:
      {
         // Only need to compare high cards
         result = this->compareHighCards(firstHand, secondHand);
         break;
      }
      case Hand::STRAIGHT:
      {
         // Could optimize further by comparing only the highest card
         // as opposed to comparing all high cards
         result = this->compareHighCards(firstHand, secondHand);
         break;
      }
      case Hand::THREEOFAKIND:
      {
         result = this->compareThreeOfAKind(firstHand, secondHand);
         break;
      }
      case Hand::TWOPAIR:
      {
         // One or two pair cards have the same comparison algorithm
         result = this->compareOneOrTwoPair(firstHand, secondHand);
         break;
      }
      case Hand::ONEPAIR:
      {
         // One or two pair cards have the same comparison algorithm
         result = this->compareOneOrTwoPair(firstHand, secondHand);
         break;
      }
      case Hand::HIGHCARD:
      {
         result = this->compareHighCards(firstHand, secondHand);
         break;
      }
      case Hand::INVALIDHAND:
      default:
      {
         throw exception("Unexpected hand type in compareHandsOfSameType");
         break;
      }      
   }

   return result;
} // end HandRanker::compareHandsOfSameType


//******************************************************************************
// Function : compareHighCards                                   
// Process  : Compare the hands by determining the high cards     
//             Called when comparing straight flush, straight,
//             flush, and high card types
//             Compare singles to determine the winner
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareHighCards(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   // Compare singles to determine the winner
   result = this->rankHandRepetitions(firstHand, secondHand, Hand::SINGLES);

   return result;
} // end HandRanker::compareHighCards

//******************************************************************************
// Function : compareOneOrTwoPair                                   
// Process  : Compare the hands by determining the pairs then high cards  
//             Called when comparing pair or two pair types 
//             Compare pairs first to see if we can determine the winner
//             If we have a tie compare the high card(s)
// Notes    : The input hands must be pair or two pair hands
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareOneOrTwoPair(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   // Compare pairs first to see if we can determine the winner
   result = this->rankHandRepetitions(firstHand, secondHand, Hand::PAIRS);

   if (result == HandRanker::TIE)
   {
      // If we have a tie compare the high card(s)
      result = this->rankHandRepetitions(firstHand, secondHand, Hand::SINGLES);      
   }
   
   return result;
} // end HandRanker::compareOneOrTwoPair

//******************************************************************************
// Function : compareThreeOfAKind                                   
// Process  : Compare the two three of a kind hands 
//             Compare trips first to see if we can determine the winner
//             If we have a tie compare the singles
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::compareThreeOfAKind(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   // Compare trips first to see if we can determine the winner
   result = this->rankHandRepetitions(firstHand, secondHand, Hand::TRIPS);

   if (result == HandRanker::TIE)
   {      
      // If we have a tie compare the singles
      result = this->rankHandRepetitions(firstHand, secondHand, Hand::SINGLES);
   }

   return result;
} // end HandRanker::compareThreeOfAKind

//******************************************************************************
// Function : fixLowAceStraightSort                                   
// Process  : Puts the Ace at low end if we have a low straight
//                Input:  A, 5, 4, 3, 2 since Ace = 14
//                Result: 5, 4, 3, 2, A 
//                Insert the cards in order into a new vector
//                Set the hand's cards with the new vector
//                Avoid resorting when calling setCards
// Notes    : Does not determine if the input hand is a low straight
//                Expects the ordering to be A, 5, 4, 3, 2
//                Private called by fixSortOrderIfLowAce
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
void HandRanker::fixLowAceStraightSort(Hand& hand) const
{
   // Represents each of the five cards in the hand
   Card firstCard;
   Card secondCard;
   Card thirdCard;
   Card fourthCard;
   Card fifthCard;

   // Initialize each card
   hand.getCard(Hand::FIRSTCARDINDEX,  firstCard);
   hand.getCard(Hand::SECONDCARDINDEX, secondCard);
   hand.getCard(Hand::THIRDCARDINDEX,  thirdCard);
   hand.getCard(Hand::FOURTHCARDINDEX, fourthCard);
   hand.getCard(Hand::FIFTHCARDINDEX,  fifthCard);

   // Fix the sorting order
   vector<Card> cards;
   cards.push_back(secondCard);
   cards.push_back(thirdCard);
   cards.push_back(fourthCard);
   cards.push_back(fifthCard);
   cards.push_back(firstCard);

   // Avoid resorting when setting the cards
   bool sort = false;
   hand.setCards(cards, sort);
} // end HandRanker::fixLowAceStraightSort

//******************************************************************************
// Function : fixSortOrderIfLowAce                                   
// Process  : Calls isLowAceStraight
//                Calls fixLowAceStraightSort if needed            
// Notes    : Consider making private
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
void HandRanker::fixSortOrderIfLowAce(Hand& hand) const
{
   if (this->isLowAceStraight(hand))
   {
      this->fixLowAceStraightSort(hand);
   }
} // end HandRanker::fixSortOrderIfLowAce

//******************************************************************************
// Function : isFlush                                   
// Process  : Determines if the input hand is a flush  
//             Check each card's suit if they match
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
bool HandRanker::isFlush(const Hand& hand) const
{
   bool isFlush = false;

   // Formatted to fit 80 chars
   // Check each card's suit if they match
   if (hand.getCardSuit(Hand::FIRSTCARDINDEX)  == 
       hand.getCardSuit(Hand::SECONDCARDINDEX) 
         &&
       hand.getCardSuit(Hand::SECONDCARDINDEX) == 
       hand.getCardSuit(Hand::THIRDCARDINDEX)  
         &&
       hand.getCardSuit(Hand::THIRDCARDINDEX)  == 
       hand.getCardSuit(Hand::FOURTHCARDINDEX) 
         &&
       hand.getCardSuit(Hand::FOURTHCARDINDEX) == 
       hand.getCardSuit(Hand::FIFTHCARDINDEX))
   {
      isFlush = true;
   }

   return isFlush;
} // end HandRanker::isFlush

//******************************************************************************
// Function : isLowAceStraight                                   
// Process  : Determines if the input hand is a low ace straight
//             (A, 5, 4, 3, 2)
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
bool HandRanker::isLowAceStraight(const Hand& hand) const
{
   bool isLowAceStraight = false;

   if (hand.getCardNumber(Hand::FIRSTCARDINDEX)  == Card::ACE   &&
       hand.getCardNumber(Hand::SECONDCARDINDEX) == Card::FIVE  && 
       hand.getCardNumber(Hand::THIRDCARDINDEX)  == Card::FOUR  && 
       hand.getCardNumber(Hand::FOURTHCARDINDEX) == Card::THREE && 
       hand.getCardNumber(Hand::FIFTHCARDINDEX)  == Card::TWO)
   {
      isLowAceStraight = true;
   }

   return isLowAceStraight;
} // end HandRanker::isLowAceStraight

//******************************************************************************
// Function : isStraight                                   
// Process  : Determines if the input hand is a straight  
//             Check if the first index is one less than the second index 
//             Check if the second index is one less than the third index
//             Check if the third index is one less than the fourth index
//             Check if the fourth index is one less than the fifth index
//             Check if we have a low ace straight (A, 5, 4, 3, 2)
// Notes    : Do not call fixSortOrderIfLowAce prior to calling this function
//             See inline function comments below
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
bool HandRanker::isStraight(const Hand& hand) const
{
   bool isStraight = false;

   // Formatted to fit 80 chars
   if (hand.getCardNumber(Hand::FIRSTCARDINDEX)  == 
       hand.getCardNumber(Hand::SECONDCARDINDEX) + 1 
         &&
       hand.getCardNumber(Hand::SECONDCARDINDEX) == 
       hand.getCardNumber(Hand::THIRDCARDINDEX)  + 1 
         &&
       hand.getCardNumber(Hand::THIRDCARDINDEX)  == 
       hand.getCardNumber(Hand::FOURTHCARDINDEX) + 1 
         &&
       hand.getCardNumber(Hand::FOURTHCARDINDEX) == 
       hand.getCardNumber(Hand::FIFTHCARDINDEX)  + 1)
   {
      isStraight = true;
   }
   // Low Ace (A, 5, 4, 3, 2) in default sort order
   // Note calling fixSortOrderIfLowAce will change the sort order to
   // (5, 4, 3, 2, A).  This should not be done prior to calling isStraight
   else if (this->isLowAceStraight(hand))
   {
      isStraight = true;
   }
      
   return isStraight;
} // end HandRanker::isStraight

//******************************************************************************
// Function : isStraightFlush                                   
// Process  : Determines if the input hand is a straight flush  
//             Call isFlush and isStraight
//                If both true, we have a straight flush
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
bool HandRanker::isStraightFlush(const Hand& hand) const
{
   bool isStraightFlush = false;

   if (this->isFlush(hand) && this->isStraight(hand)) 
   {
      isStraightFlush = true;
   }

   return isStraightFlush;
} // end HandRanker::isStraightFlush

//***************************************************************************
// Function : printHandComparisonHeader                                   
// Process  : Print the header showing hand vs hand    
//             Print a header 
//             Print first hand
//             Print "vs"
//             Print second hand
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandRanker::printHandComparisonHeader(
   const Hand& firstHand, 
   const Hand& secondHand) const
{
   cout << "---Comparing Hands---" << endl;
   firstHand.printHand();

   cout << endl << "vs" << endl;

   secondHand.printHand();
   cout << endl << endl;
}

//******************************************************************************
// Function : printWinningHand                                   
// Process  : Prints the winning hand based on the result parameter   
//             If result is HandRanker::FIRSTWINNER
//                Print first hand 
//             else If result is HandRanker::SECONDWINNER
//                Print second hand 
//             else If result is HandRanker::TIE
//                Print tie
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
void HandRanker::printWinningHand(
   const Hand& firstHand,
   const Hand& secondHand,
   const HandRanker::CompareResult result) const
{
   switch (result)
   {
      case HandRanker::FIRSTWINNER:
      {
         cout << endl << "Winner is the first hand: ";
         firstHand.printHand();
         break;
      }
      case HandRanker::SECONDWINNER:
      {
         cout << endl << "Winner is the second hand: ";
         secondHand.printHand();
         break;
      }
      case HandRanker::TIE:
      {
         cout << endl << "Result: Tie";
         break;
      }
      case HandRanker::INVALIDRESULT:
      default:
      {
         throw exception("Unexpected result in printWinningHand");
         break;
      }
   }

   cout << endl;
} // end HandRanker::printWinningHand


//******************************************************************************
// Function : rankHand                                   
// Process  : Ranks the hand to determine its type (ie Straight)  
//             Build hand repetition list (singles, pairs, trips, quads)
//             Switch on the number of unique card number elements in hand
//                If we have two items in our map,
//                we have either a full house of a four of a kind
//                   If we have four cards of same number, 
//                      we have a four of a kind
//                   Else, it is a full house
//                If we have three items in our map,
//                we have either a two pair or a three of a kind
//                   If we have three cards of same number, 
//                      we have three of a kind
//                   Else, it is two pair
//                If we have four items in our map, we have one pair
//                If we have five items in our map, we need to look further
//                   Check for straight flush, flush, or straight
//                      If this is a low ace straight, 
//                         we need to fix the sort order
//                   Check for a flush
//                   Check for a straight
//                      If this is a low ace straight, 
//                         we need to fix the sort order
//                   Else, we have a high card
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
void HandRanker::rankHand(Hand& hand) const
{
   // Build hand repetition list (singles, pairs, trips, quads)
   // Returns the map size (number of unique card number elements in hand)
   int handMapSize = this->buildHandRepetitionLists(hand);

   static const int FIVEOFAKIND            = 1; // Invalid
   static const int FULLHOUSEORFOUROFAKIND = 2; // Quads or Boat
   static const int TWOPAIRORTHREEOFAKIND  = 3; // Trips or Two Pair
   static const int ONEPAIR                = 4; // Pair
   static const int EVALUATE               = 5; // Needs further eval

   // Switch on the number of unique card number elements in hand
   switch (handMapSize)
   {
      // If we have two items in our map,
      // we have either a full house of a four of a kind
      case FULLHOUSEORFOUROFAKIND:
      {
         // If we have four cards of same number, we have a four of a kind
         if (hand.hasQuads())
         {
            hand.setType(Hand::FOUROFAKIND);
         }
         // Else, it is a full house
         else 
         {
            hand.setType(Hand::FULLHOUSE);
         }

         break;
      }
      // If we have three items in our map,
      // we have either a two pair or a three of a kind
      case TWOPAIRORTHREEOFAKIND:
      {
         // If we have three cards of same number, we have three of a kind
         if (hand.hasTrips())
         {
            hand.setType(Hand::THREEOFAKIND);
         }
         // Else, it is two pair
         else 
         {
            hand.setType(Hand::TWOPAIR);
         }

         break;
      }
      // If we have four items in our map, we have one pair
      case ONEPAIR:
      {
         // Single pair
         hand.setType(Hand::ONEPAIR);
         break;
      }
      // If we have five items in our map, we need to look further
      case EVALUATE:
      {
         // Check for straight flush, flush, or straight
         if (this->isStraightFlush(hand)) 
         {
            // If this is a low ace straight, we need to fix the sort order
            this->fixSortOrderIfLowAce(hand);

            hand.setType(Hand::STRAIGHTFLUSH);
         }
         // Check for a flush
         else if (this->isFlush(hand))
         {
            hand.setType(Hand::FLUSH);
         }
         // Check for a straight
         else if (this->isStraight(hand))
         {
            // If this is a low ace straight, we need to fix the sort order
            this->fixSortOrderIfLowAce(hand);

            hand.setType(Hand::STRAIGHT);
         }
         // Else, we have a high card hand
         else
         {
            hand.setType(Hand::HIGHCARD);
         }

         break;
      }
      case FIVEOFAKIND:
      default:
      {
         throw exception("Unexpected handMapSize in rankHand");
         break;
      }
   }
} // end HandRanker::rankHand


//******************************************************************************
// Function : rankHands                                   
// Process  : Rank all hands in the data member hands  
//             For each hand
//                Call rankHand
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
void HandRanker::rankHands()
{      
   int size = this->getHandsSize();

   for (int i = 0; i < size; ++i) 
   {
      this->rankHand(hands[i]);
   }
} // end HandRanker::rankHands

//******************************************************************************
// Function : rankHandRepetitions                                   
// Process  : Rank the input hands based on the input card repetitions   
//             Call rankHandRepetitions
//             Used for optimized hand ranking
// Notes    : Private 
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::rankHandRepetitions(
   const Hand& firstHand, 
   const Hand& secondHand,
   const Hand::CardRepetition repetition) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   // Representation of the hand repetitions (singles, pairs, trips, quads)
   vector<Card::CardNumber> firstHandReps;
   vector<Card::CardNumber> secondHandReps;

   // Based on the input selector...
   switch (repetition)
   {
      // Selector is singles, so we use the singles list
      case Hand::SINGLES:
      {
         firstHand.getSingles(firstHandReps);
         secondHand.getSingles(secondHandReps);
         break;
      }
      // Selector is pairs, so we use the pairs list
      case Hand::PAIRS:
      {
         firstHand.getPairs(firstHandReps);
         secondHand.getPairs(secondHandReps);
         break;
      }
      // Selector is trips, so we use the trips list
      case Hand::TRIPS:
      {
         firstHand.getTrips(firstHandReps);
         secondHand.getTrips(secondHandReps);
         break;
      }
      // Selector is quads, so we use the quads list
      case Hand::QUADS:
      {
         firstHand.getQuads(firstHandReps);
         secondHand.getQuads(secondHandReps);
         break;
      }
      default:
      {
         throw exception("Unexpected repetition in rankHandRepetitions");
         break;
      }
   }

   // Rank the input hands based on the input card repetitions
   result = this->rankHandRepetitionVectors(firstHandReps, secondHandReps);

   return result;
} // end HandRanker::rankHandRepetitions


//******************************************************************************
// Function : rankHandRepetitionVectors                                   
// Process  : Rank the input hands based on the input card repetitions
//             Called by rankHandRepetitions
//             Used for optimized hand ranking
//             Verify both lists are the same size
//             For each card in each list
//                Compare the card numbers to determine the winner
//                Once we have a winner break the loop for efficiency
// Notes    : Private
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************
HandRanker::CompareResult HandRanker::rankHandRepetitionVectors(
   const vector<Card::CardNumber>& firstVector,
   const vector<Card::CardNumber>& secondVector) const
{
   HandRanker::CompareResult result = HandRanker::INVALIDRESULT;

   int firstVectorSize = firstVector.size(); // As stated in notes, we assume
                                             // both vectors are the same size
                                             // in this private function.
                                             // Perhaps we should throw an
                                             // exception if the sizes differ.

   // Loops in reverse order
   // The hand repetition vectors seem to be sorted in reverse order
   // from the hands in the hand ranker
   // I noticed this pretty late in development and do not have time
   // during the initial release to fix this discrepancy.
   // The next revision should try to address this inconsistency.
   for (int element = firstVectorSize - 1; element >= 0; --element)
   {
      // For each card in the list
      // Compare the card numbers to determine the winner
      result = this->compareCardNumbers(firstVector[element], secondVector[element]);

      // Once we have a winner break the loop for efficiency
      if (result != HandRanker::TIE && result != HandRanker::INVALIDRESULT)
      {
         break;
      }
   }

   return result;
} // end HandRanker::rankHandRepetitionVectors


