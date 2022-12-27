

#pragma once

#include <vector>
#include <stdint.h>

#include "MetalBar.h"

class Marketplace
{
    public:
        Marketplace();
        void HandoverMetal(MetalBar * metalHandedOver);
        void SortStock();
        void YellStock();

    // private:
    
        std::vector<MetalBar> mixedStorage_;
        std::vector<Iron> sortedIronStorage;
        std::vector<Steel> sortedSteelStorage;
};












