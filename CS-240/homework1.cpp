// Written by: Enzo Galbo
// This is a program that allows the user to select a drawing and desired size or select character printed in drawing then end program when requested.
// 8/26/2015
// Steve Klein

#include <iostream>;
#include <string>;
#include <math.h>;
using namespace::std;

// Global Variables
char printChar = 'O';

//function prototypes
void drawTriangle(int userSize);
void drawUpsidedownTriangle(int userSize);
void drawRectangle(int userSize);
void drawPlusSign(int userSize);
void changePrintCharacter();
int getSizeOfShape();

//main function
int main()
{
	char printChar = 'O';
	char userChoice;
	int size;

	cout << "Welcome to the program!  Please Select an option by typing the corresponding letter!" << endl;
	do {
	cout << "A: Draw a triangle." << endl;
	cout << "B: Draw an upside-down triangle." << endl;
	cout << "C: Draw a rectangle." << endl;
	cout << "D: Draw a plus sign" << endl;
	cout << "E: Change print character (default character: O)" << endl;
	cout << "F: End the program." << endl;
	
	cin >> userChoice;
	cin.ignore(256, '\n');
		if (userChoice == 'A') {
			size = getSizeOfShape();
			drawTriangle(size);
		}

		else if (userChoice == 'B') {
			size = getSizeOfShape();
			drawUpsidedownTriangle(size);
		}

		else if (userChoice == 'C') {
			size = getSizeOfShape();
			drawRectangle(size);
		}

		else if (userChoice == 'D') {
			size = getSizeOfShape();
			drawPlusSign(size);
		}

		else if (userChoice == 'E') {
			changePrintCharacter();
		}
		else if (userChoice == 'F') {
			cout << "Program will be terminated, goodbye! " << endl;
			exit(0);
		}
		else {
			cout << "This is not a valid character choice, Please try again." << endl;
		}
	} while (true);

}

void drawTriangle(int userSize)
{
	for (int i = 0; i <= userSize; i++) {
		cout << string(i, printChar) << endl;
	}
	cout << "" << endl;
}

void drawUpsidedownTriangle(int userSize)
{
	for (int i = userSize; i >= 0; i--) {
		cout << string(i, printChar) << endl;
	}
	cout << "" << endl;
}

void drawRectangle(int userSize)
{
	for (int i = 0; i < userSize; i++) {
		cout << string(userSize, printChar) << endl;
	}
	cout << "" << endl;
}

void drawPlusSign(int userSize)
{
	int spaces = floor(userSize / 2);
	for (int i = 0; i < spaces; i++)
	{
		cout << string(spaces, ' ');
		cout << printChar;
		cout << endl;
	}

	cout << string(userSize, printChar) << endl;

	for (int i = 0; i < spaces; i++)
	{
		cout << string(spaces, ' ');
		cout << printChar;
		cout << endl;
	}

}

void changePrintCharacter()
{
	cout << "Please input character you would like to print." << endl;
	cin >> printChar;
}

int getSizeOfShape()
{
	int size;
	cout << "How big would you like this shape to be? (Please select an odd number between 3 and 9)" << endl;
	do {
		cin >> size;
		if (size != 3 && size != 5 && size != 7 && size != 9) {
			cout << "This is not a valid size, please try again." << endl;
			cin.clear();
			cin.ignore();
		}
	} while (size != 3 && size != 5 && size != 7 && size != 9);
	return size;
}