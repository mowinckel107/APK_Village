#pragma once

#include <concepts>
#include <type_traits>

//concept to check if T has memberfunction GetMoney
template<typename T>
concept HasMoneyAndId = requires(T t)
{
    {t.GetMoney()} -> std::same_as<int>;
    {t.GetId()} -> std::same_as<int>;
};

//check if T has memberfunction GetMoney
template<typename T, typename = void>
struct HasMoneyFunction : std::false_type {};

template<typename T>
struct HasMoneyFunction<T, std::void_t<decltype(std::declval<T>().GetMoney())>> : std::true_type {};

//if then else implentet using a primary template and two specializations
template<typename Ttrue, typename Tfalse, bool>
struct IfThenElse;

template<typename Ttrue, typename Tfalse>
struct IfThenElse<Ttrue, Tfalse, false>
{
    typedef Tfalse Type;
};

template<typename Ttrue, typename Tfalse>
struct IfThenElse<Ttrue, Tfalse, true>
{
    typedef Ttrue Type;
};