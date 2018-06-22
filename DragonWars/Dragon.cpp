/***************************************************************
** 	File:		Dragon.cpp
** 	Project: 	CMSC 202 Project 2, Spring 2018
** 	Author: 	Samuel Tayman
** 	Date: 		03/24/2018
** 	Section:	1070-06 && Lab 1072-08
** 	E-mail:		sata1@umbc.edu
**
** 	Dragon.cpp is a class file which contains functions used
**	by a dragon instance. 
**	This class allows the user to complete an attack, 
**	grow a dragon, hatch a dragon, and use a dragons
**	special breath attack
**
**
***************************************************************/

#include "Dragon.h" //Include Dragon header file

// Name: Dragon() - Overloaded constructor
// Desc - Used to build a new dragon
// Preconditions - Requires name, type, isHatched, curSize, maxSize, and rarity (from file)
// Postconditions - Creates a new dragon
Dragon::Dragon(string name, string type, bool isHatched, dragonSize curSize, 
	       dragonSize maxSize, int rarity) {
  m_name = name; //Set name of Dragon
  m_type = type; //Set type of Dragon
  m_isHatched = isHatched; //Set if Dragon is Hatched
  m_curSize = curSize; //Set Dragon current size
  m_maxSize = maxSize; //Set Dragon max size
  m_rarity = rarity; //Set Dragon rarity

}

// Name: GetName()
// Desc - Getter for Dragon name
// Preconditions - Dragon exists
// Postconditions - Returns the name of the dragon
string Dragon::GetName() { 
  return m_name;
}

// Name: SetName(string)
// Desc - Allows the user to change the name of the dragon
// Preconditions - Dragon exists
// Postconditions - Sets name of dragon
void Dragon::SetName(string name) { 
  m_name = name;
}
// Name: GetType()
// Desc - Getter for dragon type
// Preconditions - Dragon Exists
// Postconditions - Returns the type of the dragon
string Dragon::GetType() {
  return m_type;
}

// Name: SetType(string)
// Desc - Allows the user to change the type of the dragon
// Preconditions - Dragon exists
// Postconditions - Sets type of dragon
void Dragon::SetType(string Type) {
  m_type = Type;
}

// Name: GetIsHatched()
// Desc - Getter for if dragon is hatched
// Preconditions - Dragon exists
// Postconditions - Returns if the dragon has hatched from an egg
bool Dragon::GetIsHatched() {
  return m_isHatched;
}

// Name: HatchDragon()
// Desc - Setter for if dragon is hatched
// Preconditions - Unhatched Dragon (In Egg form) exists
// Postconditions - If unhatched, changes isHatched to 1
void Dragon::HatchDragon() {

  if(m_isHatched == false) {
    m_isHatched = true;
    cout << "Hatch Successful!" << endl;
  }
  else
    cout << "Dragon is already hatched" << endl;
  
}
// Name: GetCurSize()
// Desc - Getter for dragon's current size
// Preconditions - Dragon exists
// Postconditions - Returns current size from 1 - 5
dragonSize Dragon::GetCurSize() {
  return m_curSize;
}

// Name: SetCurSize(int)
// Desc - Setter for the current dragon size
// Preconditions - Dragon exists
// Postconditions - Sets size of dragon (1-5)
void Dragon::SetCurSize(dragonSize curSize) {
  m_curSize = curSize;
}

// Name: GetMaxSize()
// Desc - Getter for dragon max size
// Preconditions - Dragon exists
// Postconditions - Returns maximum size from 1 - 5
dragonSize Dragon::GetMaxSize() {
  return m_maxSize;
}

// Name: SetMaxSize(int)
// Desc - Setter for the maximum dragon size
// Preconditions - Dragon exists
// Postconditions - Sets maximum size of dragon (1-5)
void Dragon::SetMaxSize(dragonSize maxSize) {
  m_maxSize = maxSize;
}

// Name: GetRarity()
// Desc - Getter for dragon rarity
// Preconditions - Dragon exists
// Postconditions - Returns rarity of dragon (1-10)
int Dragon::GetRarity() {
  return m_rarity;
}

// Name: SetRarity()
// Desc - Setter for dragon rarity
// Preconditions - Dragon exists
// Postconditions - Sets rarity of dragon from (1-10)
void Dragon::SetRarity(int rarity) {
  m_rarity = rarity;
}

// Name: AttemptGrow()
// Desc - After a dragon wins a fight, if possible, it grows larger
// Preconditions - Dragons exist
// Postconditions - If possible, curSize increases, if increases, returns true else false
bool Dragon::AttemptGrow() {
  
  if(m_curSize < m_maxSize) {
    int nextSize = (int) m_curSize + 1;
    m_curSize = dragonSize(nextSize);
    return true;
  }
  else {
    cout << m_name << " is at its max size." << endl << endl;
    return false;
  }
}

// Name: AttackDragon(Dragon&)
// Desc - Allows the user to attack an enemy dragon
// Preconditions - Dragons exist
// Postconditions - Returns if dragon lives or dies (true lives, dies false)
bool Dragon::AttackDragon(Dragon& enemyDragon) {
  
  cout << "Your " << m_name << " attacks the enemy " << enemyDragon.GetName() << endl;

  //If user dragon is bigger, user wins
  if(m_curSize > enemyDragon.GetCurSize()) {
    cout << "Your dragon has defeated the enemy " << enemyDragon.GetName() << endl << endl; 
    return true;
  }
  else if(m_curSize == enemyDragon.GetCurSize()) {
    cout << "The battle results in a draw." << endl << endl;
    return true; 
  }

  return false;

}

// Name: BreathAttack(Dragon&)
// Desc - Allows the user to attack an enemy dragon using a special breath attack
//        Returns the string of the specific attack (different for acid, water, ice, fire, wind)
// Preconditions - During normal attack, 5% chance a special breath attack called
// Postconditions -  Automatically kills enemy dragon
string Dragon::BreathAttack() {
  string attack = "";
  attack += "Your dragon unleashes its " + m_type + " breath attack!";
  return attack;
}

