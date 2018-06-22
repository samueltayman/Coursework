/*****************************************************************
 **
 ** File:    Tqueue.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Samuel Tayman
 ** Date:    05/08/2018
 ** Section: 1070-02 1072-08
 ** E-mail:  sata1@umbc.edu
 **
 ** Description: This file contains the templated Tqueue class.
 ** The Tqueue class is a Queue which contains a dynamically
 ** allocated array m_data and the following functions: an enqueue 
 ** function which adds an item to its dynamic private array and 
 ** resizes when over capacity, a dequeue function which removes 
 ** an item from the front of its array and resizes when at less
 ** then half capacity, Getter functions, queueFront() which 
 ** retrieves the first item in the Queue, an isEmpty() function
 ** that returns 1 if the Queue is empty, a size function 
 ** that shows how many items are in the Queue, an overloaded
 ** = operator, an overloaded [] operator, and displayTqueue() 
 ** which shows displays each item in the Queue.
 **
 **
*****************************************************************/

#ifndef TQUEUE_H
#define TQUEUE_H

#include <typeinfo>
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue.
  //If queue is at capacity, doubles size and copies everything starting at 0
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  //If queue is less than half capacity, halves capacity
  //and copies everything starting at 0 
  void dequeue(); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Returns front item in queue (does not remove it)
  T& queueFront();    // Retrieve front (does not remove it)
  //Name: getBack()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_back
  int getBack();
  //Name: getFront()
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve int of m_front
  int getFront();
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: size
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (not capacity but m_back - m_front)
  int size(); //Returns size of queue
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T>& operator=( const Tqueue<T> &y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue

  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
  //Name: displayTqueue (Test function)
  //Precondition: Existing Tqueue
  //Postcondition: Used to display all members in the Tqueue
  void displayTqueue();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
  int m_capacity; //Capacity of the queue
};


//**** Add class definition below ****

//Name: Tqueue - Default Constructor
//Precondition: None (Must be templated)
//Postcondition: Creates a queue using dynamic array
template <class T>
Tqueue<T>::Tqueue() {
  //Initialize variables
  m_data = NULL; //Set m_data to NULL
  m_front = 0; //m_front set to 0
  m_back = 0; //m_back set to 0
  m_capacity = 1; //m_capacity begins at 1

}

//Name: Copy Constructor
//Precondition: Existing Tqueue
//Postcondition: Copies an existing Tqueue
template <class T>
Tqueue<T>::Tqueue(const Tqueue<T>& x) {
  //Copy elements from variable Tqueue
  m_front = x.m_front;
  m_back = x.m_back;
  m_capacity = x.m_capacity;

  //Create new dynamic array
  m_data = new T[m_capacity];

  //Copy contents of variable Tqueue
  for(int i = m_front; i < m_back; i++)
    m_data[i] = x.m_data[i];

}

//Name: Destructor
//Precondition: Existing Tqueue
//Postcondition: Destructs existing Tqueue
template <class T>
Tqueue<T>::~Tqueue() {

  //Remove elements from Tqueue
  while(!size() < 0)
    dequeue();

  //Deallocate memory from m_data
  delete[] m_data;
  
  //Reset Tqueue variables
  m_data = NULL;
  m_front = 0;
  m_back = 0;
  m_capacity = 0;

}

//Name: enqueue
//Precondition: Existing Tqueue
//Postcondition: Adds item to back of queue.
//If queue is at capacity, doubles size and copies everything starting at 0
template <class T>
void Tqueue<T>::enqueue(T data) {

  //Array not instantiated 
  if(m_data == NULL) {
    m_data = new T[m_capacity];
    m_data[m_back] = data;
    m_back++;
  }
  //Add to end of queue
  else {
    m_data[m_back] = data;
    m_back++;
  }

  //Array to small, double capacity
  if(m_back == m_capacity) {

    //Double capacity
    m_capacity = m_capacity * 2;    

    //Make temp array
    T *temp = new T[m_capacity];
    
    //Store items in temp array
    for(int i = m_front; i < m_back; i++) {
      temp[i] = m_data[i];
    }

    //Delete old array
    delete[] m_data;

    //Re-add values to old array
    m_data = temp;    
  }
}

//Name: dequeue
//Precondition: Existing Tqueue
//Postcondition: Removes item from front of queue
//If queue is less than half capacity, halves capacity
//and copies everything starting at 0 
template <class T>
void Tqueue<T>::dequeue() {

  //Check for NULL 
  if(m_data == NULL)
    return;

  //Return if Tqueue is empty
  if(isEmpty())
    return;

  //Remove front object
  m_data[m_front++] = NULL;

  //Check if size is less than half capacity
  if(size() < (m_capacity / 2)) {

    //Half the capacity   
    m_capacity = m_capacity / 2;
   
    //Create new temp array with new capacity 
    T* temp = new T[m_capacity];

    //Grab m_data contents 
    for(int i = m_front; i < m_back; i++) {
      temp[(i - m_front)] = m_data[i];
    }

    //Deallocate m_data
    delete[] m_data;

    //Reallocate m_data
    m_data = temp; 

    //Set m_back to m_capacity
    m_back = size();

    //Reset front of array
    m_front = 0;

  } 
}

//Name: queueFront
//Precondition: Existing Tqueue
//Postcondition: Returns front item in queue (does not remove it)
template <class T>
T& Tqueue<T>::queueFront() {
  return m_data[m_front];
}

//Name: getBack()
//Precondition: Existing Tqueue
//Postcondition: Retrieve int of m_back
template <class T>
int Tqueue<T>::getBack() {
  return m_back;
}

//Name: getFront()
//Precondition: Existing Tqueue
//Postcondition: Retrieve int of m_front
template <class T>
int Tqueue<T>::getFront() {
  return m_front;
}

//Name: isEmpty
//Precondition: Existing Tqueue
//Postcondition: Returns 1 if queue is empty else 0
template <class T>
int Tqueue<T>::isEmpty() {
  //Are elements available?
  if(size() == 0)
    return 1;
  else
    return 0;
}

//Name: size
//Precondition: Existing Tqueue
//Postcondition: Returns size of queue (not capacity but m_back - m_front)
template <class T>
int Tqueue<T>::size() {
  return m_back - m_front;
}

//Name: Overloaded assignment operator
//Precondition: Existing Tqueue
//Postcondition: Sets one Tqueue to same as a second Tqueue using =
template <class T>
Tqueue<T>& Tqueue<T>::operator=(const Tqueue<T> &y) {
  //Copy variables from other Tqueue
  m_front = y.m_front;
  m_back = y.m_back;
  m_capacity = y.m_capacity;

  //Deallocate m_data before copy
  if(m_data != NULL) {
    delete[] m_data;
    m_data = NULL;
  }


  //Reallocate memory for m_data
  m_data = new T[m_capacity];

  //Copy elements from variable Tqueue
  for(int i = m_front; i < m_back; i++)
    m_data[i] = y.m_data[i];

  //Return object
  return *this;
}

//Name: Overloaded [] operator
//Precondition: Existing Tqueue
//Postcondition: Returns object from Tqueue using []
template <class T>
T& Tqueue<T>::operator[](int x) {
  return m_data[(x + m_front)];
}

//Name: displayTqueue (Test function)
//Precondition: Existing Tqueue
//Postcondition: Used to display all members in the Tqueue
template <class T>
void Tqueue<T>::displayTqueue() {
  //Check if Tqueue contains data
  if(isEmpty()) 
    return;

  //Output contents of Tqueue
  for(int i = m_front; i < m_back; i++) {
    cout << m_data[i] << endl;
  }
  cout << endl;
}

/***************************************************************************
// This is the type of code you should test your Tqueue with
// Once you have coded all of the functions, compile just Tqueue and test it

int main () {
  cout << "newQ" << endl << endl;
  Tqueue<int> newQ;
  newQ.displayTqueue();
  newQ.enqueue(10);
  newQ.displayTqueue();
  newQ.enqueue(20);
  newQ.displayTqueue();
  newQ.enqueue(30);
  newQ.displayTqueue();

  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.dequeue();
  newQ.displayTqueue();
  newQ.enqueue(40);
  newQ.displayTqueue();
  
  newQ.enqueue(40);
  newQ.enqueue(50);
  newQ.displayTqueue();
  cout << "newQ2 using assignment operator" << endl;
  Tqueue<int> newQ2;
  newQ2 = newQ;
  newQ2.displayTqueue();

  cout << "newQ3 using copy constructor" << endl;
  Tqueue<int> newQ3(newQ2);
  newQ3.displayTqueue();
  cout << endl << "newQ after two dequeue" << endl;
  newQ.dequeue();
  newQ.dequeue();
  newQ.displayTqueue();
  cout << endl;
  cout << "newQ4 using copy with deletes" << endl;
  Tqueue<int> newQ4(newQ);
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.dequeue();
  newQ4.displayTqueue();
  newQ3 = newQ4;
  newQ3.displayTqueue();

  Tqueue<int> newQ5;
  for(int i = 0;i<400;i++){
    newQ5.enqueue(i);
  }
  cout << "size()=" << newQ5.size() << endl;
  newQ5.displayTqueue();
 
  return 0;
}
**************************************************************/
#endif
