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
vector<cityStructure>readMapFile(string filename);
vector<cloudyPressure> readCloudCoverFile(string filename);
vector<cloudyPressure> readPressureFile(string filename);


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


                //DEBUG --> Print values of temp2 vector x and y!
                for (int i = 0; i < temp2.size(); ++i)
                {
                    //cout << temp2[i] << endl;

                    if (i % 2 == 0) {
                        coords1.x = stoi(temp2[i]);
                    }
                    else {
                        coords1.y = stoi(temp2[i]);
                    }
                }

                //debug coordinates
                //cout << coords1.x << " " << coords1.y << endl;


                //push back into vector
                coordinates.push_back(coords1);
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
        
        //push 3 vectors into one giant vector
        for (int i = 0; i < coordinates.size(); ++i) 
        {
            //temp variable created
            cityStructure structure{};

            //extract the values
            structure.coordinates = coordinates[i];
            structure.cityType = cityType[i];
            structure.cityTypeName = cityName[i];

            //push everything into the end structure
            cityInfo.push_back(structure);
        }

        ////PURELY USED FOR DEBUG KURWA
        //for (int i = 0; i < cityInfo.size(); ++i)
        //{
        //    cout << "city Information: " << endl;
        //    cout << "city coordinates: " << cityInfo[i].coordinates.x << " " << cityInfo[i].coordinates.y << endl;
        //    cout << "city Type       : " << cityInfo[i].cityType << endl;
        //    cout << "city Name       : " << cityInfo[i].cityTypeName << endl;
        //}

        //return the vector of structures
        return cityInfo;
    }
    else {
        cout << "Unable to find the file " << filename << endl;

        //return blank vector
        return {};
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
            cout << store_line1[i] << endl;

            //use this comment to find the commented lines
            string comment{ "/" };

            //search if the string in each value of vector has this comment
            if (store_line1[i].find("/") != string::npos)
            {
                continue;
            }
            else
            {
                //only push non commented lines of code inside
                store_line2.push_back(store_line1[i]);
            }
        }

        //size_t hyphen = store_line2[0].find("-");
        vector<string> temp1  = splitString(store_line2[0],"=");

        //check string for numbers
        vector<string> temp2 = splitString(temp1[1], "-");

        //size_t hyphen = store_line2[0].find("-");
        vector<string> temp3 = splitString(store_line2[1], "=");

        //check string for numbers
        vector<string> temp4 = splitString(temp3[1], "-");

        //insert everything in, then lastly insert
        temp.insert(temp.end(), {temp2[0],temp2[1],temp4[0],temp4[1]});

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

vector<cloudyPressure> readCloudCoverFile(string filename)
{

    //declare input file stream
    ifstream inputfile;


    //variable declaration:
    coords coords1{};

    //declare a vector
    vector<string> vect1{};

    vector<coords> coordinates{};
    vector<int> nextdayForecast{};

    vector <cloudyPressure> CloudyCover{};

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

            //cout << line << endl;

            //split the string
            vect1 = splitString(line, "-");

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int i = 0; i < vect1.size(); i += 2)
            {
                //make a substring
                vect1[i] = vect1[i].substr(1, vect1[i].length() - 2);

                //remove whitespaces from string
                vect1[i].erase(std::remove_if(vect1[i].begin(), vect1[i].end(), ::isspace), vect1[i].end());

                //split the string into individual strings
                vector<string> temp2 = splitString(vect1[i], ",");


                //DEBUG --> Print values of temp2 vector x and y!
                for (int i = 0; i < temp2.size(); ++i)
                {
                    //cout << temp2[i] << endl;

                    if (i % 2 == 0) {
                        coords1.x = stoi(temp2[i]);
                    }
                    else {
                        coords1.y = stoi(temp2[i]);
                    }
                }

                //debug coordinates
                //cout << coords1.x << " " << coords1.y << endl;


                //push back into vector
                coordinates.push_back(coords1);
            }

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int j = 1; j < vect1.size(); j += 2)
            {
                //cout << vect1[j] << endl;
                nextdayForecast.push_back(stoi(vect1[j]));
            }
        }
        //cout << nextdayForecast.size() << " " << coordinates.size() << endl;

        for (int m = 0; m < coordinates.size(); ++m) 
        {
            cloudyPressure cld;
            cld.coordinates = coordinates[m];
            cld.NextDayForecast = nextdayForecast[m];

            CloudyCover.push_back(cld);
        }
       return CloudyCover;
    }
    else
    {
        cout << "Unable to find the file " << filename << endl;
        return {};
    }

    //close filestream
    inputfile.close();
    
}

vector<cloudyPressure> readPressureFile(string filename)
{
    //declare input file stream
    ifstream inputfile;


    //variable declaration:
    coords coords1{};

    //declare a vector
    vector<string> vect1{};

    vector<coords> coordinates{};
    vector<int> nextdayForecast{};

    vector <cloudyPressure> Pressure{};

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

            //cout << line << endl;

            //split the string
            vect1 = splitString(line, "-");

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int i = 0; i < vect1.size(); i += 2)
            {
                //make a substring
                vect1[i] = vect1[i].substr(1, vect1[i].length() - 2);

                //remove whitespaces from string
                vect1[i].erase(std::remove_if(vect1[i].begin(), vect1[i].end(), ::isspace), vect1[i].end());

                //split the string into individual strings
                vector<string> temp2 = splitString(vect1[i], ",");


                //DEBUG --> Print values of temp2 vector x and y!
                for (int i = 0; i < temp2.size(); ++i)
                {
                    //cout << temp2[i] << endl;

                    if (i % 2 == 0) {
                        coords1.x = stoi(temp2[i]);
                    }
                    else {
                        coords1.y = stoi(temp2[i]);
                    }
                }

                //debug coordinates
                //cout << coords1.x << " " << coords1.y << endl;


                //push back into vector
                coordinates.push_back(coords1);
            }

            //every 3 = coordinates so += 3, Do for Coordinates
            for (int j = 1; j < vect1.size(); j += 2)
            {
                //cout << vect1[j] << endl;
                nextdayForecast.push_back(stoi(vect1[j]));
            }
        }

        for (int m = 0; m < coordinates.size(); ++m)
        {
            cloudyPressure cld;
            cld.coordinates = coordinates[m];
            cld.NextDayForecast = nextdayForecast[m];

            Pressure.push_back(cld);
        }
        return Pressure;
    }
    else
    {
        cout << "Unable to find the file " << filename << endl;
        return {};
    }

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
    
    result.push_back(input);
    return (result);
}