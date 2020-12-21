#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Prints out the Englang flag to a ppm file
void flag_England(const int rows, const int columns)
{
	ofstream dout;
	dout.open("England.ppm");
	dout << "P3" << endl;
	dout << columns << " " << rows << endl;
	dout << "255 255 255 " << endl;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (abs(row - rows / 2) < (1 + rows / 10) || abs(col - columns / 2) < (1 + columns / 10))
				dout << " 0 255 0" << endl;
			else
				dout << " 255 255 255" << endl;
		}
		dout << endl;
	}
	dout.close();
}

//Prints out the Thailand flag to a ppm file
void flag_Thailand(const int rows, const int columns)
{
	ofstream dout;
	dout.open("Thailand.ppm");
	dout << "P3" << endl;
	dout << columns << " " << rows << endl;
	dout << "255 255 255 " << endl;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (abs(row - rows / 2) <= (1 + rows / 6))
				dout << " 255 0 0" << endl;
			else if (abs(row - rows / 2) < (1 + rows / 3) && abs(row - rows / 2) <= abs(1 + rows / 3))
				dout << " 255 255 255" << endl;
			else
				dout << " 0 255 0" << endl;
		}
		dout << endl;
	}
	dout.close();
}

//Prints out the France flag to a ppm file
void flag_France(const int rows, const int columns)
{
	ofstream dout;
	dout.open("France.ppm");
	dout << "P3" << endl;
	dout << columns << " " << rows << endl;
	dout << "255 255 255 " << endl;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (abs(col - columns / 2) <= (1 + columns / 6))
				dout << " 255 255 255" << endl;
			else if (abs(col - columns / 1) < (1 + columns / 3) || abs(col - columns / 1) <= abs(1 + columns / 3))
				dout << " 0 255 0" << endl;
			else
				dout << " 255 0 0" << endl;
		}
		dout << endl;
	}
	dout.close();
}

//Prints out the Russia flag to a ppm file
void flag_Russia(const int rows, const int columns)
{
	ofstream dout;
	dout.open("Russia.ppm");
	dout << "P3" << endl;
	dout << columns << " " << rows << endl;
	dout << "255 255 255 " << endl;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (abs(row - rows / 2) <= (1 + rows / 6))
				dout << " 255 0 0" << endl;
			else if (abs(row - rows / 1) < (1 + rows / 3) || abs(row - rows / 1) <= abs(1 + rows / 3))
				dout << " 0 255 0" << endl;
			else
				dout << " 255 255 255" << endl;
		}
		dout << endl;
	}
	dout.close();
}

//Prints out the Finland flag to a ppm file
void flag_Finland(const int rows, const int columns)
{
	ofstream dout;
	dout.open("Finland.ppm");
	dout << "P3" << endl;
	dout << columns << " " << rows << endl;
	dout << "255 255 255 " << endl;

	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (abs(row - rows / 2) < (1 + rows / 10) || abs(col - columns / 3) < (1 + columns / 10))
				dout << " 0 255 0" << endl;
			else
				dout << " 255 255 255" << endl;
		}
		dout << endl;
	}
	dout.close();
}


int main()
{

	int columns = 0, rows = 0; //Get width (columns) and height (rows) from user
	string userFlag = ""; //Get name of the country from the user
	string flagFrance = "France", flagThailand = "Thailand", flagRussia = "Russia"; //3 of the 5 supported flags
	string flagEngland = "England", flagFinland = "Finland"; //2 of the 5 supported flags- 5 total

	cout << "Hello! This program will print out one of five supported country flags to a .ppm file.\n";
	cout << "The supported countries are: France, Thailand, Russia, England, or Findland.\n";
	cout << "Which of the flags would you like to print out? ";

	cin >> userFlag;

	//If the user tries to pick an unsupported flag, they will be asked to pick one of the supported flags until they do
	if (!(userFlag == flagFrance || userFlag == flagThailand || userFlag == flagRussia || userFlag == flagEngland || userFlag == flagFinland))
	{
		do {
			cout << "That is not one of the supported countries.\n";
			cout << "Please choose one of the five supported countries: ";
			cin >> userFlag;
		} while (!(userFlag == flagFrance || userFlag == flagThailand || userFlag == flagRussia || userFlag == flagEngland || userFlag == flagFinland));
	}

	cout << "You have chosen " << userFlag << " as your flag to print." << endl;

	cout << "What is the height of your flag in pixels (limit of 1000): ";
	cin >> rows;

	//Checks to make sure the rows (height) is in the valid range
	if (rows > 1000 || rows < 100)
	{
		do {
			cout << "Please enter a value between 100 and 1000: ";
			cin >> rows;
		} while (rows > 1000 || rows < 100);
	}

	cout << "What is the width of your flag in pixels (limit of 1000): ";
	cin >> columns;

	//Checks to make sure the columns (width) is in the valid range
	if (columns > 1000 || columns < 100)
	{
		do {
			cout << "Please enter a value between 100 and 1000: ";
			cin >> columns;
		} while (columns > 1000 || columns < 100);
	}

	//Prints the flag that the user input
	if (userFlag == flagEngland)
	{
		flag_England(rows, columns);
	}

	if (userFlag == flagFrance)
	{
		flag_France(rows, columns);
	}

	if (userFlag == flagThailand)
	{
		flag_Thailand(rows, columns);
	}

	if (userFlag == flagRussia)
	{
		flag_Russia(rows, columns);
	}

	if (userFlag == flagFinland)
	{
		flag_Finland(rows, columns);
	}

	cout << "Your flag " << userFlag << " was output to " << userFlag << ".ppm. Thank you!"

	return 0;
}