#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "readFile.h"

using namespace std;

int main()
{
    //print name
    cout << "Student ID : "   << "8039082" << endl;
    cout << "Student Name : " << "Shane-Kyle Chua" << endl;
    cout << "--------------------------------------- " << endl;
    //cout << "enter configuration file name: ";
    
    string inputtext;

    cin >> inputtext;

    //execute read from file
    readFromFile(inputtext);


    return 0;
}