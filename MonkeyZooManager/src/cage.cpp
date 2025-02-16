#include "monkey.hpp"
namespace Monkey
{
    Cage::Cage()
    {
        cageId = 1;
        this->cageName = "Outdoor Marmoset";
        numberOfCameras = 2;
        cageColor = "Black";
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
    void Cage::to_json(json &j) const
    {
        Space::to_json(j);
        j["spaceType"] = "Cage";
        j["cageId"] = this->cageId;
        j["cageName"] = this->cageName;
        j["numberOfCameras"] = this->numberOfCameras;
        j["cageColor"] = this->cageColor;
    }
    void Cage::from_json(const json &j)
    {
        Space::from_json(j);
        cageId = j.at("cageId").get<int>();
        cageName = j.at("cageName").get<std::string>();
        numberOfCameras = j.at("numberOfCameras").get<int>();
        cageColor = j.at("cageColor").get<std::string>();
    }
}
