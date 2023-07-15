#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <vector>
#include <string>

using namespace std;
struct
{
    //store x and y coordinates
    std::vector<int> coordinates;

    //store the city type
    std::vector<int> cityType;

    //city type name
    std::vector<string> cityTypeName;
} cityStructure;


struct
{
    //x and y coordinates
    vector<int> coordinates;

    //next day forecast;
    vector<int> NextDayForecast;
}CloudyPressure;


#endif