/***************************************************************
** 	File:		proj2.cpp
** 	Project: 	CMSC 202 Project 2, Spring 2018
** 	Author: 	Samuel Tayman
** 	Date: 		03/24/2018
** 	Section:	1070-06 && Lab 1072-08
** 	E-mail:	sata1@umbc.edu
**
** 	proj.cpp is the main driver for this program 
**	This program creates a new Game instance and begins running
** 	the game by calling the StartGame() function
**
**
***************************************************************/

//Title: Project 2 for Spring 2018

#include "Dragon.h"
#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main () {
  Game newGame;
  newGame.StartGame();
  return 0;
}
