#include <concepts>
#include <iostream>
#include "BankHelpers.h"

class Bank
{
private:
    
public:
    template<HasMoney T>
    void customerArrives(T& customer) 
    {
        std::cout << "Welcome to the bank! You have " << customer.GetMoney() << " money" << std::endl;
    }
};
