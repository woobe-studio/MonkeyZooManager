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
    void OtherNote::to_json(json &j) const
    {
        Note::to_json(j);

        j["topic"] = topic;
        j["noteType"] = "otherNote";
    }
    void OtherNote::from_json(const json &j)
    {
        Note::from_json(j);
        this->topic = j.at("topic").get<float>();
    }
}
