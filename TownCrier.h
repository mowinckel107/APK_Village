

#pragma once

#include <thread>
#include <condition_variable>
#include <functional>
#include "TimeOfDay.h"




class TownCrier
{
    public:
        TownCrier(TimeOfDay* theTimePointer);
        ~TownCrier();
        
        void WakeMeWhenItIsEvning();
        void WakeMeWhenItIsNight();

    private:
        static void Work
        (
            std::condition_variable &conditionVariable,
            bool& isItEvning_,
            bool& isItnight_,
            TimeOfDay* timeOfDay
        );
        std::condition_variable conditionVariable_;
        TimeOfDay* theTimePointer_ = nullptr;
        bool isItEvning_ = false;
        bool isItnight_ = false;
        std::thread theThread_;
};

