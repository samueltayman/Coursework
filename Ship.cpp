/****************************************************************
 ** 
 ** File:    Ship.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Samuel Tayman
 ** Date:    05/08/2018
 ** Section: 1070-02 1072-08
 ** E-mail:  sata1@umbc.edu
 **
 ** Description: Class definition file for the Ship class. 
 ** The Ship class contains basic Setter and Getter functions
 ** for a Ship object, a virtual Attack function and an
 ** overloaded ostream operator
 **
 **
****************************************************************/

#include "Ship.h"

// Name: Ship (Default Constructor)
// Preconditions: Cannot call directly (used by subclasses)
// Postconditions: Either a Imperial or Rebel ship is created
Ship::Ship(string name, string type, int attack, int defense) {
  m_name = name;
  m_type = type;
  m_attack = attack;
  m_defense = defense;
}

// Name: getName()
// Preconditions: Must have a ship
// Postconditions: Gets the name of the ship
string Ship::getName() {
  return m_name;
}

// Name: setName()
// Preconditions: Must have a ship
// Postconditions: Sets the name of the ship
void Ship::setName(string name) {
  m_name = name;
}

// Name: getType()
// Preconditions: Must have a ship
// Postconditions: Gets the type of the ship
string Ship::getType() {
  return m_type;
}

// Name: setType()
// Preconditions: Must have a ship
// Postconditions: Sets the type of the ship
void Ship::setType(string type) {
  m_type = type;
}

// Name: getAttack()
// Preconditions: Must have a ship
// Postconditions: Gets the attack of the ship
int Ship::getAttack() {
  return m_attack;
}

// Name: setAttack()
// Preconditions: Must have a ship
// Postconditions: Sets the attack of the ship
void Ship::setAttack(int attack) {
  m_attack = attack;
}

// Name: getDefense()
// Preconditions: Must have a ship
// Postconditions: Gets the defense of the ship
int Ship::getDefense() {
  return m_defense;
}

// Name: setDefense()
// Preconditions: Must have a ship
// Postconditions: Sets the defense of the ship
void Ship::setDefense(int defense) {
  m_defense = defense;
}

// Name: attack (Purely virtual)
// Preconditions: One ship is attacking another ship
// Postconditions: Returns a 1 if enemy is destroyed, 0 if enemy damaged
bool Ship::attack(Ship* enemy) {
  return 0;
}

// operator<<(ostream&, Ship&) - overload the << operator to handle a Ship object
// Preconditions: a valid ostream and Ship operator (calls toString)
// Postconditions: returns an ostream object
ostream& operator<<(ostream& os, Ship& b) {
  //Set os using toString
  os << b.toString(os);
  return os;
}
