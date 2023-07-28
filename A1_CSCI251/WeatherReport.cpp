
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

pair<int,string> AsciiRainArt(char cloudCover, char Pressure);


void print_weather_report(int ** cityptr, vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize)
{
	cout << "Weather Forecast Summary Report" << endl;
	cout << "-------------------------------" << endl;

	/*================================
	       Variable Declarations
	==================================*/	
	int cnt{ 0 },citycount{ 0 }, coordscheck{ 0 };
	
	vector<pair<int, string>> temp{}, temp1{};


	//used to store the next day forecast based on city type
	vector<vector<cityStructure>> cityType{};


	vector <vector<cloudyPressure>> storage;

	vector<vector<pair<int,int>>> cloudCoverArea{};
	vector<vector<pair<int,int>>> PressureArea{};
	vector<int> cloudCoverNDFCVal;
	vector<int> PressureNDFCVal;


	//to use for display:
	vector<display> displayVect{};
	/*=================================*/


	//sort first
	sort(city.begin(), city.end(), [](const cityStructure& x, const cityStructure& y) {return (x.cityType > y.cityType); });

	//for (int i = 0; i < city.size(); ++i) 
	//{
	//	pair<int, string> t1{};

	//	t1.first = city[i].cityType;
	//	t1.second = city[i].cityTypeName;
	//	temp.push_back(t1);
	//}



	/*for (pair<int, string> x : temp) 
	{
		cout << x.first << " " << x.second << endl;
	}*/

	//debug
	for (int i = 0; i < city.size(); ++i)
	{
		vector<coords> temp = find_adjacent_tiles(city[i].coordinates);

		vector<cityStructure> temp_cityVect{};

		//insert the adjacent sagas + base coordinates into the vector
		for (int k = 0; k < temp.size(); ++k) 
		{
			cityStructure cs;
			cs.coordinates = temp[k];
			cs.cityType = -1;
			cs.cityTypeName = "";

			temp_cityVect.push_back(cs);
		}
		cityType.push_back(temp_cityVect);
	}

	//loop through the vector of vectors
	for (int h = 0; h < cityType.size(); ++h)
	{
		for (int i = 0; i < cityType[h].size(); ++i)
		{
			for (int l = 0; l < city.size(); ++l)
			{
				//if any of the adjacent coordinates matches any coordinates in the list of numbers, update their city type and name
				if ((cityType[h][i].coordinates.x == city[l].coordinates.x) && (cityType[h][i].coordinates.y == city[l].coordinates.y))
				{
					cityType[h][i].cityType = city[l].cityType;
					cityType[h][i].cityTypeName = city[l].cityTypeName;
				}
			}
			//cout << cityType[h][i].coordinates.x << " " << cityType[h][i].coordinates.y << " " << cityType[h][i].cityType << " " << cityType[h][i].cityTypeName << endl;
		}
		//cout << endl;
	}

	//Try for 1D Vector first, then move to 2D Vector!
	while(cnt != city.size())
	{
		//if citycount not equal to 
		if(citycount != cityType[cnt].size())
		{
			vector<pair<int, int>> temp_city;
			vector<pair<int, int>> temp_pressure;

			if (coordscheck != cloudy.size())
			{
				if ((cityType[cnt][citycount].coordinates.x) == (cloudy[coordscheck].coordinates.x) && (cityType[cnt][citycount].coordinates.y) == (cloudy[coordscheck].coordinates.y))
				{

					//cout << "citytype x and y: " << "[" << cityType[citycounter][citycount].coordinates.x << "," << cityType[citycounter][citycount].coordinates.y << "]" << endl;
					//cout << "cloudy x and y  : " << "[" << cloudy[coordscheck].coordinates.x << "," << cloudy[coordscheck].coordinates.y << "]" << endl;


					//push into vector:
					//cout << "pushing in: " << cloudy[coordscheck].NextDayForecast << endl;


					//push the value into city and pressure;
					int ndfc_c = cloudy[coordscheck].NextDayForecast;   //next day forecast cloudcover
					int ndfc_p = pressure[coordscheck].NextDayForecast; //next day forecast city
					int ct = cityType[cnt][citycount].cityType;         //pair with the cityType(used for later)

					//push into the 1d, then 2d vector
					temp_city.push_back({ ndfc_c, ct });
					temp_pressure.push_back({ ndfc_p, ct });


					//push into the 2d vector
					cloudCoverArea.push_back(temp_city);
					PressureArea.push_back(temp_pressure);


					//reset coords check to cloudy[0] to start again;
					coordscheck = 0;

					//increment citycount to next coordinate pair city[]
					++citycount;
				}
				else
				{
					//increment coords check if the coordinates do not match
					++coordscheck;
				}
			}
		}
		else 
		{
			//after citycount
			++cnt;
		}
	}


	//PURELY FOR DEBUGGING
	for (auto &x : PressureArea) 
	{
		for (auto &y : x) 
		{
			cout << y.first << " " << y.second << endl;
		}
	}

	//with the <cloudcover, related cityType> vector<vector> and the <pressure, related cityType> vector<vector>, 
	//loop through the cloud cover and pressure 2D vectors and check if the [i][6]'th one(base coordinate is within any city type)
	//then group the relevant coordinates together! <city type 1> <city type 2> <city type 3>
	/*
		vector<vector<pair>> ---> <vector<pair>>
	*/
	//then run it through the calculate average pressure and calculate average cloudcover
	//Generate through ASCII Rain Art with the LMH Values gotten from the above step
	//Push Everything into the display class and display!

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
	vect.insert(vect.end(),{x1,x2,x3,x4,x5,x6,x7,x8,x9});

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
pair<string,char> compute_average_cloudcover(vector<int> cloudcover_values) 
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