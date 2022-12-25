#include "ReduceTraits.h"
#include <iostream>

template<typename T>
auto reduce(T const* beginning, T const* end)
{
    using Result = typename ReduceTraits<T>::Result;

    Result result = ReduceTraits<T>::zero;

    std::cout << typeid(result).name() << std::endl;

    while (beginning != end)
    {
        result += *beginning;
        ++beginning;
    }
    return result;    
}