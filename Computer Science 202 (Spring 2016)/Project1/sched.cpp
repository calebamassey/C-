#include <iostream>
#include <iomanip>
#include <string>
#include "sched.h"

using namespace std;

// FUNCTION PROTOTYPES -- DO NOT CHANGE!

// sort() - sorts an array of floats returning sorted indices
// On return, indx[] is an array of indices such that data[indx[0]],
// data[indx[1]], ..., data[indx[len-1]] is data[] in ascending order.
//
// Parameters
//    data[] - float array of data to be ordered
//    indx[] - int array, same length as data[], to hold indices
//    len - int specifying the length of data[] and indx[]

void sort(float data[], int indx[], int len);

// sched() - schedules events given start and end times, and indx[] from sort
// Returns number of events scheduled; on return, scheduled[] contains
// indices of scheduled events (e.g. startTime[scheduled[0]] is the start
// time of the first schedled event).
//
// Parameters
//    startTime[] - float array of event start times
//    endTime[] - float array of event end times
//    indx[] - array of indices that orders the end times
//    scheduled[] - int array to hold indices of scheduled events
//    len - int specifying the length of the arrays
// Returns
//    int value specifying number of events scheduled

int sched(float startTime[], float endTime[], int indx[], int scheduled[], int len);

// printEvent() - prints an event to the console
// Converts float start and end times to hh:mm format and prints times
// along with description.  E.g. Study Session from 12.5 to 13.25 should
// print as "12:30 - 13:15 Study Session"
//
// Parameters
//    startTime - float event start time
//    endTime - float event end time
//    description - string event description

void printEvent(float startTime, float endTime, string description);

// MAIN PROGRAM - DO NOT CHANGE!

int main() {

  int indx[NUM_EVENTS];
  int scheduledEvents[NUM_EVENTS];
  int numSched;

  // Sort by event ending times
  sort(endTime, indx, NUM_EVENTS);

  // Call greedy scheduling algorithm
  numSched = sched(startTime, endTime, indx, scheduledEvents, NUM_EVENTS);

  // Display scheduled events
  for (int i = 0; i < numSched; i++)
  printEvent(startTime[scheduledEvents[i]], endTime[scheduledEvents[i]],
  	       description[scheduledEvents[i]]);

  return 0;
}

//
// FUNCTION IMPLEMENTATIONS GO HERE
//

void sort(float data[], int indx[], int len) {

  /*
    This part of the function searches through the array data[] to find the maximum size inside the array, so when the program
     is finding the minimum values it can include all numbers in array data[] 
  */
  float max = data[0];
  for (int i = 0; i < len; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }

  /*
    This part of the function searches through array data[] len number of times in order to fill array indx[] with indeces of increasing
    value from data[]. This part works by searching for the smallest value and then once found it stores it as the lastMin in order to 
    prevent the program from storing the smallest value len times and instead stores the increasing values of data[] into indx[].
  */
  float lastMin = 0.0;
  int num = 0;
  bool used = false;
  for (int j = 0; j < len; j++) { //Placement spots in indx[]
    float min = max + 1;
    int count = 0;
    for (int k = 0; k < len; k++) { //Spots in data[]
      if (data[k] < min and data[k] > lastMin) {   //This checks if the spot in data[] is the smallest value not yet used.
	min = data[k];
	num = k;
      }
      if (data[j] == data[k]) { //checks if multiple values in array.
	count++;
      }
      if (count > 1) { //Makes next if statement true if mulitple values in array
	used = false;
      }
      if (data[k] == lastMin and k != indx[j - 1] and used == false) { //This runs the repeated values in the code.
	min = data[k];
	num = k;
	used = true;
      }
    }
    indx[j] = num;
    lastMin = min;
  }
}

int sched(float startTime[], float endTime[], int indx[], int scheduled[], int len) {
  int count = 0;
  scheduled[count] = indx[0];
  count++;

  /*
    This finds the first startTime value that is greater than the current endTime value (meaning next class starts after current class ends).
    Then the program changes current class to next class and finds the most possible classes to take together and stores in scheduled[]. This 
    program also keeps track, with count, of how many values are stored in scheduled[] and returns it to main();
  */

  for (int k = 0; k < len - 1;) { //endTime
    for(int i = 0; i < len; i++) { //startTime
      if (startTime[indx[i]] >= endTime[indx[k]]) { 
	scheduled[count] = indx[i];
	count++; 
	k = i;
	i = len + 1;
      }
    } 
   }
  return count;
}

void printEvent(float startTime, float endTime, string description) {

  int startHour = 0;
  float startMin = 0;
  int endHour = 0;
  float endMin = 0;
  string prntStartMin;
  string prntStartHour;
  string prntEndMin;
  string prntEndHour;

  //This sperates the whole numbers(hours) and decimals(minutes).
  startHour =  (startTime / 1);
  startMin = (startTime - startHour) * 60;
  endHour =  (endTime / 1);
  endMin = (endTime - endHour) * 60;

  //This prints the schedule depending on situations of what the time is.

  if (startHour < 10) { //This prevents the time form being printed as "H:MM" and instead is "0H:MM".
    cout << "0" << int(startHour) << ":";
  }
  else {
    cout << int(startHour) << ":";
  }

  if (startMin == 0) { //This prevents the time form being printed as "HH:0" and instead is "HH:00".
    cout << "00 - ";
  }
  else if (startMin < 10){
    cout << "0" << int(startMin) << " - ";
  }
  else {
    cout << int(startMin) << " - ";
  }

  if (endHour < 10) { //This prevents the time form being printed as "H:MM" and instead is "0H:MM".
    cout << "0" << int(endHour) << ":";
  }
  else {
    cout << int(endHour) << ":";
  }

  if (endMin == 0) { //This prevents the time form being printed as "HH:0" and instead is "HH:00".
    cout << "00 ";
  }
  else if (endMin < 10){
    cout << "0" << int(endMin) << " ";
  }
  else {
    cout << int(endMin) << " ";
  }
  
  cout << description << endl;
 }
