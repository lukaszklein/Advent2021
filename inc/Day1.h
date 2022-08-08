#ifndef DAY1_H
#define DAY1_H

#include "CommonUtilities.h"


class Day1
{
    public:
        static void PrintSolutionA();
        static void PrintSolutionB();

    private:
        Day1();
        void ConvertInput();
        void CountDepthIncrease();
        void PrintSolution();
    
        vector<string> stringinput{};
        vector<int> intinput{};
        int windowlength{1};
        int depthincreasecounter{};
};

#endif