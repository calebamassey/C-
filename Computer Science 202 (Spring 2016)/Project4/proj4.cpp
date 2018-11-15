

/* File: proj4.cpp

   CMSC 202 Computer Science II
   Spring 2016 Project 4

   Sample main program.

*/

#include <iostream>
using namespace std ;

#include "card.h"
#include "Cruno8.h"
#include "game.h"
#include "player.h"
#include "CrunoPlayer.h"
#include "CrunoGame.h"

int main() {

  //Game G ;
  CrunoGame C;
  C.initialize(4) ;  // say we'll have four players

  // Make the 4 players and add them
  // We could add any object derived from Player.
  // So, we can have a mix of smart, dumb or cheating
  // players in the same game.
  //
  int n = C.getNumCards() ;
  Player *pptr1 = new Player(&C,n) ;
  Player *pptr2 = new Player(&C,n) ;
  Player *pptr3 = new Player(&C,n) ;
  Player *pptr4 = new Player(&C,n) ;

  C.addPlayer(pptr1) ;
  C.addPlayer(pptr2) ;
  C.addPlayer(pptr3) ;
  C.addPlayer(pptr4) ;

  // Play game with different random seeds.
  // The random seeds control the initial shuffle.

  //C.startGame(3810743) ;
  //   C.startGame(8132987) ;
     C.startGame(7831035) ;
  //   C.startGame(2310831) ;

  return 0 ;
}
