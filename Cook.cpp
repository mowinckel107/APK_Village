#include "Cook.h"
#include <iostream>
#include "unistd.h"
#include <future>

Cook::Cook(){}

Cook::Cook(Hunter* hunter)
{
    hunter_ = hunter;
}

std::string Cook::CookFood(std::string recipe)
{
    std::cout << "Preparing the meal with recipe: " << recipe << std::endl;
    if (recipe.find(recipe.find("Venison") || recipe.find("venison"))) //Kunne godt være at en iterator ville være sejere her, men det her er bare så let
    {
        std::promise<std::string> promiseOfMeat;
        std::future<std::string> futureMeat = promiseOfMeat.get_future();
        std::cout << "Hunter is being sent to hunt" << std::endl;

        std::thread huntingThread([this](std::promise<std::string> promiseOfMeat)
         {hunter_->goHunting(std::move(promiseOfMeat));},
         std::move(promiseOfMeat));//Hvis detached ikke joinable

        std::cout << "Hunter has been sent to hunt" << std::endl;
        
        std::cout << "Readying ingredients" << std::endl;
        sleep(1);
        std::cout << "Slice and Dice the vegetables" << std::endl;
        sleep(1);

        std::cout << "Waiting for meat ingredient" << std::endl;
        std::string resultOfHunt = futureMeat.get(); //Anvender automatisk "wait;" løsningen
        huntingThread.join();
        std::cout << "Returned with " << resultOfHunt << std::endl;
        if(resultOfHunt != "Danger")
        {
            std::cout << "Making stew with ingredient " << resultOfHunt << " and it's gonna be delicious" << std::endl;
            return "Meal finished";
            //Alternativt 
            //huntingThread.join(); //løsningen venter til tråden er færdig
            //futureMeat.wait; //løsningen venter evigt
            //futureMeat.wait_for(8s); //løsningen venter i 8 sekunder
            //futureMeat.wait_until(eight_seconds_passed); //løsningen venter 
            //std::chrono::system_clock::time_point eight_seconds_passed = std::chrono::system_clock::now() + std::chrono::seconds(8);
            //AKA 8 sekunder og returnerer en error (std::future_error) exception
        }
        else
        {
            return "Vegetarian meal finished";
        }
    }
    else
    {
        return "Unknown recipe";
    }
}