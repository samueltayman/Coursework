/* Name:    Car.h
   Project: CMSC 202 Project 3, Spring 2018
   Project Design: Felipe Bastos
   Date:    03/12/2018
   Desc: This file contains the class for the Car class. The Car class acts as 
         the nodes for the linked list. The train is the linked list and the
	 cars are the nodes. Each car can hold any/some/none of the cargo types
	 listed below. The cargo is the data for that node.
*/

#include "Car.h"

// Name: Car (Default Constructor)
// PreCondition:  none
// PostCondition: instantiates a default-constructed Car object
Car::Car() {

  m_cargo = LOCOMOTIVE;
  m_next = NULL;

}

// Name: Car (Overloaded Constructor)
// PreCondition:  CARGO_TYPE is valid
// PostCondition: instantiates a Car object with given cargo
Car::Car(CARGO_TYPE cargo) {
  m_cargo = cargo;
  m_next = NULL;
}

// Name: ~Car (Destructor)
// PreCondition:  none
  // PostCondition: destroys car object and deallocates memory
Car::~Car() {
  delete(this);
}

// Name: getCargo
// PreCondition:  none
// PostCondition: returns current cargo
CARGO_TYPE Car::getCargo() const {
  return m_cargo;
}

// Name: Car
// PreCondition:  CARGO_TYPE is valid
// PostCondition: sets a new cargo type for the object
void Car::setCargo(CARGO_TYPE cargo) {
  m_cargo = cargo;
}

// Name: getNext
// PreCondition:  none
// PostCondition: returns the next node in the list (or null)
Car *const Car::getNext() const {
  if(m_next == NULL)
    return NULL;
  return m_next;
}

// Name: setNext
// PreCondition:  given Car* is a valid pointer to a car object
// PostCondition: sets the next car to the given pointer.
void Car::setNext(Car *car) {
  m_next = car;
}

// Name: getLength
// PreCondition:  none
// PostCondition: returns the current length of the train, assuming callee
//                is the head of the list.
int Car::getLength() const {
  return 1;
}
