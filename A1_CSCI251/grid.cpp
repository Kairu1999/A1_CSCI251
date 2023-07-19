#include <iostream>
#include <vector>

using namespace std;

void generate_grid(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with numbers!" << endl;

		//THIS IS FOR THE BOX
	/*	for (int row = 0; row < rect_breadth; row++)
		{
			for (int col = 0; col < rect_length; col++)
			{
				if ((row == 0) || row == rect_breadth - 1 || (col == 0) || (col == rect_length - 1))
				{
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}*/


	for (int i = 0; i < xsize; ++i)
	{
		for (int j = 0; j < ysize; ++j)
		{
			cout << coordinates[i][j] << " ";
		}
		cout << endl;
	}
}