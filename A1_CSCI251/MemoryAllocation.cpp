#include <iostream>
#include <string>
#include "structs.h"

//Allocate Memory for 2D Array
int** Allocate2DArrayMemory(int xsize, int ysize) 
{
	int** ptr = new int* [xsize];

	for (int i = 0; i < xsize; ++i) 
	{
		ptr[i] = new int[ysize];
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