/* File: mytest.cpp
*Author: Caleb Massey
*Date: 3/9/2016
*Section: 18
*Email: cmassey1@umbc.edu
*Description: The main() function in this program uses
*the Card and PokerHand classes to
*to determine the rank of a poker hand.
*/

#include <iostream>
using namespace std ;
#include "pokerhand.h"

int main() {

  //Royal Flush
  Card a0(Card::Clubs,  10) ;
  Card a1(Card::Clubs,  14) ;
  Card a2(Card::Clubs,  13) ;
  Card a3(Card::Clubs,  11) ;
  Card a4(Card::Clubs,  12) ;

  PokerHand myHand1(a0, a1, a2, a3, a4) ;

  if ( myHand1.isRoyalFlush() ) {
    cout << "Yes!! I have a Royal Flush\n" ;
  } else {
    cout << "My hand " << endl;
  }
  myHand1.printCards() ;
  cout << "is a " ;
  myHand1.printRank() ;
  cout << endl ;

  //Straight
  Card b0(Card::Spades,   12) ;
  Card b1(Card::Clubs,    11) ;
  Card b2(Card::Clubs,     9) ;
  Card b3(Card::Diamonds, 13) ;
  Card b4(Card::Hearts,   10) ;

  PokerHand myHand2(b0, b1, b2, b3, b4) ;

  if ( myHand2.isRoyalFlush() ) {
    cout << "Yes!! I have a Royal Flush\n" ;
  } else {
    cout << "My hand " << endl;
  }
  myHand2.printCards() ;
  cout << "is a " ;
  myHand2.printRank() ;
  cout << endl ;
  
  //Invalid
  Card c0(Card::Spades,   16) ;
  Card c1(Card::Clubs,     8) ;
  Card c2(Card::Clubs,    12) ;
  Card c3(Card::Diamonds,  8) ;
  Card c4(Card::Hearts,   12) ;

  PokerHand myHand3(c0, c1, c2, c3, c4) ;

  if ( myHand3.isRoyalFlush() ) {
    cout << "Yes!! I have a Royal Flush\n" ;
  } else {
    cout << "My hand " << endl;
  }
  myHand3.printCards() ;
  cout << "is a " ;
  myHand3.printRank() ;
  cout << endl ;

  //Two Pair
  Card d0(Card::Spades,   12) ;
  Card d1(Card::Clubs,    12) ;
  Card d2(Card::Clubs,     4) ;
  Card d3(Card::Diamonds,  4) ;
  Card d4(Card::Hearts,    2) ;

  PokerHand myHand4(d0, d1, d2, d3, d4) ;

  if ( myHand4.isRoyalFlush() ) {
    cout << "Yes!! I have a Royal Flush\n" ;
  } else {
    cout << "My hand " << endl;
  }
  myHand4.printCards() ;
  cout << "is a " ;
  myHand4.printRank() ;
  cout << endl ;

  cout << "*****************************************" << endl;
  
  //Compare my flush to your royal flush
  Card e0(Card::Spades, 12) ;
  Card e1(Card::Spades,  4) ;
  Card e2(Card::Spades,  5) ;
  Card e3(Card::Spades,  7) ;
  Card e4(Card::Spades, 10) ;

  PokerHand myHand5(e0, e1, e2, e3, e4) ;

  if ( myHand5.isRoyalFlush() ) {
    cout << "Yes!! I have a Royal Flush\n" ;
  } else {
    cout << "My hand is a " ;
  }
  myHand5.printRank() ;
  cout << endl ;

// Pick 5 more cards
  //
  Card f0(Card::Spades,    12) ;
  Card f1(Card::Spades,    14) ;
  Card f2(Card::Spades,    13) ;
  Card f3(Card::Spades,    11) ;
  Card f4(Card::Spades,    10) ;

  PokerHand yourHand(f0, f1, f2, f3, f4) ;

  cout << "Your hand is a " ;
  yourHand.printRank() ;
  cout << endl ;

  if (myHand5.cmp(yourHand) > 0) {
    cout << "My hand beats yours.\n" ;
  } else if (myHand5.cmp(yourHand) < 0) {
    cout << "Your hand beats mine.\n" ;
  } else {
    cout << "Our hands are tied.\n" ;
  }

  cout << "\nMy hand is:\n" ;
  myHand5.printCards() ;
  cout << "\nYour hand is:\n" ;
  yourHand.printCards() ;

}
