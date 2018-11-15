/* File: pokerhand.cpp

   CMSC 202 Computer Science II
   Spring 2016 Project 2
   
   Implementation of PokerHand class.
   See pokerhand.h for documentation.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

#include "pokerhand.h"

PokerHand::PokerHand () {
  m_valid = false ;
  m_rank = NoRank ;
  
  m_lastCardPoints = 0 ;
  m_firstPairPoints = 0 ;
  m_secondPairPoints = 0 ;
  m_tripletPoints = 0 ;
  m_quadrupletPoints = 0 ;
}



PokerHand::PokerHand (Card c0, Card c1, Card c2, Card c3, Card c4) {

  // Store cards
  m_cards[0] = c0 ;
  m_cards[1] = c1 ;
  m_cards[2] = c2 ;
  m_cards[3] = c3 ;
  m_cards[4] = c4 ;


  // We have cards.
  // Note: this assumes c0, ..., c4 are valid
  //
  m_valid = true ;
  m_rank = NoRank ;

  // Default values for "additional information"
  //
  m_lastCardPoints = 0 ;
  m_firstPairPoints = 0 ;
  m_secondPairPoints = 0 ;
  m_tripletPoints = 0 ;
  m_quadrupletPoints = 0 ;

  // Don't forget to sort
  //
  sort();


  // IF YOU WANT THE ALTERNATE CONSTRUCTOR
  // TO DO MORE, PLACE THE CODE AFTER THIS
  // LINE:
  // --------------------------------------

  //check validity.
  if (m_cards[0].points() == 0 or
      m_cards[1].points() == 0 or
      m_cards[2].points() == 0 or
      m_cards[3].points() == 0 or
      m_cards[4].points() == 0){
    m_valid = false;
    m_rank = NoRank;
  }
}
int PokerHand::cmp(PokerHand &otherHand) {
  
  //stores the other hands points and rank in variables.
  pRank  yrRank = otherHand.m_rank;
  Card::cPoints yrLastCard = otherHand.m_lastCardPoints;
  Card::cPoints yrFirstPairPoints = otherHand.m_firstPairPoints;
  Card::cPoints yrSecondPairPoints = otherHand.m_secondPairPoints;
  Card::cPoints yrTripletPoints = otherHand.m_tripletPoints;
  Card::cPoints yrQuadrupletPoints = otherHand.m_quadrupletPoints;
    
  //Checks who wins by rank
  if (yrRank < m_rank){
    return 1;
  }
  else if(yrRank > m_rank){
    return -1;
  } 
  else if(yrRank == m_rank){
    //Checks whoo wins by higher fours of a kind
    if (yrQuadrupletPoints < m_quadrupletPoints){
      return 1;
    }
    else if(yrQuadrupletPoints > m_quadrupletPoints){
      return -1;
    }
    else if(yrQuadrupletPoints == m_quadrupletPoints and m_quadrupletPoints != 0){
      //Checks who wins by last card in four of a kind tie
      if (yrLastCard < m_lastCardPoints){
	return 1;
      }
      else if(yrLastCard > m_lastCardPoints){
	return -1;
      }
      else if(yrLastCard == m_lastCardPoints and m_lastCardPoints != 0){
	return 0;
      }
    }
    //Checks who wins by three of a kind
    else{
      if (yrTripletPoints < m_tripletPoints){
	return 1;
      }
      else if(yrTripletPoints > m_tripletPoints){
	return -1;
      }
      else if(yrTripletPoints == m_tripletPoints and m_tripletPoints != 0){
	//Checks who wins by higher second pair in full house
	if (yrFirstPairPoints < m_firstPairPoints){
	  return 1;
	}
	else if(yrFirstPairPoints > m_firstPairPoints){
	  return -1;
	}
	else if(yrFirstPairPoints == m_firstPairPoints and m_firstPairPoints != 0){
	  return 0;
	}
      }
      //Checks who wins by first pair 
      else{
	if (yrFirstPairPoints < m_firstPairPoints){
	  return 1;
	}
	else if(yrFirstPairPoints > m_firstPairPoints){
	  return -1;
	}
	else if(yrFirstPairPoints == m_firstPairPoints and m_firstPairPoints != 0){
	  //Checks who wins second pair in two pair
	  if (yrSecondPairPoints < m_secondPairPoints){
	    return 1;
	  }
	  else if(yrSecondPairPoints > m_secondPairPoints){
	    return -1;
	  }
	  else if(yrSecondPairPoints == m_secondPairPoints and m_secondPairPoints != 0){
	    //Checks who wins if both pairs in two pair are equal
	    if (yrLastCard < m_lastCardPoints){
	      return 1;
	    }
	    else if(yrLastCard > m_lastCardPoints){
	      return -1;
	    }
	    else if(yrLastCard == m_lastCardPoints and m_lastCardPoints != 0){
	      return 0;
	    }
	  }
	}
      }
    }
  }
}


void PokerHand::printRank(){
  //Prinks the rank if valid
  if (m_valid == true){
    m_rank = getRank();
    switch(m_rank){
    case OnePair:
      cout << "One Pair" << endl;
      break;
    case HighCard:
      cout << "High Card" << endl;
      break;
    case TwoPair:
      cout << "Two Pair" << endl;
      break;
    case ThreeOfAKind:
      cout << "Three Of A Kind" << endl;
      break;
    case Straight:
      cout << "Straight" << endl;
      break;
    case Flush:
      cout << "Flush" << endl;
      break;
    case FullHouse:
      cout << "Full House" << endl;
      break;
    case FourOfAKind:
      cout << "Four Of A Kind" << endl;
      break;
    case StraightFlush:
      cout << "Straight Flush" << endl;
      break;
    case RoyalFlush:
      cout << "Royal Flush" << endl;
      break;
    default:
      cout << "No Rank" << endl;
    break;
    }
  }
  //If invalid prints no rank
  else{
    cout << "No Rank" << endl;
  }
}

void PokerHand::printCards(){
  //Prints the cards if they are ALL valid
  if (m_valid == true){
    for (int i = 0; i < FIVE; i++){
      int points = m_cards[i].points();
      int suit = m_cards[i].suit();
      if (points <= 10){
	cout << points;
      }
      else {
	switch(points){
	case 11:
	  cout << "Jack";
	  break;
	case 12:
	  cout << "Queen";
	  break;
	case 13:
	  cout << "King";
	  break;
	case 14:
	  cout << "Ace";
	  break;
	default:
	  cout << "Invalid" << endl;
	  break;
	}
    }
      cout << " of ";
      switch(suit){
      case 1:
	cout << "Clubs" << endl;
	break;
      case 2:
	cout << "Diamonds" << endl;
	break;
      case 3:
	cout << "Hearts" << endl;
	break;
      case 4:
	cout << "Spades" << endl;
	break;
      default:
	cout << "Invalid" << endl;
	break;
      }
    }
  }
  //If any cards invalid prints invalid
  else{
    cout << "Invalid" << endl;
  }
}

PokerHand::pRank PokerHand::getRank(){
  //returns the rank of hand, if hand is valid 
  if (m_valid == true){
    if(isRoyalFlush()){
      return m_rank;
    } 
    else if(isStraightFlush()){
      return m_rank;
    }
    else if(isFourOfAKind()){
      return m_rank;
    }
    else if(isFullHouse()){
      return m_rank;
    }
    else if(isFlush()){
      return m_rank;
    }
    else if(isStraight()){
      return m_rank;
    }
    else if(isThreeOfAKind()){
      return m_rank;
    }
    else if(isTwoPair()){
      return m_rank;
    }
    else if(isOnePair()){
      return m_rank;
    }
    else if(isHighCard()){
      return m_rank;
    }
    else{
      return NoRank;
    }
  }
  //returns no rank if hand is invalid
  else{
    return NoRank;  
  }
}
  
bool PokerHand::isRoyalFlush() {
  //Checks if has same suits and straight of high cards
  if (m_cards[0].points() == 10 
      and m_cards[1].points() == 11 
      and m_cards[2].points() == 12 
      and m_cards[3].points() == 13
      and m_cards[4].points() == 14
      and isAllOneSuit()){
    m_rank = RoyalFlush;
    return true;
  }
  else{
    return false;
  }
}
  
bool PokerHand::isStraightFlush() {
  ////Checks if has same suits and straight of low cards
  if(isAllOneSuit() 
     and isSequence()){
    m_rank = StraightFlush;
    return true;
  }
  else{
    return false;
  }
}
 
bool PokerHand::isFourOfAKind() {
  //Checks if it has four of a kind in first four cards
  if (m_cards[0].points() == m_cards[1].points() 
      and m_cards[1].points() == m_cards[2].points()
      and m_cards[2].points() == m_cards[3].points()){
    m_quadrupletPoints = m_cards[3].points();
    m_lastCardPoints = m_cards[4].points();
    m_rank = FourOfAKind;
    return true;
  }
  //Checks if it has four of a kind in last four cards
  else if (m_cards[1].points() == m_cards[2].points() 
	   and m_cards[2].points() == m_cards[3].points()
	   and m_cards[3].points() == m_cards[4].points()){
    m_quadrupletPoints = m_cards[4].points();
    m_lastCardPoints = m_cards[0].points();
    m_rank = FourOfAKind;
    return true;
  }
  else{
    return false;
  }
}

bool PokerHand::isFullHouse() {
  //Checks if first three are same point value and last two are same point value
  if (m_cards[0].points() == m_cards[1].points()
      and m_cards[1].points() == m_cards[2].points()
      and m_cards[2].points() != m_cards[3].points()
      and m_cards[3].points() == m_cards[4].points()){
    m_firstPairPoints = m_cards[4].points();
    m_tripletPoints = m_cards[2].points();
    m_rank = FullHouse;
    return true;
  }
  //Checks if last three are same point value and first two are same point value
  else if  (m_cards[0].points() == m_cards[1].points()
	    and m_cards[1].points() != m_cards[2].points()
	    and m_cards[2].points() == m_cards[3].points()
	    and m_cards[3].points() == m_cards[4].points()){
    m_firstPairPoints = m_cards[1].points();
    m_tripletPoints = m_cards[4].points();
    m_rank = FullHouse;
    return true;
  }
  else{
    return false;
  }
}

bool PokerHand::isFlush() {
  //Checks if it is all one suit and isnt a royal flush or straight flush
  if(isAllOneSuit()
     and !(isRoyalFlush())
     and !(isStraightFlush())) {
    m_rank = Flush;
    return true;
  }
  else { 
    return false;
  }
}

bool PokerHand::isStraight() {
  //Checks if is a sequence, but not a straight flush
  if (isSequence()
      and !(isStraightFlush())){
    m_rank = Straight;
    return true;
  }
  else{
    return false;
  }
}

bool PokerHand::isThreeOfAKind() {
  //Checks if first three cards are three of a kind
  if(m_cards[0].points() == m_cards[1].points()
     and m_cards[1].points() == m_cards[2].points()
     and m_cards[2].points() != m_cards[3].points()
     and !(isFullHouse())){
    m_tripletPoints = m_cards[2].points();
    m_rank = ThreeOfAKind;
    return true;
  }
  //Checks if middle three cards are three of a kind
  else if(m_cards[1].points() == m_cards[2].points()
	  and m_cards[2].points() == m_cards[3].points()
	  and m_cards[3].points() == m_cards[4].points()
	  and !(isFullHouse())){
    m_tripletPoints = m_cards[3].points();
    m_rank = ThreeOfAKind;
    return true;
  }
  //Checks if last three cards are three of a kind
  else if(m_cards[2].points() == m_cards[3].points()
	  and m_cards[3].points() == m_cards[4].points()
	  and !(isFullHouse())){
    m_tripletPoints = m_cards[4].points();
    m_rank = ThreeOfAKind;
    return true;
  }
  else{
    return false;
  }
}

bool PokerHand::isTwoPair() {
  //Checks if first four cards are two pairs and not equal to full house
  if(m_cards[0].points() == m_cards[1].points() and
     m_cards[1].points() != m_cards[2].points() and
     m_cards[2].points() == m_cards[3].points() and
     m_cards[3].points() != m_cards[4].points() and 
     !(isFullHouse())){
    m_firstPairPoints = m_cards[3].points();
    m_secondPairPoints = m_cards[1].points();
    m_lastCardPoints = m_cards[4].points();
    m_rank = TwoPair;
    return true;
  }
  //Checks if last fours cards are two pair and not equal to full house
  else if(m_cards[0].points() != m_cards[1].points() and
	  m_cards[1].points() == m_cards[2].points() and
	  m_cards[2].points() != m_cards[3].points() and
	  m_cards[3].points() == m_cards[4].points() and
	  !(isFullHouse())){
      m_firstPairPoints = m_cards[4].points();
      m_secondPairPoints = m_cards[2].points();
      m_lastCardPoints = m_cards[0].points();
      m_rank = TwoPair;
      return true;
  }
  //Checks if first two and last two cards are pairs and not equal to full house
  else if(m_cards[0].points() == m_cards[1].points() and
          m_cards[1].points() != m_cards[2].points() and
          m_cards[2].points() != m_cards[3].points() and
          m_cards[3].points() == m_cards[4].points() and
          !(isFullHouse())){
    m_firstPairPoints = m_cards[4].points();
    m_secondPairPoints = m_cards[1].points();
    m_lastCardPoints = m_cards[2].points();
    m_rank = TwoPair;
    return true;
  }
  else{
    return false;
  }
}

bool PokerHand::isOnePair() {
  //Checks if first two cards are pair and not a two pair
  if(m_cards[0].points() == m_cards[1].points() 
     and m_cards[1].points() != m_cards[2].points()
     and !(isTwoPair())){
    m_firstPairPoints = m_cards[1].points();
    m_rank = OnePair;
    return true;
  }
  //Checks if second and third cards are pair and not a two pair
  else if(m_cards[1].points() == m_cards[2].points() 
	  and m_cards[2].points() != m_cards[3].points()
	  and !(isTwoPair())){
    m_firstPairPoints = m_cards[2].points();
    m_rank = OnePair;
    return true;
  }
  //Checks if third and fourth cards are pair and not a two pair
  else if(m_cards[2].points() == m_cards[3].points() 
	  and m_cards[3].points() != m_cards[4].points()
	  and !(isTwoPair())){
    m_firstPairPoints = m_cards[3].points();
    m_rank = OnePair;
    return true;
  }
  //Checks if last two cards are pair and not a two pair
  else if(m_cards[3].points() == m_cards[4].points()
	  and !(isTwoPair())){
    m_firstPairPoints = m_cards[4].points();
    m_rank = OnePair;
    return true;
  }
  else{
    return false;
  }
}


bool PokerHand::isHighCard() {
  //Checks that the hand is no other rank
  if ( !(isOnePair()) 
       and !(isRoyalFlush())
       and !(isStraightFlush())
       and !(isFourOfAKind())
       and !(isFullHouse())
       and !(isFlush())
       and !(isStraight())
       and !(isThreeOfAKind())
       and !(isTwoPair())
       and !(isOnePair())){
    m_rank = HighCard;
    return true;
  }
  else{
    return false;
  }
}

bool PokerHand::isAllOneSuit() {
  //Checks if hand is all the same suit
  if(m_cards[0].suit() == m_cards[1].suit()
     and m_cards[1].suit() == m_cards[2].suit()
     and m_cards[2].suit() == m_cards[3].suit()
     and m_cards[3].suit() == m_cards[4].suit()){
    return true;
  }
  else{
    return false;
  }
}

bool PokerHand::isSequence() {
  //Checks if the hand is in sequencial order
  if (m_cards[1].points() == m_cards[0].points() + 1
      and m_cards[2].points() == m_cards[1].points() + 1
      and m_cards[3].points() == m_cards[2].points() + 1
      and m_cards[4].points() == m_cards[3].points() + 1){
    return true;
  }
  else{
    return false;
  }

}

void PokerHand::sort() {
  //Loops through sorting array until sorted is true
  bool sorted = false;
  do{
    int sortCount = 0;
    for(int i = 1; i < FIVE; i++){
      if(m_cards[i].points() < m_cards[i-1].points()){
	Card temp = m_cards[i];
	m_cards[i] = m_cards[i-1];
	m_cards[i-1] = temp;
	sorted = false;
      }
      else{
	sortCount++;
      }
      if (sortCount == 4){
	sorted = true;
      }
    }
  }while(sorted != true);
}

