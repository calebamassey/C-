/* File: card.cpp

   CMSC 202 Computer Science II
   Spring 2016 Project 2

   Implementation of Card member functions.
   See card.h for documentation.

*/

#include <iostream>
#include "card.h"

using namespace std ;


// Default constructor marks card as invalid
//
Card::Card() {
  m_suit = Invalid ;
  m_points = 0 ;
}

//Alternative constructor that checks validity of cards.
Card::Card(cSuit s, cPoints p) {
  if (p > 1 and p <= 14) {
    m_points = p;
  }
  else{
    m_points = 0; 
  }
  if (s > 0 and s <= 4) {
    m_suit = s;
  }
  else {
    m_suit = Invalid;
  }
}

//returns points
Card::cPoints Card::points() {

  return m_points;

}
//returns suit
Card::cSuit Card::suit() {

  return m_suit;

}


void Card::print() {

  if (m_points <= 10) {
    cout << m_points << " ";
  } 
  else{
    switch (m_points) {
    case 11:
      cout << "Jack ";
      break;
    case 12:
      cout << "Queen ";
      break;
    case 13:
      cout << "King ";
      break;
    case 14:
      cout << "Ace ";
      break;
    default:
      cout <<"Invalid ";
    }
  }
  
  cout << "of";

    switch(m_suit) {
  case 1:
    cout << " Clubs" << endl;
    break;
  case 2:
    cout << " Diamonds" << endl;
    break;
  case 3:
    cout << " Hearts" << endl;
    break;
  case 4:
    cout << " Spades" << endl;
    break;
  default :
    cout << " Invalid" << endl;
    break;
  }
}
