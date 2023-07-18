#include <iostream>
#include <string>
#include "structs.h"

//Allocate Memory for 2D Array + Insert Values at certain areas
//Coordinates to check for --> [1,1] [1,2] [1,3] [2,1] [2,2]

int** Allocate2DArrayMemory_city(int xsize, int ysize, vector<cityStructure> vect);
int** Allocate2DArrayMemory_cp(int xsize, int ysize, vector<cloudyPressure> vect);


int** Allocate2DArrayMemory_city(int xsize, int ysize, vector<cityStructure> vect)
{
	int i{ 0 }, j{ 1 }, k{ 1 };

	//allocate memory for pointer
	int** ptr = new int* [xsize];

	for (int i = 0; i < xsize; ++i)
	{
		ptr[i] = new int[ysize];
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
			if (k = vect[i].coordinates.y)
			{			
				//insert value
				ptr[j][k] = vect[i].cityType;

				cout << "Match Found at: " << j << " " << k << "with value of: " << ptr[j][k] << endl;

				//set back j and k to the start and increment i to the next variable!
				j = 1;
				k = 1;
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
//Coordinates to check for --> [1,1] [1,2] [1,3] [2,1] [2,2]
int** Allocate2DArrayMemory_cp(int xsize, int ysize, vector<cloudyPressure> vect)
{
	int i{ 0 }, j{ 0 }, k{ 0 };

	//allocate memory for pointer
	int** ptr = new int* [xsize];


	for (int i = 0; i < xsize; ++i)
	{
		ptr[i] = new int[ysize];
	}

	//loop through the vector with the values
	//loop through vector(0 --> 8)
	while (i != vect.size())
	{
		//1 --> 8
		//example if j == 1 and value == 1;
		if (j == vect[i].coordinates.x)
		{
			//if k matches the coordinates of vect[i]
			if (k = vect[i].coordinates.y)
			{
				//insert value
				ptr[j][k] = vect[i].NextDayForecast;

				cout << "Match Found at: " << j << " " << k << "with value of: " << ptr[j][k] << endl;

				//set back j and k to the start and increment i to the next variable!
				j = 1;
				k = 1;
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

//DeAllocate Memory for 2D Array
void DeAllocate2DArrayMemory(int** ptr, int x_size) 
{
	for (int i = 0; i < x_size; ++i) 
	{
		delete[] ptr[i];
	}

	delete[] ptr;
}


