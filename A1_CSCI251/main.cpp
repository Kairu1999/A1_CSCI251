#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Header Files:
#include "main.h"
#include "readFile.h"
#include "grid.h"
#include "MemoryAllocation.h"
using namespace std;

string display_main_menu() 
{
    string choice{};
    cout << "========================================================" << endl;
    //print name
    cout << "Student ID   : " << "8039082" << endl;
    cout << "Student Name : " << "Shane-Kyle Chua" << endl;
    cout << "========================================================"<< endl;
    cout << "Welcome to Weather Information Processing System!" << endl;
    cout << endl;
    cout << "1)     " << "Read in and process a configuration file" << endl;
    cout << "2)     " << "Display city map" << endl;
    cout << "3)     " << "Display cloud coverage map(cloudiness index)" << endl;
    cout << "4)     " << "Display cloud coverage map(LMH symbols)" << endl;
    cout << "5)     " << "Display atmospheric pressure map(pressure index)" << endl;
    cout << "6)     " << "Display atmospheric pressure map(LMH symbols)" << endl;
    cout << "7)     " << "Show Weather forecast summary report" << endl;
    cout << "8)     " << "Quit" << endl;
    cout << "========================================================" << endl;
    cout << "Please enter your choice : " ;

    //take input!
    cin >> choice;

    return choice;
}

int main()
{

    //variable declaration:
    string str{}, choice;
    vector<string> files{};

    //return to main menu boolean
    bool returnToMain = true;

    
    //2D Arrays to Allocate Memory For
    int** cityStructure{};
    int** Cloudy{};
    int** Pressure{};

    //run the main meny
    while (true) 
    {
        //run main menu loop
        choice = display_main_menu();
        switch (stoi(choice))
        {
            //switch cases:
        case 1:
            cout << "[Read in and process a configuration file]" << endl;
            cout << "Please enter config filename :";
            cin >> str;

            cout << endl;
            //parse filename to read from file
            files = readConfigFile(str);

            if (!files.empty()) {
         

                cout << "Reading in GridX_IdxRange: " << files[0] << "-" << files[1] << "...done!" << endl;
                cout << "Reading in GridX_IdxRange: " << files[2] << "-" << files[3] << "...done!" << endl;

                cout << endl;

                cout << "Storing data from input_file: " << endl;
                for (int i = 4; i < files.size(); ++i)
                {
                    cout << files[i] << "...done!" << endl;
                }


                cout << endl;
                cout << "All records successfully stored. Going back to main menu..." << endl;
                cout << endl;

                //allocate memory
                cityStructure = Allocate2DArrayMemory(stoi(files[1]), stoi(files[3]));
                Cloudy = Allocate2DArrayMemory(stoi(files[1]), stoi(files[3]));
                Pressure = Allocate2DArrayMemory(stoi(files[1]), stoi(files[3]));
                //try
                readMapFile(files[4]);

                //readCloudCoverFile(files[5]);
                //readPressureFile(files[6]);
                

            }
            else {
                cout << "Filename: " << str << " could not be parsed. Going back to main menu..." << endl;
                cout << endl;

            }
            break;

        case 2:
            cout << "Displaying City Map!" << endl;
            break;
        case 3:
            cout << "Displaying Cloud Coverage Map!" << endl;
            break;
        case 4:
            cout << "Displaying Cloud Coverage Map with LMH Symbols!" << endl;
            break;
        case 5:
            cout << "Displaying Atmospheric Pressure! " << endl;
            break;
        case 6:
            cout << "Displaying Atmospheric Pressure with LMH Symbols!" << endl;
            break;
        case 7:
            cout << "Displaying Weather Forecast Summary Report!" << endl;
            break;
        case 8:
            cout << "Exiting Program. Goodbye!" << endl;
            
            //Deallocate memory here!
            DeAllocate2DArrayMemory(cityStructure, stoi(files[1]));
            DeAllocate2DArrayMemory(Cloudy, stoi(files[1]));
            DeAllocate2DArrayMemory(Pressure, stoi(files[1]));
                /*=================================
                = Deallocate Memory for Grid Here =
                =================================*/

            return 0;

        default:
            break;

        }
    }
    return 0;
}