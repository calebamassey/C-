//
//
// 
// CMSC 202 Project File
//
// TWO CONSTRUCTORS ARE GIVEN.  IMPLEMENT THE REMAINDER OF
// THE CLASS AND THE OVERLOADED INSERTION OPERATOR
//


#include <iostream>
using namespace std;

#include "Train.h"
#include "TrainCar.h"

// Default constructor.  Initialize variables and create dummy node.
Train::Train() : m_number(0), m_departs( Time() ), m_destination ( "" ),
		 m_hasSnackCar(false), m_numCoachClass(0), 
		 m_numBusinessClass(0), m_numSleepingCar(0) {
  m_head = new TrainCar(); // dummy node
}

// Non-default constructor.  Initialize variables and create dummy node.
Train::Train( int num, Time dep, string dest) 
  : m_number(num), m_departs(dep), m_destination(dest),
    m_hasSnackCar(false), m_numCoachClass(0), 
    m_numBusinessClass(0), m_numSleepingCar(0) {
  m_head = new TrainCar(); // dummy node
}

//
// IMPLEMENT THE REMAINDER OF THE CLASS AND THE OVERLOADED
// INSERTION OPERATOR
//
Train::~Train(){
  TrainCar *temp = new TrainCar;
  TrainCar *curr = new TrainCar;
  curr = m_head;

  while (curr != NULL){ //Goes through entire train until reaches NULL and removes the car and sets it equal to NULL.
    temp = curr;
    curr = curr->m_next;
    delete temp;
    temp->m_next = NULL;
  }

}

void Train::addCar( TrainCar::cType car ){
  TrainCar *temp = new TrainCar;
  temp = m_head;
  TrainCar *curr = new TrainCar;
  curr = m_head->m_next;
  TrainCar *newNode = new TrainCar(car);
  TrainCar::cType val; //val is used to store the type for nodes.

  if (m_head->m_next == NULL){  //Nothing in the list.
    m_head->m_next = newNode;
    newNode->m_next = NULL;
    if (car == 1)
      m_numCoachClass++;
    else if (car == 2)
      m_numBusinessClass++;
    else if (car == 5)
      m_numSleepingCar++;
    else if (car == 4)
      m_hasSnackCar = true;
  }
  else{
    switch(car){
    case 0://Locomotive
      m_head->m_next = newNode;
      newNode->m_next = curr;
      
    case 1://Coach Car
      //Checks if there is a BusinessClass and/or a SnackCar and runs accordingly.
      if (m_numBusinessClass > 0){
	val = curr->getType();
        while(val == 0 or val == 2 or val == 4){
          temp = curr;
          curr = curr->m_next;
	  val = curr->getType();
        }
        temp->m_next = newNode;
        newNode->m_next = curr;
	m_numCoachClass++;
      }
      val = curr->getType();
      if (val != 0 and m_numBusinessClass == 0 and m_hasSnackCar == false){
	newNode->m_next = m_head->m_next;
	m_head->m_next = newNode;
	m_numCoachClass++;
      }
      if (val == 0 and m_numBusinessClass == 0 and m_hasSnackCar == false){
	while(val == 0){
          temp = curr;
          curr = curr->m_next;
	  val = curr->getType();
        }
        temp->m_next = newNode;
        newNode->m_next = curr;
	m_numCoachClass++;
      }
      if (m_numBusinessClass == 0 and m_hasSnackCar == true){
	if (m_numCoachClass % 2 == 0){
	  val = curr->getType();
	  while(val != 4){
	    temp = curr;
	    curr = curr->m_next;
	    val = curr->getType();
	  }
	  temp->m_next = newNode;
	  newNode->m_next = curr;
	  m_numCoachClass++;
	}
	else {
	  val = curr->getType();
	  while(val != 4){
	    temp = curr;
            curr = curr->m_next;
	    val = curr->getType();
	  }
	  temp->m_next = newNode;
          newNode->m_next = curr;
	  m_numCoachClass++;
	}
      }
      
    case 2://Business Car
      //Checks if there is a locomotive and runs accordingly.
      val = curr->getType(); 
      while (val == 0){
	temp = curr;
	curr = curr->m_next;
	val = curr->getType();
      }
      temp->m_next = newNode;
      newNode->m_next = curr;
      m_numBusinessClass++;

    case 3://Dining Car
      //Checks if there is a SleepingCar and if there is adds DiningCar before it.
      val = curr->getType();
      while (val != 5){
	temp = curr;
	curr = curr->m_next;
	val = curr->getType();
      }
      temp->m_next = newNode;
      newNode->m_next = curr;
      
    case 4://Snack Car
      if (m_hasSnackCar == true){ //Checks if it already has SnackCar.
	delete newNode;
      }
      //If train doesn't have SnackCar runs accordingly.
      else if (m_numBusinessClass > 0){
	val = curr->getType();
	while(val == 2 or val == 0){
	  temp = curr;
	  curr = curr->m_next;
	  val = curr->getType();
	}
	temp->m_next = newNode;
	newNode->m_next = curr;
	m_hasSnackCar = true;
      }
      else{
	if (m_numCoachClass % 2 == 0){
	  val = temp->getType();
	  while(val != 4){
	    temp = curr;
	    curr = curr->m_next;
	    val = temp->getType();
	  }
	  temp->m_next = newNode;
	  newNode->m_next = curr;
	  m_hasSnackCar = true;
	}
	else{
	  val = curr->getType();
	  while(val != 4){
	    temp = curr;
	    curr = curr->m_next;
	    val = curr->getType();
          }
	  temp->m_next = newNode;
	  newNode->m_next = curr;
	  m_hasSnackCar = true;
	}
      }

    case 5://Sleep Car
      //Adds car to end of train, right before NULL.
      while (curr != NULL){
	temp = curr;
	curr = curr->m_next;
      }
      temp->m_next = newNode;
      newNode->m_next = curr;
      m_numSleepingCar++;
    default:
      delete newNode;

    }
  }
}

bool Train::removeCar( TrainCar::cType car ){
  TrainCar *temp = new TrainCar;
  temp = m_head;
  TrainCar *curr = new TrainCar;
  curr = m_head->m_next;
  TrainCar::cType val;

  switch(car){
  case 0://Locomotive
    //Checks if first car is locomotive, if it is deletes it, if not it returns false
    if (curr->m_next == 0){
      temp->m_next = curr->m_next;
      delete curr;
      curr->m_next = NULL;
      return isValid();
    }
    else{
      return false;
    }
   
  case 1://Coach Car
    //Checks if has CoachClass, if true run accordingly, if false returns false.
    if (m_numCoachClass > 0){
      if (m_numBusinessClass > 0){
	val = curr->getType();
        while(val != 1){
          temp = curr;
          curr = curr->m_next;
	  val = curr->getType();
        }
        temp->m_next = curr->m_next;
	delete curr;
	curr->m_next = NULL;
	m_numCoachClass--;
      }
      val = curr->getType();
      if (val != 0 and m_numBusinessClass == 0 and m_hasSnackCar == false){
	temp->m_next = curr->m_next;
        delete curr;
        curr->m_next = NULL;
	m_numCoachClass--;
      }
      val = curr->getType();
      if (val == 0 and m_numBusinessClass == 0 and m_hasSnackCar == false){
	while(val == 0){
          temp = curr;
          curr = curr->m_next;
	  val = curr->getType();
        }
        temp->m_next = curr->m_next;
        delete curr;
        curr->m_next = NULL;
	m_numCoachClass--;
      }
      if (m_numBusinessClass == 0 and m_hasSnackCar == true){
	if (m_numCoachClass % 2 == 0){
	  val = curr->m_next->getType();
	  while(val != 4){
	    temp = curr;
	    curr = curr->m_next;
	    val = curr->m_next->getType();
	  }
	  temp->m_next = curr->m_next;
	  delete curr;
	  curr->m_next = NULL;
	  m_numCoachClass--;
	}
	else {
	  val = temp->getType();
	  while(val != 4){
	    temp = curr;
            curr = curr->m_next;
	    val = temp->getType();
	  }
	  temp->m_next = curr->m_next;
          delete curr;
          curr->m_next = NULL;
	  m_numCoachClass--;
	}
      }
    }
    else{
      return false;
	}

  case 2://Business Car
    //Checks for business car, if true remove, if false return false.
    if (m_numBusinessClass > 0){
      val = curr->getType();
      while (val == 0){
	temp = curr;
	curr = curr->m_next;
	val = curr->getType();
      }
      temp->m_next = curr->m_next;
      delete curr;
      curr->m_next = NULL;
      m_numBusinessClass--;
    }
    else{
      return false;
    }

 case 3://Dining Car
   return false;
   
  case 4://Snack Car
    if (m_hasSnackCar == true){
      val = curr->getType();
      while(val != 4){
	temp = curr;
	curr = curr->m_next;
	val = curr->getType();
      }
      temp->m_next = curr->m_next;
      delete curr;
      curr->m_next = NULL;
      m_hasSnackCar = false;
    }
    else{
      return false;
    }
    
  case 5://Sleep Car
    //Checks for SleepCar, if true removes it, if false returns false.
    //Checks if there are no more SleepCars once removed and removes DiningCar if there are no SleepCars.
    val = curr->m_next->getType();
    while (val != NULL){
      temp = curr;
      curr = curr->m_next;
      val = curr->m_next->getType();
    }
    temp->m_next = curr->m_next;
    delete curr;
    curr->m_next = NULL;
    m_numSleepingCar--;
    if(m_numSleepingCar == 0){
      val = curr->m_next->getType();
      while (val != NULL){
	temp = curr;
	curr = curr->m_next;
	val = curr->m_next->getType();
      }
      val = curr->m_next->getType();
      if (val == NULL){
	temp->m_next = curr->m_next;
	delete curr;
	curr->m_next = NULL;
      }
    }
 default:
   return false;
  }
}

int Train::getNumber() const{
  return m_number;
}

void Train::setNumber( int num ){
  m_number = num;
}

Time Train::getDepartureTime() const{
  return m_departs;
}

void Train::setDepartureTime( const Time& t ){
  m_departs = t;
}

string Train::getDestination() const{
  return m_destination;
}

void Train::setDestination( string dest ){
  m_destination = dest;
}

bool Train::isValid(){
  //Checks for at least one locomotive and one coach.
  if (m_numCoachClass > 0 and m_head->m_next->getType() == 0){
    return true;
  }
  else{
    return false;
  }
}

//Overloads << to print the train's number, destination, and departureTime.
ostream& operator<<(ostream& os, const Train& t){
  os << "Train #" << t.getNumber() << " to "<< t.getDestination() << " departs at " << t.getDepartureTime() << endl;
  return os;
}
