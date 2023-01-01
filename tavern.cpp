#include <iostream>
#include <variant>
#include <boost/variant.hpp>
#include "tavern.h"
#include <iomanip>
#include "math.h"


class FoodVisitor : public boost::static_visitor<>
{
    public: //template skal lave primær, partial og fully specialized
    void operator() (int i) const
    {
        std::cout << "    Cup size: " << i << " liters" << std::endl;
    }
    void operator() (double i) const
    {
        std::cout << "    Cup size: " << i << " liters" << std::endl;
    }
    void operator() (float i) const
    {
        std::cout << "    Cup size: " << i << " liters" << std::endl;
    }
    void operator() (long double i) const
    {
        std::cout << "    Cup size: " << i << " pints" << std::endl;
    }
    void operator() (std::string s) const
    {
        if (s.empty())
            std::cout << "    Recipe is empty :(" << std::endl;
        else
        {
            s = s;
            std::cout << "    Recipe contains: " << s << std::endl;
        }
    }
};

//compile-time check with visitation
//Stack-based container (no heap)
//Assignable, default constructible, (=, <, >) comparable, output streamable, hashable

std::string Tavern::getFood(int menuItem)
{
    if (menuItem == 0)
    {
        std::cout << "checking local food 0 recipe: " << localFood0 << std::endl;
        return localFood0;
    }
    if (menuItem == 1)
    {
        std::cout << "checking local food 1 recipe: " << localFood1 << std::endl;
        return localFood1;
    }
    if (menuItem == 2)
    {
        std::cout << "checking local food 2 recipe: " << localFood2 << std::endl;
        return localFood2;
    }
    return "";
    //std::cout << mead << std::endl;
}

// Liter to pint converter
long double operator"" _pint(long double pint)
{return pint * 2.113;}

void Tavern::variantFood()
{
    //Forskellen på boost::variant og std::variant er at boost::variant under exception af allokering/kreering vil allokerer heap plads.
    //std::variant må derimod være valueless som resultat

    std::variant<float, int, double, std::string, long double> small_local, medium_local, large_local, extraLarge_local, mead_local, undefinedSize_local, wine_local, localFood0_local, localFood1_local, localFood2_local;
    small_local = "one";
    small_local = 1; //Small overwritten to int
    medium_local = 1.5;
    large_local = 2;
    extraLarge_local = 2.5F;
    mead_local = "1 part honey";
    std::string &s = std::get<std::string>(mead_local);
    s += ", 5 parts water";
    wine_local = "red";
    localFood0_local = 35;
    localFood1_local = -58;
    localFood2_local = "namse";
    undefinedSize_local = "";

    std::cout << "    Size of the small variant drink" << std::get<1>(small_local) << " liters <- int" << std::endl; //henter int
    //std::cout << std::get<1>(mead) << std::endl;
    std::cout << "    Recipe for the mead: " << std::get<3>(mead_local) << " <- string" << std::endl; //henter string
    //std::cout << std::get<4>(mead) << std::endl;

    small_local = 1.1_pint; //Will fail at runtime
    //auto temporary_small_local = small_local_pint; //Will fail
    //small_local = temporary_small_local_pint; //Will fail
    //small_local = small_local_pint; //Will fail
    auto fresh_variable = 3.6_pint;
    std::visit(FoodVisitor(), small_local);
    //small = small_local; //fails because long double != variant
    small = std::get<2>(medium_local) - 0.7;
    std::cout << "    new small size: " << small << std::endl;

    std::visit(FoodVisitor(), mead_local);
    std::visit(FoodVisitor(), undefinedSize_local);
    std::visit(FoodVisitor(), localFood0_local);
    std::visit(FoodVisitor(), large_local);
    //LAV EN MED LAMBDA HER
    std::cout << "    lambda visit:" << std::endl;
    std::visit([] (auto&& param) {std::cout << "    Info om localFood via lambda: " << param << std::endl;}, localFood1_local);
    //Når vi går ud af scope, så bliver alt glemt
}
