//---------------------------------------------------
// Purpose: Example with very long main program (bad design)
// Author:  John Gauch 
//---------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			if (col < (columns * (1 / 3)))
				cout << "*" << endl;
			else if (col > (columns * (1 / 3)) && col < (columns * (2 / 3)))
				cout << "&" << endl;
			else if (col > columns* (2 / 3))
				cout << "@" << endl;
		}
		cout << endl;
	}
	return 0;
}