#include "monkey.hpp"

namespace Monkey
{
    Enclosure::Enclosure()
    {
        openTime.hour = 0;
        openTime.minute = 0;
        closeTime.hour = 0;
        closeTime.minute = 0;
        visitorSpots = 0;
        temperature = 0.0f;
    }

    Enclosure::~Enclosure() {}

    hourMin Enclosure::getOpenTime()
    {
        return openTime;
    }

    hourMin Enclosure::getCloseTime()
    {
        return closeTime;
    }

    int Enclosure::getVisitorSpots()
    {
        return visitorSpots;
    }

    float Enclosure::getTemperature()
    {
        return temperature;
    }

    void Enclosure::setOpenTime(hourMin newOpenTime)
    {
        openTime = newOpenTime;
    }

    void Enclosure::setCloseTime(hourMin newCloseTime)
    {
        closeTime = newCloseTime;
    }

    void Enclosure::setVisitorSpots(int newVisitorSpots)
    {
        visitorSpots = newVisitorSpots;
    }

    void Enclosure::setTemperature(float newTemperature)
    {
        temperature = newTemperature;
    }
    void Enclosure::to_json(json &j) const
    {
        Space::to_json(j);
        j["visitorsSpots"] = this->visitorSpots;
        j["spaceType"] = "Enclosure";
    }
    void Enclosure::from_json(const json &j) {}
}
