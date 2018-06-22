/******************************************************************************
**  Name :    MailHouse.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: This file contains the functions for the MailHouse class. 
**  The functions include loading mail into the classes mail vector and 
**  building the carrier's based on the file information, filling carrier
**  mail vectors by creating the type of mail determined by the loaded file 
**  and displaying the contents of each carrier, a deliver function which
**  attempts to deliver the contents of each carrier and displays the results,
**  and a cleanUp function which deallocates any allocated memory
**
******************************************************************************/

#include "MailHouse.h"
#include <cstdlib>

// Constructor
// Preconditions: None
// Postconditions: None
MailHouse::MailHouse() {  
}

// loadMail(char*) - loads the file and sets any data from the file
// Preconditions: a valid filepath
// Postconditions: Loads m_mail. Returns int for status (1 - success, 0 - fail)
int MailHouse::loadMail(char* file) {

  string token; //token variable holding file line data
  mailType mail; //mail type variable
  int capacity; //carrier capacity variable
  float speed; //carrier rate variable
  float letterCost; //letter base cost variable
  float packageCost; //package base cost variable
 
  ifstream in(file);
  FedEx *fedTruck = new FedEx();
  Ups *upsTruck = new Ups();

  
  //While loop to get file contents and load data into object variables
  while(!in.eof()) {
    
    //Retrieve UPS Max Capacity
    getline(in, token, ' ');
    capacity = atoi(token.c_str());
    upsTruck->setMaxCapacity(capacity);   

    //Retrieve FedEx Max Capacity
    getline(in, token, ' ');
    capacity = atoi(token.c_str());
    fedTruck->setMaxCapacity(capacity);

    //Retrieve UPS rate
    getline(in, token, ' ');
    speed = atof(token.c_str());
    upsTruck->setRate(speed);

    //Retrieve FedEx rate
    getline(in, token, ' ');
    speed = atof(token.c_str());
    fedTruck->setRate(speed);

    //Retrieve mail costs
    getline(in, token, ' ');
    letterCost = atof(token.c_str());
    getline(in, token);
    packageCost = atof(token.c_str());
    
    //Insert carriers into carrier vector
    m_carriers.push_back(upsTruck);
    m_carriers.push_back(fedTruck);
    
    
    //Iterate through file to retrieve mail data and store
    while(!in.eof()) {

      carrierType carrier; //carrier type variable 
      string sender; //Mail sender
      string recipient; //Mail recipient
      float size; //size of Mail

      getline(in, token, ',');
      carrier = (carrierType) atoi(token.c_str());
      
      //Set mail variables based on carrier
      if(carrier == UPS) {

	getline(in, token, ',');
	mail = (mailType) atoi(token.c_str());  //Convert int to mailType

	//Set Mail variables
	getline(in, sender, ',');
	getline(in, recipient, ',');
	getline(in, token);
	size = atof(token.c_str()); //Convert string to float

	if(in.eof())
	  break;

	//Insert mail into mail vector(LETTER)
	if(mail == LETTER) {
	  
	  Letter *myLetter = new Letter((int) carrier, sender, recipient, size, letterCost);
	  m_mail.push_back(myLetter);

	}
	//Insert mail into mail vector(PACKAGE)
	else if(mail == PACKAGE) {

	  Package *myPackage = new Package((int) carrier, sender, recipient, size, packageCost);
	  m_mail.push_back(myPackage);

	}
      }
      else if(carrier == FEDEX) {

	getline(in, token, ',');
	
	mail = (mailType) atoi(token.c_str());  //Convert int to mailType
	
	//Set Mail variables
	getline(in, sender, ',');
	getline(in, recipient, ',');
	getline(in, token);
	size = atof(token.c_str());
	
	//Insert mail into mail vector(LETTER)
	if(mail == LETTER) {

	  Letter *myLetter = new Letter((int) carrier, sender, recipient, size, letterCost);
	  m_mail.push_back(myLetter);

	}
	//Insert mail into mail vector(PACKAGE)
	else if(mail == PACKAGE) {

	  Package *myPackage = new Package((int) carrier, sender, recipient, size, packageCost);
	  m_mail.push_back(myPackage);

	}
      }
    }
  }
  return 1;  
}

// fillCarriers() - Loads the carrier vectors from the m_mail vectors
// Preconditions: m_mail is populated. m_carriers is populated
// Postconditions: m_carriers have mail in their respective vectors. 
// Returns int for status (1 - success, 0 - fail)
int MailHouse::fillCarriers() {

  int upsCapacity = 0; //Holds current capacity of carriers vector
  int fedexCapacity = 0;  //Holds current capacity of carriers vector

  //Inserts mail into carriers, checks to see if carrier is carrying too much mail
  for(int i = 0; i < (int) m_carriers.size(); i++) {
    
    //UPS Object 
    if(i == 0) {
      for(int j = 0; j < (int) m_mail.size(); j++) {
	//Load UPS carrier with mail
	if((carrierType) m_mail[j]->getCarrier() == UPS) {
	  m_carriers[i]->insert(m_mail[j]);
	  upsCapacity++;
	  //Check if carrier is over capacity
	  if(upsCapacity > m_carriers[i]->getMaxCapacity()) {
	    cout << "Could not fill carrier, carrier is at max capacity!!!" << endl;
	    return 0;
	  }
	}
      }
    }
    //FedEx Object
    else if(i == 1) {
      for(int j = 0; j < (int) m_mail.size(); j++) {
	//Load FedEx carrier with mail
	if((carrierType) m_mail[j]->getCarrier() == FEDEX) {
	  m_carriers[i]->insert(m_mail[j]);
	  fedexCapacity++;
	  //Check if carrier is over capacity
	  if(fedexCapacity > m_carriers[i]->getMaxCapacity()) {
	    cout << "Could not fill carrier, carrier is at max capacity!!!" << endl;
	    return 0;
	  }
	}
      }
    }
  }
  //Output contents of each carrier
  for(int i = 0; i < (int) m_carriers.size(); i++) {
    cout << *m_carriers[i];
  }

  return 1;
}

// deliverMail() - Send carriers out for delivery
// Preconditions: m_carriers are populated
// Postconditions: m_carriers have cleared their vectors. 
// Returns int for status (1 - success, 0 - fail)
int MailHouse::deliverMail(){

  //Complete deliveries of each carrier
  for(int i = 0; i < (int) m_carriers.size(); i++) {
    m_carriers[i]->deliver();
  }

  return 1;

}

// cleanUp() - Any additional clean up is done here
// Preconditions: Allocated memory
// Postconditions: Deallocates any remaining allocations
int MailHouse::cleanUp(){

  //Delete all mail inside mail vector
  for(int i = 0; i < (int) m_mail.size(); i++) {
    delete (m_mail[i]);
  }

  //Clear mail vector contents
  m_mail.clear();
 
  //Delete all carriers in carrier vector
  for(int i = 0; i < (int) m_carriers.size(); i++) {
    delete (m_carriers[i]);
  }
  
  //Clear carrier vector contents
  m_carriers.clear();
 
  return 1;

}
