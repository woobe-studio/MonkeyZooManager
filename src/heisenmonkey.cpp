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
    void HeisenMonkey::to_json(json &j) const {}
    void HeisenMonkey::from_json(const json &j) {}
    void HeisenMonkey::from_json(const json &j, Space *ptrSpace) {}
}