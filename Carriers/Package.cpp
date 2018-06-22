/******************************************************************************
**  Name :    Package.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: Package.cpp contains the function definitions for the Package
**  class including its custom constructor and toString method
**
******************************************************************************/

#include "Package.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Package::Package() : Mail(0, "", "", 0.0, 0.0) {
  m_carrier = 0;
  m_sender = "";
  m_recipient = "";
  m_size = 0.0;
  m_baseCost = 0.0;
}

// Overloaded Constructor
// Preconditions: valid inputs
// Postconditions: None
Package::Package(int carrier, string sender, string recipient, float size, float baseCost) : Mail(0, "", "", 0.0, 0.0) {
  m_carrier = carrier;
  m_sender = sender;
  m_recipient = recipient;
  m_size = size;
  m_baseCost = baseCost;
}

// Destructor
// Preconditions: Allocated object
// Postconditions: Deallocates object from memory
Package::~Package(){}

// toString() - Converts the Package object to a string object
// Preconditions: A valid Package object
// Postconditions: returns a string representation of a Package
string Package::toString() {
  
  //Build string object to output package details
  string str = "PACKAGE\n"; //Initial toString string variable
  stringstream ostr; //Convert int to string
  ostr << m_size;
  str += "To: ";
  str += m_recipient;
  str += "\n";
  str += "From: ";
  str += m_sender;
  str += "\n";
  str += "Size: ";
  str += ostr.str();
  str += " lbs\n";

  return str;

}
