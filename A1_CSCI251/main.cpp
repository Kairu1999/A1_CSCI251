#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "readFile.h"

using namespace std;

int main()
{
    //variable declaration:
    string str{}, choice{};

    //print name
    cout << "Student ID   : "   << "8039082" << endl;
    cout << "Student Name : "   << "Shane-Kyle Chua" << endl;
    cout << "------------------------------------------------- " << endl;
    cout << "Welcome to Weather Information Processing System! " << endl;
    cout << endl;
    cout << "1)     " << "Read in and process a configuration file" << endl;
    cout << "2)     " << "Display city map" << endl;
    cout << "3)     " << "Display cloud coverage map(cloudiness index)" << endl;
    cout << "4)     " << "Display cloud coverage map(LMH symbols)" << endl;
    cout << "5)     " << "Display atmospheric pressure map(pressure index)" << endl;
    cout << "6)     " << "Display atmospheric pressure map(LMH symbols)" << endl;
    cout << "7)     " << "Show Weather forecast summary report" << endl;
    cout << "8)     " << "Quit" << endl;

    cout << "Please enter your choice :";

    //take input!
    cin >> choice;


    switch (stoi(choice)) 
    {
        case 1:
            cout << "[Read in and process a configuration file]" << endl;
            cout << "Please enter config filename :";
            cin >> str;

            //parse filename to read from file
            readFromFile(str);

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
        default:
            cout << "Hello World" << endl;

    }
    //cout << "enter configuration file name: ";
    
    string inputtext;

    cin >> inputtext;

    //execute read from file
    readFromFile(inputtext);


    return 0;
}