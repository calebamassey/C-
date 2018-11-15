//******************************************************************************
//Author: Caleb Massey
//Date: 5/5/2016
//Email: cmassey1@umbc.edu
//Section: 18
//Description: This is the test file for project 5
//
//******************************************************************************

#ifndef SORTED_H_
#define SORTED_H_

template <typename T>

class sorted{
 public:

  class const_iterator;

  //Default constructor
  sorted();

  // Non-default constructor copies data from array to sorted
  sorted( T* data, int len );

  // Copy constructor
  sorted( const sorted<T>& srtd );

  // Destructor
  ~sorted();

  // Overloaded assignment operator
  sorted<T> operator=(const sorted<T>& srtd);

  // Return the capacity of the storage array
  int capacity() const;

  // Return number of items stored
  int size() const;
  
  // Return the address of the storage array;
  // for use in grading programs
  T* getStorageArray() const;

  // Insert an item in sorted; return iterator to inserted item
  class const_iterator insert(T data);

  // Remove an item from sorted; return iterator to next item
  // after the erased item
  class const_iterator erase(const_iterator itr);

  // Get element at indx position                                                  
  const T& at(int indx);

  // Starting iterator value for const_iterator
  class const_iterator begin();

  // Ending iterator value for const_iterator; typically,
  // one element beyond the last valid element in the array.
  class const_iterator end();

  // Starting iterator value for rand_iterator.  Should use constant
  // value or time(NULL) as seed value for srand().
  //      111111111111           rand_iterator rndbegin();

  // Starting iterator value for rand_iterator with seed for
  // srand() specified.  Given a sorted<T> object x, repeated 
  // use of rndbegin( unsigned seed ) with the same seed value
  // must produce the same permutation of the elements of x.
  //        111111111        rand_iterator rndbegin( unsigned seed );

  // Ending iterator value for rand_iterator
  //     11111111111111       rand_iterator rndend();

  class const_iterator{
  public:
    friend class sorted;
    // Default constructor
    const_iterator();
    
    // Non-default constructor sets value to given address
    const_iterator(T* addr);
    
    // Pre-increment, e.g. ++itr
    const_iterator operator++();
    
    // Post-increment, e.g. itr++
    const_iterator operator++(int);
    
    // operator!= needed for loop control, e.g. itr != x.end()
    ////////   bool operator!=(const const_iterator& itr);
    
    // Unary dereference operator; returns element currently pointed
    // to by the const_iterator
    const T& operator*();
  private:
    T* m_current;
  };
  /*
  class rand_iterator{
    // Default constructor
    rand_iterator();
    
    // Non-default constructor; pointer to sorted<T> object passed 
    // as a parameter, which allows the rand_iterator to access 
    // variables of the associated sorted<T>> container
    rand_iterator( sorted<T>* srtdPtr );
    
    // Non-default constructor; pointer to sorted<T> passed as in
    // previous constructor, but also passes seed for random number
    // generator
    rand_iterator( sorted<T>* srtdPtr, unsigned seed );
    
    // Copy constructor
    rand_iterator( const rand_iterator& itr );
    
    // Destructor
    ~rand_iterator();
    
    // pre-increment
    rand_iterator operator++();
    
    // post-increment
    rand_iterator operator++(int);
    
    // operator!= needed for loop control, e.g. itr != x.end()
    bool operator!=(const rand_iterator& itr);
    
    // Unary dereference operator
    const T& operator*();

    // Overloaded assignment operator
    rand_iterator operator=(const rand_iterator& itr);

  private:
    T* m_current;
  };

*/
 private:
  int m_size;
  int m_capacity;
  T m_data[];
  
};
#endif
  
