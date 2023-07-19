#include <iostream>
#include <vector>

using namespace std;

void generate_grid(int** coordinates, vector<int> row_col, int mode)
{
	//row and columns to be used for array
	const int rect_length{ row_col[0] }, rect_breadth{ row_col[1] };


	/*==================================
	= (2) generate the grid from mode  =
	==================================*/
	switch (mode)
	{
		//generate grid with numbers
	case 0:
		cout << "Generating grid with numbers!" << endl;

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
		for (int i = 0; i < rect_length; ++i)
		{
			for (int j = 0; i < rect_breadth; ++j)
			{
				if (coordinates[i][j] == 0) {
					cout << " ";
				}
				else
				{
					cout << coordinates[i][j] << ", ";
				}
			}
			cout << endl;
		}

		cout << endl;
		break;
		//generate grid with LMH values
	case 1:
		cout << "Generating grid with LMH Values! in a " << rect_length << " by " << rect_breadth << " grid!" << endl;


		//for (int row = 0; row < rect_breadth; row++)
		//{
		//	for (int col = 0; col < rect_length; col++)
		//	{
		//		if ((row == 0) || row == rect_breadth - 1 || (col == 0) || (col == rect_length - 1))
		//		{
		//			cout << "#";
		//		}
		//		else {
		//			cout << " ";
		//		}
		//	}
		//	cout << endl;
		//}

		for (int i = 0; i < rect_length; ++i) 
		{
			for (int j = 0; i < rect_breadth; ++j) 
			{
				if (coordinates[i][j] == 0) {
					cout << " ";
				}
				else 
				{
					cout << coordinates[i][j] << ", ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
}