
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "WeatherReport.h"
#include "Structs.h";
using namespace std;

void print_weather_report(int** CityInfo, std::vector<cityStructure> cityData, int** cloudy, int** pressure, int xsize, int ysize)
{
	cout << "Weather Forecast Summary Report" << endl;
	cout << "-------------------------------" << endl;

	

	vector<int> cityType{};

	for (int i = 0; i < xsize; ++i) 
	{
		for (int j = 0; j < ysize; ++j) 
		{
			cityType.push_back(CityInfo[i][j]);
		}
	}


	cout << endl;

	vector<int> temp{};

	temp = findUnique(cityType);
	

	for (int i = 0; i < temp.size(); ++i)
	{
		cout << temp[i] << endl;
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
	sort(result.begin(), result.end());

	//return result
	return result;

}