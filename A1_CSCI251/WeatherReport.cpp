
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "WeatherReport.h"
#include "Structs.h";
using namespace std;


void print_weather_report(vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize)
{
	cout << "Weather Forecast Summary Report" << endl;
	cout << "-------------------------------" << endl;

	vector<int> cityType{};

	vector<cityStructure> cityInfo{};
	vector<cityStructure> Temp{};

	//to use for display:
	vector<cityStructure> displayVect{};

	for (int i = 0; i < city.size(); ++i) 
	{
		if (city[i].cityType != -1) {

			//remove -1 to push into unique function
			cityType.push_back(city[i].cityType);

			//remove -1's from cityInfo
			cityInfo.push_back(city[i]);

		}
	}

	//find the unique city type values
	cityType = findUnique(cityType);

	//should be 3....2....1 base case
	for (int i = 0; i < cityType.size(); ++i) 
	{
		for (int j = 0; j < cityInfo.size(); ++j)
		{
			//push the vector in a sorted way
			if (cityInfo[j].cityType == cityType[i]) 
			{
				Temp.push_back(cityInfo[j]);
			}
		}
	}

	//populate the display vector
	for (int l = 0; l < cityType.size(); ++l) 
	{
		cout << cityType[l] << endl;
	}

	



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