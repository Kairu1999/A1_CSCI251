#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void readFromFile(string filename)
{
    //declare input file stream
    ifstream inputfile;

    //open input file stream
    inputfile.open(filename.c_str());

    //check if inputfile exists
    while (inputfile.good())
    {
        //declare string line variable
        string line;

        //store file data in variable
        getline(inputfile, line);

        //print to debug     
        cout << line << endl;

        //declare a vector
        std::vector<string> vect1{};

        //use 'new" to store map data in assignment vect1
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

    result.push_back(input);

    return (result);
}