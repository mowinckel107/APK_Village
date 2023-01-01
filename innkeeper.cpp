#include "Innkeeper.h"
#include <boost/optional/optional_io.hpp> //Denne er vigtig for at outputte returns

Innkeeper::Innkeeper()
{
    futureCook_ = Cook (&futureHunter_);
}

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

//void Innkeeper::fireFromCleaning(struct stableBoy newCleaner)
//{
//    std::cout << newCleaner.name_ << " is fired from cleaning" << std::endl;

//    cleaningSignal.disconnect(newCleaner);

    //Alternativt: Connect newcleaner, derefter disconnect
    //boost::signals2::connection f = cleaningSignal.connect(newCleaner);
    //f.disconnect(); //Disconnect f, som nu er en connect der indeholder newCleaner
//}

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

BindMixer Innkeeper::getBindMixer()
{
    return boostedBindMixer;
}

void Innkeeper::removeMoneyFromTheRegister(int coins, int& totalCoins)//int coins, int& totalCoins)
{
    std::cout << "The register contains " << &totalCoins << " coins" << std::endl;
    if (totalCoins > coins)
    {
        std::cout << "Removing " << coins << " coins from the register" << std::endl;
        totalCoins -= coins;
        money = coins;
    }
    else
        std::cout << "The register does not contain " << coins << " coins" << std::endl; 
}

void Innkeeper::tellAssistantToGetReadyToPay(FunctionAssistant& FA)
{
    FA.emptyFunction();
    FA.saveFunction(boost::bind(&Innkeeper::removeMoneyFromTheRegister, this, boost::placeholders::_1, boost::placeholders::_2));
}

void Innkeeper::startCook(std::string recipe)
{
    std::cout << "Ordering cook to start the recipe: " << recipe << std::endl;
    std::cout << std::endl << futureCook_.CookFood(recipe) << std::endl;
}