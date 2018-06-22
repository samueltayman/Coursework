#include "Train.h"
#include <cstdlib>
#include <vector>

vector<Train> myTrains;

void loadTrains(string file) {
  
  int test = 0;
  
  //Create train object 
  Train *train;
  
  //Varibale for train number
  int trainNum;
  
  //Varibale for function 
  string function;
  
  //Variable for cargo type
  CARGO_TYPE cargo;
  
  //fstream object for file
  ifstream in(file.c_str());
  
  //Token to hold line data
  string token;

  //index variable to hold car index 
  int index = 0;
  
  while(!in.eof()) {
    
    //placeholder to parse string to int
    string placeholder = "";
    
    function = "";
    trainNum = 0;
    cargo = LOCOMOTIVE;
    
    getline(in, placeholder, ',');
    trainNum = atoi(placeholder.c_str());
    getline(in, function, ',');
    getline(in, token);
    

    cout << endl << placeholder << ",";
    cout << function << ",";
    cout << token << endl;
    
    /*
    //Retrieve current train to add cars
    if(myTrains.empty() == false) {
      for(int i = 0; i < (int) myTrains.size(); i++) {
	if(myTrains[i].getNumber() == trainNum) {
	  *train = myTrains[i];
	}
      }
    }
    */

    if(token.compare("LOCOMOTIVE") == 0) {
      cargo = LOCOMOTIVE;
      /**
      train = new Train(trainNum);
      train->addCar(cargo, 0);
      **/
      //Testing
      cout << "New Train Made" << endl << endl;
      myTrains.push_back(*new Train(trainNum));
      index = 0;
    }

    //Retrieve current train to add cars
    if(myTrains.empty() == false) {
      for(int i = 0; i < (int) myTrains.size(); i++) {
	if(myTrains[i].getNumber() == trainNum) {
	  cout << "Get a train" << endl;
	  *train = myTrains[i];
	  cout << "Got a train" << endl;
	}
      }
    }

    else {
      if(token.compare("BIOLOGICAL") == 0) {
	cargo = BIOLOGICAL;
      }
      else if(token.compare("RADIOACTIVE") == 0) {
	cargo = RADIOACTIVE;
      }
      else if(token.compare("POISONOUS") == 0) {
	cargo = POISONOUS;
      }
      else if(token.compare("OXIDIZER") == 0) {
	cargo = OXIDIZER;
      }
      else if(token.compare("CABOOSE") == 0) {
	cargo = CABOOSE;
      }
    }
    if(function.compare("add") == 0) {
      cout << "Adding car" << endl;
      //Error here
      train->addCar(cargo, index);
      cout << "Car added" << endl;
    }
    else if(function.compare("remove") == 0) { 
      train->removeCar(cargo);
    }
    cout << "Train Number: " << train->getNumber() << endl << endl;
    index++;     
    test++;
    cout << "Index Testing: " << index << endl << endl;
  }
}

int main(int argc, char* argv[]) {

  loadTrains(argv[1]);
  return 0;
}
