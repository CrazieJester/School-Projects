/*
Written by: Enzo Galbo
This is a header file for class Jedi that lists the Jedi object's data members
and associated functions
9/21/2015
Steve Klein
CS 240
*/
#ifndef JEDI_H
#define JEDI_H

#include <string>
using namespace std;

class Jedi
{
private:
	string name;
	int maxHealth;
	int currHealth;
	int attackBonus;
	int defenseBonus;

public:
	Jedi(const string name, const int maxHealth, const int currHealth, const int attackBonus, const int defenseBonus);
	Jedi(); // default constructor

	void inputData(istream& inputStream);
	void outputData(ostream& outputStream);
	void attack(Jedi& enemy);
	void toString();

	string getName() const;
	int getMaxHealth() const;
	int getCurrHealth() const;
	int getAttackBonus() const;
	int getDefenseBonus() const;

	void setName(const string name);
	void setMaxHealth(const int maxHealth);
	void setCurrHealth(const int currHealth);
	void setAttackBonus(const int attackBonus);
	void setDefenseBonus(const int defenseBonus);
};

#endif