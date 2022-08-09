#ifndef DAY3_H
#define DAY3_H

#include "CommonUtilities.h"


class Day3
{
    public:
        static void PrintSolutionA();
        static void PrintSolutionB();

    private:
        Day3();
        void CalculatePowerRates();
        int CalculateOxygenRating();
        int CalculateCO2Rating();
        vector<int> CountOnesByPosition(vector<string>& Input);

        vector<string> stringinput{};
        int gammarate{},
            epsilonrate{},
            mask{};
};

#endif