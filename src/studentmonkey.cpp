#include "monkey.hpp"

namespace Monkey
{
    StudentMonkey::StudentMonkey()
    {
    }

    StudentMonkey::~StudentMonkey()
    {
    }

    int StudentMonkey::getExamsToRetake()
    {
        return examsToRetake;
    }

    void StudentMonkey::setExamsToRetake(int newExamsToRetake)
    {
        examsToRetake = newExamsToRetake;
    }
}