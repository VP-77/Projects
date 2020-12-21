#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void flag_Sweden(const int rows, const int columns)
{
	cout << "P3" << endl;
	cout << rows << " " << columns << endl;
	cout << "255 255 255" << endl;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (abs(row - rows / 2) < (1 + rows / 10) || abs(col - columns / 2) < (1 + columns / 10))
				cout << "*";
			else
				cout << ".";
		}
		cout << endl;
	}
}

void flag_France(const int rows, const int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if ((row %= 0) || (col %= 0))
				cout << "*";
			else
				cout << ".";
		}
		cout << endl;
	}
}

int main() 
{

	int columns = 0, rows = 0; //Get width (columns) and height (rows) from user
	string userFlag = ""; //Get name of the country from the user
	string flagFrance = "France", flagGermany = "Germany", flagRussia = "Russia"; //3 of the 5 supported flags
	string flagSweden = "Sweden", flagDenmark = "Denmark"; //2 of the 5 supported flags- 5 total

	cout << "Hello! This program will print out one of five supported country flags to a .ppm file.\n";
	cout << "The supported countries are: France, Germany, Russia, Switzerland, and Denmark\n";
	cout << "Which of the flags would you like to print out? ";
	
	cin >> userFlag;

	if (!(userFlag == flagFrance || userFlag == flagGermany || userFlag == flagRussia || userFlag == flagSweden || userFlag == flagDenmark))
	{
		do {
			cout << "That is not one of the supported countries.\n";
			cout << "Please choose one of the five supported countries: ";
			cin >> userFlag;
		} while (!(userFlag == flagFrance || userFlag == flagGermany || userFlag == flagRussia || userFlag == flagSweden || userFlag == flagDenmark));
	}

	cout << "You have chosen " << userFlag << " as your flag to print." << endl;

	cout << "What is the height of your flag in pixels (limit of 1000): ";
	cin >> rows;

	if (rows > 1000 || rows < 100)
	{
		do {
			cout << "Please enter a value between 100 and 1000: ";
			cin >> rows;
		} while (rows > 1000 || rows < 100);
	}

	cout << "What is the width of your flag in pixels: ";
	cin >> columns;

	if (columns > 1000 || columns < 100)
	{
		do {
			cout << "Please enter a value between 100 and 1000: ";
			cin >> columns;
		} while (columns > 1000 || columns < 100);
	}
	
	if (userFlag == flagSweden)
	{
		flag_Sweden(rows, columns);
	}

	if (userFlag == flagFrance)
	{
		flag_France(rows, columns);
	}

	return 0;
}