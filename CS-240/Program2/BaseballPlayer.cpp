/*
Written by: Enzo Galbo
This is the cpp file for BaseballPlayer
9/30/2015
Steve Klein
CS 240
*/
#include <iostream>
#include <fstream>
#include <string>
#include "BaseballTeam.h"
#include "Pitcher.h"
#include "Batter.h"
using namespace std;

// function definitions
BaseballPlayer::BaseballPlayer(string name, string position)
{
	this->name = name;
	this->position = position;
}

BaseballPlayer::BaseballPlayer() // default constructor
{
}

// acessors
string BaseballPlayer::getName() const { return name; }
string BaseballPlayer::getPosition() const { return position; }

// mutators
void BaseballPlayer::setName(const string name) { this->name = name; }
void BaseballPlayer::setPosition(const string position) { this->position = position; }

void BaseballPlayer::display(ostream &out)
{
	string semi = ":";
	printf("%-2s %s %s \n", position.c_str(), semi.c_str(), name.c_str());
}

void BaseballPlayer::loadData(istream &in)
{
	string temp;
	while (temp == " " || temp == "") {
		getline(in, temp, '\n');
	}
	name = temp;
	temp = "";

	while (temp == " " || temp == "") {
		getline(in, temp, '\n');
	}
	position = temp;
	temp = "";

}