//******************************************************************************
//Author: Caleb Massey
//Date: 5/5/2016
//Email: cmassey1@umbc.edu
//Section: 18
//Description: This is the test file for project 5
//
//******************************************************************************

#include <iostream>
using namespace std;

#include "sorted.h"

//Default constructor
template <typename T>
sorted<T>::sorted(){
  m_size = 0;
  m_capacity = 10;
  cout << 1;
}

// Non-default constructor copies data from array to sorted
template <typename T>
sorted<T>::sorted( T* data, int len ){
  // if data array is too long, make the array longer
  if ( len > m_capacity )
    m_capacity = 2 * m_capacity;
  m_size = len;
  for (int i = 0; i < m_size; i++) 
    m_data[i] = data[i];

  cout << 2;
}

// Copy constructor
template <typename T>
sorted<T>::sorted( const sorted<T>& srtd ){
  int ptr = new int;
  ptr = *srtd.ptr; // copy the value
}

// Destructor
template <typename T>
sorted<T>::~sorted(){
  delete *const_iterator::m_current;
}


/*

// Overloaded assignment operator
template <typename T>
class sorted<T> sorted<T>::operator=(const sorted<T>& srtd){  
  return 
 }


*/

// Return the capacity of the storage array
template <typename T>
int sorted<T>::capacity() const{
  return m_capacity;
}

// Return number of items stored
template <typename T>
int sorted<T>::size() const{
  return m_size;
}
// Return the address of the storage array;
// for use in grading programs
template <typename T>
T* sorted<T>::getStorageArray() const{
  return const_iterator::m_current;
}

// Insert an item in sorted; return iterator to inserted item
template <typename T>
class sorted<T>::const_iterator sorted<T>::insert(T data){
  // if the array is already full, make array twice as large
  if ( m_size == m_capacity ) 
    m_capacity = m_capacity * 2;
  else {
    m_size++;
    m_data[m_size-1] = data;
    return const_iterator(&m_data[m_size-1]);
  }
}

// Remove an item from sorted; return iterator to next item
// after the erased item
template <typename T>
class sorted<T>::const_iterator sorted<T>::erase(const_iterator itr){
  int* end = &m_data[m_capacity];    // one past the end of data
  int* ptr = itr.m_current;        // element to erase

  // to erase element at ptr, shift elements from ptr+1 to 
  // the end of the array down one position
  while ( ptr+1 != end ) {
    *ptr = *(ptr+1);
    ptr++;
  }
  
  m_size--;

  return itr;
}

// Get element at indx position                                                  
template <typename T>
const T& sorted<T>::at(int indx){
  return m_data[indx];
}

// Starting iterator value for const_iterator
template <typename T>
class sorted<T>::const_iterator sorted<T>::begin(){
  return const_iterator(&m_data[0]);
}

// Ending iterator value for const_iterator; typically,
// one element beyond the last valid element in the array.
template <typename T>
class sorted<T>::const_iterator sorted<T>::end(){
  return const_iterator(&m_data[m_size - 1]);
}
/*
// Starting iterator value for rand_iterator.  Should use constant
// value or time(NULL) as seed value for srand().
template <typename T>
rand_iterator sorted<T>::rndbegin(){

}

// Starting iterator value for rand_iterator with seed for
// srand() specified.  Given a sorted<T> object x, repeated 
// use of rndbegin( unsigned seed ) with the same seed value
// must produce the same permutation of the elements of x.
template <typename T>
rand_iterator sorted<T>::rndbegin( unsigned seed ){

}

// Ending iterator value for rand_iterator
template <typename T>
rand_iterator sorted<T>::rndend(){

}

*/
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
 
// Default constructor
sorted<sorted::T>::const_iterator::const_iterator(){ 
  m_current = NULL;
}

// Non-default constructor sets value to given address
sorted<sorted::T>::const_iterator::const_iterator(sorted::T* addr){
  m_current = addr; 
}

// Pre-increment, e.g. ++itr
sorted<sorted::T>::const_iterator sorted<T>::const_iterator::operator++(){
  ++m_currrent;
  return *this;
}

// Post-increment, e.g. itr++
sorted<sorted::T>::const_iterator sorted<T>::const_iterator::operator++(int){
  const_iterator result(*this);
  ++(*this);
  return result;
}

// operator!= needed for loop control, e.g. itr != x.end()
bool const_iterator::operator!=(const const_iterator& itr){
  return m_current != itr.m_current;
}

// Unary dereference operator; returns element currently pointed
// to by the const_iterator
const T& sorted<sorted::T>::const_iterator::operator*(){
  return *m_current;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/*
// Default constructor
rand_iterator::rand_iterator(){

}

// Non-default constructor; pointer to sorted<T> object passed 
// as a parameter, which allows the rand_iterator to access 
// variables of the associated sorted<T>> container
rand_iterator::rand_iterator( sorted<T>* srtdPtr ){

]

// Non-default constructor; pointer to sorted<T> passed as in
// previous constructor, but also passes seed for random number
// generator
rand_iterator::rand_iterator( sorted<T>* srtdPtr, unsigned seed ){

}

// Copy constructor
rand_iterator::rand_iterator( const rand_iterator& itr ){

}

// Destructor
rand_iterator::~rand_iterator(){

}

// pre-increment
rand_iterator rand_iterator::operator++(){

}

// post-increment
rand_iterator rand_iterator::operator++(int){

}

// operator!= needed for loop control, e.g. itr != x.end()
bool rand_iterator::operator!=(const rand_iterator& itr){

}

// Unary dereference operator
const T& rand_iterator::operator*(){

}

// Overloaded assignment operator
rand_iterator rand_iterator::operator=(const rand_iterator& itr){

}
*/
