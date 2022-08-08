#ifndef DAY2_H
#define DAY2_H

#include "CommonUtilities.h"


class Day2
{
    public:
        static void PrintSolutionA();
        static void PrintSolutionB();

    private:
        Day2();
        void CalculatePosition(bool useaim = false);
        void PrintSolution();
    
        vector<string> stringinput{};
        int horizontal{},
            depth{};
};

#endif