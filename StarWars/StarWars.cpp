/****************************************************************
 ** 
 ** File:    StarWars.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Samuel Tayman
 ** Date:    05/08/2018
 ** Section: 1070-02 1072-08
 ** E-mail:  sata1@umbc.edu
 **
 ** Description: This file contains the functions used for the 
 ** StarWars class. The functions include loadShips which reads
 ** in the different ships from a text file into a vector, 
 ** createTeams which takes an integer provided by the user 
 ** for the team size and fills two Tqueues with random ships, 
 ** and a battle function which loops and determines the winner 
 ** of the battle.
 **
 **
****************************************************************/

#include "StarWars.h"

// Name: StarWars (Default Constructor)
// Preconditions: None
// Postconditions: Creates a new Star War object
StarWars::StarWars() {  



}


// Name: ~StarWars (Destructor)
// Preconditions: None
// Postconditions: Destructs Star War object
StarWars::~StarWars() {
  
  //Deallocate memory used for Rebel ships
  for(int i = 0; i < (int) m_rebelShips.size(); i++) {
    delete (m_rebelShips[i]);
  }

  //Deallocate memory used for Imperial ships
  for(int i = 0; i < (int) m_imperialShips.size(); i++) {
    delete (m_imperialShips[i]);
  }

  //Clear vectors
  m_rebelShips.clear();
  m_imperialShips.clear();

}

// Name: loadShips
// Preconditions: Two files (imperial ships then rebel ships) passed in array
// Postconditions: Populates m_imperialShips and m_rebelShips (returns 1 on success)
bool StarWars::loadShips(char* files[]) {
  
  //File variables
  string imperialFile = files[0]; //Imperial File
  string rebelFile = files[1]; //Rebel File

  //Class variables
  string name; //Name of ship
  string type; //Ship type
  int attack; //Attack value of ship
  int defense; //Defense value of ship

  //Placeholder for int variables
  string token;

  //Begin reading in files, create two ifstream objects
  ifstream rebels(rebelFile.c_str());
  ifstream imperials(imperialFile.c_str());

  //Retrieve all rebel data from file and store in m_rebelShips
  while(!rebels.eof()) {

    //Retrieve Rebel variable data
    getline(rebels, name, ',');
    getline(rebels, type, ',');
    getline(rebels, token, ',');
    attack = atoi(token.c_str());
    getline(rebels, token);
    defense = atoi(token.c_str());

    //Exit loop at end of file
    if(rebels.eof())
      break;

    //Rebel Ship object
    Rebel *myRebel = new Rebel(name, type, attack, defense);

    //Create new rebel and add to vector
    m_rebelShips.push_back(myRebel);
 
  }

  //Retrieve all imperial data from file and store in m_imperialShips
  while(!imperials.eof()) {

    //Retrieve Imperial variable data
    getline(imperials, name, ',');
    getline(imperials, type, ',');
    getline(imperials, token, ',');
    attack = atoi(token.c_str());
    getline(imperials, token);
    defense = atoi(token.c_str());

    //Exit loop at end of file
    if(imperials.eof())
      break;

    //Imperial Ship object
    Imperial *myImperial = new Imperial(name, type, attack, defense);

    //Create new imperial and add to vector
    m_imperialShips.push_back(myImperial);
 
  }

  cout << "Ships loaded" << endl;
  return 1;

}

// Name: Start
// Desc: Manages the game (loadsShips, requests team size, createsTeams, and Battles)
// Preconditions: Two files (imperial ships then rebel ships) passed in array
// Postconditions: None (game ends when it ends)
void StarWars::Start(char* files[]) {

  int numShips; //User decided team size

  cout << "Welcome to Star Wars" << endl;

  //Run loadShips
  loadShips(files);

  //Get and set team size
  cout << "How many ships would you like on a team? ";
  cin >> numShips;
  
  //Input verification
  while(numShips < 1 || cin.fail()) {

    //Clear cin buffer
    cin.clear();

    while(cin.get() != '\n')
      continue; //Continue through buffer

    //Grab new input from user
    cout << "Must input a team size of at least 1 before proceeding. Please enter a valid amount: " << endl;
    cin >> numShips;

  }

  //Create random teams
  createTeams(numShips);

  //Commence battle
  battle();

}

// Name: createTeams
// Desc: Populates two Tqueues of ships randomly
//        Tqueue m_myShips is populated from m_rebelShips (enqueue)
//        Tqueue m_enemyShips is populated from m_imperialShips (enqueue)
// Preconditions: None
// Postconditions: Teams created
void StarWars::createTeams(int numShips) {
  
  int random; //Random number for building teams
  
  //Seed random variable
  srand(time(NULL));
  
  //Add rebel ships to queue
  for(int i = 0; i < numShips; i++) {
    //Set random variable
    random = (int) (rand() % (int) m_rebelShips.size());
    m_myShips.enqueue(m_rebelShips[random]);
  }  
  
  //Add imperial ships to queue
  for(int i = 0; i < numShips; i++) {
    //Set random variable
    random = (int) (rand() % (int) m_imperialShips.size());
    m_enemyShips.enqueue(m_imperialShips[random]);
  }

}

// Name: battle
// Desc: Manages the battles (random team starts
//       Front of Tqueue attacks front of second Tqueue
//       If a member is destroyed, dequeued from Tqueue
//       Alternate turns and repeat until one of the Tqueues is empty
//       Note: If a ship is destroyed, it does not attack
// Preconditions: Two Tqueues of ships are populated
// Postconditions: A winner must be displayed
void StarWars::battle() {

  cout << "The battle begins..." << endl;

  m_myShips.displayTqueue();

  //Seed random variable
  srand(time(NULL));

  int start = (int) (rand() % 2); //Set starting team
  int result;  //Result of attack

  //Until one team has no more ships, continue battles
  while(m_myShips.size() != 0 && m_enemyShips.size() != 0) {

    //Player team starts battle
    if(start == 0) {
      
      //Attack Statement
      cout << "The " << m_myShips.queueFront()->getName() << " attacks ";
      cout << m_enemyShips.queueFront()->getName() << endl;
      
      //Get result of battle
      result = m_myShips.queueFront()->attack(m_enemyShips.queueFront());
      
      //Remove ship if destroyed
      if(result == 1) {
		cout << "The " << m_enemyShips.queueFront()->getName() << " was destroyed." << endl;
		m_enemyShips.dequeue();
      }
	  
	  //State ship was damaged and switch attackers
      else {
		cout << "The " << m_enemyShips.queueFront()->getName() << " was damaged." << endl;
		start++;
	  }
      
    }
    //Enemy team starts battle
    else if(start == 1) {
      
      //Attack Statement
      cout << "The " << m_enemyShips.queueFront()->getName() << " attacks ";
      cout << m_myShips.queueFront()->getName() << endl;
      
      //Get result of battle
      result = m_enemyShips.queueFront()->attack(m_myShips.queueFront());
      
      //Remove ship if destroyed
      if(result == 1) {
		cout << "The " << m_myShips.queueFront()->getName() << " was destroyed."  << endl;
		m_myShips.dequeue();
      }
	  //State ship was damaged and switch attackers
      else {
		cout << "The " << m_myShips.queueFront()->getName() << " was damaged." << endl;
		start--;
      }
    }

    //Determine if battle has been won
    if(m_myShips.size() == 0) {
      cout << endl << "Your team has lost the battle...." << endl;
      break;
    }
    else if(m_enemyShips.size() == 0) {
      cout << endl << "Your team has won this battle!!!!" << endl;
      break;
    }
  }
}
