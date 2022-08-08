#include "CommonUtilities.h"
#include <fstream>
#include <iostream>


vector<string> CommonUtilities::ReadInputFile(const string& daynumber)
{
    vector<string> input{};
    string line{};
    cout << "Opening file with input for task from day " << daynumber << endl;
    ifstream file("..\\resources\\day" + daynumber + "_input.txt");
    if (file.is_open())
    {
        while (getline(file,line))
        {
            input.push_back(line);
        }
        file.close();
    }

    return input;
}