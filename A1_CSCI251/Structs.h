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
    coords coordinates;

    //store the city type
    int cityType;

    //city type name
    string cityTypeName;
};

struct cloudyPressure
{
    //x and y coordinates
    coords coordinates;

    //next day forecast;
    int NextDayForecast;
};

#endif
