

#include <iostream>

#include "Smith.h"
#include "Marketplace.h"
#include "Innkeeper.h"
#include "BakerKing.h"
#include "TownCrier.h"
#include "TimeOfDay.h"



void townCrierTest();

static const bool isTestingDone = true; // Set to true/false to run tests or not


int main(int argc, char *argv[])
{

	// Initialization:
	Marketplace myMarketplace;
	Smith mySmith(&myMarketplace);
    //Tavern t;
    //Innkeeper i;

	BakerKing myBakerKing;

	if constexpr(isTestingDone)
	{
		townCrierTest();
	}
	else
	{
		// Initialization:
		TimeOfDay *timeOfDay = timeOfDay->createTimeOfDay();
		TownCrier townCrier(timeOfDay);
		Marketplace marketplace;
		Smith smith(&marketplace);

		// Running the village:
		mySmith.CalloutMetalType();
		mySmith.HandOverMetal();
		mySmith.CalloutMetalType();

		myBakerKing.OrderBasicBread();
		myBakerKing.OrderStrongBread();

	}
	return 0;
}




void townCrierTest()
{

	TimeOfDay *timeOfDay = timeOfDay->createTimeOfDay();
	TownCrier townCrier(timeOfDay);


	townCrier.WakeMeWhenItIsEvning();
    std::cout << "      Villagers: \"Going to the pub!!\"" << std::endl;

	townCrier.WakeMeWhenItIsNight();
    std::cout << "      Villagers: \"Going to bed :C\"" << std::endl;

}

