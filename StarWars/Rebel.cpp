/****************************************************************
 ** 
 ** File:    Rebel.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Samuel Tayman
 ** Date:    05/08/2018
 ** Section: 1070-02 1072-08
 ** E-mail:  sata1@umbc.edu
 **
 ** Description: Contains the attack and toString functions
 ** of the Rebel subclass. The attack function compares
 ** this classes attack to an enemy Ships defense. The toString
 ** provides an ostream object with the Rebel Data
 **
 **
****************************************************************/

#include "Rebel.h"

// Name: Attack (inherited from Ship)
// Preconditions: Requires valid enemy ship
// Postconditions: Compares Rebel attack to Imperial defense
// Returns 1 if destroyed or 0 if damaged
bool Rebel::attack(Ship* enemy) {
  //Check if enemy gets destroyed or damaged
  if(getAttack() >= enemy->getDefense()) 
    return 1;
  else {
    enemy->setDefense(enemy->getDefense() - getAttack());
    return 0;
  }
}

// Name: toString() - method to format a rebel
// Preconditions: A rebel object
// Postconditions: returns the rebel object as a ostream object
ostream& Rebel::toString(ostream& os) {
  //Output for rebel ship data
  os << "Ship Name: " << getName() << endl;
  os << "Ship Type: " << getType() << endl;
  os << "Ship Attack: " << getAttack() << endl;
  os << "Ship Defense: " << getDefense() << endl;
  return os;

}
