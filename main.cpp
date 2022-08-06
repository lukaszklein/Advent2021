
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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

int CountDepthIncrease(const vector<int>& vInput)
{
    int Counter{};
    for (int i = 1; i < vInput.size(); ++i)
    {
        if (vInput.at(i-1) < vInput.at(i))
        {
            ++Counter;
        }
    }
    return Counter;
}

int main()
{
    vector<int> mvInput{};
    PrepareInput(mvInput);
    cout << "Depth increased " << CountDepthIncrease(mvInput) << " times" << endl;

    return 0;
}