#include <iostream>
#include <string>
#include "structs.h"

//Allocate Memory for 2D Array + Insert Values at certain areas
//Coordinates to check for --> [1,1] [1,2] [1,3] [2,1] [2,2]
void Allocate2DArrayMemory_city(int xsize, int ysize,int** ptr);
void PopulateCity2DArray(int xsize, int ysize, vector<cityStructure> vect, int** ptr);
void Allocate2DArrayMemory_cp(int xsize, int ysize, int** ptr);
void PopulateCloudyPressure2DArray(int xsize, int ysize, vector<cloudyPressure>vect, int** ptr);
void DeAllocate2DArrayMemory(int** ptr, int x_size);


void Allocate2DArrayMemory_city(int xsize, int ysize,int** ptr)
{
	int i{ 0 }, j{ 0 }, k{ 0 };

	//allocate memory for pointer
	ptr = new int* [xsize];

	for (int i = 0; i < xsize; ++i)
	{
		ptr[i] = new int[ysize];
	}

	for (int x = 0; x < xsize; ++x)
	{
		for (int y = 0; y < ysize; ++y)
		{
			ptr[x][y] = 0;
		}
	}
}

void PopulateCity2DArray(int xsize, int ysize, vector<cityStructure> vect, int** ptr)
{
	int i{ 0 }, j{ 0 }, k{ 0 };
	//loop through the vector with the values
	//loop through vector(0 --> 8)
	while (i != vect.size())
	{
		//1 --> 8
		//example if j == 1 and value == 1;
		if (j == vect[i].coordinates.x)
		{
			//if k matches the coordinates of vect[i]
			if (k == vect[i].coordinates.y)
			{
				//insert value
				ptr[j][k] = vect[i].cityType;

				cout << "Match Found at: " << "[" << j << "," << k << "]" << " with value of: " << ptr[j][k] << endl;

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
}


//Allocate Memory for 2D Array + Insert Values at certain areas
//Coordinates to check for --> [0,0] [0,1] [1,3] [2,1] [2,2]
void Allocate2DArrayMemory_cp(int xsize, int ysize, int** ptr)
{
	int i = 0;

	//allocate memory for pointer
	ptr = new int* [xsize];


	//Allocate memory for the 2d Array
	for (int i = 0; i < xsize; ++i)
	{
		ptr[i] = new int[ysize];
	}

}

void PopulateCloudyPressure2DArray(int xsize, int ysize, vector<cloudyPressure>vect, int** ptr) 
{
	int i = 0;

	//populate with 0 first
	for (int x = 0; x < xsize; ++x)
	{
		for (int y = 0; y < ysize; ++y)
		{
			ptr[x][y] = 0;
		}
	}


	//loop through the vector with the values
	//loop through vector(0 --> 8)
	if (i != vect.size())
	{
		//1 --> 8
		//example if j == 1 and value == 1;
		for (int j = 0; j < xsize; ++j)
		{
			//for each j, incrmeent k
			for (int k = 0; k < ysize; ++k)
			{
				//insert value
				ptr[j][k] = vect[i].NextDayForecast;

				//cout << "Match Found at: " << "[" << j << "," << k << "]" << " with value of: " << ptr[j][k] << endl;

				//incrment i;
				++i;
			}
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

