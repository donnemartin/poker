// COPYRIGHT © 2011, Donne Martin
// All Rights Reserved.
//
//******************************************************************************
//
// File Name:     HandGenerator.cpp
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

#include "stdafx.h"
#include <iostream>
#include "HandGenerator.h"

//******************************************************************************
// File scope (static) variable definitions
//******************************************************************************

// None

//******************************************************************************
// Function : constructor                                   
// Process  : Initialize data members to invalid values                    
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//******************************************************************************                    
HandGenerator::HandGenerator() 
{

} // end HandGenerator::HandGenerator

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
HandGenerator::~HandGenerator()
{
} // end HandGenerator::~HandGenerator
      
//***************************************************************************
// Function : addHand                                   
// Process  : Add the specified hand
//             Print the hand's cards to output if specified (default true)
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::addHand(const Hand& hand, const bool printCards)
{
   Card card;

   for (int i = 0; i < Hand::MAXCARDS; ++i)
   {
      hand.getCard(i, card);

      if (printCards)
      {
         card.printCard();
      }
   }

   cout << endl;

   this->hands.push_back(hand);
}

//***************************************************************************
// Function : generateFourOfAKind        
// Process  : Generate the four of a kind hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateFourOfAKind()
{
   cout << "---Generate Four Of A Kind---" << endl << endl;

   // 10c 10d 10h 10s 5d (win)
   // vs
   // 6d 6h 6s 6c 5s
   Hand fourOfAKind0(
      Card(Card::TEN,  Card::CLUB),
      Card(Card::TEN,  Card::DIAMOND),
      Card(Card::TEN,  Card::HEART),
      Card(Card::TEN,  Card::SPADE),
      Card(Card::FIVE, Card::DIAMOND));

   this->addHand(fourOfAKind0);

   cout << "vs" << endl;

   Hand fourOfAKind1(
      Card(Card::SIX,  Card::DIAMOND),
      Card(Card::SIX,  Card::HEART),
      Card(Card::SIX,  Card::SPADE),
      Card(Card::SIX,  Card::CLUB),
      Card(Card::FIVE, Card::SPADE));

   this->addHand(fourOfAKind1);

   cout << endl;

   // 10c 10d 10h 10s qc (win)
   // vs
   // 10c 10d 10h 10s 5d
   Hand fourOfAKind2(
      Card(Card::TEN,   Card::CLUB),
      Card(Card::TEN,   Card::DIAMOND),
      Card(Card::TEN,   Card::HEART),
      Card(Card::TEN,   Card::SPADE),
      Card(Card::QUEEN, Card::CLUB));

   this->addHand(fourOfAKind2);

   cout << "vs" << endl;

   Hand fourOfAKind3(
      Card(Card::TEN,  Card::CLUB),
      Card(Card::TEN,  Card::DIAMOND),
      Card(Card::TEN,  Card::HEART),
      Card(Card::TEN,  Card::SPADE),
      Card(Card::FIVE, Card::DIAMOND));

   this->addHand(fourOfAKind3);

   cout << endl;

} // end HandGenerator::~generateFourOfAKind

//***************************************************************************
// Function : generateHands                                   
// Process  : Generate the hands by calling other generate- functions
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateHands()
{
   this->generateStraightFlush();
   this->generateFourOfAKind();
   this->generateFullHouse();
   this->generateFlush();
   this->generateStraight();
   this->generateThreeOfAKind();
   this->generateTwoPair();
   this->generateOnePair();
   this->generateHighCard();
   //this->generateStraightFlushAndFourOfAKind();
} // end HandGenerator::generateHands

//***************************************************************************
// Function : generateHighCard   
// Process  : Generate the high card hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateHighCard()
{
   cout << "---Generate High Card---" << endl << endl;

   // ad 10d 9s 5c 4c (win)
   // vs
   // kc qd jc 8h 7h
   Hand highCard0(
      Card(Card::ACE,  Card::DIAMOND),
      Card(Card::TEN,  Card::DIAMOND),
      Card(Card::NINE, Card::SPADE),
      Card(Card::FIVE, Card::CLUB),
      Card(Card::FOUR, Card::CLUB));

   this->addHand(highCard0);

   cout << "vs" << endl;

   Hand highCard1(
      Card(Card::KING,  Card::CLUB),
      Card(Card::QUEEN, Card::DIAMOND),
      Card(Card::JACK,  Card::CLUB),
      Card(Card::EIGHT, Card::HEART),
      Card(Card::SEVEN, Card::HEART));

   this->addHand(highCard1);

   cout << endl;

   // ac qc 7d 5h 2c (win)
   // vs
   // ad 10d 9s 5c 4c
   Hand highCard2(
      Card(Card::ACE,   Card::CLUB),
      Card(Card::QUEEN, Card::CLUB),
      Card(Card::SEVEN, Card::DIAMOND),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::TWO,   Card::CLUB));

   this->addHand(highCard2);

   cout << "vs" << endl;

   Hand highCard3(
      Card(Card::ACE,  Card::DIAMOND),
      Card(Card::TEN,  Card::DIAMOND),
      Card(Card::NINE, Card::SPADE),
      Card(Card::FIVE, Card::CLUB),
      Card(Card::FOUR, Card::CLUB));

   this->addHand(highCard3);

   cout << endl;

} // end HandGenerator::~generateHighCard

//***************************************************************************
// Function : generateStraight   
// Process  : Generate the straight hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateStraight()
{
   cout << "---Generate Straight---" << endl << endl;

   // 8s 7s 6h 5h 4s (win)
   // vs
   // 6d 5s 4d 3h 2c
   Hand straight0(
      Card(Card::EIGHT, Card::SPADE),
      Card(Card::SEVEN, Card::SPADE),
      Card(Card::SIX,   Card::HEART),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::FOUR,  Card::SPADE));

   this->addHand(straight0);

   cout << "vs" << endl;

   Hand straight1(
      Card(Card::SIX,   Card::DIAMOND),
      Card(Card::FIVE,  Card::SPADE),
      Card(Card::FOUR,  Card::DIAMOND),
      Card(Card::THREE, Card::HEART),
      Card(Card::TWO,   Card::CLUB));

   this->addHand(straight1);

   cout << endl;

   // 8s 7s 6h 5h 4s (tie)
   // vs
   // 8h 7d 6c 5c 4h
   Hand straight2(
      Card(Card::EIGHT, Card::SPADE),
      Card(Card::SEVEN, Card::SPADE),
      Card(Card::SIX,   Card::HEART),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::FOUR,  Card::SPADE));

   this->addHand(straight2);

   cout << "vs" << endl;

   Hand straight3(
      Card(Card::EIGHT, Card::HEART),
      Card(Card::SEVEN, Card::DIAMOND),
      Card(Card::SIX,   Card::CLUB),
      Card(Card::FIVE,  Card::CLUB),
      Card(Card::FOUR,  Card::HEART));

   this->addHand(straight3);

   cout << endl;

} // end HandGenerator::~generateStraight

//***************************************************************************
// Function : generateStraightFlush                                   
// Process  : Generate the straight flush hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateStraightFlush()
{
   cout << "---Generate Straight Flush---" << endl << endl;

   // 7h 6h 5h 4h 3h (win)
   // vs
   // 5s 4s 3s 2s as
   Hand straightFlush0(
      Card(Card::SEVEN, Card::HEART),
      Card(Card::SIX,   Card::HEART),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::FOUR,  Card::HEART),
      Card(Card::THREE, Card::HEART));

   this->addHand(straightFlush0);

   cout << "vs" << endl;

   Hand straightFlush1(
      Card(Card::FIVE,  Card::SPADE),
      Card(Card::FOUR,  Card::SPADE),
      Card(Card::THREE, Card::SPADE),
      Card(Card::TWO,   Card::SPADE),
      Card(Card::ACE,   Card::SPADE));

   this->addHand(straightFlush1);

   cout << endl;

   // jc 10c 9c 8c 7c (tie)
   // vs
   // jd 10d 9d 8d 7d
   Hand straightFlush2(
      Card(Card::JACK,  Card::CLUB),
      Card(Card::TEN,   Card::CLUB),
      Card(Card::NINE,  Card::CLUB),
      Card(Card::EIGHT, Card::CLUB),
      Card(Card::SEVEN, Card::CLUB));

   this->addHand(straightFlush2);

   cout << "vs" << endl;

   Hand straightFlush3(
      Card(Card::JACK,  Card::DIAMOND),
      Card(Card::TEN,   Card::DIAMOND),
      Card(Card::NINE,  Card::DIAMOND),
      Card(Card::EIGHT, Card::DIAMOND),
      Card(Card::SEVEN, Card::DIAMOND));

   this->addHand(straightFlush3);

   cout << endl;
} // end HandGenerator::~generateStraightFlush

//***************************************************************************
// Function : generateStraightFlushAndFourOfAKind   
// Process  : Generates straight flush and four a kind hands            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateStraightFlushAndFourOfAKind()
{
   cout << "---Generate Straight Flush And Four Of A Kind---" << endl << endl;

   Hand straightFlush(
      Card(Card::JACK,  Card::DIAMOND),
      Card(Card::TEN,   Card::DIAMOND),
      Card(Card::NINE,  Card::DIAMOND),
      Card(Card::EIGHT, Card::DIAMOND),
      Card(Card::SEVEN, Card::DIAMOND));

   this->addHand(straightFlush);

   cout << "vs" << endl;

   // 10c 10d 10h 10s 5d (win)
   // vs
   // 6d 6h 6s 6c 5s
   Hand fourOfAKind(
      Card(Card::TEN,  Card::CLUB),
      Card(Card::TEN,  Card::DIAMOND),
      Card(Card::TEN,  Card::HEART),
      Card(Card::TEN,  Card::SPADE),
      Card(Card::FIVE, Card::DIAMOND));

   this->addHand(fourOfAKind);

   cout << endl;
} // end HandGenerator::~generateStraightFlushAndFourOfAKind

//***************************************************************************
// Function : generateFlush   
// Process  : Generate the flush hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateFlush()
{
   cout << "---Generate Flush---" << endl << endl;

   // ah qh 10h 5h 3h (win)
   // vs
   // ks qs js 9s 6s
   Hand flush0(
      Card(Card::ACE,   Card::HEART),
      Card(Card::QUEEN, Card::HEART),
      Card(Card::TEN,   Card::HEART),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::THREE, Card::HEART));

   this->addHand(flush0);

   cout << "vs" << endl;

   Hand flush1(
      Card(Card::KING,  Card::SPADE),
      Card(Card::QUEEN, Card::SPADE),
      Card(Card::JACK,  Card::SPADE),
      Card(Card::NINE,  Card::SPADE),
      Card(Card::SIX,   Card::SPADE));

   this->addHand(flush1);

   cout << endl;

   // ad kd 7d 6d 2d (win)
   // vs
   // ah qh 10h 5h 3h
   Hand flush2(
      Card(Card::ACE, Card::DIAMOND),
      Card(Card::KING, Card::DIAMOND),
      Card(Card::SEVEN, Card::DIAMOND),
      Card(Card::SIX, Card::DIAMOND),
      Card(Card::TWO, Card::DIAMOND));

   this->addHand(flush2);

   cout << "vs" << endl;

   Hand flush3(
      Card(Card::ACE, Card::HEART),
      Card(Card::QUEEN, Card::HEART),
      Card(Card::TEN, Card::HEART),
      Card(Card::FIVE, Card::HEART),
      Card(Card::THREE, Card::HEART));

   this->addHand(flush3);

   cout << endl;

} // end HandGenerator::~generateFlush

//***************************************************************************
// Function : generateFullHouse   
// Process  : Generate the full house hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateFullHouse()
{
   cout << "---Generate Full House---" << endl << endl;

   // 10s 10h 10d 4s 4d (win)
   // vs
   // 9h 9c 9s ah ac
   Hand fullHouse0(
      Card(Card::TEN,  Card::SPADE),
      Card(Card::TEN,  Card::HEART),
      Card(Card::TEN,  Card::DIAMOND),
      Card(Card::FOUR, Card::SPADE),
      Card(Card::FOUR, Card::DIAMOND));

   this->addHand(fullHouse0);

   cout << "vs" << endl;

   Hand fullHouse1(
      Card(Card::NINE, Card::HEART),
      Card(Card::NINE, Card::CLUB),
      Card(Card::NINE, Card::SPADE),
      Card(Card::ACE,  Card::HEART),
      Card(Card::ACE,  Card::CLUB));

   this->addHand(fullHouse1);

   cout << endl;

   // as ac ah 4d 4c (win)
   // vs
   // as ah ad 3s 3d
   Hand fullHouse2(
      Card(Card::ACE,  Card::SPADE),
      Card(Card::ACE,  Card::CLUB),
      Card(Card::ACE,  Card::HEART),
      Card(Card::FOUR, Card::DIAMOND),
      Card(Card::FOUR, Card::CLUB));

   this->addHand(fullHouse2);

   cout << "vs" << endl;

   Hand fullHouse3(
      Card(Card::ACE,   Card::SPADE),
      Card(Card::ACE,   Card::HEART),
      Card(Card::ACE,   Card::DIAMOND),
      Card(Card::THREE, Card::SPADE),
      Card(Card::THREE, Card::DIAMOND));

   this->addHand(fullHouse3);

   cout << endl;

} // end HandGenerator::~generateFullHouse

//***************************************************************************
// Function : generateOnePair   
// Process  : Generate the pair hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateOnePair()
{
   cout << "---Generate One Pair---" << endl << endl;

   // 10c 10s 6s 4h 2h (win)
   // vs
   // 9h 9c ah qd 10d
   Hand onePair0(
      Card(Card::TEN,  Card::CLUB),
      Card(Card::TEN,  Card::SPADE),
      Card(Card::SIX,  Card::SPADE),
      Card(Card::FOUR, Card::HEART),
      Card(Card::TWO,  Card::HEART));

   this->addHand(onePair0);

   cout << "vs" << endl;

   Hand onePair1(
      Card(Card::NINE,  Card::HEART),
      Card(Card::NINE,  Card::CLUB),
      Card(Card::ACE,   Card::HEART),
      Card(Card::QUEEN, Card::DIAMOND),
      Card(Card::TEN,   Card::DIAMOND));

   this->addHand(onePair1);

   cout << endl;

   // 2d 2h 8s 5c 4c (win)
   // vs
   // 2c 2s 8c 5h 3h
   Hand onePair2(
      Card(Card::TWO,   Card::DIAMOND),
      Card(Card::TWO,   Card::HEART),
      Card(Card::EIGHT, Card::SPADE),
      Card(Card::FIVE,  Card::CLUB),
      Card(Card::FOUR,  Card::CLUB));

   this->addHand(onePair2);

   cout << "vs" << endl;

   Hand onePair3(
      Card(Card::TWO,   Card::CLUB),
      Card(Card::TWO,   Card::SPADE),
      Card(Card::EIGHT, Card::CLUB),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::THREE, Card::HEART));

   this->addHand(onePair3);

   cout << endl;

} // end HandGenerator::~generateOnePair

//***************************************************************************
// Function : generateThreeOfAKind   
// Process  : Generate the three of a kind hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateThreeOfAKind()
{
   cout << "---Generate Three Of A Kind---" << endl << endl;

   // qs qc qd 5s 3c (win)
   // vs
   // 5c 5h 5d qd 10c
   Hand threeOfAKind0(
      Card(Card::QUEEN, Card::SPADE),
      Card(Card::QUEEN, Card::CLUB),
      Card(Card::QUEEN, Card::DIAMOND),
      Card(Card::FIVE,  Card::SPADE),
      Card(Card::THREE, Card::CLUB));

   this->addHand(threeOfAKind0);

   cout << "vs" << endl;

   Hand threeOfAKind1(
      Card(Card::FIVE,  Card::CLUB),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::FIVE,  Card::HEART),
      Card(Card::QUEEN, Card::DIAMOND),
      Card(Card::TEN,   Card::CLUB));

   this->addHand(threeOfAKind1);

   cout << endl;

   // 8c 8h 8d ac 2d (win)
   // vs
   // 8s 8h 8d 5s 3c
   Hand threeOfAKind2(
      Card(Card::EIGHT, Card::CLUB),
      Card(Card::EIGHT, Card::HEART),
      Card(Card::EIGHT, Card::DIAMOND),
      Card(Card::ACE,   Card::CLUB),
      Card(Card::TWO,   Card::DIAMOND));

   this->addHand(threeOfAKind2);

   cout << "vs" << endl;

   Hand threeOfAKind3(
      Card(Card::EIGHT, Card::SPADE),
      Card(Card::EIGHT, Card::HEART),
      Card(Card::EIGHT, Card::DIAMOND),
      Card(Card::FIVE,  Card::SPADE),
      Card(Card::THREE, Card::CLUB));

   this->addHand(threeOfAKind3);

   cout << endl;

} // end HandGenerator::~generateThreeOfAKind

//***************************************************************************
// Function : generateTwoPair   
// Process  : Generate the two pair hands listed in wikipedia            
//             Output "hand" vs "hand" when generated
// Notes    : None
//
// Revision History:
//
// Date           Author               Description 
// 6.12.11        Donne Martin         Added function
//***************************************************************************
void HandGenerator::generateTwoPair()
{
   cout << "---Generate Two Pair---" << endl << endl;

   // kh kd 2c 2d jh (win)
   // vs
   // jd js 10s 10c 9s
   Hand twoPair0(
      Card(Card::KING, Card::HEART),
      Card(Card::KING, Card::DIAMOND),
      Card(Card::TWO,  Card::CLUB),
      Card(Card::TWO,  Card::DIAMOND),
      Card(Card::JACK, Card::HEART));

   this->addHand(twoPair0);

   cout << "vs" << endl;

   Hand twoPair1(
      Card(Card::JACK, Card::DIAMOND),
      Card(Card::JACK, Card::SPADE),
      Card(Card::TEN,  Card::SPADE),
      Card(Card::TEN,  Card::CLUB),
      Card(Card::NINE, Card::SPADE));

   this->addHand(twoPair1);

   cout << endl;

   // 9c 9d 7d 7s 6h (win)
   // vs
   // 9h 9s 5h 5d kc
   Hand twoPair2(
      Card(Card::NINE,  Card::CLUB),
      Card(Card::NINE,  Card::DIAMOND),
      Card(Card::SEVEN, Card::DIAMOND),
      Card(Card::SEVEN, Card::SPADE),
      Card(Card::SIX,   Card::HEART));

   this->addHand(twoPair2);

   cout << "vs" << endl;

   Hand twoPair3(
      Card(Card::NINE, Card::HEART),
      Card(Card::NINE, Card::SPADE),
      Card(Card::FIVE, Card::HEART),
      Card(Card::FIVE, Card::DIAMOND),
      Card(Card::KING, Card::CLUB));

   this->addHand(twoPair3);

   cout << endl;

   // 4s 4c 3s 3h kd (win)
   // vs
   // 4h 4d 3d 3c 10s
   Hand twoPair4(
      Card(Card::FOUR,  Card::SPADE),
      Card(Card::FOUR,  Card::CLUB),
      Card(Card::THREE, Card::SPADE),
      Card(Card::THREE, Card::HEART),
      Card(Card::KING,  Card::DIAMOND));

   this->addHand(twoPair4);

   cout << "vs" << endl;

   Hand twoPair5(
      Card(Card::FOUR,  Card::HEART),
      Card(Card::FOUR,  Card::DIAMOND),
      Card(Card::THREE, Card::DIAMOND),
      Card(Card::THREE, Card::CLUB),
      Card(Card::TEN,   Card::SPADE));

   this->addHand(twoPair5);

   cout << endl;

} // end HandGenerator::~generateTwoPair