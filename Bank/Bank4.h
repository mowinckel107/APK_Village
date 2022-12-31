//#include <type_traits>
#include "BankHelpers.h"


class Bank4
{
private:

public:
    template<typename T>
    typename std::enable_if<HasMoneyFunction<T>::value>::type
     customerArrives(T& customer) 
    {
        std::cout << "Welcome to the bank4! You have " << customer.GetMoney() << " money" << std::endl;
    }

    template<typename T>
    typename std::enable_if<!HasMoneyFunction<T>::value>::type
     customerArrives(T& customer) 
    {
        std::cout << "You have no money! get out of my bank" << std::endl;
    }
};