// Osbaldo Esquivel
// CS 225
// 15JAN2014

#include <iostream>
#include "theCell.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	char choice;
	int userH, userW;

	cout << "                          Game of Life                          \n"
		 << "----------------------------------------------------------------\n"
		 << "\nThis program is based on Conway's Game of Life. You will be\n"
		 << "asked the height and width of a grid to generate a living map.\n"
		 << "The map will consist of living and dead cells that will die or\n" 
		 << "regenerate according to the following rules: \n\n"
		 << "\t1. If an occupied cell has zero or one neighbor, it dies of\n"
		 << "\t   loneliness.\n"
		 << "\t2. If an occupied cell has more than three neighbors, it dies\n"
		 << "\t   of overcrowding\n"
		 << "\t3. If an empty cell has exactly three occupied neigbor cells,\n"
		 << "\t   there is a birth of a new cell to replace the empty cell.\n"
		 << "\t4. Births and deaths are instantaneous and occur at the changes\n"
		 << "\t   of generation.\n" 
		 << "\nIt is strongly recommended to use a 20x70 grid."<< endl;

	cout << "\nPlease enter the height of the grid (up to 22): ";
	cin >> userH;

	cout << "Please enter the width of the grid (up to 80): ";
	cin >> userW;

	theCell game(userH, userW);

	game.pickChoice();

	game.initGrid();

	// allow user to iterate through generations to view changes
	do{
		cout << endl << endl;

		cout << "Would you like to advance to the next generation?\n"
			 << "Please enter Y/N: ";
		cin >> choice;

		game.initGrid();

		game.copyFunc();

	}while(choice == 'Y' || choice == 'y');

	return 0;
}