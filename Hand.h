//******************************************************************************
//
// File Name:     Hand.h
//
// File Overview: Represents a Hand containing five cards
//
//******************************************************************************
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//******************************************************************************

#ifndef Hand_h
#define Hand_h

#include <algorithm>
#include <map>
#include <vector>
#include "Card.h"

//******************************************************************************
//
// Class:    Hand
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class 
//
// Notes    : None
//
//******************************************************************************
class Hand
{
public:

   // Forward declaration for Hand enum used in member function params
   enum HandType;
      
   //***************************************************************************
   // Function    : constructor                                   
   // Description : None        
   //                Not the recommended constructor        
   // Constraints : Need to set cards afterwards
   //***************************************************************************
   Hand();
   
   //***************************************************************************
   // Function    : constructor                                   
   // Description : Initializes data members to input cards          
   //                Recommended constructor        
   // Constraints : None
   //***************************************************************************
   Hand(
      Card card0,
      Card card1,
      Card card2,
      Card card3,
      Card card4);

   //***************************************************************************
   // Function    : destructor                                   
   // Description : Performs cleanup tasks              
   // Constraints : None
   //***************************************************************************
   virtual ~Hand();   

   // Member functions in alphabetical order
               
   //***************************************************************************
   // Function    : addToPairs                                   
   // Description : Adds the number to the list of pairs
   //                Used for optimized hand ranking
   // Constraints : None
   //***************************************************************************
   inline void addToPairs(const Card::CardNumber cardNumber);

   //***************************************************************************
   // Function    : addToQuads                                   
   // Description : Adds the number to the list of quads
   //                Used for optimized hand ranking          
   // Constraints : None
   //***************************************************************************
   inline void addToQuads(const Card::CardNumber cardNumber);

   //***************************************************************************
   // Function    : addToSingles                                   
   // Description : Adds the number to the list of singles
   //                Used for optimized hand ranking         
   // Constraints : None
   //***************************************************************************
   inline void addToSingles(const Card::CardNumber cardNumber);

   //***************************************************************************
   // Function    : addToTrips                                   
   // Description : Adds the number to the list of trips
   //                Used for optimized hand ranking           
   // Constraints : None
   //***************************************************************************
   inline void addToTrips(const Card::CardNumber cardNumber);

   //***************************************************************************
   // Function    : getCard                                
   // Description : Accessor for cards
   //                Does not check if index is valid
   // Constraints : index must be valid
   //***************************************************************************
   inline void getCard(
      const int index, 
      Card& card) const;
   
   //***************************************************************************
   // Function    : getCardNumber                                   
   // Description : Accessor for card number     
   //                Checks index for validity
   // Constraints : None
   //***************************************************************************
   inline Card::CardNumber getCardNumber(const int index) const;

   //***************************************************************************
   // Function    : getCards                                
   // Description : Accessor for cards
   // Constraints : None
   //***************************************************************************
   inline void getCards(vector<Card>& cards) const;
      
   //***************************************************************************
   // Function    : getCardSafe                                
   // Description : Accessor for cards, verifies index is valid
   //                Checks if index is valid, return success, update card param
   // Constraints : None
   //***************************************************************************
   bool Hand::getCardSafe(
      const int index, 
      Card& card) const;
   
   //***************************************************************************
   // Function    : getCardSuit                                   
   // Description : Get the card suit associated with the card
   //                Checks index for validity         
   // Constraints : None
   //***************************************************************************
   inline Card::CardSuit getCardSuit(const int index) const;
      
   //***************************************************************************
   // Function    : getPairs                                   
   // Description : Accessor for the list of pairs    
   //                Used for optimized hand ranking           
   // Constraints : None
   //***************************************************************************
   inline void getPairs(vector<Card::CardNumber>& pairs) const;

   //***************************************************************************
   // Function    : getQuads                                   
   // Description : Accessor for the list of quads    
   //                Used for optimized hand ranking         
   // Constraints : None
   //***************************************************************************
   inline void getQuads(vector<Card::CardNumber>& quads) const;

   //***************************************************************************
   // Function    : getSingles                                   
   // Description : Accessor for the list of singles    
   //                Used for optimized hand ranking            
   // Constraints : None
   //***************************************************************************
   inline void getSingles(vector<Card::CardNumber>& singles) const;

   //***************************************************************************
   // Function    : getTrips                                   
   // Description : Accessor for the list of trips    
   //                Used for optimized hand ranking            
   // Constraints : None
   //***************************************************************************
   inline void getTrips(vector<Card::CardNumber>& trips) const;
   
   //***************************************************************************
   // Function    : getType                                 
   // Description : Accessor for type              
   // Constraints : None
   //***************************************************************************
   inline Hand::HandType getType() const;

   //***************************************************************************
   // Function    : hasPairs                                 
   // Description : Determines if the hand has pairs      
   //                Used for optimized hand ranking               
   // Constraints : None
   //***************************************************************************
   inline bool hasPairs() const;

   //***************************************************************************
   // Function    : hasQuads                                 
   // Description : Determines if the hand has quads      
   //                Used for optimized hand ranking               
   // Constraints : None
   //***************************************************************************
   inline bool hasQuads() const;

   //***************************************************************************
   // Function    : hasTrips                                 
   // Description : Determines if the hand has trips      
   //                Used for optimized hand ranking               
   // Constraints : None
   //***************************************************************************
   inline bool hasTrips() const;

   //***************************************************************************
   // Function    : hasSingles                                 
   // Description : Determines if the hand has singles      
   //                Used for optimized hand ranking               
   // Constraints : None
   //***************************************************************************
   inline bool hasSingles() const;

   //***************************************************************************
   // Function    : isValidCardIndex                                 
   // Description : Determines if the card index is valid (within range)
   // Constraints : None
   //***************************************************************************
   inline bool isValidCardIndex(const int index) const;

   //***************************************************************************
   // Function    : printHand                                 
   // Description : Prints each card in the hand    
   //                Prints the hand type
   // Constraints : None
   //***************************************************************************
   void printHand() const;
   
   //***************************************************************************
   // Function    : printType                                 
   // Description : Prints the hand type (straight flush, full house, etc)             
   // Constraints : None
   //***************************************************************************
   void Hand::printType() const;

   //***************************************************************************
   // Function    : setCards                                
   // Description : Mutator for cards
   //                Optionally sorts cards
   // Constraints : None
   //***************************************************************************
   inline void setCards(const vector<Card>& cards, bool sort = true);
   
   //***************************************************************************
   // Function    : setType                                   
   // Description : Mutator for type             
   // Constraints : None
   //***************************************************************************
   inline void setType(Hand::HandType type);

   //***************************************************************************
   // Function    : sortCards                                   
   // Description : Cards utility function
   //                Sorts the cards based on their CardNumber (low to high)             
   // Constraints : None
   //***************************************************************************
   inline void sortCards();

   //***************************************************************************
   // Function    : sortPairs                                   
   // Description : Sorts the list of pairs   
   //                Used for optimized hand ranking             
   // Constraints : None
   //***************************************************************************
   inline void sortPairs();

   //***************************************************************************
   // Function    : sortQuads                                   
   // Description : Sorts the list of pairs   
   //                Used for optimized hand ranking           
   // Constraints : None
   //***************************************************************************
   inline void sortQuads();

   //***************************************************************************
   // Function    : sortSingles                                   
   // Description : Sorts the list of pairs   
   //                Used for optimized hand ranking           
   // Constraints : None
   //***************************************************************************
   inline void sortSingles();

   //***************************************************************************
   // Function    : sortTrips                                   
   // Description : Sorts the list of pairs   
   //                Used for optimized hand ranking           
   // Constraints : None
   //***************************************************************************
   inline void sortTrips();
      
   //***************************************************************************
   // public Class Attributes.
   //***************************************************************************
      
   // Represents the card's hand index from 0 to 4, max 5 cards
   enum CardIndex
   {
      FIRSTCARDINDEX,
      SECONDCARDINDEX,
      THIRDCARDINDEX,
      FOURTHCARDINDEX,
      FIFTHCARDINDEX,
      MAXCARDS
   };
   
   // Represents the number of times a card appears in the hand
   enum CardRepetition
   {
      SINGLES = 1,
      PAIRS,
      TRIPS,
      QUADS
   };

   // Represents the hand type (poker hands)
   enum HandType
   {
      INVALIDHAND,
      HIGHCARD,
      ONEPAIR,
      TWOPAIR,
      THREEOFAKIND,
      STRAIGHT,
      FLUSH,
      FULLHOUSE,
      FOUROFAKIND,
      STRAIGHTFLUSH
   };
   
private:   
   vector<Card>                  cards;   // List of cards
   HandType                      type;    // Hand type (poker hands)
   
   // The following data members are used for optimized hand ranking  
   vector<Card::CardNumber>      pairs;   // List of pairs
   vector<Card::CardNumber>      quads;   // List of quads
   vector<Card::CardNumber>      singles; // List of singles
   vector<Card::CardNumber>      trips;   // List of trips
}; // end class Hand
      
//***************************************************************************
// Function : addToPairs                                   
// Process  : Add the number to the list of pairs
//                Used for optimized hand ranking          
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::addToPairs(const Card::CardNumber cardNumber)
{
   this->pairs.push_back(cardNumber);
} // end Card::addToPairs

//***************************************************************************
// Function : addToQuads                                   
// Process  : Add the number to the list of quads
//                Used for optimized hand ranking            
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::addToQuads(const Card::CardNumber cardNumber)
{
   this->quads.push_back(cardNumber);
} // end Card::addToQuads

//***************************************************************************
// Function : addToSingles                                   
// Process  : Add the number to the list of singles
//                Used for optimized hand ranking                    
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::addToSingles(const Card::CardNumber cardNumber)
{
   this->singles.push_back(cardNumber);
} // end Card::addToSingles

//***************************************************************************
// Function : addToTrips                                   
// Process  : Add the number to the list of trips
//                Used for optimized hand ranking               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::addToTrips(const Card::CardNumber cardNumber)
{
   this->trips.push_back(cardNumber);
} // end Card::addToTrips

//***************************************************************************
// Function : getCard                                
// Process  : Accessor for cards
//                Does not check if index
// Notes    : index must be valid
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::getCard(
   const int index, 
   Card& card) const
{
   card = this->cards[index];
} // end Card::getCard

//***************************************************************************
// Function : getCardNumber                                   
// Process  : Get the card number associated with the card
//             Checks index for validity
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline Card::CardNumber Hand::getCardNumber(const int index) const
{
   Card card;
   this->getCardSafe(index, card);

   return card.getNumber();
} // end Card::getCardNumber

//***************************************************************************
// Function : getCards                                
// Process  : Accessor for cards
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::getCards(vector<Card>& card) const
{
   card = this->cards;
} // end Card::getCards

//***************************************************************************
// Function : getCardSuit                                   
// Process  : Get the card suit associated with the card
//             Checks index for validity
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline Card::CardSuit Hand::getCardSuit(const int index) const
{
   Card card;
   this->getCardSafe(index, card);

   return card.getSuit();
} // end Card::getCardSuit

//***************************************************************************
// Function : getPairs                                   
// Process  : Accessor for the list of pairs    
//                Used for optimized hand ranking              
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::getPairs(vector<Card::CardNumber>& pairs) const
{
   pairs = this->pairs;
} // end Card::getPairs

//***************************************************************************
// Function : getQuads                                   
// Process  : Accessor for the list of quads    
//                Used for optimized hand ranking              
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::getQuads(vector<Card::CardNumber>& quads) const
{
   quads = this->quads;
} // end Card::getQuads

//***************************************************************************
// Function : getSingles                                   
// Process  : Accessor for the list of singles    
//                Used for optimized hand ranking              
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::getSingles(vector<Card::CardNumber>& singles) const
{
   singles = this->singles;
} // end Card::getSingles

//***************************************************************************
// Function : getTrips                                   
// Process  : Accessor for the list of trips    
//                Used for optimized hand ranking                
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::getTrips(vector<Card::CardNumber>& trips) const
{
   trips = this->trips;
} // end Card::getTrips

//***************************************************************************
// Function : getType                                 
// Process  : Accessor for type               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline Hand::HandType Hand::getType() const
{
   return this->type;
} // end Card::getType

//***************************************************************************
// Function : hasPairs                                 
// Process  : Determines if the hand has pairs      
//                Used for optimized hand ranking            
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline bool Hand::hasPairs() const
{
   bool hasPairs = false;

   if (this->pairs.size() > 0)
   {
      hasPairs = true;
   }

   return hasPairs;
} // end Card::hasPairs

//***************************************************************************
// Function : hasQuads                                 
// Process  : Determines if the hand has quads        
//                Used for optimized hand ranking          
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline bool Hand::hasQuads() const
{
   bool hasQuads = false;

   if (this->quads.size() > 0)
   {
      hasQuads = true;
   }

   return hasQuads;
} // end Card::hasQuads

//***************************************************************************
// Function : hasTrips                                 
// Process  : Determines if the hand has trips      
//                Used for optimized hand ranking           
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline bool Hand::hasTrips() const
{
   bool hasTrips = false;

   if (this->trips.size() > 0)
   {
      hasTrips = true;
   }

   return hasTrips;
} // end Card::hasTrips

//***************************************************************************
// Function : hasSingles                                 
// Process  : Determines if the hand has singles     
//                Used for optimized hand ranking           
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline bool Hand::hasSingles() const
{
   bool hasSingles = false;

   if (this->singles.size() > 0)
   {
      hasSingles = true;
   }

   return hasSingles;
} // end Card::hasSingles

//***************************************************************************
// Function : isValidCardIndex                                 
// Process  : Determine if the card index is valid (within range)
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline bool Hand::isValidCardIndex(const int index) const
{
   bool isValid = false;   // determines if the card is valid

   if (index < Hand::MAXCARDS) 
   {
      isValid = true;
   }

   return isValid;
} // end Card::isValidCardIndex

//***************************************************************************
// Function : setCards                                
// Process  : Mutator for cards
//             Optionally sorts the cards (default to true)
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::setCards(const vector<Card>& cards, bool sort)
{
   this->cards = cards;

   if (sort)
   {
      this->sortCards();
   }
} // end Card::setCards
  
//***************************************************************************
// Function : setType                                 
// Process  : Mutator for type               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::setType(Hand::HandType type)
{
   this->type = type;
} // end Card::setType
      
//***************************************************************************
// Function : sortCards                                   
// Process  : Cards utility function
//             Sort the cards based on their CardNumber (low to high)  
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::sortCards()
{
   sort(this->cards.begin(), this->cards.end());
} // end Card::sortCards

//***************************************************************************
// Function : sortPairs                                   
// Process  : Sort the list of pairs   
//                Used for optimized hand ranking               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::sortPairs()
{
   sort(this->pairs.begin(), this->pairs.end());
} // end Card::sortPairs

//***************************************************************************
// Function : sortQuads                                   
// Process  : Sort the list of pairs   
//                Used for optimized hand ranking             
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::sortQuads()
{
   sort(this->quads.begin(), this->quads.end());
} // end Card::sortQuads

//***************************************************************************
// Function : sortSingles                                   
// Process  : Sort the list of pairs   
//                Used for optimized hand ranking               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::sortSingles()
{
   sort(this->singles.begin(), this->singles.end());
} // end Card::sortSingles

//***************************************************************************
// Function : sortTrips                                   
// Process  : Sort the list of pairs   
//                Used for optimized hand ranking               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Hand::sortTrips()
{
   sort(this->trips.begin(), this->trips.end());
} // end Card::sortTrips

#endif // Hand_h