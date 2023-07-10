#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<string> readConfigFile(string filename);
vector<string> splitString(string input, string delimiter);
void readMapFile(string filename);
void readCloudCoverFile(string filename);
void readPressureFile(string filename);

#endif
