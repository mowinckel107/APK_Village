#include "Hunter.h"
#include "Animals.h"
#include "unistd.h"

AnimalsOfTheForest::Deer Bambi;
AnimalsOfTheForest::Wolf FenrisJunior;

void Hunter::goHunting(std::promise<std::string>&& huntPromise)
{
    std::cout << "Hunt initiated" << std::endl;
    sleep(4);
    huntPromise.set_value(Bambi.food_);
    //huntPromise.set_value(FenrisJunior.info_);
}