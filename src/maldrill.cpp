#include "monkey.hpp"
namespace Monkey
{
    Maldrill::Maldrill()
    {
    }

    Maldrill::~Maldrill()
    {
    }

    float Maldrill::getJumpHeight()
    {
        return jumpHeight;
    }

    void Maldrill::setJumpHeight(float newJump)
    {
        jumpHeight = newJump;
    }
    void Maldrill::to_json(json &j) const
    {
        Monkey::to_json(j);
        j["jumpHeight"] = this->jumpHeight;
        j["MonkeyType"] = "Maldrill";
    }
    void Maldrill::from_json(const json &j) {}
    void Maldrill::from_json(const json &j, Space *ptrSpace) {}
}
