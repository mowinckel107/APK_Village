

#pragma once

#include <vector>
#include <stdint.h>
#include <stack>


#include "MetalBar.h"

class Marketplace
{
    public:
        Marketplace();
        void HandoverMetal(MetalBar * metalHandedOver);
        void SortStock();
        void YellStock();

    private:
        std::stack< MetalBar, std::vector<MetalBar> > mixedStorage; 
        std::vector<Iron> sortedIronStorage;
        std::vector<Steel> sortedSteelStorage;
};












