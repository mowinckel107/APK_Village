//#include <type_traits>
#include "BankHelpers.h"

class Bank2
{
private:
    
public:
    template<typename T>
    void customerArrives(T& customer) 
    {
        static_assert(HasMoneyFunction<T>::value);
        std::cout << "    Welcome to the bank2! You have " << customer.GetMoney() << " money" << std::endl;
    }
};