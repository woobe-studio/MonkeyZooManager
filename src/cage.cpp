#include "monkey.hpp"

class Cage
{
private:
    int cageId;
    std::string name;
    int numberOfCams;
    std::string cageColor;

public:
    Cage()
    {
        cageId = 0;
        name = "";
        numberOfCams = 0;
        cageColor = "";
    }

    ~Cage() {}

    int getCageId()
    {
        return cageId;
    }

    std::string getName()
    {
        return name;
    }

    int getNumberOfCams()
    {
        return numberOfCams;
    }

    std::string getCageColor()
    {
        return cageColor;
    }

    void setCageId(int newCageId)
    {
        cageId = newCageId;
    }

    void setName(std::string newName)
    {
        name = newName;
    }

    void setNumberOfCams(int newNumberOfCams)
    {
        numberOfCams = newNumberOfCams;
    }

    void setCageColor(std::string newCageColor)
    {
        cageColor = newCageColor;
    }
};