#include "Day2.h"
#include <iostream>
#include <sstream>


Day2::Day2()
{
    this->stringinput = CommonUtilities::ReadInputFile("2");
}

void Day2::CalculatePosition(bool useaim)
{
    int aim{};
    for (const auto& line : this->stringinput)
    {
        stringstream linestream{line};
        string direction{};
        linestream >> direction;
        int value{};
        linestream >> value;
        
        if (direction == "up")
        {
            if (useaim)
            {
                aim += value;
            }
            else
            {
                this->depth -= value;
            }
        }
        else if (direction == "down")
        {
            if (useaim)
            {
                aim -= value;
            }
            else
            {
                this->depth += value;
            }
        }
        else
        {
            this->horizontal += value;
            if (useaim)
            {
                this->depth += value * aim;
            }
        }
    }
    this->depth = abs(this->depth);
}

void Day2::PrintSolution()
{
    cout << "Depth of submarine is " << this->depth << ", horizontal position is " << this->horizontal << "." << endl;
    cout << "Product is " << this->depth * this->horizontal << endl << endl;;
}

void Day2::PrintSolutionA()
{
    Day2 Day2A;
    Day2A.CalculatePosition();
    Day2A.PrintSolution();
}

void Day2::PrintSolutionB()
{
    Day2 Day2B;
    Day2B.CalculatePosition(true);
    Day2B.PrintSolution();
}