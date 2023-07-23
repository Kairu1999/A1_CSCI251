
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "WeatherReport.h"
#include "Structs.h";
using namespace std;

void print_weather_report(int** cityptr,vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize);
vector<coords>find_adjacent_tiles(coords city);
string compute_average_cloudcover(vector<int> cloudcover_values);
string compute_average_pressure(vector<int> pressure_values);
vector<int> findUnique(vector<int> info);
string AsciiRainArt(char cloudCover, char Pressure, int rain);


void print_weather_report(int ** cityptr, vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize)
{
	cout << "Weather Forecast Summary Report" << endl;
	cout << "-------------------------------" << endl;

	/*================================
	       Variable Declarations
	==================================*/
	vector<int> cityType{};

	//to hold unique city types
	vector<int> uniqueCityType{};

	//to hold next day forecast
	vector<int> cloudCoverArea{};
	
	//to push back all the new coordinates from every set of 8
	vector<vector<coords>> Coordinates{};
	//to use for display:
	vector<cityStructure> displayVect{};
	/*=================================*/

	//1: get the unique city types from city():
	for (int i = 0; i < city.size(); ++i) 
	{
		cityType.push_back(city[i].cityType);
	}

	//find the unique values
	 uniqueCityType = findUnique(cityType);



	for (int j = 0; j < city.size(); ++j) 
	{
		vector<coords> proliferate8tiles{};

		//populate the vector<coords>
		proliferate8tiles = find_adjacent_tiles(city[j].coordinates);
		//cout << proliferate8tiles.size() << endl;

		/*for (int k = 0; k < proliferate8tiles.size(); ++k) 
		{
			cout << proliferate8tiles[k].x << " " << proliferate8tiles[k].y << endl;
		}*/
		
		//push back into vector<vectors>
		Coordinates.push_back(proliferate8tiles);
	}

	for (int i = 0; i < Coordinates.size(); i++)
	{
		for (int j = 0; j < Coordinates[i].size(); j++)
		{
			//FULL SIZE OF COORDINATES GOTTEN!
			cout << Coordinates[i][j].x << " " << Coordinates[i][j].y << ",";
		}
		cout << endl;
	}
}
//pushes 8 values in
vector<coords>find_adjacent_tiles(coords cords) 
{
	vector<coords> vect{};

	// x - 1's first
	coords x1 = { (cords.x - 1), (cords.y) };
	coords x2 = { (cords.x - 1), (cords.y - 1)};
	coords x3 = { (cords.x - 1), (cords.y + 1) };

	//x + 1's next
	coords x4 = { (cords.x + 1), (cords.y) };
	coords x5 = { (cords.x + 1), (cords.y - 1) };
	coords x6 = { (cords.x + 1), (cords.y + 1) };

	//x's last
	coords x7 = { (cords.x), (cords.y) };
	coords x8 = { (cords.x), (cords.y - 1) };
	coords x9 = { (cords.x), (cords.y + 1) };


	//insert them all into the vector
	vect.insert(vect.end(), { x1,x2,x3,x4,x5,x6,x7,x8,x9 });

	return vect;
}
//compute the average pressure
string compute_average_pressure(vector<int> pressure_values) 
{
	return "";
}


//compute average cloud pressure
string compute_average_cloudcover(vector<int> cloudcover_values) 
{
	return "";
}


//PURELY USED TO FIND UNIQUE CITY TYPES
vector<int> findUnique(vector<int> info) 
{
	vector<int> result{};

	//find unique values in the vector and then push back into results
	for (unsigned i = 0; i < info.size(); ++i) {
		if (count(result.begin(), result.end(), info.at(i)) == 0) {
			result.push_back(info.at(i));
		}
	}


	//sort the vector from smallest to biggest
	sort(result.begin(), result.end(),greater<int>());

	//return result
	return result;

}

string AsciiRainArt(char cloudCover, char Pressure, int rain) 
{
	string l{}, m{}, n{}, o{}, p{}, q{}, r{}, s{}, t{};

	l = "~\n~~\n";
	m = "~~\n~~~\n";
	n = "~~~\n~~~~\n";
	o = "~~~~\n~~~~~\n";
	p = "~~~~\n~~~~~\n    \\";
	q = "~~~~\n~~~~~\n   \\\\";
	r = "~~~~\n~~~~~\n  \\\\\\";
	s = "~~~~\n~~~~~\n \\\\\\\\";
	t = "~~~~\n~~~~~\n\\\\\\\\\\";

	if ((cloudCover == 'L') && (Pressure == 'H') && (rain == 90)) 
	{
		return t;
	}
	if ((cloudCover == 'L') && (Pressure == 'M') && (rain == 80))
	{
		return s;
	}
	if ((cloudCover == 'L') && (Pressure == 'L') && (rain == 70))
	{
		return r;
	}
	if ((cloudCover == 'M') && (Pressure == 'H') && (rain == 60))
	{
		return q;
	}
	if ((cloudCover == 'M') && (Pressure == 'M') && (rain == 50))
	{
		return p;
	}
	if ((cloudCover == 'M') && (Pressure == 'L') && (rain == 40))
	{
		return o;
	}
	if ((cloudCover == 'H') && (Pressure == 'H') && (rain == 30))
	{
		return n;
	}
	if ((cloudCover == 'H') && (Pressure == 'M') && (rain == 20))
	{
		return m;
	}
	if ((cloudCover == 'H') && (Pressure == 'L') && (rain == 10))
	{
		return l;
	}
}