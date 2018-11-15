//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Game and it changes the  
//code to make the game initialize the proper number of cards and to make certain
//functions work properly.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Cruno8.h"
#include "CrunoDraw2.h"
#include "CrunoSkip.h"
#include "CrunoReverse.h"
#include "CrunoGame.h"
#include "CrunoPlayer.h"
#include "game.h"
#include "card.h"

static void ifNullCrash(void *ptr) {
  if (ptr == NULL) {
    cerr << "Could not allocate memory\n" ;
    exit(1) ;
  }
  return ;
}

CrunoGame::CrunoGame(){
  Game();
  m_clockwise = true;
}

void CrunoGame::initialize(int numPlayers){
  m_suit = 0 ;
  m_points = 0 ;
  m_currentPlayer = 0 ;

  // can't play by yourself
  //
  if (numPlayers < 2) {
    cerr << "Insufficient players\n" ;
    exit(1) ;
  }

  // not enough cards to make it fun for >10.
  //
  if (numPlayers > 10) {
    cerr << "Too many players\n" ;
    exit(1) ;
  }

  m_numPlayers = 0 ;  // no players added yet.

  // allocate space for max requested
  //
  m_maxPlayers = numPlayers ;
  m_players = new Player*[numPlayers] ;
  ifNullCrash(m_players) ;

  m_winner = m_maxPlayers + 1 ;  // not a real player

  // usually use just one deck
  int decks = 1 ;
  m_maxCards = 76 ;   // 76 cards in one deck

  if (numPlayers > 5) {
    // use two decks
    decks = 2 ;
    m_maxCards = 152 ;   // 152 cards in two decks
  }
  // allocate space for the discard pile
  m_discard = new Card*[m_maxCards] ;
  ifNullCrash(m_discard) ;
  m_numDiscard = 0 ;  // nothing discarded yet

  // allocate space for the stock pile
  m_stock = new Card*[m_maxCards] ;
  ifNullCrash(m_stock) ;


  int i = 0 ;  // next available slot in m_stock[]

  for (int d = 0 ; d < decks ; d++) {  // # of decks
      
    // iterate over suits
    for (unsigned int s = Card::Clubs ; s <= Card::Spades ; s++) {

      // iterate over point values 
      for (unsigned int p = 2 ; p <= 20 ; p++) {
	if (p >= 2 and p <= 14 and p != 8){
	  m_stock[i] = new Card(s,p) ;  // insert new card with normal points
	  ifNullCrash(m_stock[i]) ;
	  i++ ;
	}
	else if(p > 14 and p <= 16){  // insert new card with draw 2 points
	  m_stock[i] = new CrunoDraw2(s,p);
	  ifNullCrash(m_stock[i]);
	  i++;
	}
	else if(p > 16 and p <= 18){  // insert new card with skip points
	  m_stock[i] = new CrunoSkip(s,p);
	  ifNullCrash(m_stock[i]);
	  i++;
	}
	else if(p > 18 and p <= 20){  // insert new card with reverse points
	  m_stock[i] = new CrunoReverse(s,p);
	  ifNullCrash(m_stock[i]);
	  i++;
	}
	else if(p == 8){             // insert new card with Cruno8 points
	  m_stock[i] = new Cruno8(s,p);
	  ifNullCrash(m_stock[i]);
	  i++;
	}
      }
    }
  }

  // remember how many cards we added
  m_numStock = m_maxCards ;

  // Still haven't started (need to have players added)
  m_started = false ;
  m_over = false ;
}

unsigned int CrunoGame::nextPlayer() {
  if(m_clockwise == true){ //Makes game run clockwise
    m_currentPlayer = (m_currentPlayer + 1) % m_numPlayers ;
    return m_currentPlayer ;
  }
  else{       //Make game run counter-clockwise
    m_currentPlayer = (m_currentPlayer - 1) % m_numPlayers;
    return m_currentPlayer;
  }
}

//Boolean is ture when clockwise and false when counter-clockwise
void  CrunoGame::changeDirection(){
  if (m_clockwise == true){
    m_clockwise = false;
  }
  else{
    m_clockwise = true;
  }
}

void CrunoGame::gameOver(){
  int j;
  Card *topCard = m_discard[m_numDiscard];
  for(unsigned int i = 0 ; i < m_numDiscard - 1 ; i++) {
    m_stock[i] = m_discard[i];
    m_numStock++;

  }

  for(unsigned int i = 0 ; i < m_numDiscard - 1 ; i++) {
    Card *temp ;
    
    j = rand() % m_numStock ;
    temp = m_stock[i] ;
    m_stock[i] = m_stock[j] ;
    m_stock[j] = temp ;
  }
  m_discard[0] = topCard;
}

