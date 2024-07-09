#include "monkey.hpp"

namespace Monkey
{
    BehavioralNote::BehavioralNote()
    {
        mood = 3;
        sleepTime = 12.0;
        activeTime = 5.0;
        isSocializing = false;
    }

    BehavioralNote::~BehavioralNote() {}

    int BehavioralNote::getMood()
    {
        return mood;
    }

    float BehavioralNote::getSleepTime()
    {
        return sleepTime;
    }
    float BehavioralNote::getActiveTime()
    {
        return activeTime;
    }
    bool BehavioralNote::getIsSocializing()
    {
        return isSocializing;
    }

    void BehavioralNote::setMood(int newMood)
    {
        mood = newMood;
    }

    void BehavioralNote::setSleepTime(float newSleepTime)
    {
        sleepTime = newSleepTime;
    }
    void BehavioralNote::setActiveTime(float newActiveTime)
    {
        activeTime = newActiveTime;
    }
    void BehavioralNote::setIsSocializing(bool newIsSocializing)
    {
        isSocializing = newIsSocializing;
    }
    void BehavioralNote::to_json(json &j) const {}
    void BehavioralNote::to_json(json &j) const
    {
        Note::to_json(j);

        j["mood"] = mood;
        j["sleepTime"] = sleepTime;
        j["activeTime"] = activeTime;
        j["isSocializing"] = isSocializing;
        j["noteType"] = "behavioralNote";
    }
    void BehavioralNote::from_json(const json &j)
    {
        Note::from_json(j);
        this->mood = j.at("mood").get<int>();
        this->sleepTime = j.at("sleepTime").get<float>();
        this->activeTime = j.at("activeTime").get<float>();
        this->isSocializing = j.at("isSocializing").get<bool>();
    }
}