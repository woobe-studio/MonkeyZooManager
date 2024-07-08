#include "monkey.hpp"

namespace Monkey
{
    StudentMonkey::StudentMonkey()
    {
        this->examsToRetake = 5;
    }

    StudentMonkey::~StudentMonkey()
    {
    }

    int StudentMonkey::getExamsToRetake()
    {
        return examsToRetake;
    }

    void StudentMonkey::setExamsToRetake(int newExamsToRetake)
    {
        examsToRetake = newExamsToRetake;
    }

    void StudentMonkey::to_json(json &j) const
    {
        Monkey::to_json(j);
        j["examsToRetake"] = this->examsToRetake;
        j["MonkeyType"] = "StudentMonkey";
    }
    void StudentMonkey::from_json(const json &j) {}
    void StudentMonkey::from_json(const json &j, Space *ptrSpace) {}
}