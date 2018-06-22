/****************************************************************
 ** 
 ** File:    driver.cpp
 ** Project: CMSC 202 Project 5, Spring 2018
 ** Author:  Samuel Tayman
 ** Date:    05/08/2018
 ** Section: 1070-02 1072-08
 ** E-mail:  sata1@umbc.edu
 **
 ** Description: Driver program for project 5, tests if input
 ** files are available, creates a new StarWars object and 
 ** calls the Start function to continue program
 **
 **
****************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Tqueue.cpp"
#include "Ship.h"
#include "StarWars.h"
#include "Imperial.h"
#include "Rebel.h"
using namespace std;

int main (int argc, char* argv[]) {
  if(argc != 3){
    cout << "Program requires two file: proj5_imperial.txt and proj5_rebel.txt" << endl;
    cout << "Try: ./proj5 proj5_imperial.txt proj5_rebel.txt" << endl;
    return -1;
  }

  StarWars newStarWars;
  char* files[] = {argv[1],argv[2]};
  newStarWars.Start(files);
  return 0;
}
