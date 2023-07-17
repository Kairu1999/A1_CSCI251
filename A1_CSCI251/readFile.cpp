#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

//struct is here
#include "structs.h"

using namespace std;

//function prototype:
vector<string> readConfigFile(string filename);
vector<string> splitString(string input, string delimiter);
//vector<cityStructure>readMapFile(string filename);
void readMapFile(string filename);
void readCloudCoverFile(string filename);
void readPressureFile(string filename);


//vector<cityStructure> readMapFile(string filename)
void readMapFile(string filename)
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
        cout << "File " << filename << " successfully opened! " << endl;
        //check if inputfile exists
        while (inputfile.good())
        {
            //declare string line variable
            string line;

            //store file data in variable
            getline(inputfile, line);

            //declare a vector
            vector<string> vect1{};

            //split the string
            vect1 = splitString(line, "-");


            //every 3 = coordinates so += 3, Do for Coordinates
            for (int i = 0; i < vect1.size(); i += 3)
            {

                //make a substring
                vect1[i] = vect1[i].substr(1, vect1[i].length() - 2);

                //remove whitespaces from string
                vect1[i].erase(std::remove_if(vect1[i].begin(), vect1[i].end(), ::isspace), vect1[i].end());

                //split the string into individual strings
                vector<string> temp2 = splitString(vect1[i], ",");
                

                //DEBUG
                for (int i = 0; i < temp2.size(); ++i) 
                {
                    cout << temp2[i] << endl;
                }

            }
           

            //every 3 = coordinates so += 3, do the same for city area!(1, 2, 3 etc)
            for (int j = 1; j < vect1.size(); j += 3)
            {
                //cout << vect1[j] << endl;
                
                int citytype = stoi(vect1[j]);

                //string to integer conversion
                cityType.push_back(citytype);
            }
            

            //every 3 = coordinates so += 3, do the same for city Type!(BIG CITY, MID CITY etc)
            for (int k = 2; k < vect1.size(); k += 3)
            {
                //cout << vect1[k] << "endl;

                //push in name to the vector
                cityName.push_back(vect1[k]);
            }
        }
        //return {};
    }
    else {
        cout << "Unable to find the file " << filename << endl;
        //return {};
    }

    //close filestream
    inputfile.close();
}
vector<string> readConfigFile(string filename)
{
    //declare input file stream
    ifstream inputfile;
    //store lines from configuration file
    vector<string> store_line1{}, store_line2{};

    //to store minimum and maximum
    vector<string>temp{};

    cout << "opening the file :" << filename << endl;

    //open input file stream
    inputfile.open(filename.c_str());


    if (inputfile)
    {
        cout << "File " << filename << " successfully opened! " << endl;
        //check if inputfile exists
        while (inputfile.good())
        {
            //declare string line variable
            string line;

            //store file data in variable
            while (getline(inputfile, line))
            {
                if (!line.empty())
                {
                    store_line1.push_back(line);
                }
            }

        }

        for (int i = 0; i < store_line1.size(); ++i)
        {
            //Debug
            //cout << store_line1[i] << endl;

            //use this comment to find the commented lines
            string comment{ "/" };

            //search if the string in each value of vector has this comment
            if (store_line1[i].find("/") != string::npos)
            {
                //if found, skip the line
                //cout << "Found Comment, Skipping Line!" << endl;
                continue;
            }
            else
            {
                //only push non commented lines of code inside
                store_line2.push_back(store_line1[i]);
            }
        }

        for (int j = 0; j < store_line2[0].length(); ++j)
        {
            if (isdigit(store_line2[0][j]))
            {
                //cout << "detected digit :" << value << endl;
                string value(1, store_line2[0][j]);
                temp.push_back(value);
            }
        }

        for (int k = 0; k < store_line2[1].length(); ++k)
        {
            if (isdigit(store_line2[1][k]))
            {
                //cout << "detected digit :" << value << endl;
                string value(1, store_line2[0][k]);
                temp.push_back(value);
            }
        }

        for (int m = 2; m < store_line2.size(); ++m)
        {
            //push back the file names into the file
            temp.push_back(store_line2[m]);
        }

        //close filestream
        inputfile.close();
        return temp;
    }
    else {
        cout << "Unable to find the file " << filename << endl;
        return {};
    }
}

void readCloudCoverFile(string filename) 
{

    //declare input file stream
    ifstream inputfile;

    cout << "opening the file :" << filename << endl;

    //open input file stream
    inputfile.open(filename.c_str());

    if (inputfile)
    {
        cout << "File " << filename << " successfully opened! " << endl;
        //check if inputfile exists
        while (inputfile.good())
        {
            //declare string line variable
            string line;

            //store file data in variable
            getline(inputfile, line);

            //declare a vector
            vector<string> vect1{};
            vector<int> nextdayForecast{};

            //cout << line << endl;

            //split the string
            vect1 = splitString(line, "-");

            //for (int i = 0; i < vect1.size(); ++i) {
            //    cout << vect1[i] << endl;
            //}

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int i = 0; i < vect1.size(); i += 2)
            {
                //erase first character
                //cout << vect1[i].length() << endl;
                vect1[i] = vect1[i].substr(1, vect1[i].length() - 2);
                //cout << vect1[i] << endl;
            }

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int j = 1; j < vect1.size(); j += 2)
            {
                nextdayForecast.push_back(stoi(vect1[j]));
            }
        }
    }
    else
    {
        cout << "Unable to find the file " << filename << endl;
    }

    //close filestream
    inputfile.close();
    
}

void readPressureFile(string filename)
{

    //declare input file stream
    ifstream inputfile;

    cout << "opening the file :" << filename << endl;

    //open input file stream
    inputfile.open(filename.c_str());

    if (inputfile)
    {
        cout << "File " << filename << " successfully opened! " << endl;
        //check if inputfile exists
        while (inputfile.good())
        {
            //declare string line variable
            string line;

            //store file data in variable
            getline(inputfile, line);

            //declare a vector
            vector<string> vect1{};
            vector<int> nextdayForecast{};

            //cout << line << endl;

            //split the string
            vect1 = splitString(line, "-");

            for (int i = 0; i < vect1.size(); ++i) {
                cout << vect1[i] << endl;
            }

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int i = 0; i < vect1.size(); i += 2)
            {
                //erase first character
                //cout << vect1[i].length() << endl;
                vect1[i] = vect1[i].substr(1, vect1[i].length() - 2);
                
                //cout << vect1[i] << endl;
            }

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int j = 1; j < vect1.size(); j += 2)
            {
                nextdayForecast.push_back(stoi(vect1[j]));
            }
        }
    }
    else
    {
        cout << "Unable to find the file " << filename << endl;
    }

    //close filestream
    inputfile.close();

}
vector<string> splitString(string input, string delimiter)
{
    size_t pos = 0;
    string token;
    vector<string> result;

    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.length());
    }

    if (!input.empty())
    {
        result.push_back(input);
    }
    
    return (result);
}