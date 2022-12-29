

#include "Marketplace.h"

#include <iostream>
#include <algorithm>



Marketplace::Marketplace()
{
    // Seeding:
    mixedStorage_.push(Steel());
    mixedStorage_.push(Iron());
    mixedStorage_.push(Steel());
    mixedStorage_.push(Steel());
    mixedStorage_.push(Iron());
    mixedStorage_.push(Steel());
    mixedStorage_.push(Iron());
    mixedStorage_.push(Steel());
    
};




void Marketplace::SortStock()
{
    std::cout << "            Marketplace sorts inventory" << std::endl;

    while(!mixedStorage_.empty())
    {

        if(*mixedStorage_.top().data_ == iron)
        {
            sortedIronStorage.emplace(sortedIronStorage.end(), std::move(mixedStorage_.top()));
            mixedStorage_.pop();
        }
        else if(*mixedStorage_.top().data_ == steel)
        {
            sortedSteelStorage.emplace(sortedSteelStorage.end(), std::move(mixedStorage_.top()));
            mixedStorage_.pop();
        }
        else
        {
            std::cout << "            something else" << std::endl;
            mixedStorage_.pop();
        }
        
        // YellStock();
    }
}


void Marketplace::YellStock()
{

    std::cout << "            Marketplace I have " << mixedStorage_.size() << " unsorted stock." << std::endl;

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
                // std::cout << " nullpointer";
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
                // std::cout << " nullpointer";
            }
        }
    );
    std::cout << std::endl;

}



void Marketplace::HandoverMetal(MetalBar * metalHandedOver)
{
    mixedStorage_.push(std::move(*metalHandedOver));

	std::cout << "            Marketplace: \"Got some Metal\"" << std::endl;
}


