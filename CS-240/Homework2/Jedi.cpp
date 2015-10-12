/*
Written by: Enzo Galbo
This is the cpp file for class Jedi that includes function definitions
and associated functions
9/21/2015
Steve Klein
CS 240
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Jedi.h"
using namespace std;

// function definitions
Jedi::Jedi(string name, int maxHealth, int currHealth, int attackBonus, int defenseBonus)

{
	this->name = name;

	this->maxHealth = (maxHealth < 0) ? this->maxHealth : maxHealth;  // if maxHealth is negative, do not change it, otherwise set it
	if (this->maxHealth < currHealth) {
		currHealth = this->maxHealth; // if maxHealth is set to be less than currHealth, change currHealth to value of maxHealth
	}

	if (currHealth < 0 || currHealth > maxHealth) {
		//do not change currentHealth if value given is negative or greater than maxHealth, else set it
	}
	else this->currHealth = currHealth;

	this->attackBonus = (attackBonus < 0) ? 0 : attackBonus;  // set attackBonus to 0 if it is negative, otherwise set it to given value

	this->defenseBonus = (defenseBonus < 0) ? 0 : defenseBonus;  // set defenseBonus to 0 if it is negative, otherwise set it

} // Jedi constructor

Jedi::Jedi() // default constructor
{
}

// accessors
string Jedi::getName() const { return name; }
int Jedi::getMaxHealth() const { return maxHealth; }
int Jedi::getCurrHealth() const { return currHealth; }
int Jedi::getAttackBonus() const { return attackBonus; }
int Jedi::getDefenseBonus() const { return defenseBonus; }

// mutators
void Jedi::setName(const string name) { this->name = name; }

void Jedi::setMaxHealth(const int maxHealth)
{
	this->maxHealth = (maxHealth < 0) ? this->maxHealth : maxHealth;  // if maxHealth is negative, do not change it, otherwise set it
	if (this->maxHealth < currHealth) {
		currHealth = this->maxHealth; // if maxHealth is set to be less than currHealth, change currHealth to value of maxHealth
	}
}

void Jedi::setCurrHealth(const int currHealth)
{
	if (currHealth < 0 || currHealth > maxHealth) {
		//do not change currentHealth if value given is negative or greater than maxHealth, else set it
	}
	else this->currHealth = currHealth;
}

void Jedi::setAttackBonus(const int attackBonus)
{
	this->attackBonus = (attackBonus < 0) ? 0 : attackBonus;  // set attackBonus to 0 if it is negative, otherwise set it to given value
}

void Jedi::setDefenseBonus(const int defenseBonus)
{
	this->defenseBonus = (defenseBonus < 0) ? 0 : defenseBonus;  // set defenseBonus to 0 if it is negative, otherwise set it to given value
}

// function to read data from file and validate it
void Jedi::inputData(istream& inputStream)
{
	srand(time(NULL));
	string jediName;
	string jediStat;

	getline(inputStream, jediName, ' ');
	this->name = jediName;
	getline(inputStream, jediStat, ' ');
	this->maxHealth = stoi(jediStat);
	if (this->maxHealth < 0) {
		this->maxHealth = 0; // if maxHealth is negative, set it to 0
	}
	getline(inputStream, jediStat, ' ');
	this->currHealth = stoi(jediStat);
	if (this->currHealth < 0) {
		this->currHealth = 0; // if currHealth is negative, set it to 0
	}
	if (this->maxHealth < this->currHealth) {
		this->currHealth = this->maxHealth;
	}
	getline(inputStream, jediStat, ' ');
	this->attackBonus = stoi(jediStat);
	if (this->attackBonus < 0) {
		this->attackBonus = 0; // if attackBonus is negative, set it to 0
	}
	getline(inputStream, jediStat, '\n');
	this->defenseBonus = stoi(jediStat);
	if (this->defenseBonus < 0) {
		this->defenseBonus = 0; // if defenseBonus is negative, set it to 0
	}

}

// function to write data to outputStream
void Jedi::outputData(ostream& outputStream) 
{
	outputStream << "Jedi name: " << name << endl
				 << "Max health: " << maxHealth << endl
				 << "Current Health: " << currHealth << endl
				 << "Attack bonus: " << attackBonus << endl
				 << "Defense bonus: " << defenseBonus << endl << endl;
}

void Jedi::attack(Jedi& enemy)
{
	int chanceToHit = 75;
	chanceToHit = chanceToHit - this->defenseBonus + enemy.getAttackBonus();
		if (chanceToHit < 5) {
			chanceToHit = 5;
		}
		if (chanceToHit > 95) {
			chanceToHit = 95;
		}
	int random = (rand() % 101);
	int random2 = (rand() % 10 + 6);
		if (random >= chanceToHit) {
			enemy.setCurrHealth(enemy.currHealth - random2);
		}

}

// list out data contained in jedi object to console (mainly for testing)
void Jedi::toString()
{
	cout << "Jedi name: " << name << endl
		<< "Max health: " << maxHealth << endl
		<< "Current Health: " << currHealth << endl
		<< "Attack bonus: " << attackBonus << endl
		<< "Defense bonus: " << defenseBonus << endl;
}