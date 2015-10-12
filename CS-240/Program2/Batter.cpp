/*
Written by: Enzo Galbo
This is the cpp file for batter
9/30/2015
Steve Klein
CS 240
*/
#include <iostream>
#include <fstream>
#include <string>
#include "BaseballTeam.h"
#include "BaseballPlayer.h"
#include "Pitcher.h"
using namespace std;

Batter::Batter(int at_bats, int hits, int home_runs, int runs_batted_in, int stolen_bases)
{
	setAt_bats(at_bats);
	setHits(hits);
	setHome_runs(home_runs);
	setRuns_batted_in(runs_batted_in);
	setStolen_bases(stolen_bases);
} // uses setters to validate data

Batter::Batter()
{

} // default constructor

// accessors
int Batter::getAt_bats() const { return at_bats; }
int Batter::getHits() const { return hits; }
int Batter::getHome_runs() const { return home_runs; }
int Batter::getRuns_batted_in() const { return runs_batted_in; }
int Batter::getStolen_bases() const { return stolen_bases; }

// mutators
void Batter::setAt_bats(const int at_bats)
{
	// data validation keeping above 0
	if (at_bats < 0) {
		this->at_bats = 0;
	}
	else this->at_bats = at_bats;
}
void Batter::setHits(const int hits)
{
	if (hits < 0) {
		this->hits = 0;
	}
	else this->hits = hits;
}
void Batter::setHome_runs(const int home_runs)
{
	if (home_runs < 0) {
		this->home_runs = 0;
	}
	else this->home_runs = home_runs;
}
void Batter::setRuns_batted_in(const int runs_batted_in)
{
	if (runs_batted_in < 0) {
		this->runs_batted_in = 0;
	}
	else this->runs_batted_in = runs_batted_in;
}

void Batter::setStolen_bases(const int stolen_bases)
{
	if (stolen_bases < 0) {
		this->stolen_bases = 0;
	}
	else this->stolen_bases = stolen_bases;
}

double Batter::calculateBattingAverage()
{
	if (at_bats == 0) {
		return -1;
	}
	double battingAverage = ((double)hits / at_bats);
	return battingAverage;
}

void Batter::display(ostream &out)
{
	if (at_bats == 0) {
		printf("%-2s %25s %10s %10i %10i %10i \n", position.c_str(), name.c_str(), "N/A", home_runs, runs_batted_in, stolen_bases);
	}
	else {
		printf("%-2s %25s %10.3f %10i %10i %10i \n", position.c_str(), name.c_str(), calculateBattingAverage(), home_runs, runs_batted_in, stolen_bases);
	}
}

void Batter::loadData(istream& in)
{
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
	in >> position >> at_bats >> 
	hits >> home_runs >> 
	runs_batted_in >> stolen_bases;
}