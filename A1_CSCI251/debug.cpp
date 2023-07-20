#include <iostream>
#include <vector>
#include "Structs.h"

using namespace std;

void print_2DArr_output_city(int row, int col, int** ptr)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "[" << i << "," << j << "]" << "-" << ptr[i][j] << " ";
			//cout << char(ptr[i][j]) << " ";
		}
		cout << endl;
	}
}


//USE TO PRINT 2D ARRAY OF CITY
void print_2DArr_output(int row, int col, int** ptr)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "[" << i << "," << j << "]" << "-" << ptr[i][j]  << " ";
			//cout << char(ptr[i][j]) << " ";
		}
		cout << endl;
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