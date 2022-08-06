
#include "day1.h"
#include <iostream>
#include <fstream>
#include <numeric>


void PrepareInput(vector<int>& vInput)
{
    string Line{};
    cout << "Opening file with input \"input.txt\"" << endl;
    ifstream Myfile("input.txt");
    if (Myfile.is_open())
    {
        while (getline(Myfile,Line))
        {
            vInput.push_back(stoi(Line));
        }
    Myfile.close();
  }
}

int CountDepthIncrease(vector<int> vInput, const int Width)
{
    int Counter{},
        ValueA{accumulate(vInput.begin(), vInput.begin() + Width, 0)},
        ValueB{};
        
    vInput.erase(vInput.begin());

    while (vInput.size() >= Width)
    {
        ValueB = accumulate(vInput.begin(), vInput.begin() + Width, 0);
        if (ValueA < ValueB)
        {
            ++Counter;
        }
        vInput.erase(vInput.begin());
        ValueA = ValueB;
    }

    return Counter;
}

int main()
{
    vector<int> mvInput{};
    PrepareInput(mvInput);
    cout << "Depth increased for single measurements " << CountDepthIncrease(mvInput) << " times" << endl;
    cout << "Depth increased for sliding window sum measurements " << CountDepthIncrease(mvInput, 3) << " times" << endl;

    return 0;
}