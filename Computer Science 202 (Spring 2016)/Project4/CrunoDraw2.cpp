//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with draw2's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "CrunoPlayer.h"
#include "player.h"
#include "game.h"
#include "CrunoGame.h"
#include "CrunoDraw2.h"
#include "card.h"

CrunoDraw2::CrunoDraw2(unsigned int s, unsigned int p){
  m_suit = s;
  m_points = p;
}

string CrunoDraw2::toString() {
  ostringstream oss;
  if (m_points == 15 or m_points == 16){
    oss << "Draw 2" ;
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

void CrunoDraw2::playCard(Game *gptr, Player *pptr){
  Card::playCard(gptr, pptr);
  int nextPlayer = gptr->nextPlayer();
  cout << endl << endl;
  Card *card1 = gptr->dealOneCard();
  Card *card2 = gptr->dealOneCard();


  //I got the program to add two cards form the top of the stock deck,
  //but i couldnt figure out how to have the player pointer point to the 
  //next player, so the player that plays draw2 draws 2 cards themselves.
  cout << "Player " << nextPlayer << " draws a " << card1-> toString() << endl;
  pptr->takeCard(card1);
  cout << "Player " << nextPlayer << " draws a " << card2-> toString() << endl;
  pptr->takeCard(card2);
  for (int i = 0; i < 3; i++){
    gptr->nextPlayer();
  }

}
