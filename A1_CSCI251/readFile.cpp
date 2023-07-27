#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

//struct is here
#include "structs.h"

using namespace std;

//function prototype:
vector<string> readConfigFile(string filename);
vector<string> splitString(string input, string delimiter);
vector<cityStructure>readMapFile(string filename);
vector<cloudyPressure> readCloudCoverFile(string filename);
vector<cloudyPressure> readPressureFile(string filename);

vector<cityStructure> readMapFile(string filename)
{
    //declare input file stream
    ifstream inputfile;

    //to store the city information
    vector<cityStructure> cityInfo{};

    //declare string line variable
    string line{};
    cout << "File " << filename << " successfully opened! " << endl;


    cout << "opening the file :" << filename << endl;

    //open the input file
    inputfile.open(filename.c_str());

    while (inputfile)
    {
        //read the file line by line
        while (getline(inputfile, line))
        {
            if (line.find("-") != string::npos)
            {
                //cout << line << endl;
                vector<string> temp = splitString(line, "-");

                temp[0].erase(remove(temp[0].begin(), temp[0].end(), '['), temp[0].end()); //remove [ from string
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), ']'), temp[0].end()); //remove [ from string
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), ' '), temp[0].end()); //remove [ from string

                vector<string> hatred = splitString(temp[0], ",");

                //cout << hatred[0] << " " << hatred[1] << endl;
                

                cityStructure city{};

                city.coordinates.x = stoi(hatred[0]);
                city.coordinates.y = stoi(hatred[1]);
                city.cityType = stoi(temp[1]);
                city.cityTypeName = temp[2];
                
                cityInfo.push_back(city);
            }
        }
    
    }
    return cityInfo;
}
vector<string> readConfigFile(string filename)
{
    fstream inputfile;

    string line;

    vector<string> result, result2;
    cout << filename << "...";

    //open the input file
    inputfile.open(filename.c_str());

    //while input file is open
    while (inputfile)
    {
        while (getline(inputfile, line)) 
        {
            size_t GridX = line.find("GridX_IdxRange");
            size_t GridY = line.find("GridY_IdxRange");
            size_t txt = line.find(".txt");

            if (GridX != string::npos)
            {
                ////cout << line << endl;
                result.push_back(line);
            }

            if (GridY != string::npos) 
            {
                //cout << line << endl;
                result.push_back(line);
            }
            if (txt != string::npos) 
            {
                //cout << line << endl;
                result.push_back(line);

            }

        }
    }

    //close input file
    inputfile.close();
    cout << "Done!" << endl;

    //split string for result[0]
    vector<string> temp1 = splitString(result[0], "=");
    vector<string> temp2 = splitString(temp1[1] , "-");

    vector<string> temp3 = splitString(result[1], "=");
    vector<string> temp4 = splitString(temp3[1], "-");

    result2.insert(result2.end(), { temp2[0],temp2[1],temp4[0],temp4[1],result[2],result[3],result[4] });

    //debug
   /* for (string s : result2) 
    {
        cout << s << endl;
    }*/

    //return the array
    return result2;
}

vector<cloudyPressure> readCloudCoverFile(string filename)
{

    //declare input file stream
    ifstream inputfile;

    //to store the city information
    vector < cloudyPressure > cloudy {};

    //declare string line variable
    string line{};
    cout << "File " << filename << " successfully opened! " << endl;


    cout << "opening the file :" << filename << endl;

    //open the input file
    inputfile.open(filename.c_str());

    while(inputfile)
    {
        //read the file line by line
        while (getline(inputfile, line))
        {
            if (line.find("-") != string::npos)
            {
                //cout << line << endl;
                vector<string> temp = splitString(line, "-");

                //remove the "[", " " and "]" from each value
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), '['), temp[0].end()); //remove [ from string
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), ']'), temp[0].end()); //remove [ from string
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), ' '), temp[0].end()); //remove [ from string

                //split the string at the comma to get the 2 numbers
                vector<string> hatred = splitString(temp[0], ",");

                //cout << hatred[0] << " " << hatred[1] << endl;


                cloudyPressure cp{};

                //allocate a new variable to cloudy
                cp.coordinates.x = stoi(hatred[0]);
                cp.coordinates.y = stoi(hatred[1]);
                cp.NextDayForecast = stoi(temp[1]);

                //push back into the array
                cloudy.push_back(cp);
            }
        }

    }

    inputfile.close();
    return cloudy;
    
}

vector<cloudyPressure> readPressureFile(string filename)
{
    //declare input file stream
    ifstream inputfile;

    //to store the city information
    vector < cloudyPressure > pressure{};

    //declare string line variable
    string line{};
    cout << "File " << filename << " successfully opened! " << endl;


    cout << "opening the file :" << filename << endl;

    //open the input file
    inputfile.open(filename.c_str());

    while (inputfile)
    {
        //read the file line by line
        while (getline(inputfile, line))
        {
            if (line.find("-") != string::npos)
            {
                //cout << line << endl;
                vector<string> temp = splitString(line, "-");



                //remove the "[", " " and "]" from each value
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), '['), temp[0].end()); //remove [ from string
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), ']'), temp[0].end()); //remove [ from string
                temp[0].erase(remove(temp[0].begin(), temp[0].end(), ' '), temp[0].end()); //remove [ from string

                //split the string at the comma to get the 2 numbers
                vector<string> hatred = splitString(temp[0], ",");

                //cout << hatred[0] << " " << hatred[1] << endl;


                //create a new pressure struct
                cloudyPressure cp{};

                //assign values to pressure
                cp.coordinates.x = stoi(hatred[0]);
                cp.coordinates.y = stoi(hatred[1]);
                cp.NextDayForecast = stoi(temp[1]);

                //push back to 2d vector
                pressure.push_back(cp);
            }
        }

    }
    inputfile.close();
    return pressure;
}
vector<string> splitString(string input, string delimiter)
{
    size_t pos = 0;
    string token{};
    vector<string> result{};

    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    
    result.push_back(input);
    return (result);
}