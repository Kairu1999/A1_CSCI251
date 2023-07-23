
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

	//for debug
	for (int k = 0; k < Temp.size(); ++k)
	{
		cout << Temp[k].coordinates.x << " " << Temp[k].coordinates.y << " " << Temp[k].cityType << endl;
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