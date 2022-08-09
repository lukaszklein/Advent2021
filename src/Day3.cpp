#include "Day3.h"
#include <iostream>
#include <numeric>


Day3::Day3()
{
    this->stringinput = CommonUtilities::ReadInputFile("3");
}

void Day3::CalculatePowerRates()
{
    vector<int> countones = CountOnesByPosition(this->stringinput);

    for (const auto& e : countones)
    {
        if (this->stringinput.size() - e <= e)
        {
            ++this->gammarate;
        }
        this->gammarate <<= 1;
    }
    this->gammarate >>= 1;
    this->epsilonrate = ~(this->gammarate) & mask;
}

int Day3::CalculateOxygenRating()
{
    vector<string> uptodatelines = this->stringinput;
    int bitposition{};
    while (uptodatelines.size() > 1)
    {
        vector<string> templines{};
        vector<int> countones = this->CountOnesByPosition(uptodatelines);
        char filter = countones.at(bitposition) >= uptodatelines.size() - countones.at(bitposition) ? '1' : '0';
        for (const auto& e : uptodatelines)
        {
            if (e.at(bitposition) == filter)
            {
                templines.push_back(e);
            }
        }
        uptodatelines = templines;
        ++bitposition;
    }

    return stoi(uptodatelines.at(0), nullptr, 2);
}

int Day3::CalculateCO2Rating()
{
    vector<string> uptodatelines = this->stringinput;
    int bitposition{};
    while (uptodatelines.size() > 1)
    {
        vector<string> templines{};
        vector<int> countones = this->CountOnesByPosition(uptodatelines);
        char filter = countones.at(bitposition) < uptodatelines.size() - countones.at(bitposition) ? '1' : '0';
        for (const auto& e : uptodatelines)
        {
            if (e.at(bitposition) == filter)
            {
                templines.push_back(e);
            }
        }
        uptodatelines = templines;
        ++bitposition;
    }

    return stoi(uptodatelines.at(0), nullptr, 2);
}

vector<int> Day3::CountOnesByPosition(vector<string>& Input)
{
    vector<int> countones{};
    this->mask = 0;
    for (int i{}; i < Input.at(0).size(); ++i)
    {
        countones.push_back(0);
        ++this->mask;
        this->mask <<= 1;
    }
    this->mask >>= 1;

    for (const auto& line : Input)
    {
        // cout << "line " << line.size() << endl;
        for (int i{}; i < countones.size(); ++i)
        {
            // cout << i << endl;
            if (line.at(i) == '1')
            {
                ++countones.at(i);
            }
        }
    }
    return countones;
}

void Day3::PrintSolutionA()
{
    Day3 DayA;
    DayA.CalculatePowerRates();
    cout << "Gamma rate: " << DayA.gammarate << endl << "Epsilon rate: " << DayA.epsilonrate << endl <<
    "Power consumption " << DayA.gammarate * DayA.epsilonrate << endl << endl;
}

void Day3::PrintSolutionB()
{
    Day3 DayB;
    int oxygen{DayB.CalculateOxygenRating()},
        co2{DayB.CalculateCO2Rating()};
    cout << "Oxygen generator rating: " << oxygen << endl << "CO2 scrubber rating: " << co2 << endl <<
    "Life support rating: " << oxygen * co2 << endl << endl;
}