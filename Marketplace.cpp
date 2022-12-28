

#include "Marketplace.h"

#include <iostream>
#include <algorithm>



Marketplace::Marketplace()
{
    // Seeding:

    mixedStorage_.push_back(Steel());
    mixedStorage_.push_back(Iron());
    mixedStorage_.push_back(Steel());
    mixedStorage_.push_back(Steel());
    mixedStorage_.push_back(Iron());
    mixedStorage_.push_back(Steel());
    mixedStorage_.push_back(Iron());
    mixedStorage_.push_back(Steel());
    
};




void Marketplace::SortStock()
{
    std::cout << "            Marketplace sorts inventory" << std::endl;

    std::for_each
    (
        mixedStorage_.begin(),
        mixedStorage_.end(),
        [&](MetalBar &bar)
        {
            if(*bar.data_ == iron)
            {
                sortedIronStorage.emplace(sortedIronStorage.end(), std::move(bar));
            }
            else if(*bar.data_ == steel)
            {
                sortedSteelStorage.emplace(sortedSteelStorage.end(), std::move(bar));
            }
            else
            {
                std::cout << "            something else" << std::endl;
            }

            // YellStock();
        }
    );
}


void Marketplace::YellStock()
{

    std::cout << "            Marketplace unsorted stock is: ";
    std::for_each
    (
        mixedStorage_.begin(),
        mixedStorage_.end(),
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
                //std::cout << " nullpointer";
            }
        }
    );
    std::cout << std::endl;



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
    mixedStorage_.emplace(mixedStorage_.end(), std::move(*metalHandedOver));

	std::cout << "            Marketplace: \"Got some Metal\"" << std::endl;
}



