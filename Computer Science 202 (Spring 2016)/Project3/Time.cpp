#include <iostream>
using namespace std;

#include "Time.h"


//Default Constructor
Time::Time(){
  m_hours = 0;
  m_mins = 0;
}

//Alternative Constructor
Time::Time(int hrs, int mns){
  m_hours = hrs;
  m_mins = mns;
}

//The next four functions are,
//set up to allow operators to access m_mins and m_hours.
int Time::GetHours() const {
  return m_hours;
}

int Time::GetMins() const {
  return m_mins;
}
void Time::SetHours(int hours){
  m_hours = hours;
}

void Time::SetMins(int mins){
  m_mins = mins;
}
//

//Prints the time with zeros to maintain 00:00 time.
ostream& operator<<(ostream& os,const Time &time) {
  if (time.GetHours() > 9){
    os << time.GetHours() << ":";
    if (time.GetMins() > 9){
      os << time.GetMins() << endl;
    }
    else{
      os << "0" << time.GetMins();
    }
  }
  else{
    os << "0" << time.GetHours() << ":";
    if (time.GetMins() > 9){
      os << time.GetMins() << endl;
    }
    else{
      os << "0" << time.GetMins();
    }
  } 
  return os;
}

//Makes a new Time variable that stores the new overloaded time and returns it.
Time& operator+(const Time& timeVal, const int& amount) {
    Time *ret = new Time(
        timeVal.GetHours() + ((timeVal.GetMins() + amount) % 60),
        (timeVal.GetMins() + amount) / 60);
    return *ret;
}

//Checks if time1 is greater than time2 by hours unless same hours, 
//then it checks for greater minutes and returns true if time2 > time1 and false if not.
bool operator<(const Time& time1, const Time& time2) {
  if (time1.GetHours() < time2.GetHours()){
    return true;
  }
  else if (time1.GetHours() > time2.GetHours()){
    return false;
  }
  else{
    if (time1.GetMins() < time2.GetMins()){
      return true;
    }
    else{
      return false;
    }
  }
}
