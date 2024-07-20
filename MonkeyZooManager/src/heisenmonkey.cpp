#include "monkey.hpp"

namespace Monkey
{
    HeisenMonkey::HeisenMonkey()
    {
        this->poundsOfCandyCooked = 450;
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
    void HeisenMonkey::to_json(json &j) const
    {
        Monkey::to_json(j);
        j["poundsOfCandyCooked"] = this->poundsOfCandyCooked;
        j["MonkeyType"] = "HeisenMonkey";
    }
    void HeisenMonkey::from_json(const json &j)
    {
        Monkey::from_json(j);
        this->poundsOfCandyCooked = j.at("poundsOfCandyCooked").get<float>();
    }
}