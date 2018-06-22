/******************************************************************************
**  Name :    Package.h
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: Package.h is the header file for the Package class and contains
**  the function prototypes for the class including the constructor and 
**  toString method
**
******************************************************************************/

#ifndef PACKAGE_H
#define PACKAGE_H

#include "Mail.h"

class Package:public Mail{
 public:
  // Default Constructor
  // Preconditions: None
  // Postconditions: None
  Package();
  
  // Overloaded Constructor
  // Preconditions: valid inputs
  // Postconditions: None
  Package(int, string, string, float, float);
  
  // Destructor
  // Preconditions: Allocated object
  // Postconditions: Deallocates object from memory
  ~Package();
  
  // toString() - Converts the Package object to a string object
  // Preconditions: A valid Package object
  // Postconditions: returns a string representation of a Package
  string toString();
  
};


#endif
