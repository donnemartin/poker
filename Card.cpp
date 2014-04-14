// COPYRIGHT © 2011, Donne Martin
// All Rights Reserved.
//
//******************************************************************************
//
// File Name:     Card.cpp
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

#include "stdafx.h"
#include <iostream>
#include "Card.h"

//******************************************************************************
// File scope (static) variable definitions
//******************************************************************************

// None

//******************************************************************************
// Function : constructor                                   
// Process  : Initialize data members to invalid values                    
// Notes    : Not the recommended constructor
//             Need to set the number and suit afterwards
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************                    
Card::Card() 
{
   this->setNumber(Card::INVALIDNUMBER);
   this->setSuit(Card::INVALIDSUIT);
} // end Card::Card

//******************************************************************************
// Function : constructor                                   
// Process  : Initializes data members to input suit and number                    
// Notes    : Recommended constructor
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************                    
Card::Card(Card::CardNumber number, Card::CardSuit suit) 
{
   this->setNumber(number);
   this->setSuit(suit);
} // end Card::Card

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
Card::~Card()
{
} // end Card::~Card

//***************************************************************************
// Function : printCard                                   
// Process  : Print the card number and suit
//             Call printNumber
//             Call printSuit
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void Card::printCard()
{
   this->printNumber();
   this->printSuit();
} // end Card::printCard

//***************************************************************************
// Function : printNumber                                   
// Process  : print the card number
//             11 - J for Jack
//             12 - Q for Queen
//             13 - K for King
//             14 - A for Ace
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void Card::printNumber()
{
   Card::CardNumber number = this->getNumber(); // Obtain the card's number

   switch (number)
   {
      case Card::TWO:
      case Card::THREE:
      case Card::FOUR:
      case Card::FIVE:
      case Card::SIX:
      case Card::SEVEN:
      case Card::EIGHT:
      case Card::NINE:
      case Card::TEN:
      {
         cout << number;
         break;
      }
      case Card::JACK:
      {
         cout << "J";
         break;
      }
      case Card::QUEEN:
      {
         cout << "Q";
         break;
      }
      case Card::KING:
      {
         cout << "K";
         break;
      }
      case Card::ACE:
      {
         cout << "A";
         break;
      }
      case Card::INVALIDNUMBER:
      default:
      {
         throw exception("Unexpected number in printNumber");
         break;
      }
   }
} // end Card::printNumber


//***************************************************************************
// Function : printSuit                                   
// Process  : Print the card suit
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void Card::printSuit()
{
   Card::CardSuit suit = this->getSuit(); // Obtain the card's suit
   
   switch (suit)
   {
      case Card::CLUB:
      {
         cout << "c" << " ";
         break;
      }
      case Card::SPADE:
      {
         cout << "s" << " ";
         break;
      }
      case Card::HEART:
      {
         cout << "h" << " ";
         break;
      }
      case Card::DIAMOND:
      {
         cout << "d" << " ";
         break;
      }
      case Card::INVALIDSUIT:
      default:
      {
         throw exception("Unexpected suit in printSuit");
         break;
      }
   }
} // end Card::printSuit

      
