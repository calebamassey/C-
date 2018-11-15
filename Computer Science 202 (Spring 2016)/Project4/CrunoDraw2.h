//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with draw2's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CRUNODRAW2_H_
#define CRUNODRAW2_H_

#include "card.h"

class CrunoDraw2 : public Card {
 public:
  CrunoDraw2(unsigned int s, unsigned int p);
  string toString();
  void playCard(Game *gptr, Player *pptr);
};

#endif
