/******************************************************************************
**  Name :    Mail.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: Mail.cpp contains the function definitions for the Mail class.
**  The overloaded operator << calls the classes toString method, and the 
**  toString method builds a string to display the contents of the type 
**  of Mail
**
******************************************************************************/


#include "Mail.h"

// Default Constructor
// Preconditions: None
// Postconditions: None
Mail::Mail() {
  m_sender = "";
  m_recipient = "";
  m_carrier = 0;
  m_size = 0.0;
  m_baseCost = 0.0;
}

// Overloaded Constructor
// Preconditions: Valid inputs
// Postconditions: None
Mail::Mail(int carrier, string sender, string recipient, float size, float baseCost) {
  m_carrier = carrier;
  m_sender = sender;
  m_recipient = recipient;
  m_size = size;
  m_baseCost = baseCost;
}

// getCarrier() - returns the type of the carrier
// Preconditions: m_carrier is set
// Postconditions: returns an int reffering to which carrier
int Mail::getCarrier() {
  return m_carrier;
}

// getSender() - returns the sender of the mail
// Preconditions: m_sender is set
// Postconditions: returns a string of the sender
string Mail::getSender() {
  return m_sender;
}

// getRecipient() - returns the recipient of the mail
// Preconditions: m_recipient is set
// Postconditions: returns a string of the recipient
string Mail::getRecipient() {
  return m_recipient;
}

// getSize() - returns the size of the Mail
// Preconditions: m_size is set
// Postconditions: returns a float
float Mail::getSize() {
  return m_size;
}

// getBaseCost() - returns the base cost of the mail
// Preconditions: m_baseCost is set
// Postconditions: returns a float
float Mail::getBaseCost() {
  return m_baseCost;
}

// operator<<(ostream&, Mail&) - overload the << operator to handle a Mail object
// Preconditions: a valid ostream and Mail operator
// Postconditions: returns an ostream object
ostream& operator<<(ostream& os, Mail& mail) {
  //Use object toString method
  os << mail.toString();
  return os;
}

// toString() - returns a string representation of a Mail object
// Preconditions: a valid Mail object
// Postconditions: returns a string
string toString() {
  return "";
}
