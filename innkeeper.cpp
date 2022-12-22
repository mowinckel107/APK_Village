

#include "Innkeeper.h"

Innkeeper::Innkeeper()
{
    t.getFood(0);
    t.getFood(1);
    t.getFood(2);
    //std::visit(FoodVisitor(), t.getFood(1));
}

Innkeeper::~Innkeeper()
{

}