/******************************************************************************
**  Name :    Carrier.h
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: This file contains the class definition for the Carrier class.
**	The Carrier class is the parent class for the FedEx and Ups classes.
**
******************************************************************************/

/* Name:    Car.h
   Project: CMSC 202 Project 3, Spring 2018
   Project Design: Felipe Bastos
   Date:    03/12/2018
   Desc: This file contains the class for the Car class. The Car class acts as 
         the nodes for the linked list. The train is the linked list and the
	 cars are the nodes. Each car can hold any/some/none of the cargo types
	 listed below. The cargo is the data for that node.
*/

#ifndef CARRIER_H
#define CARRIER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "Mail.h"

using namespace std;

class Carrier{

public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Carrier();
  
  // Destructor
  // Preconditions: An initialized Carrier object in memory
  // Postconditions: Object deallocated
  virtual ~Carrier(){};
  
  // insert(Mail*) - Inserts mail into the vector of Mail*
  // Preconditions: A valid Mail pointer. Not at max capacity
  // Postconditions: Adds the mail pointer to m_storage
  int insert(Mail*);
  
  // deliver() - Virtual function to handle delivering mail
  // Preconditions: Mail to be present in m_storage
  // Postconditions: Displays info about the delivery
  virtual int deliver() = 0;
  
  // setMaxCapacity(int) - Sets the max capacity of the Carrier
  // Preconditions: a positive int
  // Postconditions: m_max_capacity is set
  void setMaxCapacity(int);
  
  // setRate(float) - Sets the delivery cost rate of the Carrier
  // Preconditions: a positve float
  // Postconditions: m_delivery_rate is set
  void setRate(float);

  // getMaxCapacity() - Gets the max capacity of the Carrier
  // Preconditions: Max capacity is set
  // Postconditions: returns max capacity
  int getMaxCapacity();
  
  // operator<<(ostream&, const Carrier&) - Allows the << operator to be 
  // used on a Carrier object
  // Preconditions: valid ostream and Carrier objects
  // Postconditions: returns ostream
  friend ostream &operator<<(ostream&,const Carrier&);

 protected:
  // toString - Virtual function to return a string version of Carrier
  // Preconditions: Carrier object exists
  // Postconditions: Returns string
  virtual ostream& print(ostream&) const = 0;
  
  int m_max_capacity;
  float m_delivery_rate;
  vector<Mail*> m_storage;
};

#endif
