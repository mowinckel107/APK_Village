

#include "Marketplace.h"

#include<iostream>



void Marketplace::HandoverMetal(MetalBar * metalHandedOver)
{
    MetalBar metalToBeSold;

    metalToBeSold = std::move(*metalHandedOver);
	std::cout << "Marketplace: \"Got some Metal\"" << std::endl;
}



