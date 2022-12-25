#include "tavern.h"
#include "boost/signals2.hpp"
#include <iostream>

struct stableBoy //Fri struct
{
    void operator()() const
    {
        std::cout << name_ << " the stableboy is cleaning the stables" << std::endl;
    }
    std::string name_;
};

struct Barmaid
{
    void operator()() const
    {
        std::cout << name_ << " the barmaid is cleaning the tables" << std::endl;
    }
    std::string name_;
};

class Innkeeper
{
private:
    Tavern boostTavern;
    boost::signals2::signal<void()> cleaningSignal;
    boost::signals2::signal<void()> bringFoodAndDrinkSignal;
public:
    std::string makeFood();
    std::string bringFood();
    std::string bringAle(std::string);
    std::string replaceFood(std::string);
    std::string checkMenuItem(int);
    void clean();
    void addAssistant();
    void addToCleaning(struct stableBoy newCleaner);
    void addToCleaning(struct Barmaid newCleaner);
    Tavern getTavern();
};

