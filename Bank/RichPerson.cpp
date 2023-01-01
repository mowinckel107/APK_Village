#include "RichPerson.h"
#include <iostream>

RichPerson::RichPerson(int id) : RichPerson(id, 0) {}

RichPerson::RichPerson(int id, int money)
{
    this->id = id%2 == 0 ? id : id+1;
    this->money = money > 0 ? money : 0;
}

int RichPerson::GetMoney()
{
    return money;
}

int RichPerson::GetId()
{
    return id;
}

void RichPerson::Brag()
{
    std::cout << "    I have id: " << id << " and " << money << " money" << std::endl;
}