#include <type_traits>
#include "BankHelpers.h"

struct GotMoney {};
struct GotNoMoney {};

class Bank3
{
private:
    template<typename T>
    void customerArrivesImpl(T& customer, GotMoney) 
    {
        std::cout << "Welcome to the bank3! You have " << customer.GetMoney() << " money" << std::endl;
    }

    template<typename T>
    void customerArrivesImpl(T& customer, GotNoMoney) 
    {
        std::cout << "You have no money! get out of my bank" << std::endl;
    }
public:
    template<typename T>
    void customerArrives(T& customer) 
    {
        customerArrivesImpl(customer, typename IfThenElse<GotMoney, GotNoMoney, HasMoneyFunction<T>::value>::Type());
    }
};