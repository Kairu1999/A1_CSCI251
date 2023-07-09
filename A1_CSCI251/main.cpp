#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "readFile.h"

using namespace std;

int main()
{
    string s = "Kurwa, blyat, cyka nahui";

    string delim = ", ";

    vector<string>dataItems = splitString(s, delim);

    for (size_t i = 0; i < dataItems.size(); ++i)
    {
        cout << dataItems[i] << endl;
    }

    return 0;
}