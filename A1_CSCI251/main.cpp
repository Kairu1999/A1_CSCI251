#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Header Files:
#include "main.h"
#include "readFile.h"
#include "grid.h"
#include "MemoryAllocation.h"
#include "debug.h"
#include "WeatherReport.h"


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

    //store the max X and Y values
    int MaxX{}, MaxY{};

    
    //2D Arrays to Allocate Memory For
    int** CityStructure{nullptr};
    int** Cloudy{nullptr};
    int** Pressure{nullptr};
    int** CloudyLMH{ nullptr };
    int** PressureLMH{ nullptr };

    //Vector to Store Values
    vector<cityStructure>cityVect{};
    vector<cloudyPressure>cloudCoverVect{};
    vector<cloudyPressure>PressureVect{};

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
                cout << "Reading in GridY_IdxRange: " << files[2] << "-" << files[3] << "...done!" << endl;

                cout << endl;

                cout << "Storing data from input_file: " << endl;
                for (int i = 4; i < files.size(); ++i)
                {
                    cout << files[i] << "...done!" << endl;
                }

                //declare the maxX and maxY Value, add 1 to prevent buffer overflow
                MaxX = stoi(files[1]) + 1;
                MaxY = stoi(files[3]) + 1;
 
                //read the map files and populate the Vector of Structs:
                cityVect = readMapFile(files[4]);
                cloudCoverVect = readCloudCoverFile(files[5]);
                PressureVect = readPressureFile(files[6]);

                //allocate memory and populate the array
                CityStructure = Allocate2DArrayMemory_city(MaxX,MaxY,cityVect);
                Cloudy = Allocate2DArrayMemory_cp(MaxX,MaxY,cloudCoverVect);
                Pressure = Allocate2DArrayMemory_cp(MaxX,MaxY,PressureVect);
                //Low Medium High
                CloudyLMH = Allocate2DArrayMemory_cp(MaxX, MaxY, cloudCoverVect);
                PressureLMH = Allocate2DArrayMemory_cp(MaxX, MaxY, PressureVect);


                //Update the 2D Array Values:
                Update2DArray(Cloudy, MaxX,MaxY, 0);
                Update2DArray(CloudyLMH,MaxX, MaxY, 1);
                Update2DArray(Pressure, MaxX, MaxY,0);
                Update2DArray(PressureLMH, MaxX, MaxY, 1);

                cout << endl;

                cout << "Address of CityStructure pointer is: " << CityStructure << endl;
                cout << "Address of CloudCover pointer is: " << Cloudy << endl;
                cout << "Address of Pressure pointer is: " << Pressure << endl;

                cout << endl;
                cout << "All records successfully stored. Going back to main menu..." << endl;
                cout << endl;
                break;

            }
            else {
                cout << "Filename: " << str << " could not be parsed. Going back to main menu..." << endl;
                cout << endl;
                break;

            }
            
            break;

        case 2:
            if (CityStructure == nullptr)
            {
                cout << "Data and Memory Has not been Allocated! Please Return to #1!" << endl;
                break;
            }
            else 
            {
                cout << "Displaying City Map!" << endl;

                // NUMBERS MODE
                generate_grid_city(CityStructure, stoi(files[1]), stoi(files[3]));

                cout << "Press Enter to return to main menu!" << endl;
                cin.ignore();
                cin.ignore();
                break;
            }
        case 3:
            if (Cloudy == nullptr)
            {
                cout << "Data and Memory Has not been Allocated! Please Return to #1!" << endl;
                break;
            }
            else 
            {
                cout << "Displaying Cloud Coverage Map!" << endl;

                //NORMAL MODE
                generate_grid(Cloudy, stoi(files[1]), stoi(files[3]));
                cout << "Press Enter to return to main menu!" << endl;
                cin.ignore();
                cin.ignore();
                break;
            }


        case 4:
            if (CloudyLMH == nullptr)
            {
                cout << "Data and Memory Has not been Allocated! Please Return to #1!" << endl;
                break;
            }
            else 
            {
                cout << "Displaying Cloud Coverage Map with LMH Symbols!" << endl;
                cout << endl;

                generate_gridLMH(CloudyLMH, stoi(files[1]), stoi(files[3]));
                cout << "Press Enter to return to main menu!" << endl;
                cin.ignore();
                cin.ignore();
                break;
            }
        case 5:
            if (Pressure == nullptr)
            {
                cout << "Data and Memory Has not been Allocated! Please Return to #1!" << endl;
                break;
            }
            else
            {
                cout << "Displaying Pressure Map!" << endl;
                cout << endl;

                generate_grid(Pressure, stoi(files[1]), stoi(files[3]));
                cout << "Press Enter to return to main menu!" << endl;
                cin.ignore();
                cin.ignore();
                break;
            }
        case 6:
            if (Pressure == nullptr)
            {
                cout << "Data and Memory Has not been Allocated! Please Return to #1!" << endl;
                break;
            }
            else
            {
                cout << "Displaying Atmospheric Pressure with LMH Symbols!" << endl;
                generate_gridLMH(CloudyLMH, stoi(files[1]), stoi(files[3]));
                cout << "Press Enter to return to main menu!" << endl;
                cin.ignore();
                cin.ignore();
                break;
            }

        case 7:
            //Print Weather Report
            print_weather_report(CityStructure,cityVect,cloudCoverVect ,PressureVect, stoi(files[1]), stoi(files[3]));
            cout << "Press Enter to return to main menu!" << endl;
            cin.ignore();
            cin.ignore();
            break;
        case 8:
            cout << "Exiting Program. Goodbye!" << endl;
            
            //Deallocate memory here!
            DeAllocate2DArrayMemory(CityStructure, stoi(files[1]),stoi(files[3]));
            DeAllocate2DArrayMemory(Cloudy, (stoi(files[1]) + 1), (stoi(files[3]) + 1));
            DeAllocate2DArrayMemory(Pressure, (stoi(files[1]) + 1), (stoi(files[3]) + 1));
            DeAllocate2DArrayMemory(CloudyLMH, (stoi(files[1]) + 1), (stoi(files[3]) + 1));
            DeAllocate2DArrayMemory(PressureLMH, (stoi(files[1]) + 1), (stoi(files[3]) + 1));
            return 0;

        default:
            break;
        }
    }
    return 0;
}