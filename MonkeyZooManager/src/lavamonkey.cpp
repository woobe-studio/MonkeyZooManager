#include "monkey.hpp"
namespace Monkey
{
    LavaMonkey::LavaMonkey()
    {
        this->jumpHeight = 1;
    }

    LavaMonkey::~LavaMonkey()
    {
    }

    float LavaMonkey::getJumpHeight()
    {
        return jumpHeight;
    }

    void LavaMonkey::setJumpHeight(float newJump)
    {
        jumpHeight = newJump;
    }
    void LavaMonkey::to_json(json &j) const
    {
        Monkey::to_json(j);
        j["jumpHeight"] = this->jumpHeight;
        j["MonkeyType"] = "LavaMonkey";
    }
    void LavaMonkey::from_json(const json &j)
    {
        Monkey::from_json(j);
        this->jumpHeight = j.at("jumpHeight").get<float>();
    }
}
