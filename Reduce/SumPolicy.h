#pragma once

class SumPolicy
{
public:
    template<typename T1, typename T2>
    static void reduction(T1& result, T2 const& value)
    {
        result += value;
    }
};