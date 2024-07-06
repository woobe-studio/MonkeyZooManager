#include "monkey.hpp"

namespace Monkey
{
    BehavioralNote::BehavioralNote()
    {
        mood = 0;
        sleepTime = 0.0;
        activeTime = 0.0;
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
}