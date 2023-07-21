#ifndef WEATHERREPORT_H
#define WEATHEREPORT_H

#include <vector>
using namespace std;

void print_weather_report(int** CityInfo, std::vector<cityStructure> cityData, int** cloudy, int** pressure, int xsize, int ysize);
vector<int>findUnique(vector<int> info);

#endif