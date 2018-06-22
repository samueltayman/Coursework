/******************************************************************************
**  Name :    Train.cpp
**  Project:  CMSC 202 Project 3, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/11/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: This file contains the functions for the Train class. 
**  The functions include getting the length of the train, adding a car to the
**  train, checking the configuration of the train, and displaying the train 
**  to the user, formatted
**
**
******************************************************************************/

#include "Train.h"


// Name: Train (Default Constructor)
// PreCondition:  none
// PostCondition: instantiates a default-constructed Train object
Train::Train() {
  m_len = 0; //Length of train
  m_number = 0; //Train number
  m_head = NULL; //Head Node
}

// Name: Train (Overloaded Constructor)
// PreCondition:  none
// PostCondition: instantiates a Train object with a given number
Train::Train(int number) {
  m_len = 0; //Length of train
  m_number = number; //Train number
  m_head = NULL; //Head Node
}

// Name: ~Train
// PreCondition:  none
// PostCondition: destroys train object
Train::~Train() {
}

// Name: display
// PreCondition:  given ostream& is valid
// PostCondition: appends own train information to a given ostream&
void Train::display(ostream& os) const {

  Car *temp = m_head; //Set temp variable 
  string cargo; //Converter for CARGO_TYPE
  os << "Train " << getNumber() << ": ";

  while(temp != NULL) {
    if(temp->getNext() == NULL) {

      //If the next car is NULL, we reached the end of the train      
      cargo = "CABOOSE";      
      os << cargo;

    }
    else {
      //Convert CARGO_TYPE's
      if((int)temp->getCargo() == 0)
	cargo = "BIOLOGICAL";
      else if((int)temp->getCargo() == 1)
	cargo = "POISONOUS";
      else if((int)temp->getCargo() == 2)
	cargo = "COMBUSTIBLE";
      else if((int)temp->getCargo() == 3)
	cargo = "OXIDIZER";
      else if((int)temp->getCargo() == 4)
	cargo = "RADIOACTIVE";
      else if((int)temp->getCargo() == 5)
	cargo = "ENGINE";

      os << cargo << "->";
    }
    //Increment loop variable
    temp = temp->getNext();
    
  }
  
  //Check if the train is valid
  if(isValid() == true)
    os << "(valid)" << endl;
  else if(isValid() == false)
    os << "(invalid)" << endl;
}

// Name: isValid
// PreCondition:  none
// PostCondition: returns a boolean indicating whether the current
//                arrangement of the train is valid
bool Train::isValid() const {
  
  Car *temp = m_head; //temp variable for loop
  Car *prev = NULL; //previous car in train

  bool valid = true; //boolean to check if current train configuration is valid
  int bio = 0; //BIOLOGICAL car increment value for consecutive BIO cars

  while(temp != NULL) {
    //If previous is NULL, skip these steps
    if(prev != NULL) {
      //Check first configuration condition of train
      if(temp->getCargo() == OXIDIZER && (prev->getCargo() == COMBUSTIBLE || temp->getNext()->getCargo() == COMBUSTIBLE)) {
	valid = false;
	bio = 0;
      }
      //Check second configuration condition of train
      else if(temp->getCargo() == COMBUSTIBLE && temp->getNext()->getCargo() == COMBUSTIBLE && prev->getCargo() == COMBUSTIBLE) {
	valid = false;
	bio = 0;
      }
      //Check third configuration condition of train
      else if(temp->getCargo() == BIOLOGICAL && temp->getNext()->getCargo() == RADIOACTIVE && prev->getCargo() == RADIOACTIVE) {
	valid = false;
	bio = 0;
      }
      
      //Check for consecutive biological cars
      if(temp->getCargo() == BIOLOGICAL) 
	bio = bio + 1;
      if(bio == 5) 
	valid = false;
    }
    prev = temp;
    temp = temp->getNext();

  }	     
  return valid;
}

// Name: addCar
// PreCondition:  given CARGO_TYPE is valid, given integer is a valid 
//                index (where to insert in train)
// PostCondition: adds car to the train, at given index. zero-indexed
int Train::addCar(const CARGO_TYPE& cargo, int index) {

  Car *temp; //temp variable to add new car
  int i = 0; //incremental variable for loop

  if(index == 0) { 
    m_head = new Car(cargo);
    m_head->setNext(NULL);
  }
  else {  
    //While not at insertion index
    temp = m_head;
    while(i < index - 1) {
      temp = temp->getNext();
      i++;
    }

    //temp = new Car(cargo);
    temp->setNext(new Car(cargo));
  }
  m_len = m_len + 1;
  return 0;
}

// Name: removeCar
// PreCondition:  given integer is a valid index
// PostCondition: removes Car from train at given index. zero-indexed
int Train::removeCar(int index) {

  Car *cur = m_head; //Current node
  Car *temp; //previous node
  int i = 0; //incremental value

  //If the head is getting deleted
  if(index == 0) {
    m_head = m_head->getNext();
    delete(cur);
    m_len = m_len - 1;
  }
  else {
    temp = m_head;
   
    //Find the car that is getting removed 
    while(temp != NULL && i < index) {
      temp = cur;
      cur = cur->getNext();
      i++;
    }
    //if next car is available, point to that car  
    if(cur->getNext() != NULL) 
      temp->setNext(cur->getNext());
    //If next car is not available, set next car to NULL
    else 
      temp->setNext(NULL);
    delete(cur);
    m_len = m_len - 1;
  }
  return 0;
}

// Name: removeCar
// PreCondition:  given CARGO_TYPE is valid
// PostCondition: removes every car of given cargo_type from train.
int Train::removeCar(CARGO_TYPE cargo) {
  Car *cur = m_head; //Current node
  Car *temp; //previous node

  //If cargo to remove is the LOCOMOTIVE
  if(cargo == m_head->getCargo()) {
    m_head = m_head->getNext();
    delete(cur);
    m_len = m_len - 1;
  }
  else {    
    //While car is available and cargo is not the requested cargo
    while(cur != NULL) {
      if(cur->getCargo() == cargo) {

	//if next car is available, point to that car  
	if(cur->getNext() != NULL)
	  temp->setNext(cur->getNext());

	//If next car is not available, set next car to NULL
	else
	  temp->setNext(NULL);
	delete(cur);
	m_len = m_len - 1;
      }
      temp = cur;
      cur = cur->getNext();
    }
  }
  return 0;
}

// Name: getLength
// PreCondition:  none
// PostCondition: returns current length of the train
int Train::getLength() const {
  return m_len;
}

// Name: getNumber
// PreCondition:  none
// PostCondition: returns current number of the train (The number is the name of the train)
int Train::getNumber() const {
  return m_number;
}

// Name: setNumber
// PreCondition:  none
// PostCondition: sets a new number for the train
void Train::setNumber(int number) {
  m_number = number;
}

// Name: operator<<
// PreCondition:  given arguments are valid
// PostCondition: appends train information to ostream&
// This function just calls the display function and allows us to cout << myTrain
std::ostream &operator<<(std::ostream& os, const Train& train) {
  train.display(os);
  return os;
}
