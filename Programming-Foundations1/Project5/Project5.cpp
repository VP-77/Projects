//---------------------------------------------------------------------------
// Purpose:  To simulate the lives of rabbits and foxes in the forest.
//
// Author:   John Gauch - Created skeleton program.
// Author:   Riley Nadwodny - Completed implementation.
//
// Change:   Fixed animal loss bug in move_board function -- 11/03 JMG
// Change:   Fixed infinite loop bug in choose_move function -- 11/03 JMG
// Change:   Removed second board from main function -- 11/03 JMG
// Change:   Printed animal counts in draw_board -- 11/03 JMG
//---------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <random>
using namespace std;

// Global Variables
const int SIZE = 20;

//---------------------------------------------------------------------------
// Purpose: To initialize the board with rabbits and foxes.
// Inputs:  The board, the number of rabbits, the number of foxes.
// Outputs: None
//---------------------------------------------------------------------------
void init_board(char board[SIZE][SIZE],
	const int num_rabbits, const int num_foxes)
{
	// Init board
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
			board[r][c] = ' ';

	// Add rabbits at random locations
	int count = 0;
	while (count < num_rabbits)
	{
		int r = rand() % SIZE;
		int c = rand() % SIZE;
		if (board[r][c] == ' ')
		{
			board[r][c] = 'R';
			count++;
		}
	}

	// Add foxes at random locations
	count = 0;
	while (count < num_foxes)
	{
		int r = rand() % SIZE;
		int c = rand() % SIZE;
		if (board[r][c] == ' ')
		{
			board[r][c] = 'F';
			count++;
		}
	}
}

//---------------------------------------------------------------------------
// Purpose: To draw the board with rabbits and foxes.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void draw_board(char board[SIZE][SIZE])
{
	//system("sleep 1");
	//system("clear");

	// Initialize animal counts
	int num_rabbits = 0;
	int num_foxes = 0;

	// Draw top of board
	cout << "+";
	for (int c = 0; c < SIZE; c++)
		cout << "--";
	cout << "+\n";

	// Draw board
	for (int r = 0; r < SIZE; r++)
	{
		cout << "|";
		for (int c = 0; c < SIZE; c++)
		{
			cout << board[r][c] << " ";

			// Increment animal counts
			if (board[r][c] == 'R')
				num_rabbits++;
			if (board[r][c] == 'F')
				num_foxes++;
		}
		cout << "|\n";
	}

	// Draw bottom of the board
	cout << "+";
	for (int c = 0; c < SIZE; c++)
		cout << "--";
	cout << "+\n";

	// Print animal counts
	cout << "Number of rabbits: " << num_rabbits << endl;
	cout << "Number of foxes:   " << num_foxes << endl;
}

//---------------------------------------------------------------------------
// Purpose: To choose a random direction to move.
// Inputs:  The board and the current row and column location.
// Outputs: The new row and column location on the board.
//---------------------------------------------------------------------------
void choose_move(char board[SIZE][SIZE],
	const int row, const int col, int& new_row, int& new_col)
{
	// Loop until a valid move is found
	for (int loop = 0; loop < 10; loop++)
	{
		// Take a random step to adjacent location
		new_row = row + (rand() % 3) - 1;
		new_col = col + (rand() % 3) - 1;

		// Check if location is in bounds and board is empty
		if ((new_row >= 0) && (new_row < SIZE) &&
			(new_col >= 0) && (new_col < SIZE) &&
			(board[new_row][new_col] == ' '))
			return;
	}

	// Use current location if other move is possible
	new_row = row;
	new_col = col;
}

//---------------------------------------------------------------------------
// Purpose: To move the rabbits and foxes on the board.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void move_animals(char board[SIZE][SIZE])
{
	// Loop over board to find and move animals
	int new_row = 0;
	int new_col = 0;
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
			if (isupper(board[r][c]))
			{
				// Find empty location for move
				choose_move(board, r, c, new_row, new_col);

				// Move animal into empty location
				board[new_row][new_col] = tolower(board[r][c]);

				// Make old location empty
				if ((new_row != r) || (new_col != c))
					board[r][c] = ' ';
			}

	// Loop over board to change letters to upper case
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
			board[r][c] = toupper(board[r][c]);
}

//---------------------------------------------------------------------------
// Purpose: To reproduce adjacent foxes and rabbits on the board.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void reproduce_animals(char board[SIZE][SIZE])
{
	// Loop over board to find adjacent rabbits and reproduce
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
		{
			if (((board[r][c]) == 'R' && (board[r][c + 1]) == 'R') && (c+1 < SIZE))
			{
				int r = rand() % SIZE;
				int c = rand() % SIZE;
				if (board[r][c] == ' ')
				{
					board[r][c] = 'R';
				}
			}
		}

	// Loop over board to find adjacent foxes and reproduce
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
		{
			if (((board[r][c]) == 'F' && (board[r + 1][c]) == 'F') && (r + 1 < SIZE))
			{
				int chance = (rand() % 2);
				if (chance == 1)
				{
					int r = rand() % SIZE;
					int c = rand() % SIZE;
					if (board[r][c] == ' ')
					{
						board[r][c] = 'F';
					}
				}
			}
		}
}

//---------------------------------------------------------------------------
// Purpose: To simulate fox and rabbit battles on the board.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void animal_battles(char board[SIZE][SIZE])
{
	// Loop over board to find adjacent foxes and reproduce
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
		{
			if ((r + 1 < SIZE) && (c + 1 < SIZE))
			{
				if (((board[r][c]) == 'F' && (board[r + 1][c]) == 'R') || ((board[r][c]) == 'F' && (board[r][c + 1]) == 'R') || ((board[r][c]) == 'F' && (board[r - 1][c]) == 'R') || ((board[r][c]) == 'F' && (board[r][c - 1]) == 'R'))
				{
					int chance = ((rand() % 10));
					if (chance == 1)
					{
						int r = rand() % SIZE;
						int c = rand() % SIZE;
						if (board[r][c] == 'R')
						{
							board[r][c] = ' ';
						}
					}
				}
			}
		}
}

//---------------------------------------------------------------------------
// Purpose: The main program.
// Inputs:  None.
// Outputs: None.
//---------------------------------------------------------------------------
int main()
{
	// Seed the random number generator
	srand(time(NULL));

	// Prompt user
	cout << "Welcome to the fox and rabbit simulation\n\n";
	int num_rabbits = 0;
	cout << "Enter the number of rabbits: ";
	cin >> num_rabbits;
	int num_foxes = 0;
	cout << "Enter the number of foxes: ";
	cin >> num_foxes;
	int num_steps = 0;
	cout << "Enter the number of simulation steps: ";
	cin >> num_steps;

	// Initialize board
	char board[SIZE][SIZE];
	init_board(board, num_rabbits, num_foxes);

	// Draw the board
	draw_board(board);
	cout << "Start " << endl;

	// Run the simulation
	for (int step = 1; step <= num_steps; step++)
	{
		// Move the animals
		move_animals(board);

		// Foxes and rabbits reproduce
		reproduce_animals(board);

		//Simulate fox-rabbit battles
		animal_battles(board);

		// Draw the board
		draw_board(board);
		cout << "Step " << step << endl;
	}
	return 0;
}