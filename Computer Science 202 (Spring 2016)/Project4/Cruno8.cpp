//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with 8's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "CrunoPlayer.h"
#include "Cruno8.h"
#include "card.h"

Cruno8::Cruno8(unsigned int s,unsigned int p){
  Card::m_suit = s;
  Card::m_points = p;
}

string Cruno8::toString() {
  ostringstream oss;
  if (m_points == 8){
    oss << m_points;
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




bool Cruno8::playable(Game *gptr){
  if (Card::m_points == 8){
    return true;
  }
  else{
    Card::playable(gptr);
  }
  return false;;
}

void Cruno8::playCard(Game *gptr, Player *pptr){
  Card::playCard(gptr, pptr);
  cout << "New suit is ";
  switch (pptr->pickSuit()){
    case Clubs :
      cout << "Clubs" << endl ;
    break ;
  case Diamonds :
    cout << "Diamonds" << endl;
    break ;
  case Hearts :
    cout << "Hearts" << endl;
    break ;
  case Spades :
    cout << "Spades" << endl;
    break ;
  default :
    cout << "INVALID SUIT\n" ;
  }

  gptr->setSuit(pptr->pickSuit());
  return ;
}
