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

    void OtherNote::to_json(json &j) const {}
    void OtherNote::from_json(const json &j) {}
}
