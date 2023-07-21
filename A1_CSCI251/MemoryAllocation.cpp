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
	int i{ 0 }, j{ 0 }, k{ 0 };

	//allocate memory for pointer
	int** ptr = new int* [xsize];

	//allocate memory for pointer
	for (int i = 0; i <= xsize; ++i)
	{
		ptr[i] = new int[ysize];
	}

	for (int x = 0; x <= xsize; ++x)
	{
		for (int y = 0; y <= ysize; ++y)
		{
			ptr[x][y] = -1;
		}
	}

	//loop through the vector with the values
	//loop through vector(0 --> 8)
	while(i != vect.size())
	{
		//1 --> 8
		//example if j == 1 and value == 1;
		if (j == vect[i].coordinates.x)
		{
			//if k matches the coordinates of vect[i]
			if (k == vect[i].coordinates.y)
			{			
				//insert value
				ptr[xsize - k][j] = vect[i].cityType;

				//cout << "Match Found at: " << "[" << j << "," << k <<"]" << " with value of: " << ptr[j][k] << endl;

				//set back j and k to the start and increment i to the next variable!
				j = 0;
				k = 0;
				++i;

			}
			else 
			{
				//increment k
				++k;
			}
		}
		else
		{
			//increment j
			++j;
		}

	}
	return ptr;
}

//Allocate Memory for 2D Array + Insert Values at certain areas
//Coordinates to check for --> [0,0] [0,1] [1,3] [2,1] [2,2]
int** Allocate2DArrayMemory_cp(int xsize, int ysize, vector<cloudyPressure> vect)
{
	int i = 0;

	//allocate memory for pointer
	int** ptr = new int* [xsize];


	//Allocate memory for the 2d Array, +1 because 0 --> 8
	for (int i = 0; i <= xsize; i++)
	{
		//cout <<"y value: " << i << endl;
		ptr[i] = new int[ysize];
	}

	//populate with 0 first
	for (int x = 0; x <= xsize; ++x)
	{
		for (int y = 0; y <= ysize; ++y)
		{
			ptr[x][y] = -1;
			//cout << "[" << x << "," << y << "]" << endl;
		}
	}


	//loop through the vector with the values

	//1 --> 8
	//example if j == 1 and value == 1;
	for (int j = 0; j <= (xsize); ++j)
	{
		//for each j, incrmeent k
		for (int k = 0; k <= (ysize); ++k)
		{
			//THIS LINE WORKS GODDAMIT
			ptr[xsize - k][j] = vect[i].NextDayForecast;

			//cout << "x" << k << " y" << (xsize - j) << endl;
			//cout << "Match Found at: " << "[" << j << "," << k << "]" << " with value of: " << ptr[j][k] << endl;

			//incrment i;
			++i;
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
	int temp{0};

	if ((value >= 0) && (value < 35))
	{
		temp = 'L';
	}
	if ((value >= 35) && (value < 65))
	{
		temp = 'M';
	}
	if((value >= 65) && (value < 100))
	{
		temp = 'H';
	}
	
	return temp;
}

//USED ONLY FOR CLOUDY AND PRESSURE.CPP
void Update2DArray(int** ptr, int xsize, int ysize, int mode) 
{
	for (int i = 0; i <= (xsize); ++i) 
	{
		for (int j = 0; j <= (ysize); ++j)
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

			//cout << "Old Value: " << ptr[i][j] << " replaced by: " << static_cast<char>(xan) << endl;

		}
	}
}

//DeAllocate Memory for 2D Array
void DeAllocate2DArrayMemory(int** ptr, int x_size) 
{
	for (int i = 0; i < x_size; ++i) 
	{
		delete[] ptr[i];
	}

	delete[] ptr;
}


