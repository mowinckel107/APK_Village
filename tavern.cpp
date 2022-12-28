#include <iostream>
#include <variant>
#include <boost/variant.hpp>
#include "tavern.h"



class FoodVisitor : public boost::static_visitor<>
{
    public: //template skal lave primær, partial og fully specialized
    void operator() (int i) const
    {
        std::cout << "Cup size: " << i << std::endl;
    }
    void operator() (double i) const
    {
        std::cout << "Cup size: " << i << std::endl;
    }
    void operator() (float i) const
    {
        std::cout << "Cup size: " << i << std::endl;
    }
    void operator() (std::string s) const //template - fully specialized template
    {
        if (s.empty())
            std::cout << "recipe is empty: " << std::endl;
        else
        {
            s = s;
            std::cout << "Recipe contains: " << s << std::endl;
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

void Tavern::variantFood()
{
    //Forskellen på boost::variant og std::variant er at boost::variant under exception af allokering/kreering vil allokerer heap plads.
    //std::variant må derimod være valueless som resultat

    //std::variant, fordi den må kun indeholde floats
    std::variant<float, int, double, std::string> small, medium, large, extraLarge, mead, undefinedSize, wine, localFood0, localFood1, localFood2;
    small = "one";
    small = 1; //Small overwritten to int
    medium = 1.5;
    large = 2;
    extraLarge = 2.5F; //Stops existing at end of scope
    mead = "1 part honey";
    //std::cout << "Proleminary mead recipe: " << mead << std::endl;
    std::string &s = std::get<std::string>(mead); //Stops existing at end of scope
    s += ", 5 parts water";
    //std::cout << "Final mead recipe: " << mead << std::endl;
    wine = "red"; //Stops existing at end of scope
    localFood0 = 35;
    localFood1 = -58;
    localFood2 = "namse";
    undefinedSize = "";

    std::cout << std::get<1>(small) << std::endl;
    //std::cout << std::get<1>(mead) << std::endl;
    std::cout << std::get<3>(mead) << std::endl;
    //std::cout << std::get<4>(mead) << std::endl;


    std::visit(FoodVisitor(), mead);
    std::visit(FoodVisitor(), undefinedSize);
    std::visit(FoodVisitor(), localFood0);
    std::visit(FoodVisitor(), large);
    //LAV EN MED LAMBDA HER
    std::cout << "lambda visit:" << std::endl;
    std::visit([] (auto&& param) {std::cout << "Info om localFood via lambda: " << param << std::endl;}, localFood1);
    //Når vi går ud af scope, så bliver alt glemt
}