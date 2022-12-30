#include <string>
#include <future>
#include <iostream>

class Hunter
{
    private:
    std::string result_;
    bool successfulHunt_ = false;
    public:
    void goHunting(std::promise<std::string>&& huntPromise);
};