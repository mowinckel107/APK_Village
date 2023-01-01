#include "BakerKing.h"
#include <iostream>
#include <stdexcept>

BakerKing::BakerKing()
{
    theBasicBakery = BasicBakery();
    theStrongBakery = StrongBakery();
}

void BakerKing::OrderBasicBread()
{
    std::cout << "Baking bread using basic bakery" << std::endl;
    try
    {
        Bread* b = theBasicBakery.BakeBread();
        std::cout << "Succes you got bread from the basic bakery" << std::endl;
        delete b;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Baking using basic bakery failed: ";  
        std::cerr << e.what() << std::endl;
    }
}

void BakerKing::OrderStrongBread()
{
    std::cout << "Baking bread using strong bakery" << std::endl;
    try
    {
        Bread* b = theStrongBakery.BakeBread();
        std::cout << "Succes you got bread from the strong bakery" << std::endl;
        delete b;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "Baking using strong bakery failed: ";
        std::cerr << e.what() << std::endl;
    }
}

void BakerKing::AddIngredientsToBasicBakery(int flour, int water, int salt)
{
    theBasicBakery.AddIngredients(flour, water, salt);
}

void BakerKing::AddIngredientsToStrongBakery(int flour, int water, int salt)
{
    theStrongBakery.AddIngredients(flour, water, salt);
}