#include "monkey.hpp"
namespace Monkey
{
    GalacticMonkey::GalacticMonkey()
    {
    }

    GalacticMonkey::~GalacticMonkey()
    {
    }

    int GalacticMonkey::getBlackHolesCreated()
    {
        return blackHolesCreated;
    }

    void GalacticMonkey::setBlackHolesCreated(int newBlackHolesCreated)
    {
        blackHolesCreated = newBlackHolesCreated;
    }
}
