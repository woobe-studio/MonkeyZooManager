#include "monkey.hpp"

namespace Monkey
{
    MedicalNote::MedicalNote()
    {
        costOfMedications = 0.0;
        proceduresCost = 0.0;
    }

    MedicalNote::~MedicalNote() {}

    float MedicalNote::getCostOfMedications()
    {
        return costOfMedications;
    }
    float MedicalNote::getProceduresCost()
    {
        return proceduresCost;
    }

    void MedicalNote::setCostOfMedications(float newCost)
    {
        costOfMedications = newCost;
    }
    void MedicalNote::setProceduresCost(float newCost)
    {
        proceduresCost = newCost;
    }
}
