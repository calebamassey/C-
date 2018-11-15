//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Author: Caleb Massey
//Email: cmassey1.edu
//Date: 4/22/2016
//Section: 18
//Description: This is a child class for the class Player and it changes the  
//code to make the game work to allow Cruno8n to pick the best suit to change
//to.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
using namespace std;
#include "Cruno8.h"
#include "CrunoPlayer.h"
#include "CrunoGame.h"


Card *CrunoPlayer::playOneCard(bool &lastCard, bool &oneCardLeft) {

  unsigned int c ;
  Card *cptr, *temp ;

  // find first card that is playable
   
  c = 0 ;        // index into array of Card pointers
  cptr = NULL ;  // haven't found a playable card yet

  while( 1 ) {
    if (c >= m_numCards) break ;   // hit end of array
      
    if (m_cards[c]->playable(m_game)) { // found playable card

      cptr = m_cards[c] ;  // remember the card

      // To remove the card we will play from the hand,
      // we replace it with the last card in the array.
      // This changes the order of the cards, but 
      // order doesn't matter here.

      m_numCards-- ;                       // one less card
      m_cards[c] = m_cards[m_numCards] ;   // replace with last card
      m_cards[m_numCards] = NULL ;         // just to be safe

      if (m_numCards == 1) oneCardLeft = true ;  // say "Uno"?
      if (m_numCards == 0) lastCard = true ;     // did we win?
      break ;
    }

    c++ ;    // no pun intended
  }

  return cptr ; 
   
}

unsigned int CrunoPlayer::pickSuit(){
  cout << "Yes" << endl;
  return 0;
}
