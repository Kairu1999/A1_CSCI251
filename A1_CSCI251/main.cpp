#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "readFile.h"

using namespace std;

string display_main_menu() 
{
    string choice{};

    //print name
    cout << "Student ID   : " << "8039082" << endl;
    cout << "Student Name : " << "Shane-Kyle Chua" << endl;
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

    return choice;
}

int main()
{

    //variable declaration:
    string str{}, choice;
    vector<string> files{};

    //return to main menu boolean
    bool returnToMain = true;


    //run the main meny
    choice = display_main_menu();
 

    switch (stoi(choice)) 
    {
        returnToMain = false;

        //switch cases:
        case 1:
            cout << "[Read in and process a configuration file]" << endl;
            cout << "Please enter config filename :";
            cin >> str;

            cout << endl;
            //parse filename to read from file
            files = readConfigFile(str); 

            //debug
           /* for (int i = 0; i < files.size(); ++i) 
            {
                cout << files[i] << " ";
            }*/

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
            
            //test read cloud cover file
            //readMapFile(files[4]);
            //readCloudCoverFile(files[5]);
            readPressureFile(files[6]);

            /*============================================*/
            /*          Allocate Memory for Data          */ 
            /*============================================*/
            //option to return to main menu
            returnToMain = true;

        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            return 0;

        default:
            cout << "That is not a valid option!" << endl;
            returnToMain = true;

    }

    if (returnToMain = true) 
    {
        returnToMain = false;
        main();
    }
    return 0;
}