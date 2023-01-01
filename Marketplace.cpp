

#include "Marketplace.h"

#include <iostream>
#include <algorithm>



Marketplace::Marketplace()
{
    // Seeding:
    mixedStorage.push(Steel());
    mixedStorage.push(Iron());
    mixedStorage.push(Steel());
    mixedStorage.push(Steel());
    mixedStorage.push(Iron());
    mixedStorage.push(Steel());
    mixedStorage.push(Iron());
    mixedStorage.push(Steel());
    
};



void Marketplace::SortStock()
{
    std::cout << "            Marketplace sorts inventory" << std::endl;

    while(!mixedStorage.empty())
    {
        if(*mixedStorage.top().data_ == iron)
        {
            sortedIronStorage.emplace(sortedIronStorage.end(), std::move(mixedStorage.top()));
            mixedStorage.pop();
        }
        else if(*mixedStorage.top().data_ == steel)
        {
            sortedSteelStorage.emplace(sortedSteelStorage.end(), std::move(mixedStorage.top()));
            mixedStorage.pop();
        }
        else
        {
            std::cout << "            something else" << std::endl;
            mixedStorage.pop();
        }
        
    }
}



void Marketplace::YellStock()
{

    std::cout << "            Marketplace I have " << mixedStorage.size() << " unsorted stock." << std::endl;

    std::cout << "            Marketplace sorted iron is:    ";
    std::for_each
    (
        sortedIronStorage.begin(),
        sortedIronStorage.end(),
        [&]( MetalBar& bar)
        {
            if(*bar.data_ == iron)
            {
                std::cout << " iron ";
            }
            else if(*bar.data_ == steel)
            {
                std::cout << " steel";
            }
            else
            {
                std::cout << " Error";
            }
        }
    );
    std::cout << std::endl;



    std::cout << "            Marketplace sorted steel is:   ";
    std::for_each
    (
        sortedSteelStorage.begin(),
        sortedSteelStorage.end(),
        [&]( MetalBar& bar)
        {
            if(*bar.data_ == iron)
            {
                std::cout << " iron ";
            }
            else if(*bar.data_ == steel)
            {
                std::cout << " steel";
            }
            else
            {
                std::cout << " Error";
            }
        }
    );
    std::cout << std::endl;

}



void Marketplace::HandoverMetal(MetalBar * metalHandedOver)
{
    mixedStorage.push(std::move(*metalHandedOver));

	std::cout << "            Marketplace: \"Got some Metal\"" << std::endl;
}


