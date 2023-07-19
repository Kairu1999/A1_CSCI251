#include <iostream>
#include <vector>
#include "Structs.h"

using namespace std;


//print output of 2D array
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


//Test the output of cloudyPressure vector
void print_vector_output(vector<cloudyPressure> cld) 
{
	for (int i = 0; i < cld.size(); ++i) 
	{
		cout << cld[i].coordinates.x << " " << cld[i].coordinates.y << " " << cld[i].NextDayForecast << endl;
	}
}