#include <iostream>
#include <vector>

using namespace std;


void print_2DArr_output(int row, int col, int** ptr) 
{
	for (int i = 0; i < row; ++i) 
	{
		for (int j = 0; j < col; ++j) 
		{
			cout << ptr[i][j] << endl;
		}
	}
}