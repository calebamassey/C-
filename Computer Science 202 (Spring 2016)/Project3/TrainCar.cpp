// 
// CMSC 202 Project file
//
// COMPLETE THE IMPLEMENTATION AS INSTRUCTED
//

#include <iostream>
using namespace std;

#include "TrainCar.h"

TrainCar::TrainCar() : m_type( NoType ), m_next( NULL ) 
{ /* empty constructor body */ }

TrainCar::TrainCar( TrainCar::cType car ) : m_type( car ), m_next( NULL ) 
{ /* empty constructor body */ }

void TrainCar::setType( TrainCar::cType car ) {
  m_type = car;
}

TrainCar::cType TrainCar::getType() const {
  return m_type;
}

//
// IMPLEMENT THE OVERLOADED INSERTION OPERATOR
//

//Prints out a model of the train
ostream& operator<<(ostream& outStream, const TrainCar& car){
  switch (car.getType()){
  case TrainCar::Locomotive:
    cout << "// Locomotive ]]";
  case 1:
    cout << "[ oo Coach oo ]";
  case 2:
    cout << "[  Business  ]";
  case 3:
    cout << "[ - Dining - ]";
  case 4:
    cout << "[ -- Snack -- ]";
  case 5:
    cout << "[ o Sleeper o ]";
    }
  return outStream;
}
