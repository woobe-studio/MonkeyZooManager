#include "monkey.hpp"

namespace Monkey
{
    Hospital::Hospital()
    {
        medicineQuantity = 0;
        bedsCount = 0;
        volunteerAmount = 0;
    }

    Hospital::~Hospital() {}

    int Hospital::getMedicineQuantity()
    {
        return medicineQuantity;
    }

    int Hospital::getBedsCount()
    {
        return bedsCount;
    }

    int Hospital::getVolunteerAmount()
    {
        return volunteerAmount;
    }

    void Hospital::setMedicineQuantity(int newMedicineQuantity)
    {
        medicineQuantity = newMedicineQuantity;
    }

    void Hospital::setBedsCount(int newBedCount)
    {
        bedsCount = newBedCount;
    }

    void Hospital::setVolunteerAmount(int newVolunteerAmount)
    {
        volunteerAmount = newVolunteerAmount;
    }
    void Hospital::to_json(json &j) const
    {
        Space::to_json(j);
        j["spaceType"] = "Hospital";
        j["medicineQuantity"] = this->medicineQuantity;
        j["bedsCount"] = this->bedsCount;
        j["volunteerAmount"] = this->volunteerAmount;
    }
    void Hospital::from_json(const json &j) {}
}