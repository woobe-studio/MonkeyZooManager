#include "monkey.hpp"
namespace Monkey
{
    Monkey::Monkey() {}
    Monkey::~Monkey() {}

    std::string Monkey::getMonkeyOrigin() { return this->monkeyOrigin; }
    float Monkey::getMonkeyJumpHeight() { return this->monkeyJumpHeight; }
    float Monkey::getToleratedTempMax() { return this->toleratedTempMax; }
    float Monkey::getToleratedTempMin() { return this->toleratedTempMin; }
    float Monkey::getFoodPounds() { return this->foodPounds; }

    void Monkey::setMonkeyOrigin(std::string newMonkeyOrigin) { this->monkeyOrigin = newMonkeyOrigin; }
    void Monkey::setMonkeyJumpHeight(float newMonkeyJumpHeight) { this->monkeyJumpHeight = newMonkeyJumpHeight; }
    void Monkey::setToleratedTempMax(float newTemp) { this->toleratedTempMax = newTemp; }
    void Monkey::setToleratedTempMin(float newTemp) { this->toleratedTempMin = newTemp; }
    void Monkey::setFoodPounds(float newFoodPounds) { this->foodPounds = newFoodPounds; }

    void Monkey::to_json(json &j) const
    {
        Animal::to_json(j);
        j["monkeyOrigin"] = this->monkeyOrigin;
        j["monkeyJumpHeight"] = this->monkeyJumpHeight;
        j["toleratedTempMax"] = this->toleratedTempMax;
        j["toleratedTempMin"] = this->toleratedTempMin;
        j["foodPounds"] = this->foodPounds;
        j["animalType"] = "Monkey";
    }
    void Monkey::from_json(const json &j)
    {
        Animal::from_json(j);
        this->monkeyOrigin = j.at("monkeyOrigin").get<std::string>();
        this->monkeyJumpHeight = j.at("monkeyJumpHeight").get<float>();
        this->toleratedTempMax = j.at("toleratedTempMax").get<float>();
        this->toleratedTempMin = j.at("toleratedTempMin").get<float>();
        this->foodPounds = j.at("foodPounds").get<float>();
    }
}
