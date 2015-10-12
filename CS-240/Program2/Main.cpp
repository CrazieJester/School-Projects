/*
Enzo Galbo
9/28/2015
CS 240
Steve Klein
This is the Driver that connects to the file, loads the data, and displays the data to the cmd window
*/

#include <iostream>
#include <fstream>
#include <string>
#include "BaseballTeam.h"
#include "BaseballPlayer.h"
#include "Pitcher.h"
#include "Batter.h"

using namespace std;
string FILE_NAME = "BaseballTeam.txt";


int main()
{
	// connect to file and test if it is open
	ifstream fin(FILE_NAME);
	if (!fin.is_open()) {
		cerr << "Error opening " + FILE_NAME + " for reading." << endl;
		exit(1);
	}

	BaseballTeam myTeam; // create a baseball team named myTeam
	myTeam.loadTeam(fin); // load data into team

	myTeam.displayTeam(cout); // show data

	fin.close(); // close the file

}
