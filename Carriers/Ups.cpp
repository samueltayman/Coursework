/******************************************************************************
**  Name :    Ups.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: Ups subclass of the Carrier class, this file contains the class
**  function definitions including the unique deliver function and print
**  function
**
******************************************************************************/

#include "Ups.h"

// Constructor
// Preconditions: None
// Postconditions: None
Ups::Ups() : Carrier() {
}

Ups::~Ups(){}

// deliver() - performs the actions of delivering as a UPS object
// Preconditions: mail present in m_storage
// Postconditions: outputs data and returns a status # (0 - fail, 1 - success)
int Ups::deliver() {

  float gross = 0; //Income from mail deliveries

  //Check if mail storage is empty
  if(m_storage.empty()) 
    return 0;

  //Determine gross income from deliveries
  for(int i = 0; i < (int) m_storage.size(); i++) {
    gross = gross + (m_storage[i]->getBaseCost() * m_storage[i]->getSize() * m_delivery_rate);
  }

  //Output delivery details
  for(int i = 0; i < (int) m_storage.size(); i++) {
    cout << "Delivered:" << endl;
    cout << "----------------------" << endl;
    cout << *m_storage[i];
    cout << "----------------------" << endl << endl;
  }

  //Display gross income of deliveries
  cout << "Deliveries completed. UPS total earned: $" << setprecision(2) << fixed << gross << endl << endl;

  return 1;
}


// toString() - method to format the object as a string
// Preconditions: a valid UPS object
// Postconditions: returns the UPS object as a string
ostream& Ups::print(ostream& os) const {

  //Check if mail storage is empty
  if(m_storage.empty()){
    return os;
  }

  //Construct os object to output truck contents
  os << "****************************" << endl;
  os << "UPS Truck Contents:" << endl;
  for(int i = 0; i < (int) m_storage.size(); i++) {
    os << "----------------------" << endl;
    os << *m_storage[i];
    os << "----------------------" << endl;
  }
  os << "****************************" << endl << endl;
  
  return os;
}
