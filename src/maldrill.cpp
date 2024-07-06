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
}
