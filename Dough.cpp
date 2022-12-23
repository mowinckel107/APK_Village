#include "Dough.h"

Dough::Dough(int flour, int water, int salt)
{
    this->flour = flour;
    this->water = water;
    this->salt = salt;
}

//bread requires 500g flour 400ml water and 2g salt
bool Dough::CheckIngridients() noexcept
{
    if (flour >= 500 && water >= 400 && salt >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}