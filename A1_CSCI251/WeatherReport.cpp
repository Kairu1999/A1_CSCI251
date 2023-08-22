
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "WeatherReport.h"
#include "Structs.h"
using namespace std;

void print_weather_report(int** cityptr, vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize);
vector<coords>find_adjacent_tiles(coords city);
pair<string, char> compute_average_cloudcover(vector<int> cloudcover_values);
pair<string, char> compute_average_pressure(vector<int> pressure_values);

pair<int, string> AsciiRainArt(char cloudCover, char Pressure);


void print_weather_report(int** cityptr, vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize)
{
	cout << "Weather Forecast Summary Report" << endl;
	cout << "-------------------------------" << endl;

	/*================================
		   Variable Declarations
	==================================*/
	//unique city types
	vector<int> temp{}, temp1{};
	vector<int>::iterator citytypes{};


	//used to store the next day forecast based on city type
	bool next = false;
	//for final coords used
	vector<coords> finalpts;

	//to use for display:
	vector<display> displayVect{};
	/*=================================*/


	//push in first city variable
	temp1.push_back(city[0].cityType);

	//push back all the city types into the vector
	for (int i = 0; i < city.size(); ++i)
	{
		bool pushIn = true;
		for (int m = 0; m < temp1.size(); ++m)
		{
			if (city[i].cityType == temp1[m])
			{
				pushIn = false;
				break;
			}
		}
		if (pushIn == true)
			temp1.push_back(city[i].cityType);
	}


	////separator here
	//for (int j = 0; j < temp1.size(); j++)
	//{
	//	cout << " temp1 check" << endl;
	//	for (int i = 0; i < city.size(); ++i)
	//	{
	//		if (temp1[j] == city[i].cityType)
	//		{
	//			cout << " city check" << endl;
	//			//generate the 8 coordinates for the surrounding grids for each city coordinate
	//			vector<coords> unique = find_adjacent_tiles(city[i].coordinates);
	//			next = false;

	//			for (int x = 0; x < unique.size(); ++x)
	//			{
	//				if (unique[x].x < 0 || unique[x].x >= xsize || unique[x].y < 0 || unique[x].y >= ysize)
	//				{
	//					next = true;
	//				}
	//				//check if point has already been pushed in to finalpts
	//				for (int k = 0; k < finalpts.size(); ++k)
	//				{
	//					//check if the point exists in final points
	//					if ((unique[x].x == finalpts[k].x) && (unique[x].y == finalpts[k].y))
	//					{
	//						next = true;
	//						break;
	//					}
	//				}

	//				//check if point intersects with any point in the city
	//				for (int k = 0; k < city.size(); ++k)
	//				{
	//					if ((unique[x].x == city[k].coordinates.x) && (unique[x].y == city[k].coordinates.y))
	//					{
	//						next = true;
	//						break;
	//					}
	//				}

	//				if (next == false)
	//				{
	//					//push back to final points
	//					finalpts.push_back(unique[x]);
	//				}

	//			}

	//		}
	//	}

	//	cout << "city code: " << temp[j] << endl;
	//	for (coords x : finalpts)
	//	{
	//		cout << x.x << " " << x.y << endl;
	//	}
	//}







	////loop through the possible city codes
	//for (int i = 0; i < temp1.size(); ++i)
	//{
	//	//loop through unique city codes
	//	for (int j = 0; j < temp.size(); ++j)
	//	{
	//		//compare type with value in array
	//		if (city[i].cityType == temp[j])
	//		{
	//			//if same type, save all the data into the stuff
	//			display dist;
	//			//allocat the name and city type
	//			dist.cityTypeName = city[i].cityTypeName;
	//			dist.cityNumber = city[i].cityType;

	//		}
	//	}
	//}

}
//pushes 8 values in
vector<coords>find_adjacent_tiles(coords cords)
{
	vector<coords> vect{};

	//// x - 1's first
	//coords x1 = { (cords.x - 1), (cords.y) };
	//coords x2 = { (cords.x - 1), (cords.y - 1) };
	//coords x3 = { (cords.x - 1), (cords.y + 1) };

	////x + 1's next
	//coords x4 = { (cords.x + 1), (cords.y) };
	//coords x5 = { (cords.x + 1), (cords.y - 1) };
	//coords x6 = { (cords.x + 1), (cords.y + 1) };

	////x's last
	//coords x7 = { (cords.x), (cords.y - 1) };
	//coords x8 = { (cords.x), (cords.y + 1) };


	////insert them all into the vector
	//vect.insert(vect.end(), { x1,x2,x3,x4,x5,x6,x7,x8 });

	return vect;
}

//compute the average pressure
pair<string, char> compute_average_pressure(vector<int> pressure_values)
{
	pair<string, char> p1;
	int length = pressure_values.size();

	float number = (accumulate(pressure_values.begin(), pressure_values.end(), 0) / length);


	//STILL NEED ADD SECOND BEHIND FIRST
	p1.first = to_string(number);

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

	return p1;
}


//compute average cloud pressure
pair<string, char> compute_average_cloudcover(vector<int> cloudcover_values)
{
	pair<string, char> p1;
	int length = cloudcover_values.size();

	float number = (accumulate(cloudcover_values.begin(), cloudcover_values.end(), 0) / length);

	//STILL NEED ADD SECOND BEHIND FIRST
	p1.first = to_string(number);

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


	return p1;
}


pair<int, string> AsciiRainArt(char cloudCover, char Pressure)
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
	if ((cloudCover == 'H'))
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