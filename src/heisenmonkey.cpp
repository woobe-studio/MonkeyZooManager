#include "monkey.hpp"

namespace Monkey
{
    HeisenMonkey::HeisenMonkey()
    {
    }

    HeisenMonkey::~HeisenMonkey()
    {
    }

    float HeisenMonkey::getPoundsOfCandyCooked()
    {
        return static_cast<float>(poundsOfCandyCooked);
    }

    void HeisenMonkey::setPoundsOfCandyCooked(float newPoundsOfCandyCooked)
    {
        poundsOfCandyCooked = newPoundsOfCandyCooked;
    }
}