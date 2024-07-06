#include "monkey.hpp"
namespace Monkey
{
    DartMonkey::DartMonkey()
    {
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
    void DartMonkey::to_json(json &j) const {}
    void DartMonkey::from_json(const json &j) {}
    void DartMonkey::from_json(const json &j, Space *ptrSpace) {}
}
