

#include "TownCrier.h"

#include <iostream>


TownCrier::TownCrier(TimeOfDay* theTimePointer)
{
    std::cout << "      TownCrier wakes up" << std::endl;
    theTimePointer_ = theTimePointer;
    std::thread aThread(Work, std::ref(theMutex_), std::ref(conditionVariable_), std::ref(isItEvning_), std::ref(isItnight_), theTimePointer_);
    theThread_ = std::move(aThread);
}

TownCrier::~TownCrier()
{
    theThread_.join();
}

// void Work(std::mutex &theMutex, std::condition_variable &conditionVariable)
void TownCrier::Work(std::mutex &theMutex, std::condition_variable &conditionVariable, bool& isItEvning, bool& isItnight, TimeOfDay* timeOfDay)
{
    std::cout << "      Town Crier: \"It is now daytime!\"" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

    timeOfDay->SetTime(evning);
    std::cout << "      Town Crier: \"It is now evning!\"" << std::endl;
    isItEvning = true;
    conditionVariable.notify_all(); // wake every thread waiting on the conditionVariable

    std::this_thread::sleep_for(std::chrono::seconds(5));

    timeOfDay->SetTime(night);
    std::cout << "      Town Crier: \"It is now night!\"" << std::endl;
    isItnight = true;
    conditionVariable.notify_all(); // wake every thread waiting on the conditionVariable

}

void TownCrier::WakeMeWhenItIsEvning()
{
    std::mutex aMutex;
    std::unique_lock aUnique_lock(aMutex);
     // make this a variable in the class, and send it with the thread to be set to true

    conditionVariable_.wait(aUnique_lock, [&]{return isItEvning_;}); // have the caller wait until the towncrier wakes them up
}

void TownCrier::WakeMeWhenItIsNight()
{
    std::mutex aMutex;
    std::unique_lock aUnique_lock(aMutex);
     // make this a variable in the class, and send it with the thread to be set to true

    conditionVariable_.wait(aUnique_lock, [&]{return isItnight_;}); // have the caller wait until the towncrier wakes them up
}


