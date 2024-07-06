#include "monkey.hpp"

namespace Monkey
{
    OtherNote::OtherNote()
    {
        topic = "";
    }

    OtherNote::~OtherNote() {}

    std::string OtherNote::getTopic()
    {
        return topic;
    }
    void OtherNote::setTopic(const std::string &newTopic)
    {
        topic = newTopic;
    }
}
