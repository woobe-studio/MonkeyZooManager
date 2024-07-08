#include "monkey.hpp"
namespace Monkey
{
    DartMonkey::DartMonkey()
    {
        this->baloonsPopped = 162;
    }

    DartMonkey::~DartMonkey()
    {
    }

    int DartMonkey::getBaloonsPopped()
    {
        return baloonsPopped;
    }

    void DartMonkey::setBaloonsPopped(int newBaloonsPopped)
    {
        baloonsPopped = newBaloonsPopped;
    }
    void DartMonkey::to_json(json &j) const
    {
        Monkey::to_json(j);
        j["baloonsPopped"] = this->baloonsPopped;
        j["MonkeyType"] = "DartMonkey";
    }
    void DartMonkey::from_json(const json &j) {}
    void DartMonkey::from_json(const json &j, Space *ptrSpace) {}
}
