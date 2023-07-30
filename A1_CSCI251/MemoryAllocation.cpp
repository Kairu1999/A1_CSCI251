#include <iostream>
#include <string>
#include "structs.h"

//Allocate Memory for 2D Array + Insert Values at certain areas
//Coordinates to check for --> [1,1] [1,2] [1,3] [2,1] [2,2]

int** Allocate2DArrayMemory_city(int xsize, int ysize, vector<cityStructure> vect);
int** Allocate2DArrayMemory_cp(int xsize, int ysize, vector<cloudyPressure> vect);
int Update2DArrayValues(int value, int mode);
void Update2DArray(int** ptr, int xsize, int ysize);
void DeAllocate2DArrayMemory(int** ptr, int x_size);


int** Allocate2DArrayMemory_city(int xsize, int ysize, vector<cityStructure> vect)
{

	//allocate memory for pointer
	int** ptr = new int* [ysize];

	//allocate memory for pointer
	for (int row = 0; row <= ysize; ++row)
	{
		ptr[row] = new int[xsize];
	}

	for (int x = 0; x <= ysize; ++x)
	{
		for (int y = 0; y <= xsize; ++y)
		{
			ptr[x][y] = -1;
		}
	}

	for (int i = 0; i < vect.size(); ++i)
	{
		for (int j = 0; j <= ysize; ++j)
		{
			for (int k = 0; k <= xsize; ++k)
			{
				if ((k == vect[i].coordinates.x) && (j == vect[i].coordinates.y))
				{
					ptr[j][k] = vect[i].cityType;
				}
			}
		}
	}

	return ptr;
}

//Allocate Memory for 2D Array + Insert Values at certain areas
//Coordinates to check for --> [0,0] [0,1] [1,3] [2,1] [2,2]
int** Allocate2DArrayMemory_cp(int xsize, int ysize, vector<cloudyPressure> vect)
{
	//allocate memory for pointer
	int** ptr = new int* [ysize];

	//allocate memory for pointer
	for (int row = 0; row <= ysize; ++row)
	{
		ptr[row] = new int[xsize];
	}

	//populate the array
	for (int x = 0; x <= ysize; ++x)
	{
		for (int y = 0; y <= xsize; ++y)
		{
			ptr[x][y] = -1;
		}
	}

	for (int j = 0; j <= ysize; ++j)
	{
		for (int k = 0; k <= xsize; ++k)
		{
			ptr[j][k] = vect[(k * (ysize + 1)) + j].NextDayForecast;

		}

	}


	return ptr;
}

//updates the values of the 2d array
int Update2DArrayValues(int value)
{
	int temp{ 0 };

	//insert value
	if ((value >= 0) && (value < 10))
	{
		value = 0;

	}
	if ((value >= 10) && (value < 20))
	{
		value = 1;
	}
	if ((value >= 20) && (value < 30))
	{
		value = 2;

	}
	if ((value >= 30) && (value < 40))
	{
		value = 3;

	}
	if ((value >= 40) && (value < 50))
	{
		value = 4;

	}
	if ((value >= 50) && (value < 60))
	{
		value = 5;
	}
	if ((value >= 60) && (value < 70))
	{
		value = 6;

	}
	if ((value >= 70) && (value < 80))
	{
		value = 7;

	}
	if ((value >= 80) && (value < 90))
	{
		value = 8;

	}
	if ((value >= 90) && (value < 100))
	{
		value = 9;
	}

	return value;
}
int Update2DArrayValuesLMH(int value)
{
	int temp{ 0 };

	if ((value >= 0) && (value < 35))
	{
		temp = 'L';
	}
	if ((value >= 35) && (value < 65))
	{
		temp = 'M';
	}
	if ((value >= 65) && (value < 100))
	{
		temp = 'H';
	}

	return temp;
}

//USED ONLY FOR CLOUDY AND PRESSURE.CPP
void Update2DArray(int** ptr, int xsize, int ysize, int mode)
{

	for (int i = 0; i <= (ysize); ++i)
	{
		for (int j = 0; j <= (xsize); ++j)
		{

			int xan{ 0 };

			switch (mode)
			{
			case 0:
				xan = Update2DArrayValues(ptr[i][j]);
				ptr[i][j] = xan;
				break;
			case 1:
				xan = Update2DArrayValuesLMH(ptr[i][j]);
				ptr[i][j] = xan;
				break;
			}

		}
	}
}

//DeAllocate Memory for 2D Array
void DeAllocate2DArrayMemory(int** ptr, int x_size, int y_size)
{
	if (y_size == 0) {
		return;
	}

	//allocate memory for pointer
	for (int row = 0; row <= x_size; ++row)
	{
		delete ptr[row];
	}


	delete[] ptr;
}


