//#include <concepts>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "BankHelpers.h"


class Bank
{
private:
    std::unordered_map<int, int> passbook;
    std::vector<int> transactions;
public:
    Bank();

    void PrintPassbook();

    long getTotalMoneyInBank();
    int getsmallestTransaction();

    template<HasMoneyAndId T>
    void customerArrives(T& customer) 
    {
        std::cout << "    Welcome to the bank customer with id: " << customer.GetId() << "! You have added " << customer.GetMoney() << " money to the bank" << std::endl;
        transactions.push_back(customer.GetMoney());

        passbook[customer.GetId()] += customer.GetMoney();
    }
};
