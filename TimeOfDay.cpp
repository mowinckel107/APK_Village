

#include "TimeOfDay.h"



TimeOfDay *TimeOfDay::instance_ = nullptr; // Initialize instance_


TimeOfDay::TimeOfDay() // Private constructor
{
    timeOfDay_ = daytime;
}

TimeOfDay* TimeOfDay::createTimeOfDay()
{
      if (!instance_) // Ensuring that there can only be 1
      instance_ = new TimeOfDay;
      return instance_;
}



Times TimeOfDay::GetTime()
{
    std::lock_guard<std::mutex> theLockGuard(theMutex);
    // lock_guard uses RAII. It locks the mutex at creation and unlocks the mutex when going out of scope

    return timeOfDay_;
}


void TimeOfDay::SetTime(Times newTime)
{
    std::lock_guard<std::mutex> theLockGuard(theMutex);
    // lock_guard uses RAII. It locks the mutex at creation and unlocks the mutex when going out of scope
    timeOfDay_ = newTime;

    // It could be replaced by this non RAII solution:
    // theMutex.lock();
    // timeOfDay_ = newTime;
    // theMutex.unlock();
}








