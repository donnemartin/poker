// COPYRIGHT © 2011, Donne Martin
// All Rights Reserved.
//
//******************************************************************************
//
// File Name:     Hand.cpp
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

#include "stdafx.h"
#include <iostream>
#include "Hand.h"
#include <algorithm>

//******************************************************************************
// File scope (static) variable definitions
//******************************************************************************

// None

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
Hand::Hand()
{

} // end Hand::Hand
   
//***************************************************************************
// Function : constructor                                   
// Process  : Initialize data members to input cards             
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
Hand::Hand(
   Card card0,
   Card card1,
   Card card2,
   Card card3,
   Card card4)
{
   vector<Card> cards(Hand::MAXCARDS); // Holds the hand of cards

   cards.push_back(card0);
   cards.push_back(card1);
   cards.push_back(card2);
   cards.push_back(card3);
   cards.push_back(card4);

   this->setCards(cards);
}

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
Hand::~Hand()
{
} // end Hand::~Hand
     
//***************************************************************************
// Function : getCardSafe                                
// Process  : verifies index is valid
//             Check if index is valid, return success, update card param
// Notes    : Might be good to inline
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
bool Hand::getCardSafe(
   const int index, 
   Card& card) const
{
   bool success = false;   // determines if the function succeeded

   if (this->isValidCardIndex(index)) {
      card = this->cards[index];
   }

   return success;
} // end Card::getCardSafe

//***************************************************************************
// Function : printHand                                   
// Process  : Print the hand by calling each card's print method
//             Print the hand type
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void Hand::printHand() const
{
   Card card;  // Current card, used to iterate the hand and print each card

   for (int cardIndex = 0; cardIndex < MAXCARDS; ++cardIndex)
   {
      this->getCard(cardIndex, card);
      card.printCard();
   }
   
   this->printType();
}
//***************************************************************************
// Function : printType                                   
// Process  : Print the hand type  (straight flush, full house, etc)  
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void Hand::printType() const
{
   Hand::HandType type = this->getType();

   switch (type)
   {
      case Hand::HIGHCARD:
      {
         cout << "(High Card)";
         break;
      }
      case Hand::ONEPAIR:
      {
         cout << "(Pair)";
         break;
      }
      case Hand::TWOPAIR:
      {
         cout << "(Two Pair)";
         break;
      }
      case Hand::THREEOFAKIND:
      {
         cout << "(Three of a Kind)";
         break;
      }
      case Hand::STRAIGHT:
      {
         cout << "(Straight)";
         break;
      }
      case Hand::FLUSH:
      {
         cout << "(Flush)";
         break;
      }
      case Hand::FULLHOUSE:
      {
         cout << "(Full House)";
         break;
      }
      case Hand::FOUROFAKIND:
      {
         cout << "(Four of a Kind)";
         break;
      }
      case Hand::STRAIGHTFLUSH:
      {
         cout << "(Straight Flush)";
         break;
      }
      case Hand::INVALIDHAND:
      default:
      {
         throw exception("Unexpected type in printType");
         break;
      }
   }
}
