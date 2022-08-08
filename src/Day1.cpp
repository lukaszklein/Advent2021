#include "Day1.h"
#include <iostream>
#include <numeric>


Day1::Day1()
{
    this->stringinput = CommonUtilities::ReadInputFile("1");
}

void Day1::ConvertInput()
{
    for (const auto& e : this->stringinput)
    {
        this->intinput.push_back(stoi(e));
    }
}

void Day1::CountDepthIncrease()
{
    const int width = this->windowlength;
    int ValueA{accumulate(this->intinput.begin(), this->intinput.begin() + width, 0)},
        ValueB{};
        
    this->intinput.erase(this->intinput.begin());

    while (this->intinput.size() >= width)
    {
        ValueB = accumulate(this->intinput.begin(), this->intinput.begin() + width, 0);
        if (ValueA < ValueB)
        {
            ++this->depthincreasecounter;
        }
        this->intinput.erase(this->intinput.begin());
        ValueA = ValueB;
    }
}

void Day1::PrintSolution()
{
    cout << "For window length " << this->windowlength << " depth increased " << this->depthincreasecounter << " times" << endl << endl;
}

void Day1::PrintSolutionA()
{
    Day1 Day1A;
    Day1A.ConvertInput();
    Day1A.CountDepthIncrease();
    Day1A.PrintSolution();
}

void Day1::PrintSolutionB()
{
    Day1 Day1B;
    Day1B.ConvertInput();
    Day1B.windowlength = 3;
    Day1B.CountDepthIncrease();
    Day1B.PrintSolution();
}