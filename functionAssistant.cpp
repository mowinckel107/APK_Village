#include "functionAssistant.h"

void donation(int coins, int &totalMoney)
{
    std::cout << "    Donating " << 2*coins << " coins to the inn" << std::endl;
    totalMoney += 2*coins;
}

void FunctionAssistant::saveFunction(boost::function<void(int, int &)> incomingFunction)
{
    cb_ = incomingFunction;
}


void FunctionAssistant::runSaved(int money, int &totalMoney)
{
    if (!cb_.empty())
        cb_(money, innRegister);
    else
        std::cout << "    FunctionAssistantFunction is empty function" << std::endl;
}

void FunctionAssistant::runSavedOnce(int money, int &totalMoney)
{
    if (!cb_.empty())
    {
        cb_(money, innRegister);
        cb_.clear();
    }
    else
        std::cout << "    FunctionAssistantFunction is empty function" << std::endl;
}

void FunctionAssistant::swapSaved(boost::function<void(int,int &)> incomingFunction)
{
    if (!cb_.empty())
        cb_.swap(incomingFunction);
    else
        std::cout << "    FunctionAssistantFunction is empty function" << std::endl;
}

int FunctionAssistant::getRegister()
{
    return innRegister;
}

void FunctionAssistant::emptyFunction()
{
    cb_.empty();
}