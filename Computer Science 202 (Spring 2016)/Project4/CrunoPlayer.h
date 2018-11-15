//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Player and it changes the  
//code to make the game work to allow Cruno8n to pick the best suit to change
//to.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _CRUNOPLAYER_H_
#define _CRUNOPLAYER_H_

#include "player.h"

class CrunoPlayer: public Player {

 public:
  Card *playOneCard(bool &lastCard, bool &oneCardLeft);
  unsigned int pickSuit(); 

};
#endif
