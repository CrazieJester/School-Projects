/*
Written by: Enzo Galbo
This is the cpp file for BaseballTeam
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
#include "BaseballPlayer.h"

using namespace std;

// function definitions

// default constructor
BaseballTeam::BaseballTeam()
{
}	

// copy constructor
BaseballTeam::BaseballTeam(const BaseballTeam &t)
{
	BaseballPlayerPtr entry = new BaseballPlayer[TEAM_SIZE];
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		entry = t.team[i];
	}
}

// assignment operator
BaseballTeam& BaseballTeam::operator = (const BaseballTeam &t)
{
	BaseballPlayerPtr entry = new BaseballPlayer[TEAM_SIZE];
	for  (int i = 0; i < TEAM_SIZE; i++)
	{
		entry = t.team[i];
	}
	return *this;
}

BaseballTeam::~BaseballTeam()
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		delete team[i];
	}
}

void BaseballTeam::loadTeam(istream &in)
{
	// keep track of player count
	int playerNum = 0;

	// for loop for pitcher reading, creates pitcher object to point at with BaseballPlayer pointer casted to pitcher
	for (int i = 0; i < NUMBER_PITCHERS; i++)
	{
		team[playerNum] = new Pitcher;
		static_cast <Pitcher*> (team[playerNum])->loadData(in);
		playerNum++;
	}
	
	// for loop for batter reading, creates batter object to point at with BaseballPlayer pointer casted to batter
	for (int i = 0; i < NUMBER_BATTERS; i++)
	{
		team[playerNum] = new Batter;
		static_cast <Batter*>  (team[playerNum])->loadData(in);
		playerNum++;
	}

	// for loop for player reading, creates player object to point at with BaseballPlayer pointer casted to player
	for (int i = 0; i < NUMBER_SUBS; i++)
	{
		team[playerNum] = new BaseballPlayer;
		team[playerNum]->loadData(in);
		playerNum++;
	}
}

// show team
void BaseballTeam::displayTeam(ostream &out)
{
	// declare strings to replace in printf methods
	string title = "Team Data";
	string stats = "Individual Stats:";
	string pitcher = "Pitchers:";
	string pos = "Pos:";
	string batter = "Batters:";
	string subs = "Subs:";
	string name = "Name:";
	string bave = "BAve:";
	string hr = "HR:";
	string rbi = "RBI:";
	string sb = "SB:";
	string wins = "Wins:";
	string saves = "Saves:";
	string era = "ERA:";
	string whip = "WHIP:";
	string small_lines = "-----------------------------";
	string long_lines = "----------------------------------------------------------------------------";

	// show title, stats, and then pitcher
	printf("%45s\n\n %30s\n%9s\n", title.c_str(), stats.c_str(), pitcher.c_str());

	// show catagories and then line spacing
	printf("%-4s%24s%13s%12s%8s%11s   \n%s\n",
		pos.c_str(),name.c_str(),wins.c_str(),saves.c_str(),era.c_str(),whip.c_str(),long_lines.c_str());

	// display pitcher data
	for (int i = 0; i < 10; i++)
	{
		static_cast <Pitcher*> (team[i])->display(cout);
	}
	cout << endl;

	// show batter title
	printf("%s\n", batter.c_str());

	// show batter headings
	printf("%-4s%24s%11s%12s%11s%11s   \n%s\n",
		pos.c_str(), name.c_str(), bave.c_str(), hr.c_str(), rbi.c_str(), sb.c_str(), long_lines.c_str());

	// show batter data
	for (int i = 10; i < 20; i++)
	{
		static_cast <Batter*> (team[i])->display(cout);
	}

	cout << endl;

	// show title names then line spacing
	printf("%s\n%-6s%4s\n%30s\n", subs.c_str(), pos.c_str(), name.c_str(), small_lines.c_str());

	// show substitute data
	for (int i = 20; i < 25; i++)
	{
	(team[i])->display(cout);
	}
	cout << "\n\n\n";

	// call showTotals function to show later part
	showTotals(out);
}

void BaseballTeam::showTotals(ostream &out)
{
	// declare strings to use in printf
	string medium_lines = "--------------------------------------";
	string totals = "Team Totals:";
	string pitchers = "Pitchers:";
	string wins = "Wins:";
	string saves = "Saves:";
	string era = "ERA:";
	string whip = "WHIP:";
	string batters = "Batters:";
	string bave = "BatAve:";
	string hr = "HR:";
	string rbi = "RBI:";
	string sb = "SB:";

	// show headings then line spacing
	printf("%s\n%6s%10s%10s%10s\n%s\n", totals.c_str(), wins.c_str(), saves.c_str(), era.c_str(), whip.c_str(), medium_lines.c_str());

	// show data of team wins, team saves, team era, team whip, and title for batters
	printf("%4i%9i%13.2f%10.3f\n\n%s\n", calculateTeamWins(), calculateTeamSaves(), calculateTeamERA(), calculateTeamWHIP(), batters.c_str());

	// show more data, batting ave, home runs, runs batted in, stolen bases, line spacing
	printf("%7s %7s %9s %9s\n%s\n", bave.c_str(), hr.c_str(), rbi.c_str(), sb.c_str(), medium_lines.c_str());

	// show team batting average, home runs, runs batted in, team stolen bases
	printf("%-5.3f %8i %9i %9i\n\n", calculateTeamBA(), calculateTeamHomeRuns(), calculateTeamRBI(), calculateTeamSB());
}

void BaseballTeam::deleteTeam()
{
	// delete but leave space for possible later declaration
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		delete team[i];
		team[i] = NULL;
	}
}


int BaseballTeam::calculateTeamWins() const
{
	// keep track of wins
	int wins = 0;

	for (int i = 0; i < NUMBER_PITCHERS; i++)
	{
		// add wins to next pitcher's wins data member
		wins += (static_cast <Pitcher*>  (team[i])->getWins());
	}
	return wins;
}

int BaseballTeam::calculateTeamSaves() const
{
	// keep track of saves
	int saves = 0;

	for (int i = 0; i < NUMBER_PITCHERS; i++)
	{
		// add saves to next pitchers saves data member
		saves += (static_cast <Pitcher*>  (team[i])->getSaves());
	}
	return saves;
}

double BaseballTeam::calculateTeamERA() const
{
	// keep track of earned runs and innings pitched
	int earned_runs = 0;
	int innings_pitched = 0;

	for (int i = 0; i < NUMBER_PITCHERS; i++)
	{
		// add earned runs and savers to next pitchers earned runs and saves data members
		earned_runs += (static_cast <Pitcher*>  (team[i])->getEarned_runs());
		innings_pitched += (static_cast <Pitcher*>  (team[i])->getInnings_pitched());
	}
	// calculate ERA, be sure to return as a double by casting earned runs as double
	return ((double)earned_runs / innings_pitched) * 9;
}

double BaseballTeam::calculateTeamWHIP() const
{
	// keep track of walks, hits, and innings pitched
	int walks = 0;
	int hits = 0;
	int innings_pitched = 0;

	for (int i = 0; i < NUMBER_PITCHERS; i++)
	{
		// add data members to next pitchers data
		walks += (static_cast <Pitcher*>  (team[i])->getWalks());
		hits += (static_cast <Pitcher*>  (team[i])->getHits());
		innings_pitched += (static_cast <Pitcher*>  (team[i])->getInnings_pitched());
	}
	// calculate WHIP, be sure to return as double by casting walks as a double
	return ((double)walks + hits) / innings_pitched;
}

double BaseballTeam::calculateTeamBA() const
{
	// keep track of runs and team at bats
	int runs = 0;
	int team_at_bats = 0;

	for (int i = 10; i < 20; i++)
	{
		// add runs and team at bats to next batter's data members
		runs += (static_cast <Batter*>  (team[i])->getHits());
		team_at_bats += (static_cast <Batter*>  (team[i])->getAt_bats());
	}
	// calculate batting average, cast as double to ensure double return
	return (double)runs / team_at_bats;
}

int BaseballTeam::calculateTeamHomeRuns() const
{
	// keep track of home runs
	int hr = 0;

	for (int i = 10; i < 20; i++)
	{
		// add home runs to each next batters data member
		hr += (static_cast <Batter*>  (team[i])->getHome_runs());
	}
	return hr;
}

int BaseballTeam::calculateTeamRBI() const
{
	// keep track of runs batted in
	int runs_batted_in = 0;

	for (int i = 10; i < 20; i++)
	{
		// add runs batted in to next batter's data member
		runs_batted_in += (static_cast <Batter*>  (team[i])->getRuns_batted_in());
	}
	return runs_batted_in;
}

int BaseballTeam::calculateTeamSB() const
{
	// keep track of stolen bases
	int stolen_bases = 0;

	for (int i = 10; i < 20; i++)
	{
		// add stolen bases to next batter's stolen bases
		stolen_bases += (static_cast <Batter*>  (team[i])->getStolen_bases());
	}
	return stolen_bases;
}