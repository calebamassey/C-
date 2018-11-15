//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Game and it changes the  
//code to make the game initialize the proper number of cards and to make certain
//functions work properly.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef CRUNOGAME_H_
#define CRUNOGAME_H_

#include "game.h"

class CrunoGame: public Game{
 public:
  CrunoGame();
  void initialize(int numPlayers);
  unsigned int nextPlayer();
  void changeDirection();
  void gameOver();
  private:
  bool m_clockwise;
};
#endif
