#include "monkey.hpp"
namespace Monkey
{
    GalacticMonkey::GalacticMonkey()
    {
        this->blackHolesCreated = 0;
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
    void GalacticMonkey::to_json(json &j) const
    {
        Monkey::to_json(j);
        j["blackHolesCreated"] = this->blackHolesCreated;
        j["MonkeyType"] = "GalacticMonkey";
    }
    void GalacticMonkey::from_json(const json &j)
    {
        Monkey::from_json(j);
        this->blackHolesCreated = j.at("blackHolesCreated").get<int>();
    }
}
