/******************************************************************************
**  Name :    Letter.h
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: Letter.h contains the function prototypes for the Letter subclass
**	which includes a custom constructor and toString method
**
******************************************************************************/

#ifndef LETTER_H
#define LETTER_H

#include "Mail.h"

class Letter:public Mail{
 public:
  // Default Constructor
  // Preconditions: None
  // Postconditions: None
  Letter();
  
  // Overloaded Constructor
  // Preconditions: Valid inputs
  // Postconditions: None
  Letter(int, string, string, float, float);
  
  // Destructor
  // Preconditions: A letter object allocated in memory
  // Postconditions: Deallocates the object in memory
  ~Letter();
  
  // toString() - method to format the Letter object as a string
  // Preconditions: A Letter object
  // Postconditions: returns the letter object as a string
  string toString();
  
};

#endif
