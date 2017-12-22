// Osbaldo Esquivel
// CS 225
// 15JAN2014

#include <iostream>
#include "theCell.h"

using std::cout;
using std::cin;
using std::endl;

/*****************************************************************
 *            this function sets the height and width            *
 *                         of the array                          *
 ****************************************************************/

theCell::theCell(int r, int s)
{
	h = r;
	w = s;
}

/*****************************************************************
 *            this function allows the user to select            *
 *                 a preset configuration to view                *
 ****************************************************************/

void theCell::pickChoice()
{
	int config; // store user config choice

	cout << "\n\nChoose a starting configuration from below: \n"
		 << "\t1. Glider Gun\n"
		 << "\t2. Oscillators\n"
		 << "\t3. Gliders\n"
		 << "Please enter your choice: ";
	cin >> config;

	// set array elements to false
	for(int x = 0; x < h; x++)
	{
		for(int y = 0; y < w; y++)
		{
			map[x][y] = false;
		}
	}

	// set different configurations
	switch(config)
	{
		case 1: map[6][2] = true; // glider gun
				map[6][3] = true;
				map[7][2] = true;
				map[7][3] = true;
				map[4][14] = true;
				map[4][15] = true;
				map[5][13] = true;
				map[5][17] = true;
				map[6][12] = true;
				map[6][18] = true;
				map[7][12] = true;
				map[7][16] = true;
				map[7][18] = true;
				map[7][19] = true;
				map[8][12] = true;
				map[8][18] = true;
				map[9][13] = true;
				map[9][17] = true;
				map[10][14] = true;
				map[10][15] = true;
				map[2][26] = true;
				map[3][24] = true;
				map[3][26] = true;
				map[4][22] = true;
				map[4][23] = true;
				map[5][22] = true;
				map[5][23] = true;
				map[6][22] = true;
				map[6][23] = true;
				map[7][24] = true;
				map[7][26] = true;
				map[8][26] = true;
				map[4][36] = true;
				map[4][37] = true;
				map[5][36] = true;
				map[5][37] = true;
				break;
		case 2: map[2][3] = true; // blinker
				map[3][3] = true;
				map[4][3] = true;
				map[7][3] = true; //toad
				map[7][4] = true;
				map[7][5] = true;
				map[8][2] = true;
				map[8][3] = true;
				map[8][4] = true;
				map[12][2] = true; // beacon
				map[12][3] = true;
				map[13][2] = true;
				map[13][3] = true;
				map[14][4] = true;
				map[14][5] = true;
				map[15][4] = true;
				map[15][5] = true; 
				map[13][3] = true;
				map[2][17] = true; // pulsar
				map[2][23] = true;
				map[3][17] = true;
				map[3][23] = true;
				map[4][17] = true;
				map[4][18] = true;
				map[4][22] = true;
				map[4][23] = true;
				map[6][13] = true;
				map[6][14] = true;
				map[6][15] = true;
				map[6][18] = true;
				map[6][19] = true;
				map[6][21] = true;
				map[6][22] = true;
				map[6][25] = true;
				map[6][26] = true;
				map[6][27] = true;
				map[7][15] = true;
				map[7][17] = true;
				map[7][19] = true;
				map[7][21] = true;
				map[7][23] = true;
				map[7][25] = true;
				map[8][17] = true;
				map[8][18] = true;
				map[8][22] = true;
				map[8][23] = true;
				map[10][17] = true;
				map[10][18] = true;
				map[10][22] = true;
				map[10][23] = true;
				map[11][15] = true;
				map[11][17] = true;
				map[11][19] = true;
				map[11][21] = true;
				map[11][23] = true;
				map[11][25] = true;
				map[12][13] = true;
				map[12][14] = true;
				map[12][15] = true;
				map[12][18] = true;
				map[12][19] = true;
				map[12][21] = true;
				map[12][22] = true;
				map[12][25] = true;
				map[12][26] = true;
				map[12][27] = true;
				map[14][17] = true;
				map[14][18] = true;
				map[14][22] = true;
				map[14][23] = true;
				map[15][17] = true;
				map[15][23] = true;
				map[16][17] = true;
				map[16][23] = true;
				break;
		case 3: map[2][4] = true; // glider
				map[3][5] = true;
				map[4][3] = true;
				map[4][4] = true;
				map[4][5] = true;
				map[2][11] = true; // spaceship glider
				map[2][14] = true;
				map[3][15] = true;
				map[4][11] = true;
				map[4][15] = true;
				map[5][12] = true;
				map[5][13] = true;
				map[5][14] = true;
				map[5][15] = true;
				break;
		default: cout << "That is not a valid choice." << endl;
				break;
	}
}

/*****************************************************************
 *            this function initializes the grid                 *
 *                and displays it to the user                    *
 ****************************************************************/

void theCell::initGrid()
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(map[i][j] == true)
			{
				cout << "0";
			}
			else
			{
				cout << "-";
			}

			// make sure the grid does not extend outside of window
			if((j + 1) >= w)
			{
				cout << endl;
			}
		}
	}
}

/*****************************************************************
 *            this function computes the live/dead               *
 *              cells and copies the temp grid to                *
 *                 the initial grid to display                   *
 ****************************************************************/

void theCell::copyFunc()
{
	int neighAdj = 0;

	for(int ii = 0; ii < h; ii++)
	{
		for(int jj = 0; jj < w; jj++)
		{
			if(map[ii - 1][jj -1] == true 
				&& (ii - 1) >= 0 && (jj - 1) >= 0)
				neighAdj++;
			if(map[ii][jj - 1] == true 
				&& (jj - 1) >= 0)
				neighAdj++;
			if(map[ii + 1][jj - 1] == true 
				&& (ii + 1) < h && (jj - 1) < w)
				neighAdj++;
			if(map[ii - 1][jj] == true 
				&& (ii - 1) >= 0)
				neighAdj++;
			if(map[ii + 1][jj] == true 
				&& (ii + 1) < h)
				neighAdj++;;
			if(map[ii - 1][jj + 1] == true 
				&& (ii - 1) >= 0 && (jj + 1) < w)
				neighAdj++;
			if(map[ii][jj + 1] == true 
				&& (jj + 1) < h)
				neighAdj++;
			if(map[ii + 1][jj + 1] == true 
				&& (ii + 1) < h && (jj + 1) < w)
				neighAdj++;

			// set the value of coordinates depending on rules of the game
			if(neighAdj == 0 || neighAdj == 1)
				mapTemp[ii][jj] = false;
			else if(neighAdj > 3)
				mapTemp[ii][jj] = false;
			else if(neighAdj == 2)
				mapTemp[ii][jj] = map[ii][jj];
			else if(neighAdj == 3)
				mapTemp[ii][jj] = true;

			neighAdj = 0; //reset value of neighboring cells

		}
	}

	// copy temp grid to initial grid
	for(int a = 0; a < h; a++)
	{
		for(int b = 0; b < w; b++)
		{
			map[a][b] = mapTemp[a][b];
		}
	}
}