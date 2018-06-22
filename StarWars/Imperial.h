/****************************************************************
 ** 
 ** File:    Imperial.h
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Samuel Tayman
 ** Date:    05/08/2018
 ** Section: 1070-02 1072-08
 ** E-mail:  sata1@umbc.edu
 **
 ** Description: This file contains the class items for the 
 ** Imperial class. The Imperial class is a Ship subclass and contains
 ** an inherited Attack() function and toString() function.
 **
 **
****************************************************************/

#ifndef IMPERIAL_H
#define IMPERIAL_H

#include "Ship.h"

class Imperial:public Ship{
 public:
  // Name: Imperial (Default Constructor)
  // Preconditions: Uses ship constructor (initialization list)
  // Postconditions: Creates an Imperial ship
 Imperial(string name, string type, int attack, int defense) 
   : Ship(name, type, attack, defense) {}

  // Name: Attack (Inherited from Ship)
  // Preconditions: Requires valid enemy ship
  // Postconditions: Compares Imperial attack to Rebel defense
  // Returns 1 if destroyed or 0 if damaged
  bool attack(Ship* enemy);

  // Name: toString() - Method to format a rebel
  // Preconditions: A rebel object
  // Postconditions: returns the rebel object as a ostream object
  ostream& toString(ostream& os);
};

#endif
