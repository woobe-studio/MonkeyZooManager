#include "monkey.hpp"
namespace Monkey
{
    Monkey::Monkey() {}
    Monkey::~Monkey() {}

    std::string Monkey::getMonkeOrigin() { return this->monkeOrigin; }
    float Monkey::getMonkeJumpHeight() { return this->monkeJumpHeight; }
    float Monkey::getToleratedTempMax() { return this->toleratedTempMax; }
    float Monkey::getToleratedTempMin() { return this->toleratedTempMin; }
    float Monkey::getFoodPounds() { return this->foodPounds; }

    void Monkey::setMonkeOrigin(std::string newMonkeOrigin) { this->monkeOrigin = newMonkeOrigin; }
    void Monkey::setMonkeJumpHeight(float newMonkeJumpHeight) { this->monkeJumpHeight = newMonkeJumpHeight; }
    void Monkey::setToleratedTempMax(float newTemp) { this->toleratedTempMax = newTemp; }
    void Monkey::setToleratedTempMin(float newTemp) { this->toleratedTempMin = newTemp; }
    void Monkey::setFoodPounds(float newFoodPounds) { this->foodPounds = newFoodPounds; }

    void Monkey::to_json(json &j) const
    {
        Animal::to_json(j);
        j["monkeOrigin"] = this->monkeOrigin;
        j["monkeJumpHeight"] = this->monkeJumpHeight;
        j["toleratedTempMax"] = this->toleratedTempMax;
        j["toleratedTempMin"] = this->toleratedTempMin;
        j["foodPounds"] = this->foodPounds;
        j["animalType"] = "Monkey";
    }
    void Monkey::from_json(const json &j) {}
}
