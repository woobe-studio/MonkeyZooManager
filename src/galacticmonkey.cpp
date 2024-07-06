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
    void GalacticMonkey::to_json(json &j) const {}
    void GalacticMonkey::from_json(const json &j) {}
    void GalacticMonkey::from_json(const json &j, Space *ptrSpace) {}
}
