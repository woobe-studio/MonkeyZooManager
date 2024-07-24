#include "scripts.h"

void custom_init() {
    Monkey::AuthDaemon* authorizationDaemon = Monkey::AuthDaemon::getInstance();
    Monkey::User* usr = new Monkey::User;
    usr->setUsername("boss");
    usr->setPassword("strong");
    Monkey::Zoo* zoo = new Monkey::Zoo;
    zoo->setZooName("Local Zoo");
    usr->setZoo(zoo);
    Monkey::Cage* testspace = new Monkey::Cage;
    zoo->addSpace(testspace);
    testspace->setCapacity(10);
    Monkey::Cage* testspace2 = new Monkey::Cage;
    zoo->addSpace(testspace2);
    testspace2->setCapacity(10);
    Monkey::Enclosure* testspace3 = new Monkey::Enclosure;
    zoo->addSpace(testspace3);
    testspace3->setCapacity(20);
    Monkey::Hospital* testspace4 = new Monkey::Hospital;
    zoo->addSpace(testspace4);
    testspace4->setCapacity(5);
    authorizationDaemon->addUser(usr);
    int i = 0;
    while (i < 2) {
        Monkey::RichMonkey* itAnimal = new Monkey::RichMonkey;
        int j = 0;
        itAnimal->setName("medd" + i);
        itAnimal->setAge(i);
        while (j < 2) {
            Monkey::Note* itNote = new Monkey::Note;
            itAnimal->addNote(itNote);
            j++;
        }
        testspace2->addAnimal(itAnimal);
        i++;
    }
    i = 0;
    while (i < 2) {
        Monkey::DartMonkey* itAnimal = new Monkey::DartMonkey;
        itAnimal->setName("mnk" + i);
        itAnimal->setAge(i);
        int j = 0;
        while (j < 2) {
            Monkey::Note* itNote = new Monkey::Note;
            itAnimal->addNote(itNote);
            j++;
        }
        testspace->addAnimal(itAnimal);
        i++;
    }
}

std::string getSpaceName(Monkey::Space* space)
{
    std::string space_name;
    if (Monkey::Enclosure* enclosurePtr = dynamic_cast<Monkey::Enclosure*>(space)) {
        space_name = "Enclosure";
    }
    else if (Monkey::Hospital* hospitalPtr = dynamic_cast<Monkey::Hospital*>(space)) {
        space_name = "Hospital";
    }
    else if (Monkey::Cage* cagePtr = dynamic_cast<Monkey::Cage*>(space)) {
        space_name = "Cage";
    }
    return space_name;
}

std::string getMonkeyName(Monkey::Animal*monkey)
{
    std::string monkey_name;
    if (Monkey::StudentMonkey* studentPtr = dynamic_cast<Monkey::StudentMonkey*>(monkey)) {
        monkey_name = "Student Monkey";
    }
    else if (Monkey::GalacticMonkey* galacticPtr = dynamic_cast<Monkey::GalacticMonkey*>(monkey)) {
        monkey_name = "Galactic Monkey";
    }
    else if (Monkey::DartMonkey* dartPtr = dynamic_cast<Monkey::DartMonkey*>(monkey)) {
        monkey_name = "Dart Monkey";
    }
    else if (Monkey::RichMonkey* heisenPtr = dynamic_cast<Monkey::RichMonkey*>(monkey)) {
        monkey_name = "Rich Monkey";
    }
    else if (Monkey::LavaMonkey* lavaPtr = dynamic_cast<Monkey::LavaMonkey*>(monkey)) {
        monkey_name = "Lava Monkey";
    }
    return monkey_name;
}

std::string rarityToString(Monkey::Rarity r)
{
    switch (r)
    {
    case Monkey::Rarity::COMMON:    return "COMMON";
    case Monkey::Rarity::UNCOMMON:  return "UNCOMMON";
    case Monkey::Rarity::RARE:      return "RARE";
    case Monkey::Rarity::EPIC:      return "EPIC";
    case Monkey::Rarity::LEGENDARY: return "LEGENDARY";
    default:                return "UNKNOWN";
    }
}

Monkey::Rarity StringToRarity(std::string r)
{
    std::map<std::string, Monkey::Rarity> rarityMap = {
        {"COMMON", Monkey::Rarity::COMMON},
        {"UNCOMMON", Monkey::Rarity::UNCOMMON},
        {"RARE", Monkey::Rarity::RARE},
        {"EPIC", Monkey::Rarity::EPIC},
        {"LEGENDARY", Monkey::Rarity::LEGENDARY}
    };

    auto it = rarityMap.find(r);
    if (it != rarityMap.end())
    {
        return it->second;
    }
    else
    {
        throw std::invalid_argument("Unknown rarity: " + r);
    }
}