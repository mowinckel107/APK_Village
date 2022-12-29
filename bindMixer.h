#pragma once
#include "boost/bind/bind.hpp"
//structs to bind
//template<typename amount, typename cost, typename count>
//struct orderSTL
//{
//    typedef amount double;
//    typedef cost std::string;
//    typedef count int;
//};

//struct compareOrdersSTL : std::binary_function<orderSTL, orderSTL, bool>
//{
//    bool operator()(const orderSTL& a, const orderSTL& b) const
//    {
//        return a.amount > b.amount;
//    }
//};

//g(std::bind(f, 5, _1));
//Functor to bind
struct F
{
    int operator()(int a, int b) {return a - b;}
};


//Member function to bind
//boost::thread, reordering, composition


class BindMixer
{
    private:
    public: //STL::bind has limitations - mainly bad because DEPRECATED
    void bindTasks();
    double removeWater(double a, double b);
};
//However, lambdas do what std::bind does without the boost overhead