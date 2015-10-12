/*
Written by: Enzo Galbo
This is the header file for batter
9/30/2015
Steve Klein
CS 240
*/

#ifndef BATTER
#define BATTER

#include <iostream>
#include <fstream>
#include <string>
#include "BaseballTeam.h"
#include "BaseballPlayer.h"
#include "Pitcher.h"
using namespace std;

class Batter : public BaseballPlayer
{
public:
	Batter(const int at_bats, const int hits, const int home_runs, const int runs_batted_in, const int stolen_bases);
	Batter(); // default constructor

	void display(ostream &out);
	void loadData(istream &in);

	double calculateBattingAverage();

	int getAt_bats() const;
	int getHits() const;
	int getHome_runs() const;
	int getRuns_batted_in() const;
	int getStolen_bases() const;

	void setAt_bats(const int at_bats);
	void setHits(const int hits);
	void setHome_runs(const int home_runs);
	void setRuns_batted_in(const int runs_batted_in);
	void setStolen_bases(const int stolen_bases);

private:
	int at_bats;
	int hits;
	int home_runs;
	int runs_batted_in;
	int stolen_bases;

};

#endif