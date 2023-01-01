#include "Bank/Bank.h"
#include "Reduce/Reduce.h"
#include "Reduce/MinPolicy.h"
#include <vector>
#include <limits.h>
#include <iostream>

template<typename T>
struct MyMinTraits;

template<>
struct MyMinTraits<int>
{
    using Result = int;
    static Result const startValue = INT_MAX;
};

Bank::Bank()
{
    transactions = {5,7,13,5,20};
}

void Bank::PrintPassbook()
{
    for (auto const &pair: passbook)
    {
        std::cout << "    id: " << pair.first << " have " << pair.second << " money in the bank" << std::endl;
    }
    
}

long Bank::getTotalMoneyInBank()
{
    return reduce<int>(transactions.begin(),transactions.end());
}

int Bank::getsmallestTransaction()
{
    return reduce<int, MinPolicy, MyMinTraits<int>>(transactions.begin(), transactions.end());
}