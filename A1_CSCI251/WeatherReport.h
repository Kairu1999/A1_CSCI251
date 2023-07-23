#ifndef WEATHERREPORT_H
#define WEATHEREPORT_H

#include <vector>
#include <string>
#include "Structs.h"
using namespace std;

struct display 
{
	string cityTypeName;
	int cityNumber;
	string Average_cloudcover;
	string Average_pressure;
	float Rain_Probability;

	//display ascii art
	string ascii_rain;
};

void print_weather_report(vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize);
vector<int>findUnique(vector<int> info);
string AsciiRainArt(char cloudCover, char Pressure, int rain);
string compute_average_cloudcover(vector<int> cloudcover_values);
string compute_average_pressure(vector<int> pressure_values);
#endif