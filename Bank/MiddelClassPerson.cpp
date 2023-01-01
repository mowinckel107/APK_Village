#include "MiddelClassPerson.h"

MiddelClassPerson::MiddelClassPerson(int id) : MiddelClassPerson(id, 0) {}

MiddelClassPerson::MiddelClassPerson(int id, int money)
{
    this->id = id%2 == 0 ? id : id+1;
    this->money = money > 0 ? money : 0;
}

int MiddelClassPerson::GetMoney()
{
    return money;
}

int MiddelClassPerson::GetId()
{
    return id;
}