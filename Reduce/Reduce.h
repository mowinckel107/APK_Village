#pragma once

#include "ReduceTraits.h"
#include "SumPolicy.h"
#include <iostream>

template<typename T, typename Policy = SumPolicy,  typename RES = ReduceTraits<T>, typename P>
auto reduce(P beginning, P const end)
{
    typename RES::Result result = RES::startValue;

    //std::cout << "Reduce template result type: " << typeid(result).name() << std::endl;

    while (beginning != end)
    {
        Policy::reduction(result, *beginning);
        ++beginning;
    }
    return result;
}


/*template<typename T, typename RES = ReduceTraits<T>>
auto reduce(T const* beginning, T const* end)
{
    typename RES::Result result = RES::startValue;

    std::cout << "Reduce template result type: " << typeid(result).name() << std::endl;

    while (beginning != end)
    {
        result += *beginning;
        ++beginning;
    }
    return result;    
}*/