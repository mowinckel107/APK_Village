#include "BakerKing.h"
#include "iostream"
#include <stdexcept>

BakerKing::BakerKing()
{
    theBasicBakery = BasicBakery();
    theStrongBakery = StrongBakery();
}

Bread* BakerKing::OrderBasicBread()
{
    try
    {
        return theBasicBakery.BakeBread();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << "BakerKing: " << e.what() << '\n';
        throw(e); //rethrow
    }
    
    
}

Bread* BakerKing::OrderStrongBread()
{
    try
    {
        return theStrongBakery.BakeBread();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
}