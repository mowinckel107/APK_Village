#pragma once

class MinPolicy
{
public:
    template<typename T1, typename T2>
    static void reduction(T1& result, T2 const& value)
    {
        result = result < value ? result : value;
    }
};