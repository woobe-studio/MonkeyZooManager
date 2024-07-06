#include "monkey.hpp"
namespace Monkey
{
    DartMonkey::DartMonkey()
    {
    }

    DartMonkey::~DartMonkey()
    {
    }

    int DartMonkey::getBaloonsPopped()
    {
        return baloonsPopped;
    }

    void DartMonkey::setBaloonsPopped(int newBaloonsPopped)
    {
        baloonsPopped = newBaloonsPopped;
    }
}
