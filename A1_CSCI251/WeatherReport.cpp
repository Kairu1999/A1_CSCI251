
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "WeatherReport.h"
#include "Structs.h";
using namespace std;

void print_weather_report(int** cityptr,vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize);
vector<coords>find_adjacent_tiles(cityStructure city);
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
	vector<int> cloudCoverArea{};
	vector<cityStructure> cityInfo{};
	vector<cityStructure> Temp{};
	//to push back all the new coordinates from every set of 8
	vector<vector<coords>> Coordinates{};
	//to use for display:
	vector<cityStructure> displayVect{};
	/*=================================*/

}
//pushes 8 values in
vector<coords>find_adjacent_tiles(cityStructure city) 
{
	vector<coords> vect{};

	// x - 1's first
	coords x1 = { (city.coordinates.x - 1), (city.coordinates.y) };
	coords x2 = { (city.coordinates.x - 1), (city.coordinates.y - 1)};
	coords x3 = { (city.coordinates.x - 1), (city.coordinates.y + 1) };

	//x + 1's next
	coords x4 = { (city.coordinates.x + 1), (city.coordinates.y - 1) };
	coords x5 = { (city.coordinates.x + 1), (city.coordinates.y) };
	coords x6 = { (city.coordinates.x + 1), (city.coordinates.y + 1)};

	//x's last
	coords x7 = { (city.coordinates.x), (city.coordinates.y + 1) };
	coords x8 = { (city.coordinates.x), (city.coordinates.y - 1) };


	//insert them all into the vector
	vect.insert(vect.end(), { x1,x2,x3,x4,x5,x6,x7,x8 });

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