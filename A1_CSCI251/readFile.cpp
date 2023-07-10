#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//function prototype:

void readFromFile(string filename);
vector<string> splitString(string input, string delimiter);

void readFromFile(string filename)
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

            stringstream ss{};


            //store file data in variable
            getline(inputfile, line);

            //declare a vector
            vector<string> vect1{};

            //Used for X and Y Coordinates
            vector<vector<int>> Coordinates{};

            //store the city type
            vector<int> City_Area{};

            //store the last perimeter
            vector<string> City_Type{};

            //split the string
            vect1 = splitString(line, "-");
            
            //every 3 = coordinates so += 3, Do for Coordinates
            for (int i = 0; i < vect1.size(); i += 3)
            {
                //erase first character
                //cout << vect1[i].length() << endl;
                vect1[i] = vect1[i].substr(1, vect1[i].length() - 2);
                cout << vect1[i] << endl;
                //Need to find a way to remove the "[ ]" and the ","

            }
            //every 3 = coordinates so += 3, do the same for city Area!
            /*for (int j = 1; j < vect1.size(); j += 3)
            {
                //cout << vect1[j] << endl;

                //string to integer conversion
                City_Area.push_back(stoi(vect1[j]));
            }
            */

            //every 3 = coordinates so += 3, do the same for city Type!
            /*for (int k = 2; k < vect1.size(); k += 3)
            {
                //cout << vect1[k] << endl;
                City_Type.push_back(vect1[k]);
            }
            */

        }
    }
    else {
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
    return (result);
}