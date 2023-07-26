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
vector<string> ReadRangeOfIdx(string line, size_t foundIdxRange, int& count);


vector<string>ReadRangeOfIdx(string line, size_t foundIdxRange, int& count)
{
    //tokenize string at the "="
    vector<string> vect1 = splitString(line, "=");
    vector<string> temp{};

    cout << "Reading: " << vect1[0] << "," << vect1[1] << endl;
    
    
    if (vect1[0] == "GridX_IdxRange") 
    {
        //split string
        temp = splitString(vect1[1], "-");
        count++;
    }
    else {
        //split string
        temp = splitString(vect1[1], "-");
        count++;
    }
    return temp;
}
vector<cityStructure> readMapFile(string filename)
{
    //declare input file stream
    ifstream inputfile;


    //individual struct variable
    coords coords1{};

    vector<coords> coordinates{};

    vector<int> cityType{};

    vector<string>cityName{};

    
    //to store the city information
    vector<cityStructure> cityInfo{};


    cout << "opening the file :" << filename << endl;

    //open input file stream
    inputfile.open(filename.c_str());
    if (inputfile)
    {
        //declare string line variable
        string line{};
        cout << "File " << filename << " successfully opened! " << endl;
        
        //read the file line by line
        while (getline(inputfile, line))
        {
            if (line.find("-") != string::npos)
            {
                cout << line << endl;
            }
            //return the vector of structures
            return cityInfo;

        }
    }
    else {
        cout << "Unable to find the file " << filename << endl;

        //return blank vector
        return {};
    }
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