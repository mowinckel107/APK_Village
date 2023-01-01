#pragma once
#include "boost/bind/bind.hpp"
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
//However, lambdas do what std::bind does sorta without the boost overhead