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

    ////declare input file stream
    //ifstream inputfile;


    ////variable declaration:
    //coords coords1{};

    ////declare a vector
    //vector<string> vect1{};

    //vector<coords> coordinates{};
    //vector<int> nextdayForecast{};

    //vector <cloudyPressure> CloudyCover{};

    //cout << "opening the file :" << filename << endl;

    ////open input file stream
    //inputfile.open(filename.c_str());

    //if (inputfile)
    //{
    //    //declare string line variable
    //    string line;
    //    cout << "File " << filename << " successfully opened! " << endl;
    //    //check if inputfile exists
    //    while (getline(inputfile, line))
    //    {

    //        if (line.find("-") != string::npos) 
    //        {

    //        }

    //    }
    //}
    //else
    //{
    //    cout << "Unable to find the file " << filename << endl;
    //    return {};
    //}

    ////close filestream
    //inputfile.close();
    return {};
    
}

vector<cloudyPressure> readPressureFile(string filename)
{
    ////declare input file stream
    //ifstream inputfile;

    ////declare string line variable
    //string line;

    ////variable declaration:
    //coords coords1{};

    ////declare a vector
    //vector<string> vect1{};

    //vector<coords> coordinates{};
    //vector<int> nextdayForecast{};

    //vector <cloudyPressure> Pressure{};

    //cout << "opening the file :" << filename << endl;

    ////open input file stream
    //inputfile.open(filename.c_str());

    //if (inputfile)
    //{
    //    cout << "File " << filename << " successfully opened! " << endl;

    //    //check if inputfile exists
    //    while (getline(inputfile, line))
    //    {
    //        if (line.find('-') != string::npos) 
    //        {

    //            //split the string
    //            vect1 = splitString(line, "-");


    //        }
    //    }

    //}
    //else
    //{
    //    cout << "Unable to find the file " << filename << endl;
    //    return {};
    //}
    return {};

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