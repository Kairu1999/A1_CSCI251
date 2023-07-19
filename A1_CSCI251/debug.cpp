#include <iostream>
#include <vector>
#include "Structs.h"

using namespace std;


//USE TO PRINT 2D ARRAY OF CITY
void print_2DArr_output_city(int row, int col, int** ptr)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << ptr[i][j] << endl;
		}
	}
}

//USE TO PRINT 2D ARRAY OF CLOUDCOVER AND PRESSURE
void print_2DArr_output_cp(int row, int col, int** ptr) 
{
	int rows{ 0 }, columns{ 0 };
	
	int** ptr1{};
	
	ptr1 = ptr;

	rows = row;
	columns = col;


	for (int i = 0; i <= rows; ++i) 
	{
		for (int j = 0; j <= columns; ++j) 
		{
			cout << ptr1[i][j] << endl;
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