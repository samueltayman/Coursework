/***************************************************************
** 	File:		Game.cpp
** 	Project: 	CMSC 202 Project 2, Spring 2018
** 	Author: 	Samuel Tayman
** 	Date: 		03/24/2018
** 	Section:	1070-02 && 1072-08
** 	E-mail:		sata1@umbc.edu
**
** 	Game.cpp runs all core functions of this program. 
**	This program displays the main menu to the user, and allows them
**	to select a variety of options.
**	Each option then runs a function inside Game.cpp which may or may not
**	access Dragon.cpp functions
**
**
***************************************************************/

#include "Game.h" //Include Game Header File
#include <iostream> 
#include <string>
#include <ctime>

using namespace std;

/* Name: Game() Default Constructor
// Desc - Builds a new game by: 
// 1. Asking user for their name, 
// 2. Loading all dragons from file (function call)
// Preconditions - None
// Postconditions - m_dragons is populated
*/ 
//Default Constructor
Game::Game() {

  //Intro
  cout << "Welcome to Dragon Wars!!" << endl << endl;

  //Get user name
  cout << "What is your name?" << endl;
  getline(cin, m_name); //Store name in m_name
  cout << endl;

  //Load all dragons from file
  LoadDragons();

}
// Name: LoadDragons
// Desc - Loads each dragon into m_dragon from file
// Preconditions - Requires file with valid dragon data
// Postconditions - m_dragons is populated with Dragon objects
void Game::LoadDragons() {
  
  Dragon dragon("","",false,small,medium,1);

  ifstream in(PROJ2_DRAGONS.c_str()); //Variable to load file
  string token; //Holds current line
  string intHold; //Placeholder to convert int values
  string dragonName; //Name of dragon in file
  string dragonType; //Dragon type in file
  dragonSize maxSize; //Dragon max size from file
  int rarity; //Dragon rarity from file

  //Iterate through file and store dragons in vector
  while(!in.eof()) {
    getline(in,dragonName,','); 
    getline(in,dragonType,',');
    getline(in,token,',');
    
    //Convert token into dragonSize
    if(token.compare("1") == 0)
      maxSize = tiny;
    else if(token.compare("2") == 0) 
      maxSize = small;
    else if(token.compare("3") == 0) 
      maxSize = medium;
    else if(token.compare("4") == 0)
      maxSize = large;
    else if(token.compare("5") == 0) 
      maxSize = huge;
    
    //Convert token into integer
    getline(in,token,',');
    rarity = atoi(token.c_str());
    
    //Set dragon attributes and add to m_dragons
    dragon.SetName(dragonName);
    dragon.SetType(dragonType);
    dragon.SetMaxSize(maxSize);
    dragon.SetRarity(rarity);
    m_dragons.push_back(dragon);
    
    //Go to next line
    getline(in,token);
  }  
}

// Name: SearchEgg
// Desc - Randomly chooses an egg and adds to players dragon vector
// Preconditions - m_dragons is populated
// Postconditions - m_myDragons is populated
void Game::SearchEgg() {

  Dragon myDragon("","",false,small,medium,1); //Create a Dragon object to hold new player dragon
  int rarity; //User chosen rarity
  double random; //Random number generated for chance
  double chance; //Chance of acquiring dragon of selected rarity

  cout << "How rare of an egg would you like to search for? (Enter a rarity from 1-10)" << endl;
  cin >> rarity;

  //Set chance variable 
  chance = (1 - (rarity * .09));
  
  //Set random seed as time
  srand(time(NULL));

  //Set random number 
  random = ((rand() % 100 + 1) * .01);

  //Gain a dragon is random variable is within chance range
  if(random <= chance) {
    
    int size = (int) m_myDragons.size() + 1; //While loop condition initialize
    
    /**
     * Until a dragon with matching rarity is found, a random number will be
     * generated and used to find a matching dragon
     *
     * Once a dragon is found, the dragon is added to m_myDragons and
     * exit loop condition will be met
     **/
    while(size != (int) m_myDragons.size()) {
      random = rand() % (int) m_dragons.size();
      
      //Does the random selected dragons rarity meet the requested rarity?
      if(m_dragons[random].GetRarity() == rarity) {
	myDragon = (m_dragons[random]);

	//Add dragon to players list
	m_myDragons.push_back(myDragon);
	cout << "Success! You've received a " << m_dragons[random].GetName() << " egg!" << endl << endl;
	m_myDragons[size - 1].SetCurSize(tiny);
      }
    }
  }
}

// Name: HatchEgg
// Desc - Tries to change from egg to small dragon
// Preconditions - m_dragons is populated
// Postconditions - m_myDragons is populated
void Game::HatchEgg() {

  int choice; //Dragon to hatch

  //Does the player have dragons?
  if((int) m_myDragons.size() > 0) {
    DisplayMyDragons();
    cout << "Select an egg to try and hatch: " << endl;
    cin >> choice;

    //Out of bounds guard
    while(choice > (int) m_myDragons.size()) {
      cout << "Incorrect selection." << endl << "Select a dragon to hatch: " << endl << endl;
      DisplayMyDragons();
      cin >> choice;
    }
    //Seed randomizer
    srand(time(NULL));
    int random = (int) (rand() % 2);
    
    //Hatch dragon 
    if(random == 1) {
      m_myDragons[(choice - 1)].HatchDragon();
      cout << endl;
    }
    else
      cout << "Hatch unsuccessful" << endl << endl;
  }

  //No dragons available
  else 
    cout << "No dragons are available, please find a dragon egg first." << endl << endl;
}

// Name: StartGame()
// Desc - Manages the game itself including win conditions continually
//         calling the main menu 
// Preconditions - Player has an egg or a dragon
// Postconditions - Continually checks to see if player has an egg or a dragon
void Game::StartGame() {

  for(;;) {
    
    cout << "What would you like to do?" << endl;
    
    int choice = MainMenu(); //Users menu choice

    //Use function according to user selection
    switch(choice) {
    case 1 :
      cout << endl << endl;
      SearchEgg();
      break;
    case 2 :
      cout << endl << endl;
      HatchEgg();
      break;
    case 3 :
      cout << endl << endl;
      DisplayMyDragons();
      break;
    case 4 :
      cout << endl << endl;
      Attack();
      break;
    case 5 :
      cout << endl << "Thank you for playing Dragon Wars!!" << endl << endl;
      exit(0);
    }
  }
}

// Name: DisplayMyDragons()
// Desc - Displays the current dragons (both hatched and unhatched)
// Preconditions - Player has dragons (either hatched or unhatched)
// Postconditions - Displays a numbered list of dragons
void Game::DisplayMyDragons() {

  //Set format for list and user name
  cout << "**********************" << endl;
  cout << m_name << "'s Dragons" << endl << endl;
  cout.fill(' ');
  
  //Set format for dragon attributes
  cout << setw(33) << "Name";
  cout << setw(30) << "Type";
  cout << setw(30) << "Egg/Dragon";
  cout << setw(30) << "Current Size";
  cout << setw(30) << "Max Size" << endl;
  
  //Get each dragon in user list and display each attribute with formatting
  for(int i = 0; i < (int) m_myDragons.size(); i++) {
    cout << i + 1 << ". " << setw(30);
    cout << m_myDragons[i].GetName() << setw(30);
    cout << m_myDragons[i].GetType() << setw(30);

    //If the dragon is hatched, display egg, else display dragon
    if(m_myDragons[i].GetIsHatched() == false) 
      cout << "Egg" << setw(30);
    else
      cout << "Dragon" << setw(30);

    cout << (m_myDragons[i].GetCurSize() + 1) << setw(30); 
    cout << (m_myDragons[i].GetMaxSize() + 1) << endl << endl;
    
  }
  cout << endl;
  cout << "**********************" << endl;
}

// Name: MainMenu()
// Desc - Displays and manages menu
// Preconditions - Player has a dragon (either hatched or unhatched)
// Postconditions - Returns number indicating exit
int Game::MainMenu() {
  
  int response; //User response
  
  //Display menu
  for(;;) {
    cout << "1. Search for an egg" << endl;
    cout << "2. Try to hatch egg" << endl;
    cout << "3. Display all dragons and eggs" << endl;
    cout << "4. Attack!" << endl;
    cout << "5. Quit" << endl;
    
    //Get user response
    cin >> response;
    
    //Check user response, if response isn't listed, redisplay menu
    switch(response) {
    //Search for egg?
    case 1 :
      return response;
      break;
    //Hatch egg?
    case 2 : 
      return response;
      break;
    //Display user dragons
    case 3 :
      return response;
      break;
    //Attack enemy dragon
    case 4 :
      return response;
      break;
    //Exit game
    case 5 :
      return response;
    default : 
      cout << endl << "Incorrect menu option please select another choice" << endl;
    }   
  }
}

// Name: Attack()
// Desc - Manages the dragons attacking each other
// FYI: remove element at front of a vector is m_vectorName.erase(m_vectorName.begin());
// Preconditions - Player has hatched dragons
// Postconditions - Player attacks a random dragon of random size
void Game::Attack() {

  bool availableDragon; //Check if a dragon is available to fight with
  int choice; //Selected dragon to fight with
  int randomSize; //Random enemy dragon size
  srand(time(NULL)); //Seed randomizer

  //Check if user has dragons
  if((int) m_myDragons.size() == 0) {
    cout << "No dragons available, please find a dragon egg first!!" << endl << endl;
  }

  else {
    
    //Check if user has a hatched dragon      
    for(int i = 0; i < (int) m_myDragons.size(); i++) {
      if(m_myDragons[i].GetIsHatched() == true) {
	availableDragon = true;
      }
    }
    
    //If a user has a hatched dragon, continue
    if(availableDragon == true) {
      cout << "Select a dragon you would like to fight with: " << endl;
      DisplayMyDragons(); //Display dragons to choose from
      cin >> choice;
      
      //Out of bounds check
      while(choice > (int) m_myDragons.size() || choice < 1) {
	cout << "Invalid choice, please make another selection: " << endl << endl;
	DisplayMyDragons();
	cin >> choice;
      }  
      
      //Set selected dragon with Out of Bounds guard
      if(m_myDragons[(choice - 1)].GetIsHatched() == false) 
	cout << "Dragon is not hatched, please try again." << endl;
      
      else {  
	
	//Get random dragon from m_dragons
	Dragon enemyDragon = m_dragons[(rand() % (int) m_dragons.size())];
	
	char answer; //user response
        
	//Display enemy dragon name, ask for continue
	cout << "You've found an enemy " << enemyDragon.GetName() << endl;    
	cout << "Would you like to fight it? Type y for yes or n for no" << endl;
	cin >> answer;
	
	if(answer == 'y') {
	  //Set enemy size as a random integer less than the max size
	  randomSize  = (int) (rand() % (enemyDragon.GetMaxSize() + 1));
	  enemyDragon.SetCurSize((dragonSize) (randomSize));
	  cout << endl;
	  
	  //Dragon breath attack chance 
	  if((int) (rand() % (100 + 1)) <= 5) {
	    cout << m_myDragons[(choice - 1)].BreathAttack() << endl;
	    cout << "The enemy " << enemyDragon.GetName() << " has been slain!" << endl;
	    if(m_myDragons[(choice - 1)].AttemptGrow() == true) {
	      cout << "Your dragon grows a bit larger" << endl;
	    }
	  }

	  //Attack the enemy dragon
	  else {
	    if(m_myDragons[(choice - 1)].AttackDragon(enemyDragon) == true) {
	      if(m_myDragons[(choice - 1)].AttemptGrow() == true) {
		cout << "Your dragon grows a bit larger" << endl;
	      }
	    }
	    
	    //If enemy dragon is bigger, remove selected dragon
	    else {
	      m_myDragons.erase(m_myDragons.begin() + (choice - 1));
	      cout << "Your " << m_myDragons[(choice - 1)].GetName() << " has been slain!" << endl << endl;
	    }
	  }
	}

	//User chooses to not fight enemy dragon
	else if(answer == 'n') {
	  cout << "You chose not to fight the enemy dragon" << endl << endl;
	}
      }
    }

    //No dragons are hatched
    else {
      cout << "No hatched dragons available, please hatch your dragons!!" << endl << endl;
    }
  }
} 


// Name: DisplayAllDragons (Test Function)
// Desc - Used to test that all dragons were loaded into m_dragons correctly
// Preconditions - Requires file with valid dragon data
// Postconditions - m_dragons is displayed (all relevant data from m_dragons)
void Game::DisplayAllDragons() {

  //Formatting for display
  cout << setw(30) << left << "Dragon Name";
  cout << setw(13) << "Dragon Type";
  cout << setw(10) << "Max Size";
  cout << setw(10) << "Rarity" << endl;
  
  //Loop through all dragons
  for(int i = 0; i < (int) m_dragons.size(); i++) {
    cout << setw(30) << left << m_dragons[i].GetName();
    cout << setw(13) << m_dragons[i].GetType();
    cout << setw(10) << m_dragons[i].GetMaxSize() + 1;
    cout << setw(10) << m_dragons[i].GetRarity() << endl;
  }
}
