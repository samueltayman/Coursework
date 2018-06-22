/******************************************************************************
**  Name :    driver.cpp
**  Project:  CMSC 202 Project 4, Spring 2018
**  Author:   Samuel Tayman
**  Date:     04/24/2018
**  Section:  1070-02 && 1072-08
**  E-mail:   sata1@umbc.edu
**
**  Desc: The driver.cpp file is the main driver for this program. It 
** 	creates the MailHouse object and initiates all functions. This file
** 	also has success and failure conditions dependent on the MailHouse
**	functions
**
******************************************************************************/

#include <iomanip>

using namespace std;

#include "MailHouse.h"

// failed() - Exits the program stating a failure
// Precondition - None
// Postcondition - Program terminates
int failed(){
    cout << "Failed. Exitting..." << endl << endl;
    return 0;
}

int main(int argv, char* argc[]){
	//Checks the number of arguments provided
    if(argv != 2){
        cout << "Invalid number of parameters..." << endl;
        return -1;
    }

    MailHouse m; //MailHouse object
    cout << "Loading file: " << argc[1] << endl << endl;
	//Load file contents
    if(!m.loadMail(argc[1])){
        m.cleanUp();
        return failed();
    }
    cout << "SUCCESS" << endl << endl;

    cout << "Filling carriers...." << endl << endl;
	//Fill carriers with loaded mail
    if(!m.fillCarriers()){
        m.cleanUp();
        return failed();
    }
    cout << "SUCCESS" << endl << endl;

    cout << "Delivering...." << endl << endl;
    //Perform deliveries
	if(!m.deliverMail()){
        m.cleanUp();
        return failed();
    }
    cout << "SUCCESS" << endl << endl;

    cout << "Cleaning up the carriers....." << endl << endl;
	//Deallocate memory
    m.cleanUp();

    cout << "Simulation success. Have a nice day!" << endl;
    return 0;
}
