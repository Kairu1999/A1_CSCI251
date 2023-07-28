#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void generate_grid_city(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with numbers!" << endl;
	//THIS IS THE TOP WALL
	for (int i = 0; i <= xsize + 2; ++i)
	{
		if (i == 0)
		{
			cout << "    #  ";
		}
		else
		{
			cout << "#  ";
		}
	}
	cout << endl;

	//THIS IS THE DATA
	for (int i = ysize; i >= 0; --i)
	{
		for (int j = 0; j <= xsize; ++j)
		{
			//for the left wall
			if (j == 0)
			{
				//i value + wall of #
				cout << " " << setw(2) << i << " #";
			}

			//print coordinates whether wall was printed or not
			if (coordinates[i][j] == -1)
			{
				//print the rest of the grid as blank if vector has -1 inside
				cout << "   ";
			}
			else
			{
				//if value exists, 2 space required
				cout << "  " << coordinates[i][j];
			}

			//print back wall
			if (j == xsize)
			{
				//print the back wall of the grid
				cout << "  #";
			}
		}
		cout << endl;
	}


	//This is for the bottom wall
	for (int j = 0; j < 2; j++)
	{

		for (int i = 0; i <= xsize; ++i)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					cout << "    #  ";
				}
				else if (i == xsize)
				{
					cout << "#  #  #";
				}
				else
				{
					cout << "#  ";
				}
			}
			if (j == 1)
			{
				if (i == 0)
				{
					cout << "       " << i << "  ";
				}
				else
				{
					cout << i << "  ";
				}
			}
		}
		cout << endl;
	}
}

void generate_grid(int** coordinates, int xsize, int ysize)
{

	cout << "Generating grid with numbers!" << endl;
	//THIS IS THE TOP WALL
	for (int i = 0; i <= xsize + 2; ++i)
	{
		if (i == 0)
		{
			cout << "    #  ";
		}
		else
		{
			cout << "#  ";
		}
	}
	cout << endl;

	//THIS IS THE DATA
	for (int i = ysize; i >= 0; --i)
	{
		for (int j = 0; j <= xsize; ++j)
		{
			//for the left wall
			if (j == 0)
			{
				//i value + wall of #
				cout << " " << setw(2) << i << " #";
			}

			//print coordinates whether wall was printed or not
			if (coordinates[i][j] == -1)
			{
				//print the rest of the grid as blank if vector has -1 inside
				cout << "   ";
			}
			else
			{
				//if value exists, 2 space required
				cout << "  " << coordinates[i][j];
			}

			//print back wall
			if (j == xsize)
			{
				//print the back wall of the grid
				cout << "  #";
			}
		}
		cout << endl;
	}


	//This is for the bottom wall
	for (int j = 0; j < 2; j++)
	{

		for (int i = 0; i <= xsize; ++i)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					cout << "    #  ";
				}
				else if (i == xsize)
				{
					cout << "#  #  #";
				}
				else
				{
					cout << "#  ";
				}
			}
			if (j == 1)
			{
				if (i == 0)
				{
					cout << "       " << i << "  ";
				}
				else
				{
					cout << i << "  ";
				}
			}
		}
		cout << endl;
	}
}

void generate_gridLMH(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with numbers!" << endl;
	//THIS IS THE TOP WALL
	for (int i = 0; i <= xsize + 2; ++i)
	{
		if (i == 0)
		{
			cout << "    #  ";
		}
		else
		{
			cout << "#  ";
		}
	}
	cout << endl;

	//THIS IS THE DATA
	for (int i = ysize; i >= 0; --i)
	{
		for (int j = 0; j <= xsize; ++j)
		{
			//for the left wall
			if (j == 0)
			{
				//i value + wall of #
				cout << " " << setw(2) << i << " #";
			}

			//print coordinates whether wall was printed or not
			if (coordinates[i][j] == -1)
			{
				//print the rest of the grid as blank if vector has -1 inside
				cout << "   ";
			}
			else
			{
				//if value exists, 2 space required
				cout << "  " << static_cast<char>(coordinates[i][j]);
			}

			//print back wall
			if (j == xsize)
			{
				//print the back wall of the grid
				cout << "  #";
			}
		}
		cout << endl;
	}


	//This is for the bottom wall
	for (int j = 0; j < 2; j++)
	{

		for (int i = 0; i <= xsize; ++i)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					cout << "    #  ";
				}
				else if (i == xsize)
				{
					cout << "#  #  #";
				}
				else
				{
					cout << "#  ";
				}
			}
			if (j == 1)
			{
				if (i == 0)
				{
					cout << "       " << i << "  ";
				}
				else
				{
					cout << i << "  ";
				}
			}
		}
		cout << endl;
	}
}