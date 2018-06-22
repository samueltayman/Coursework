/******************************************************************************
**  Name :    FedEx.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: FedEx subclass of the Carrier class, this file contains the 
** 	FedEx class function definitions including the custom deliver function and
**	print function
**
******************************************************************************/


#include "FedEx.h"

// Constructor
// Preconditions: None
// Postconditions: None
FedEx::FedEx() : Carrier() {
}

// Destructor
// Preconditions: An allocated object in memory
// Postconditions: Deallocates the memory
FedEx::~FedEx(){}

// deliver() - performs the actions of delivering as a FedEx object
// Preconditions: mail present in m_storage
// Postconditions: outputs data and returns a status # (0 - fail, 1 - success)
int FedEx::deliver() {

  float gross = 0; //Income from deliveries

  //Check if mail storage is empty
  if(m_storage.empty()) 
    return 0;

  //Determine gross income from deliveries
  for(int i = 0; i < (int) m_storage.size(); i++) {
    gross = gross + (m_storage[i]->getSize() * m_storage[i]->getBaseCost() * m_delivery_rate);
  }

  //Output details of deliveries
  for(int i = 0; i < (int) m_storage.size(); i++) {
    cout << "Delivered:" << endl;
    cout << "----------------------" << endl;
    cout << *m_storage[i];
    cout << "----------------------" << endl << endl;
  }

  //Display delivery income
  cout << "Deliveries completed. Fedex total earned: $" << setprecision(2) << fixed << gross << endl << endl;

  return 1;
}


// toString() - method to format the object as a string
// Preconditions: a valid FedEx object
// Postconditions: returns the FedEx object as a string
ostream& FedEx::print(ostream& os) const {

  //Check if mail storage is empty
  if(m_storage.empty()) {
    return os;
  }

  //Create os object to display truck contents
  os << "****************************" << endl;
  os << "FedEx Truck Contents:" << endl;
  for(int i = 0; i < (int) m_storage.size(); i++) {
    os << "----------------------" << endl;
    os << *m_storage[i];
    os << "----------------------" << endl;
  }
  os << "****************************" << endl << endl;
  return os;
}
