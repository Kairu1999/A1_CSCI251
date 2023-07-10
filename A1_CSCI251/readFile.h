#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<string> readFromFile(string filename);
vector<string> splitString(string input, string delimiter);
void readFromFileToMap(string filename);
#endif
