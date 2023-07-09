#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "readFile.h"

using namespace std;

int main()
{
    cout << "Enter configuration file name: ";
    
    string inputtext;

    cin >> inputtext;

    //execute read from file
    readFromFile(inputtext);


    return 0;
}