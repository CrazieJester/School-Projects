// Written by: Enzo Galbo
// This is a program that loads in boggle dice caps and simulates a boggle board, allowing the user to shake the board.
// 8/26/2015
// Steve Klein

#include <iostream>;
#include <fstream>;
#include <string>;
#include <ctime>;
#include <Windows.h>;
using namespace std;

// function prototypes
void loadDieListFromFile(string DieList[16]);
void createBoard(string DieList[16], string boggleBoard[4][4]);
void swapTwoDie(string boggleBoard[4][4]);
void displayBoard(string boggleBoard[4][4]);
void shakeBoard(string boggleBoard[4][4]);

int main()
{
	// seed random
	srand(unsigned(time(NULL)));

	// initialize array of die and 2d array representing boggleBoard to later fill with data
	string DieList[16];
	string boggleBoard[4][4];

	// call function to alter blank dieList and populate with data from file
	loadDieListFromFile(DieList);

	// call function to populate boggleBoard with die from list, giving to list of die and the board to alter
	createBoard(DieList, boggleBoard);

	// call function to "shake" board, swapping two dice and displaying a random face at each die 250 times
	shakeBoard(boggleBoard);
}

// uses the text file to populate array with "dice" (list of each die's faces)
void loadDieListFromFile(string DieList[16])
{
	int x = 0;
	string line;
	ifstream myfile("BoggleDicecaps.txt");
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			DieList[x] = line;
			x++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

// loads list of 16 words in 2d array
void createBoard(string DieList[16], string boggleBoard[4][4])
{

	int temp = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			boggleBoard[i][j] = DieList[temp];
			temp++;
		}
	}
}

// swaps entire dice at location, including all faces
void swapTwoDie(string boggleBoard[4][4])
{
	int randRow = (rand() % 4);
	int randCol = (rand() % 4);
	int randRow2 = (rand() % 4);
	int randCol2 = (rand() % 4);
	boggleBoard[randRow][randCol].swap(boggleBoard[randRow2][randCol2]);

}

// shows a random face of each die on the board
void displayBoard(string boggleBoard[4][4])
{
	int randomNumber = (rand() % 6);
	string dieFace;
	cout << "+---+---+---+---+\n";
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int j = 0; j < 4; j++)
		{
			dieFace = boggleBoard[i][j].at(randomNumber);
			if (dieFace == "Q") {
				dieFace = "Qu";
				cout << " " << dieFace << "|";
			}
			else
			cout << " " << dieFace << " |";
		}
		cout << "\n+---+---+---+---+\n";
	}
}

// "shake" board by swapping die and show board
void shakeBoard(string boggleBoard[4][4])
{
	cout << "Please press any key to shake the board." << endl;
	system("pause");
	while (true) {
		for (int i = 0; i < 250; i++) {
			swapTwoDie(boggleBoard);

			system("cls");
			displayBoard(boggleBoard);

		}
		cout << "Please press any key to shake the board." << endl;
		system("pause");
	}
}

