#include <iostream>
#include <vector>

using namespace std;

void generate_grid_city(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with numbers!" << endl;

	////THIS IS FOR THE BOX
	//for (int row = 0; row < xsize; row++)
	//{
	//	for (int col = 0; col < ysize; col++)
	//	{
	//		//for up and down lines
	//		if ((row == 0) || (row = xsize - 1)) 
	//		{
	//			cout << "# ";
	//		}

	//		//for left and right lines
	//		else if ((col == 0) || (col = ysize - 1)) {
	//			cout << "#";
	//		}
	//		else {
	//			cout << " ";
	//		}
	//	}
	//	cout << endl;
	//}

//TEST PRINTED VALUES
	for (int i = 0; i <= xsize; ++i)
	{
		for (int j = 0; j <= ysize; ++j)
		{
			if (coordinates[i][j] == 0) 
			{
				cout << " ";
			}
			else 
			{
				cout << coordinates[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void generate_grid(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with numbers!" << endl;

		////THIS IS FOR THE BOX
		//for (int row = 0; row < xsize; row++)
		//{
		//	for (int col = 0; col < ysize; col++)
		//	{
		//		//for up and down lines
		//		if ((row == 0) || (row = xsize - 1)) 
		//		{
		//			cout << "# ";
		//		}

		//		//for left and right lines
		//		else if ((col == 0) || (col = ysize - 1)) {
		//			cout << "#";
		//		}
		//		else {
		//			cout << " ";
		//		}
		//	}
		//	cout << endl;
		//}

	//TEST PRINTED VALUES
	for (int i = 0; i <= xsize; ++i)
	{
		for (int j = 0; j <= ysize; ++j)
		{
			cout << coordinates[i][j] << " ";
		}
		cout << endl;
	}
}

void generate_gridLMH(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with LMH Values: " << endl;
	cout << endl;

	////THIS IS FOR THE BOX
	//for (int row = 0; row < xsize; row++)
	//{
	//	for (int col = 0; col < ysize; col++)
	//	{
	//		//for up and down lines
	//		if ((row == 0) || (row = xsize - 1)) 
	//		{
	//			cout << "# ";
	//		}

	//		//for left and right lines
	//		else if ((col == 0) || (col = ysize - 1)) {
	//			cout << "#";
	//		}
	//		else {
	//			cout << " ";
	//		}
	//	}
	//	cout << endl;
	//}

//TEST PRINTED VALUES
	for (int i = 0; i <= xsize; ++i)
	{
		for (int j = 0; j <= ysize; ++j)
		{
			cout << static_cast<char>(coordinates[i][j]) << " ";
		}
		cout << endl;
	}
}