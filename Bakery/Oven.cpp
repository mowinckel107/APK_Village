#include "Oven.h"
#include <stdexcept>

Bread* Oven::BakeBread(Dough* d)
{
    if (d->CheckIngridients())
    {
        return new Bread();
    }
    else
    {
        throw std::runtime_error("Insufficient ingridients");
    }   
}