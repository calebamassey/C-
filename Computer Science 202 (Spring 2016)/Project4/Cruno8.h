//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with 8's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CRUNO8_H_
#define CRUNO8_H_

#include "card.h"

class Cruno8 : public Card{
 public:
  Cruno8(unsigned int s, unsigned int p);
  string toString();
  bool playable(Game *gptr);
  void playCard(Game *gptr, Player *pptr);
};

#endif
