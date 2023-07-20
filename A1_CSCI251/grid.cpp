#include <iostream>
#include <vector>

using namespace std;

void generate_grid(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with numbers!" << endl;

		//THIS IS FOR THE BOX
		for (int row = 0; row < xsize; row++)
		{
			for (int col = 0; col < ysize; col++)
			{
				//if ((row == 0) || (col == 0))

				//for up and down lines
				if (row == 0 || (row = xsize - 1))

				//for left and right lines
				if (col == 0 || (col = ysize - 1))



				//if ((row == 0) || row == xsize - 1 || (col == 0) || col == ysize - 1)
				{
					cout << "#";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}

	//TEST PRINTED VALUES
	//for (int i = 0; i < xsize; ++i)
	//{
	//	for (int j = 0; j < ysize; ++j)
	//	{
	//		cout << coordinates[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}