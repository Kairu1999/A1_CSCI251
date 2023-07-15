#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct coords 
{
    int x;
    int y;
};
struct cityStructure
{
    //store x and y coordinates
    vector<coords> coordinates;

    //store the city type
    vector<int> cityType;

    //city type name
    vector<string> cityTypeName;
};

struct cloudyPressure
{
    //x and y coordinates
    vector<int> coordinates;

    //next day forecast;
    vector<int> NextDayForecast;
};

#endif
