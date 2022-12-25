

#include <iostream>

#include "Smith.h"
#include "Marketplace.h"
#include "Innkeeper.h"
#include "BakerKing.h"
#include "TownCrier.h"
#include "TimeOfDay.h"

#include "Reduce/Reduce.h"
#include "Reduce/SumPolicy.h"
#include "Reduce/MinPolicy.h"



void townCrierTest();
void ReduceTest();

static const bool isTestingDone = true; // Set to true/false to run tests or not


int main(int argc, char *argv[])
{

	// Initialization:
	Marketplace myMarketplace;
	Smith mySmith(&myMarketplace);
    Innkeeper boostInnkeeper;
	stableBoy John;
	John.name_ = "John";
	stableBoy Jim;
	Jim.name_ = "Jim";
	Barmaid Mary;
	Mary.name_ = "Mary";
	BakerKing myBakerKing;

	if constexpr(isTestingDone)
	{
		ReduceTest();
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
	//boostInnkeeper.addToCleaning(John);
	//boostInnkeeper.addToCleaning(Jim);
	//boostInnkeeper.addToCleaning(Mary);
	boostInnkeeper.addToCleaning(&dishwasher);
	//boostInnkeeper.addAssistant();
	//boostInnkeeper.getTavern().variantFood();
	boostInnkeeper.clean();

	}
	return 0;
}

template<typename T>
struct MainSumTraits;

template<>
struct MainSumTraits<int>
{
    using Result = int;
    static Result const startValue = 5;
};


template<typename T>
struct MainMinTraits;

template<>
struct MainMinTraits<int>
{
    using Result = int;
    static Result const startValue = INT_MAX;
};

void ReduceTest()
{
	int num[] = {3,2,1,4,5};

	auto result1 = reduce<int, SumPolicy, MainSumTraits<int>>(num, num+5);
	std::cout << "reduce result with Main ReduceTraits: " << result1 << std::endl;

	auto result2 = reduce(num, num+5);
	std::cout << "reduce result with default ReduceTraits: " << result2 << std::endl;

	auto result3 = reduce<int, MinPolicy, MainMinTraits<int>>(num, num+5);
	std::cout << "reduce result with min policy: " << result3 << std::endl;
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

