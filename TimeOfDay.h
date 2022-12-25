

#pragma once


#include<stdint.h>
#include <thread>
#include <mutex>


enum Times : uint8_t // Strongly typed enum
{
    daytime,
    evning,
    night
};


class TimeOfDay
{
    public:
        static TimeOfDay* createTimeOfDay();
        Times GetTime();
        void SetTime(Times newTime);

    private:
        TimeOfDay(); // Private constructor

        static TimeOfDay* instance_;
        Times timeOfDay_;
        std::mutex theMutex;


};