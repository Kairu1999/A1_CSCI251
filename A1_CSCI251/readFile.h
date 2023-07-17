#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Structs.h"

using namespace std;
vector<string> readConfigFile(string filename);
vector<string> splitString(string input, string delimiter);
vector<cityStructure> readMapFile(string filename);
vector<cloudyPressure> readCloudCoverFile(string filename);
vector<cloudyPressure> readPressureFile(string filename);

#endif
