/*
Written by: Enzo Galbo
This is the header file for pitcher
9/30/2015
Steve Klein
CS 240
*/

#ifndef PITCHER
#define PITCHER

#include <iostream>
#include <fstream>
#include <string>
#include "BaseballTeam.h"
#include "BaseballPlayer.h"
#include "Batter.h"
using namespace std;

class Pitcher : public BaseballPlayer
{
public:
	Pitcher(const int wins, const int saves, const int innings_pitched, const int earned_runs, const int hits, const int walks);
	Pitcher(); // default constructor

	void display(ostream &out);
	void loadData(istream &in);

	double calculateERA();
	double calculateWHIP();

	int getWins() const;
	int getSaves() const;
	int getInnings_pitched() const;
	int getEarned_runs() const;
	int getHits() const;
	int getWalks() const;

	void setWins(const int wins);
	void setSaves(const int saves);
	void setInnings_pitched(const int innings_pitched);
	void setEarned_runs(const int earned_runs);
	void setHits(const int hits);
	void setWalks(const int walks);

private:
	int wins;
	int saves;
	int innings_pitched;
	int earned_runs;
	int hits;
	int walks;
};

#endif