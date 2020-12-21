//---------------------------------------------------
// Purpose:     Implementation of the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              YOUR NAME - Completed implementation.
//---------------------------------------------------

#include "tic4.h"
#include <cstdlib>
#include <time.h>

//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Tic4::Tic4()
{
	ClearBoard();
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Tic4::~Tic4()
{
	// Intentionally empty
}

//---------------------------------------------------
// Clear the Tic4 board
//---------------------------------------------------
void Tic4::ClearBoard()
{
	// Initialize Tic4 board
	for (int c = 0; c < SIZE; c++)
		for (int r = 0; r < SIZE; r++)
			board[r][c] = ' ';
	board_count = 0;
}

//---------------------------------------------------
// Set value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::SetBoard(const int row, const int col, const char player)
{
	// Error checking
	if ((row < 0) || (row >= SIZE) ||
		(col < 0) || (col >= SIZE) ||
		(board[row][col] != ' '))
		return false;

	// Set value of board
	board[row][col] = player;
	board_count++;
	return true;
}

//---------------------------------------------------
// Get value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::GetBoard(const int row, const int col, char& player)
{
	// Error checking
	if ((row < 0) || (row >= SIZE) ||
		(col < 0) || (col >= SIZE))
		return false;

	// Get value of board
	player = board[row][col];
	return true;
}

//---------------------------------------------------
// Check to see if player has won the game
//---------------------------------------------------
bool Tic4::CheckWin(const char player)
{
	// Check all the rows
	for (int r = 0; r < SIZE; r++)
	{
		// Count player pieces
		int count = 0;
		for (int c = 0; c < SIZE; c++)
			if (board[r][c] == player)
				count++;
		if (count == SIZE)
			return true;
	}

	// Check all the cols
	for (int c = 0; c < SIZE; c++)
	{
		// Count player pieces
		int count = 0;
		for (int r = 0; r < SIZE; r++)
			if (board[r][c] == player)
				count++;
		if (count == SIZE)
			return true;
	}

	// Check first diagonal
	int count = 0;
	for (int r = 0; r < SIZE; r++)
	{
		int c = r;
		if (board[r][c] == player)
			count++;
	}
	if (count == SIZE)
		return true;

	// Check second diagonal
	count = 0;
	for (int r = 0; r < SIZE; r++)
	{
		int c = SIZE - 1 - r;
		if (board[r][c] == player)
			count++;
	}
	if (count == SIZE)
		return true;

	// The player did not win
	return false;
}

//---------------------------------------------------
// Print the Tic4 board
//---------------------------------------------------
void Tic4::PrintBoard()
{
	// Draw column numbers
	cout << "\n     ";
	for (int c = 0; c < SIZE; c++)
		cout << c << "   ";
	cout << "\n";

	// Print the Tic4 board
	for (int r = 0; r < SIZE; r++)
	{
		// Draw dashed line
		cout << "   +";
		for (int c = 0; c < SIZE; c++)
			cout << "---+";
		cout << "\n";

		// Draw board contents
		cout << " " << r << " | ";
		for (int c = 0; c < SIZE; c++)
			cout << board[r][c] << " | ";
		cout << "\n";
	}

	// Draw dashed line
	cout << "   +";
	for (int c = 0; c < SIZE; c++)
		cout << "---+";
	cout << "\n\n";
}

//---------------------------------------------------
// Check if board is full
//---------------------------------------------------
bool Tic4::IsFull()
{
	return (board_count == SIZE * SIZE);
}

//---------------------------------------------------
// Simple AI that will place a character in the 
// first spot found, top to bottom or left to right
//---------------------------------------------------
bool Tic4::SimpleAI(const char player)
{

	// Check all the rows
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			if (board[r][c] == ' ')
				board[r][c] = 'O';
			return true;
		}
	}
	//Spot not found
	return false;
}

//---------------------------------------------------
// Random AI that randomly selects locations on the
// board and places it in the first one found
//---------------------------------------------------
bool Tic4::RandomAI(const char player)
{
	int row, column;
	for (int c = 0; c < SIZE; c++)
	{
		for (int r = 0; r < SIZE; r++)
		{
			do {
				row = rand() % 4;
				column = rand() % 4;
			}
				while (board[row][column] == 'X');
			if (board[row][column] == ' ')
				SetBoard(row, column, 'O');
			return true;
		}
	}
	//Spot not found
	return false;
}

//---------------------------------------------------
// Clever AI that searches the diagonals first,
// and then searches the non-diagonals locations
// to find an empty location to play a character
//---------------------------------------------------
bool Tic4::CleverAI(const char player)
{
	//Empty
	return true;
}

//---------------------------------------------------
// Fancy AI that selects either SimpleAI, RandomAI,
// or CleverAI to make it's move
//---------------------------------------------------
bool Tic4::FancyAI(const char player)
{
	//Empty
	return true;
}