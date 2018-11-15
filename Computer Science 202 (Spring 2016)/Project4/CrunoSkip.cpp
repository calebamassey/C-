//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with skip's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "game.h"
#include "CrunoGame.h"
#include "CrunoSkip.h"
#include "card.h"

CrunoSkip::CrunoSkip(unsigned int s,unsigned int p){
  Card::m_suit = s;
  Card::m_points = p;
}

string CrunoSkip::toString() {
  ostringstream oss;
  if (m_points == 17 or m_points == 18){
    oss << "Skip" ;
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

void CrunoSkip::playCard(Game *gptr, Player *pptr){
  Card::playCard(gptr, pptr);
  int player = gptr->nextPlayer();
  cout << endl << "Player " << player << " got skipped" << endl;
}
