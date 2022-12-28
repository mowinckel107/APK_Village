#include "Innkeeper.h"
#include <boost/optional/optional_io.hpp> //Denne er vigtig for at outputte returns

std::string Innkeeper::checkMenuItem(int menuItem)
{
    std::string food = boostTavern.getFood(menuItem); //0, 1, 2
    return food;
}

void Innkeeper::addToCleaning(struct stableBoy newCleaner)
{
    std::cout << "Adding stableboy to cleaning" << std::endl;
    cleaningSignal.connect(newCleaner); //ligeglad hvornår, så bare gør det til sidst
}

void Innkeeper::addToCleaning(struct Barmaid newCleaner)
{
    std::cout << "Adding barmaid to cleaning" << std::endl;
    cleaningSignal.connect(0, newCleaner); //først hent tallerkener ind
}

void Innkeeper::addToCleaning(void newCleaner())
{
    std::cout << "Adding dishwashing to cleaning" << std::endl;
    cleaningSignal.connect(1, newCleaner); //derefter gør dem rent
}

void Innkeeper::addToSpecificCleaning(bool newCleaner(std::string))
{
    superSpecificCleaningSignal.connect(newCleaner);
}

void Innkeeper::fireFromCleaning(struct stableBoy newCleaner)
{
    std::cout << newCleaner.name_ << " is fired from cleaning" << std::endl;

    cleaningSignal.disconnect(newCleaner);

    //Alternativt: Connect newcleaner, derefter disconnect
    //boost::signals2::connection f = cleaningSignal.connect(newCleaner);
    //f.disconnect(); //Disconnect f, som nu er en connect der indeholder newCleaner
}

void Innkeeper::tempWorker(struct stableBoy newCleaner)
{
    std::cout << "Temp cleaner hired" << std::endl;
    boost::signals2::scoped_connection c = cleaningSignal.connect(newCleaner);
    cleaningSignal();
}//newCleaner is disconnected

void Innkeeper::clean()
{
    cleaningSignal();
}

void Innkeeper::clean(std::string name_)
{
    std::cout << "Specific clean is called with " << name_ << std::endl;
    std::cout << "And so it was that " << superSpecificCleaningSignal(name_) << std::endl; //Hvis der er flere med std::string på dette signal, så er det kun den sidste der kommer igennem
    //Med flere talværdier, kan man returnere den højeste talværdi ved at skrive
}

void Innkeeper::addAssistant()
{
    std::cout << "Adding assistant to catering" << std::endl;
}

Tavern Innkeeper::getTavern()
{
    return boostTavern;
}

BindAssistant Innkeeper::getBindAssistant()
{
    return boostedBindAssistant;
}