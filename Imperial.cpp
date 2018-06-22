/****************************************************************
 ** 
 ** File:    Imperial.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Samuel Tayman
 ** Date:    05/08/2018
 ** Section: 1070-02 1072-08
 ** E-mail:  sata1@umbc.edu
 **
 ** Description: Contains the attack and toString functions
 ** of the Imperial subclass. The attack function compares
 ** this classes attack to an enemy Ships defense. The toString
 ** provides an ostream object with the Imperial Data
 **
 **
****************************************************************/

#include "Imperial.h"

// Name: Attack (Inherited from Ship)
// Preconditions: Requires valid enemy ship
// Postconditions: Compares Imperial attack to Rebel defense
// Returns 1 if destroyed or 0 if damaged
bool Imperial::attack(Ship* enemy) {
  //Check whether enemy ship is damaged or destroyed
  if(getAttack() >= enemy->getDefense()) 
    return 1;
  else {
    enemy->setDefense(enemy->getDefense() - getAttack());
    return 0;
  }
}

// Name: toString() - Method to format a rebel
// Preconditions: A rebel object
// Postconditions: returns the rebel object as a ostream object
ostream& Imperial::toString(ostream& os) {
  //Output of Imperial ship data
  os << "Ship Name: " << getName() << endl;
  os << "Ship Type: " << getType() << endl;
  os << "Attack: " << getAttack() << endl;
  os << "Defense: " << getDefense() << endl;

  return os;

}
