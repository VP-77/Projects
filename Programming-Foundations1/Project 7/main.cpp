//---------------------------------------------------
// Purpose:     Main program for the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              YOUR NAME - Completed implementation.
//---------------------------------------------------

#include "tic4.h"
#include <cstdlib>

//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------
int main()
{

	Tic4 tic;
	char player;
	int row, column;

	cout << "Hello, and welcome to Tic-tac-toe! You will be playing against an AI in this game." << endl;
	cout << "You will be X's and the AI will be O's. You will be going first." << endl;

	tic.ClearBoard();
	tic.PrintBoard();

	cout << "You may input your first move when you are ready. Please make your move as 'row, column, X'" << endl;
	cout << "Your move: ";

	do {
		do {
			do
				cin >> row >> column >> player;
			while (player != 'X');
		} while ((tic.SetBoard(row, column, player) == false));

		//Print the board after the player's move
		tic.PrintBoard();

		//Testing SimpleAI
		tic.RandomAI(player);

		//Print the board after the AI's move
		tic.PrintBoard();


	} while ((tic.CheckWin('O') == false) && (tic.CheckWin('X') == false));

	return 0;
}