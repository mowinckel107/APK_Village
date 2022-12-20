#include "BakerKing.h"
#include "iostream"
#include <stdexcept>

BakerKing::BakerKing()
{
    theBasicBakery = BasicBakery();
    theStrongBakery = StrongBakery();
}

void BakerKing::OrderBasicBread()
{
    try
    {
        theBasicBakery.BakeBread();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        //throw() //rethrow
    }
    
    
}

void BakerKing::OrderStrongBread()
{
    try
    {
        theStrongBakery.BakeBread();
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        //throw() //rethrow
    }
}