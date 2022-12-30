#include "Hunter.h"
#include <string>

class Cook
{
    private:
    Hunter* hunter_;
    public:
    Cook();
    Cook(Hunter* hunter);
    std::string CookFood(std::string recipe);
};