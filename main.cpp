
#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>

using namespace std;
int CountDepthIncrease(vector<int> vInput, const int Width = 1);

void PrepareInput(vector<int>& vInput)
{
    string Line{};
    cout << "Opening file with input \"input1.txt" << endl;
    ifstream Myfile("input1.txt");
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
        cout << vInput.at(0) << endl;
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