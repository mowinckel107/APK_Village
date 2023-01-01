#include "bindMixer.h"
#include <iostream>


//Free function to bind
double addDrinks(double a, double b)
{
    std::cout << "    AddDrinks called" << std::endl;
    std::cout << "    Add " << a << " to " << b << std::endl;
    return a+b; //Dette skal være minus, find ud af hvordan det giver mening
}

template<typename H>
double Inbetween(H h, double beer, double water)
{
    std::cout << "    Inbetween step called" << std::endl;
    return h(beer, water*2);
}

//Functors to bind
struct DoublingBeer //The amount of drinks and then the extra drinks
{
    double operator()(double a, double b)
    {
        std::cout << "    Multiplying " << a << " by " << b << std::endl;
        return a*b;
    }
};

//Methods to bind
struct Distiller
{
    double removeWater (double a, double b)
    {
        //Using a magical cup
        std::cout << "    RemoveWater called" << std::endl;
        return a-b;
    }
};

void BindMixer::bindTasks()
{
    int beer = 3;
    int water = 8;
    DoublingBeer MagicMug;
    Distiller distilationDevice;

    //Demonstrer bind i bind
    auto boundAddDrinks = boost::bind(addDrinks, boost::placeholders::_2, boost::placeholders::_1);

    std::cout << Inbetween(boundAddDrinks, water, beer) << " liters" << std::endl; //bind combine drinks here too
    //    std::cout << Inbetween(boost::bind(addDrinks, boost::placeholders::_1, boost::placeholders::_2), beer, water) << std::endl; //Omvendt rækkefølge
    std::cout << boundAddDrinks(beer, water) << " liters" << std::endl;

    //auto boundDoubleBeer = boost::bind(&DoublingBeer::operator(), boost::placeholders::_1, boost::placeholders::_2);
    boost::bind<double>(MagicMug, boost::placeholders::_1, 5)(beer);//, water);

    //Demonstrer ændring af rækkefølge
    auto boundRemoveWater = boost::bind(&Distiller::removeWater, &distilationDevice, boost::placeholders::_1, boost::placeholders::_2);
    std::cout << boundRemoveWater(beer, water) << " liters" << std::endl;
    //boost::bind(&Distiller::removeWater, std::ref(distilationDevice) distilationDevice.removeWater (it's a reference)
    //boost::bind(&Distiller::removeWater, distilationDevice distilationDevice.removeWater (it's a copy)
}

