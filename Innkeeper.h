#pragma once

#include "tavern.h"
#include "boost/signals2.hpp"
#include <iostream>
#include "bindMixer.h"
#include "functionAssistant.h"
#include "Cook.h"

struct stableBoy //Fri struct
{
    void operator()() const
    {
        std::cout << "    " << name_ << " the stableboy is cleaning the stables" << std::endl;
    }
    bool operator==(stableBoy const& incoming) const
    {
        return (this->name_ == incoming.name_);
    }
    std::string name_;
};

struct Barmaid
{
    void operator()() const
    {
        std::cout << "    " << name_ << " the barmaid is clearing the tables" << std::endl;
    }
    std::string name_;
};

class Innkeeper
{
private:
    Tavern boostTavern;
    BindMixer boostedBindMixer;
    boost::signals2::signal<void()> cleaningSignal;
    boost::signals2::signal<bool(std::string)> superSpecificCleaningSignal;
    Hunter futureHunter_;
    Cook futureCook_;
    int money = 0;
    //Combiners: Man kan lave en struct som tager inputtet fra alle signalerne og sammenligner dem... Det giver mening for talværdier, men måske ikke så meget her
    //Sådan en reducer f.eks.
public:
    Innkeeper();
    std::string checkMenuItem(int);
    void clean();
    void clean(std::string);
    void addAssistant();
    template<typename Cleaner>
    void addToCleaning(Cleaner newCleaner);
    template<typename Cleaner>
    void fireFromCleaning(Cleaner hiredCleaner);
    template<typename Cleaner>
    void tempWorker(Cleaner newCleaner);

    void addToCleaning(struct stableBoy newCleaner); //detect type in class - metaprogramming
    void addToCleaning(struct Barmaid newCleaner); //detect type in class
    void addToCleaning(void (*)()); //detect type in class
    void addToSpecificCleaning(bool(*)(std::string));
    //void fireFromCleaning(struct stableBoy newCleaner);

    Tavern getTavern();
    BindMixer getBindMixer();
    void removeMoneyFromTheRegister(int, int&);
    void tellAssistantToGetReadyToPay(FunctionAssistant&);
    void startCook(std::string);
};

template<typename Cleaner>
void Innkeeper::fireFromCleaning(Cleaner hiredCleaner)
{
    std::cout << "    Firing cleaner" << std::endl;
    cleaningSignal.disconnect(hiredCleaner);
}

//template<typename Cleaner>
//void Innkeeper::addToCleaning(Cleaner newCleaner)
//{
//    cleaningSignal.connect(newCleaner);
//}

template<typename Cleaner>
void Innkeeper::tempWorker(Cleaner newCleaner)
{
    std::cout << "    Temp cleaner hired" << std::endl;
    boost::signals2::scoped_connection c = cleaningSignal.connect(newCleaner);
    cleaningSignal();
}//newCleaner is disconnected