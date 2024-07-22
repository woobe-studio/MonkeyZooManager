#include "monkey.hpp"

namespace Monkey
{
    RichMonkey::RichMonkey()
    {
        this->poundsOfCandyCooked = 450;
    }

    RichMonkey::~RichMonkey()
    {
    }

    float RichMonkey::getPoundsOfCandyCooked()
    {
        return static_cast<float>(poundsOfCandyCooked);
    }

    void RichMonkey::setPoundsOfCandyCooked(float newPoundsOfCandyCooked)
    {
        poundsOfCandyCooked = newPoundsOfCandyCooked;
    }
    void RichMonkey::to_json(json &j) const
    {
        Monkey::to_json(j);
        j["poundsOfCandyCooked"] = this->poundsOfCandyCooked;
        j["MonkeyType"] = "RichMonkey";
    }
    void RichMonkey::from_json(const json &j)
    {
        Monkey::from_json(j);
        this->poundsOfCandyCooked = j.at("poundsOfCandyCooked").get<float>();
    }
}