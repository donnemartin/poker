//******************************************************************************
//
// File Name:     Card.h
//
// File Overview: Represents a Card containing a number and a suit
//
//******************************************************************************
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//******************************************************************************

#ifndef Card_h
#define Card_h

using namespace std;

//******************************************************************************
//
// Class:    Card
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added class
//
// Notes    : None
//
//******************************************************************************
class Card
{
public:

   // Forward declarations for Card enums used in member function params
   enum CardSuit;
   enum CardNumber;

   //***************************************************************************
   // Function    : constructor                                   
   // Description : Initializes data members to invalid values  
   //                Not the recommended constructor
   // Constraints : Need to set the number and suit afterwards
   //***************************************************************************
   Card();

   //***************************************************************************
   // Function    : constructor                                   
   // Description : Initializes data members to input suit and number
   //                Recommended constructor
   // Constraints : None
   //***************************************************************************
   Card(Card::CardNumber number, Card::CardSuit suit);

   //***************************************************************************
   // Function    : destructor                                   
   // Description : Performs cleanup tasks              
   // Constraints : None
   //***************************************************************************
   virtual ~Card();   

   // Member functions in alphabetical order
   
   //***************************************************************************
   // Function    : getNumber                                 
   // Description : Accessor for number              
   // Constraints : None
   //***************************************************************************
   inline Card::CardNumber getNumber() const;
   
   //***************************************************************************
   // Function    : getSuit                                 
   // Description : Accessor for suit              
   // Constraints : None
   //***************************************************************************
   inline Card::CardSuit getSuit() const;
        
   //***************************************************************************
   // Function    : printCard                                   
   // Description : prints the card number and suit     
   // Constraints : None
   //***************************************************************************
   void printCard();
           
   //***************************************************************************
   // Function    : printNumber                                   
   // Description : Prints the card number            
   // Constraints : None
   //***************************************************************************
   void printNumber();
        
   //***************************************************************************
   // Function    : printSuit                                   
   // Description : Prints the suit            
   // Constraints : None
   //***************************************************************************
   void printSuit();
   
   //***************************************************************************
   // Function    : setNumber                                   
   // Description : Mutator for number             
   // Constraints : None
   //***************************************************************************
   inline void setNumber(Card::CardNumber number);
   
   //***************************************************************************
   // Function    : setSuit                                   
   // Description : Mutator for suit             
   // Constraints : None
   //***************************************************************************
   inline void setSuit(Card::CardSuit suit);

   //***************************************************************************
   // Function    : operator<                                   
   // Description : Overloads the < operator            
   // Constraints : None
   //***************************************************************************
   inline bool operator<(const Card& a);

   //***************************************************************************
   // public Class Attributes.
   //***************************************************************************
   
   // Represents a card's suit
   enum CardSuit
   {
      INVALIDSUIT,
      CLUB,
      SPADE,
      HEART,
      DIAMOND
   };

   // Represents a card's number
   enum CardNumber
   {
      INVALIDNUMBER,
      TWO = 2,
      THREE,
      FOUR,
      FIVE,
      SIX,
      SEVEN,
      EIGHT,
      NINE,
      TEN,
      JACK,
      QUEEN,
      KING,
      ACE
   };

private:   
   Card::CardNumber  number;  // Card's number
   Card::CardSuit    suit;    // Card's suit

}; // end class Card
   
//***************************************************************************
// Function : getNumber                                 
// Process  : Accessor for number               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline Card::CardNumber Card::getNumber() const
{
   return this->number;
} // end Card::getNumber

//***************************************************************************
// Function : getSuit                                 
// Process  : Accessor for suit               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline Card::CardSuit Card::getSuit() const
{
   return this->suit;
} // end Card::getSuit

//***************************************************************************
// Function : setNumber                                 
// Process  : Mutator for number               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Card::setNumber(Card::CardNumber number)
{
   this->number = number;
} // end Card::setNumber
   
//***************************************************************************
// Function : setSuit                                 
// Process  : Mutator for suit               
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline void Card::setSuit(Card::CardSuit suit)
{
   this->suit = suit;
} // end Card::setSuit
   
//***************************************************************************
// Function : operator<                                 
// Process  : Overload the < operator to work with the Card class              
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
inline bool Card::operator<(const Card& a) 
{
   return a.getNumber() < this->getNumber();
} // end Card::operator<

#endif // Card_h