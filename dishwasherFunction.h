#include <iostream>

void dishwasher()
{
    std::cout << "Dishwasher is washing the dishes" << std::endl;
}

bool specificDishwasher(std::string name_)
{
    std::cout << name_ << " the dishwasher is washing the dishes: ";
    return true;
}