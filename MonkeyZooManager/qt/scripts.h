#ifndef SCRIPTS_H
#define SCRIPTS_H

#include "../src/monkey.hpp"

// Declaration of custom_init function
void custom_init();

std::string getSpaceName(Monkey::Space* space);
std::string getMonkeyName(Monkey::Animal* monkey);
std::string rarityToString(Monkey::Rarity r);


#endif // SCRIPTS_H
