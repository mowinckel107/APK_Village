
#include "Innkeeper.h"

std::string Innkeeper::checkMenuItem(int menuItem)
{
    std::string food = boostTavern.getFood(menuItem); //0, 1, 2
    return food;
}

void Innkeeper::addToCleaning(struct stableBoy newCleaner)
{
    std::cout << "Adding stableboy to cleaning" << std::endl;
    cleaningSignal.connect(newCleaner);
}

void Innkeeper::addToCleaning(struct Barmaid newCleaner)
{
    std::cout << "Adding barmaid to cleaning" << std::endl;
    cleaningSignal.connect(newCleaner);
}

void Innkeeper::clean()
{
    cleaningSignal();
    //std::cout << "Stableboy is currently cleaning" << std::endl;
}

void Innkeeper::addAssistant()
{
    std::cout << "Adding assistant to catering" << std::endl;
}

Tavern Innkeeper::getTavern()
{
    return boostTavern;
}