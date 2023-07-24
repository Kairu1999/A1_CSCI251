
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "WeatherReport.h"
#include "Structs.h";
using namespace std;

void print_weather_report(int** cityptr,vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize);
vector<coords>find_adjacent_tiles(coords city);
pair<string, char> compute_average_cloudcover(vector<int> cloudcover_values);
pair<string, char> compute_average_pressure(vector<int> pressure_values);
vector<int> findUnique(vector<int> info);
pair<int,string> AsciiRainArt(char cloudCover, char Pressure);


void print_weather_report(int ** cityptr, vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize)
{
	cout << "Weather Forecast Summary Report" << endl;
	cout << "-------------------------------" << endl;

	/*================================
	       Variable Declarations
	==================================*/	
	//counter;
	int count = 0;

	vector<int> cityType{};

	//to hold unique city types
	vector<int> uniqueCityType{};

	//to hold next day forecast
	vector<vector<int>> cloudCoverArea{};
	vector<vector<int>> PressureArea{};

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



	 //2: find the possible points both adjacent and diagonal for each city type;
	for (int j = 0; j < city.size(); ++j) 
	{
		vector<coords> proliferate8tiles{};

		//populate the vector<coords>
		proliferate8tiles = find_adjacent_tiles(city[j].coordinates);
		
		//push back into vector<vectors>
		Coordinates.push_back(proliferate8tiles);
	}

	//3: Now that all the adjacent coordinates have been gotten, retrieve the cloudcover and pressure values of each of them~!
	//check size of cloud cover
	for (int i = 0; i < Coordinates[0].size(); ++i)
	{
		cout << Coordinates[0][i].x << " " << Coordinates[0][i].y << endl;
	}



	//3.1 Loop through the outer vector, base case is 14.
	for (int k = 0; k < Coordinates.size(); ++k) 
	{
		//3.2 Loop through the inner vector, base case is 9.
		for (int l = 0; l < Coordinates[k].size(); ++l)
		{
			

			//3.3 Loop through each x and y per vector coord provided to find a match, after match is found, move on
			//3.3.1 while m{0} != 81(base case size)
			//for(int count = 0; count < cloudy.size(); ++count)
			//{
			//	//check X and Y Values match
			//	if ((Coordinates[k][l].x == cloudy[count].coordinates.x) && (Coordinates[k][l].x == cloudy[count].coordinates.x))
			//	{
			//		//push the corresponding next day forecast into the vector
			//		int ndfc{ 0 };
			//		ndfc = cloudy[count].NextDayForecast;
			//		vector<int> temp;
			//		temp.push_back(ndfc);
			//		cloudCoverArea.push_back(temp);
			//	}
			//}

		}
	}

	//Check the size of everything
	cout << Coordinates.size() << "x" << Coordinates[0].size() << endl;
	cout << cloudCoverArea.size() << endl;

	
	//Steps to do here:
	//1) Sort each vector in the vector<vector>
	//2) run them through to find the pressure and cloud cover


	//4: compute average cloud cover and average pressure

	//5: compute rain and ascii art

	//6: push it all into vector display

	//7: Display Vector

	
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
	coords x7 = { (cords.x), (cords.y) }; //<- base values LOL
	coords x8 = { (cords.x), (cords.y - 1) };
	coords x9 = { (cords.x), (cords.y + 1) };


	//insert them all into the vector
	vect.insert(vect.end(), { x1,x2,x3,x4,x5,x6,x7,x8,x9 });

	return vect;
}
//compute the average pressure
pair<string, char> compute_average_pressure(vector<int> pressure_values)
{
	pair<string, char> p1;
	int length = pressure_values.size();
	
	float number = (accumulate(pressure_values.begin(), pressure_values.end(), 0) / length);

	if ((number >= 0) && (number < 35)) 
	{
		p1.second = 'L';
	}
	else if ((number >= 35) && (number < 65))
	{
		p1.second = 'M';
	}
	else
	{
		p1.second = 'H';
	}


	//STILL NEED ADD SECOND BEHIND FIRST
	p1.first = to_string(number);

	return p1;
}


//compute average cloud pressure
pair<string,char> compute_average_cloudcover(vector<int> cloudcover_values) 
{
	pair<string, char> p1;
	int length = cloudcover_values.size();

	float number = (accumulate(cloudcover_values.begin(), cloudcover_values.end(), 0) / length);

	if ((number >= 0) && (number < 35))
	{
		p1.second = 'L';
	}
	else if ((number >= 35) && (number < 65))
	{
		p1.second = 'M';
	}
	else
	{
		p1.second = 'H';
	}


	//STILL NEED ADD SECOND BEHIND FIRST
	p1.first = to_string(number);

	return p1;
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

pair<int,string> AsciiRainArt(char cloudCover, char Pressure) 
{
	pair<int, string> p1{};
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

	int rain{};

	if ((cloudCover == 'L')) 
	{
		if ((Pressure == 'H')) 
		{
			p1.first = 90;
			p1.second = t;
		}
		else if ((Pressure == 'M'))
		{
			p1.first = 80;
			p1.second = s;
		}
		else 
		{
			p1.first = 70;
			p1.second = r;

		}
	}
	if ((cloudCover == 'M'))
	{
		if ((Pressure == 'H'))
		{
			p1.first = 60;
			p1.second = q;
		}
		else if ((Pressure == 'M'))
		{
			p1.first = 50;
			p1.second = p;
		}
		else
		{
			p1.first = 40;
			p1.second = o;

		}

	}
	if((cloudCover == 'H'))
	{
		if ((Pressure == 'H'))
		{
			p1.first = 30;
			p1.second = n;
		}
		else if ((Pressure == 'M'))
		{
			p1.first = 20;
			p1.second = m;
		}
		else 
		{
			p1.first = 10;
			p1.second = l;
		}

	}

	cout << p1.first << " " << endl;
	cout << p1.second << endl;
	return p1;

}