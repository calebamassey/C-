//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with reverse's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CRUNOREVERSE_H_
#define CRUNOREVERSE_H_

#include "card.h"
class CrunoReverse : public Card {
 public:
  CrunoReverse(unsigned int s,unsigned  int p);
  string toString();
  void playCard(Game* gptr, Player* pptr);
};

#endif
