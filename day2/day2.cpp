#include "day2.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <numeric>


void PrepareInputVer1(vector<int>& vDepth, vector<int>& vHorizontal)
{
    string Line{};
    cout << "Opening file with input \"input.txt\"" << endl;
    ifstream Myfile("input.txt");
    smatch smatch{};
    regex expression{"[0-9]+"},
          up{"up"},
          down{"down"};
    if (Myfile.is_open())
    {
        while (getline(Myfile,Line))
        {
            regex_search(Line, smatch, expression);
            string match = smatch.str(0);
            if (regex_search(Line, smatch, up))
            {
                vDepth.push_back((-1) * stoi(match));
            }
            else if (regex_search(Line, smatch, down))
            {
                vDepth.push_back(stoi(match));
            }
            else
            {
                vHorizontal.push_back(stoi(match));
            }
        }
    Myfile.close();
  }
}

void PrepareInputVer2(vector<int>& vDepth, vector<int>& vHorizontal)
{
    string Line{};
    cout << "Opening file with input \"input.txt\"" << endl;
    ifstream Myfile("input.txt");
    smatch smatch{};
    regex expression{"[0-9]+"},
          up{"up"},
          down{"down"};
    int aim{};
    if (Myfile.is_open())
    {
        while (getline(Myfile,Line))
        {
            regex_search(Line, smatch, expression);
            string match = smatch.str(0);
            if (regex_search(Line, smatch, up))
            {
                aim -=stoi(match);
            }
            else if (regex_search(Line, smatch, down))
            {
                aim +=stoi(match);
            }
            else
            {
                vHorizontal.push_back(stoi(match));
                vDepth.push_back(stoi(match) * aim);
            }
        }
    Myfile.close();
  }
}

int main()
{
    vector<int> vDepth{},
                vHorizontal{};
    PrepareInputVer2(vDepth, vHorizontal);

    int Horizontal{accumulate(vHorizontal.begin(), vHorizontal.end(), 0)},
        Depth{accumulate(vDepth.begin(), vDepth.end(), 0)};
    cout << "Horizontal position is " << Horizontal << endl;
    cout << "Depth is " << Depth << endl;
    cout << "Product is " << Horizontal * Depth << endl;
}