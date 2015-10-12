/*
Written by: Enzo Galbo
This is the cpp file for Pitcher
9/30/2015
Steve Klein
CS 240
*/

#include <iostream>
#include <fstream>
#include <string>
#include "BaseballTeam.h"
#include "BaseballPlayer.h"
#include "Batter.h"
using namespace std;

Pitcher::Pitcher(int wins, int saves, int innings_pitched, int earned_runs, int hits, int walks)
{
	setWins(wins);
	setSaves(saves);
	setInnings_pitched(innings_pitched);
	setEarned_runs(earned_runs);
	setHits(hits);
	setWalks(walks);
}

Pitcher::Pitcher()
{

} // default constructor

// accessors
int Pitcher::getWins() const { return wins; }
int Pitcher::getSaves() const { return saves; }
int Pitcher::getInnings_pitched() const { return innings_pitched; }
int Pitcher::getEarned_runs() const { return earned_runs; }
int Pitcher::getHits() const { return hits; }
int Pitcher::getWalks() const { return walks; }

// mutators
void Pitcher::setWins(const int wins) 
{
	// data validation keeping above 0
	if (wins < 0) {
		this->wins = 0;
	}
	else this->wins = wins;
}
void Pitcher::setSaves(const int saves) 
{
	if (saves < 0) {
		this->saves = 0;
	}
	else this->saves = saves;
}
void Pitcher::setInnings_pitched(const int innings_pitched)
{
	if (innings_pitched < 0) {
		this->innings_pitched = 0;
	}
	else this->innings_pitched = innings_pitched;
}
void Pitcher::setEarned_runs(const int earned_runs)
{
	if (earned_runs < 0) {
		this->earned_runs = 0;
	}
	else this->earned_runs = earned_runs;
}

void Pitcher::setHits(const int hits)
{
	if (hits < 0) {
		this->hits = 0;
	}
	else this->hits = hits;
}
void Pitcher::setWalks(const int walks)
{
	if (walks < 0) {
		this->walks = 0;
	}
	else this->walks = walks;
}

// calculate functions

double Pitcher::calculateERA() 
{
	if (innings_pitched == 0) {
		return -1; // return -1 if division by 0
	}
	double era = ((double)earned_runs / innings_pitched) * 9;
	return era;
}

double Pitcher::calculateWHIP()
{
	if (innings_pitched == 0) {
		return -1; // return -1 if division by 0
	}
	double whip = ((double)walks + hits) / innings_pitched;
	return whip;
}

void Pitcher::display(ostream &out)
{
	if (innings_pitched == 0) {
		printf("%-2s %25s %10i %10i %10s %10s \n", position.c_str(), name.c_str(), wins, saves, "N/A", "N/A");
	}
	else printf("%-2s %25s %10i %10i %10.2f %10.3f \n", position.c_str(), name.c_str(), wins, saves, calculateERA(), calculateWHIP());
}

void Pitcher::loadData(istream &in)
{
	setPosition("P");
	string first;
	string last;
	char escapeCharacter = '\n'; // initialize escape character variable to later store data (other than name)

	// while loop to read while escapeCharacter is blank
	while (escapeCharacter == '\n')
	{
		in.get(escapeCharacter);
	}

	in >> first >> last;

	name = escapeCharacter + first + " " + last; // get first character then first and last names, store in name

	// while loop to read while escapeCharacter is blank
	while (escapeCharacter == '\n')
	{
		in.get(escapeCharacter);
	}

	// store data members in order they're read
	in >> wins >> saves >>
		innings_pitched >> earned_runs >>
		hits >> walks;

}