//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is the test file I made to test my code 
// for the Project 4 "Cruno".
//                                                          
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
using namespace std;

#include "card.h"
#include "game.h"
#include "player.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"

int main() {
  
  CrunoGame C;
  C.initialize(3) ;  

  int n = C.getNumCards() ;
  Player *pptr1 = new Player(&C,n) ;
  Player *pptr2 = new Player(&C,n) ;
  Player *pptr3 = new Player(&C,n) ;
  Player *pptr4 = new Player(&C,n) ;
  //Player *pptr5 = new Player(&C,n) ;
  //Player *pptr6 = new Player(&C,n) ;
  //Player *pptr7 = new Player(&C,n) ;
  //Player *pptr8 = new Player(&C,n) ;

  C.addPlayer(pptr1) ;
  C.addPlayer(pptr2) ;
  C.addPlayer(pptr3) ;
  C.addPlayer(pptr4) ;
  //C.addPlayer(pptr5) ;
  //C.addPlayer(pptr6) ;
  //C.addPlayer(pptr7) ;
  //C.addPlayer(pptr8) ;

  //C.startGame(3810743) ;
  //C.startGame(8132987) ;
  C.startGame(7831035) ;
  //   C.startGame(2310831) ;

  return 0 ;

}

