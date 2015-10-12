/*
Written by: Enzo Galbo
This is the header file for BaseballPlayer
9/30/2015
Steve Klein
CS 240
*/

#ifndef BASEBALLPLAYER
#define BASEBALLPLAYER
#include <string>
using namespace std;

class BaseballPlayer
{
public:
	BaseballPlayer(const string name, const string position);
	BaseballPlayer();

	// declared virtual to later be overridden
	virtual void display(ostream &out);
	virtual void loadData(istream &in);

	string getName() const;
	string getPosition() const;

	void setName(const string name);
	void setPosition(const string position);

protected:
	string name;
	string position;
};

#endif