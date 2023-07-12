#include <iostream>
#include <vector>

using namespace std;

void generate_grid(int** coordinates, vector<int> row_col)
{
	//row and columns to be used for array
	const int row{row_col[0]}, col{row_col[1]};

	//============================
	//allocate memory for 2d array
	//============================
	
	//allocate memory rows first
	int** temp = new int* [row];

	for (int i = 0; i < row; ++i) 
	{
		//allocate memory for columns
		temp[i] = new int[col];
	}

	//COMMENCE GRID GENERATION HERE!!


	//==============================
	//delete the memory for 2D array
	//==============================
	for (int i = 0; i < row; ++i) 
	{
		//1st --> Columns
		delete[] temp[i];
	}

	//delete row memory next
	delete[] temp;


}