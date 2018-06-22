/******************************************************************************
**  Name :    Letter.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: Letter.cpp contains the function definitions for the Letter 
**	subclass. This includes the Letter constructor and toString which
**	returns a string to display the attributes of the Letter object
**
******************************************************************************/


#include "Letter.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Letter::Letter() : Mail(0, "", "", 0.0, 0.0) { 
  m_carrier = 0; 
  m_sender = "";
  m_recipient = "";
  m_size = 0.0;
  m_baseCost = 0.0;
}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Letter::Letter(int carrier, string sender, string recipient, float size, float baseCost) : Mail(0, "", "", 0.0, 0.0) { 
  m_carrier = carrier;
  m_sender = sender;
  m_recipient = recipient;
  m_size = size;
  m_baseCost = baseCost;
}

// Destructor
// Preconditions: A letter object allocated in memory
// Postconditions: Deallocates the object in memory
Letter::~Letter(){}

// toString() - method to format the Letter object as a string
// Preconditions: A Letter object
// Postconditions: returns the letter object as a string
string Letter::toString() {

  //Create toString for Letter object class combining all variables to print
  string str = "LETTER\n";
  stringstream ostr;
  ostr << m_size;
  str += "To: "; 
  str += m_recipient;
  str += "\n";
  str += "From: ";
  str += m_sender;
  str += "\n";
  str += "Size: ";
  str += ostr.str();
  str += " square inches\n";

  return str;

}
