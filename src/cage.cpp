#include "monkey.hpp"
namespace Monkey
{
    Cage::Cage()
    {
        cageId = 0;
        this->cageName = "";
        numberOfCameras = 0;
        cageColor = "";
    }

    Cage::~Cage() {}

    int Cage::getCageId()
    {
        return cageId;
    }

    std::string Cage::getName()
    {
        return cageName;
    }

    int Cage::getNumberOfCams()
    {
        return numberOfCameras;
    }

    std::string Cage::getCageColor()
    {
        return cageColor;
    }

    void Cage::setCageId(int newCageId)
    {
        cageId = newCageId;
    }

    void Cage::setName(std::string newName)
    {
        cageName = newName;
    }

    void Cage::setNumberOfCams(int newNumberOfCams)
    {
        numberOfCameras = newNumberOfCams;
    }

    void Cage::setCageColor(std::string newCageColor)
    {
        cageColor = newCageColor;
    }
    void Cage::to_json(json &j) const {}
    void Cage::from_json(const json &j) {}
}
