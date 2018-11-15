//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Card and it changes the  
//code to make the game work with skips's special skills.
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CRUNOSKIP_H_
#define CRUNOSKIP_H_

#include "card.h"

class CrunoSkip : public Card{
 public:
  CrunoSkip(unsigned int s, unsigned int p);
  string toString();
  void playCard(Game *gptr, Player *pptr);
};

#endif
