#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void generate_grid_city(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with numbers!" << endl;

	//THIS IS THE TOP WALL
	for (int i = 0; i <= ysize+2; ++i)
	{
		if (i == 0)
		{
			cout << " #  ";
		}
		else
		{
			cout << "#  ";
		}
	}
	cout << endl;

	//THIS IS THE DATA
	for (int i = 0; i <= ysize; ++i) 
	{
		for (int j = 0; j <= xsize; ++j)
		{
			//for the left wall
			if (j == 0) 
			{
				//i value + wall of #
				cout << (ysize - i) << "# ";
			}

			//print coordinates whether wall was printed or not
			if (coordinates[i][j] == -1)
			{
				//print the rest of the grid as blank if vector has -1 inside
				cout << "  ";
			}
			else
			{
				cout << coordinates[i][j] << " ";
			}

			//print back wall
			if (j == xsize) 
			{
				//print the back wall of the grid
				cout << "#";
			}
		}
		cout << endl;
	}


	//This is for the bottom wall
	for (int j = 0; j < 2; j++) 
	{

		for (int i = 0; i <= ysize; ++i)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					cout << " #  ";
				}
				else if (i == ysize) 
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
					cout << "   " << i << "  ";
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

	//THIS IS THE TOP WALL
	for (int i = 0; i <= ysize + 2; ++i)
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
	for (int i = 0; i <= ysize; ++i)
	{
		for (int j = 0; j <= xsize; ++j)
		{
			//for the left wall
			if (j == 0)
			{
				//i value + wall of #
				cout << " " << (ysize - i) << "  #";
			}

			//print coordinates whether wall was printed or not
			if (coordinates[i][j] == -1)
			{
				//print the rest of the grid as blank if vector has -1 inside
				cout << "  ";
			}
			else
			{
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

		for (int i = 0; i <= ysize; ++i)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					cout << "    #  ";
				}
				else if (i == ysize)
				{
					cout << "#" << setw(3) << setfill(' ') << "#" << setw(3) << setfill(' ') <<"#";
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
					cout << setw(8  ) << setfill(' ') << i << "  ";
				}
				else
				{
					cout << i << setw(3) << setfill(' ');
				}
			}
		}
		cout << endl;
	}
}

void generate_gridLMH(int** coordinates, int xsize, int ysize)
{
	cout << "Generating grid with LMH Values: " << endl;
	cout << endl;

	//THIS IS THE TOP WALL
	for (int i = 0; i <= ysize + 2; ++i)
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
	for (int i = 0; i <= ysize; ++i)
	{
		for (int j = 0; j <= xsize; ++j)
		{
			//for the left wall
			if (j == 0)
			{
				//i value + wall of #
				cout << " " << (ysize - i) << "  #";
			}

			//print coordinates whether wall was printed or not
			if (coordinates[i][j] == -1)
			{
				//print the rest of the grid as blank if vector has -1 inside
				cout << "  ";
			}
			else
			{
				cout << "  " << static_cast<char>(coordinates[i][j]);
			}

			//print back wall
			if (j == xsize)
			{
				//print the back wall of the grid
				cout <<"  #";
			}
		}
		cout << endl;
	}



	//This is for the bottom wall
	for (int j = 0; j < 2; j++)
	{

		for (int i = 0; i <= ysize; ++i)
		{
			if (j == 0)
			{
				if (i == 0)
				{
					cout << "    #  ";
				}
				else if (i == ysize)
				{
					cout << "#" << setw(3) << setfill(' ') << "#" << setw(3) << setfill(' ') << "#";
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
					cout << setw(8) << setfill(' ') << i << "  ";
				}
				else
				{
					cout << i << setw(3) << setfill(' ');
				}
			}
		}
		cout << endl;
	}
}