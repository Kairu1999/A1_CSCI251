#ifndef WEATHERREPORT_H
#define WEATHEREPORT_H

#include <vector>
#include <string>
#include "Structs.h"
using namespace std;

struct display
{
	//store the name of the city
	string cityTypeName{};

	//store the cityNumber(1...2...3...etc)
	int cityNumber{};

	//store the average cloud cover
	string Average_cloudcover{};

	//store the LMH Value for cloud cover
	char cloudcoverLMH{};

	//store the average pressure
	string Average_pressure{};

	//store the LMH Value for pressure
	char PressureLMH{};

	//store the rain probability
	float Rain_Probability{};

	//display ascii art
	string ascii_rain{};
};

//methods
void print_weather_report(int ** cityptr, vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize);
vector<coords>find_adjacent_tiles(coords city);
pair<string, char> compute_average_cloudcover(vector<int> cloudcover_values);
pair<string, char> compute_average_pressure(vector<int> pressure_values);
pair<int, string> AsciiRainArt(char cloudCover, char Pressure);
#endif