/******************************************************************************
**  Name :    Carrier.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: This file contains the functions for the Carrier class. 
**  The functions include adding mail into the carrier's storage vector,
**      using a virtual deliver function, setting the carrier's max
**	storage capacity of mail objects, setting the carrier's delivery 
**	rate, retrieving the max capacity for error checks, and an overloaded
**	output stream operator <<
**
******************************************************************************/


#include "Carrier.h"

// Constructor
// Preconditions: None
// Postconditions: None
Carrier::Carrier() {
  m_max_capacity = 0;
  m_delivery_rate = 0.0;
}

// insert(Mail*) - Inserts mail into the vector of Mail*
// Preconditions: A valid Mail pointer. Not at max capacity
// Postconditions: Adds the mail pointer to m_storage
int Carrier::insert(Mail* mail) { 
  //Insert mail into m_storage
  m_storage.push_back(mail);
  return 1;
}
  
// deliver() - Virtual function to handle delivering mail
// Preconditions: Mail to be present in m_storage
// Postconditions: Displays info about the delivery
int Carrier::deliver() {
  return 0;
}
  
// setMaxCapacity(int) - Sets the max capacity of the Carrier
// Preconditions: a positive int
// Postconditions: m_max_capacity is set
void Carrier::setMaxCapacity(int capacity) {
  m_max_capacity = capacity;
}

// setRate(float) - Sets the delivery cost rate of the Carrier
// Preconditions: a positve float
// Postconditions: m_delivery_rate is set
void Carrier::setRate(float rate) {
  m_delivery_rate = rate;
}

// getMaxCapacity - Gets the max capacity of the Carrier
// Preconditions: max capacity is set
// Postconditions: returns the max capacity
int Carrier::getMaxCapacity() {
  return m_max_capacity;
}


// operator<<(ostream&, const Carrier&) - Allows the << operator to be 
// used on a Carrier object
// Preconditions: valid ostream and Carrier objects
// Postconditions: returns ostream
ostream &operator<<(ostream& os,const Carrier& carrier) {
  //Use print statement of carrier
  carrier.print(os);
  return os;
}
