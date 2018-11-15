//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with reverse's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "CrunoGame.h"
#include "CrunoReverse.h"
#include "card.h"

CrunoReverse::CrunoReverse(unsigned int s, unsigned int p){
  Card::m_suit = s;
  Card::m_points = p;
}

string CrunoReverse::toString() {
  ostringstream oss;
  if (m_points == 19 or m_points == 20){
    oss << "Reverse" ;
  }
  switch (m_suit) {
  case Clubs :
    oss << " of Clubs" ;
    break ;
  case Diamonds :
    oss << " of Diamonds" ;
    break ;
  case Hearts :
    oss << " of Hearts" ;
    break ;
  case Spades :
    oss << " of Spades" ;
    break ;
  default :
    oss << "of INVALID SUIT\n" ;
  }
  return oss.str();
}

void CrunoReverse::playCard(Game *gptr, Player *pptr){
  Card::playCard(gptr, pptr);
  
  CrunoGame *cgptr ; 
  cgptr = dynamic_cast<CrunoGame *>(gptr) ;

  int player = gptr->currentPlayer();
  cout << endl << "Player " << player << " reversed direction " << endl;
  cgptr->changeDirection();
  
}
