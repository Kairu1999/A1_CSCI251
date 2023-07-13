#ifndef MAIN_H
#define MAIN_H

#include <string>
using namespace std;

struct
{
    //store x and y coordinates
    std::vector<int> coordinates;

    //store the city type
    std::vector<int> cityType;

    //city type name
    vector<string> cityTypeName;
} cityStructure;

struct
{
    //x and y coordinates
    vector<int> coordinates;

    //next day forecast;
    vector<int> NextDayForecast;
}CloudyPressure;

int main();
string display_main_menu();

#endif