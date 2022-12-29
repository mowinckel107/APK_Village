//#include <functional> functinoal har anden syntax, fjernet unødvendige and such https://en.cppreference.com/w/cpp/utility/functional/function
#include <string>
#include <iostream>
#include "boost/function.hpp"

struct Patron
{
    void operator()(int coins, int & totalMoney)
    {
        std::cout << "Patron pay " << coins << " coin(s) for a meal/drink" << std::endl;
        totalMoney  += coins;
    }
};

void donation(int, int &);

class FunctionAssistant
{
    private:
    boost::function<void(int, int &)> cb_;
    int innRegister = 0;
    public:
    void saveFunction(boost::function<void(int, int &)>);
    void swapSaved(boost::function<void(int,int &)>);
    void runSaved(int,int &);
    void runSavedOnce(int,int &);
    int getRegister();
    void emptyFunction();
    //FunctionAssistant& getSelf();
};
