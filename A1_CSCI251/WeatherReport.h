#ifndef WEATHERREPORT_H
#define WEATHEREPORT_H

#include <vector>
#include "Structs.h"
using namespace std;

void print_weather_report(vector<cityStructure> city, vector<cloudyPressure> cloudy, vector<cloudyPressure> pressure, int xsize, int ysize);
vector<int>findUnique(vector<int> info);

#endif