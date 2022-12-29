#include <iostream>

#include "Smith.h"
#include "Marketplace.h"
#include "BakerKing.h"
#include "TownCrier.h"
#include "TimeOfDay.h"

#include "Reduce/Reduce.h"
#include "Reduce/SumPolicy.h"
#include "Reduce/MinPolicy.h"

#include "dishwasherFunction.h"
#include "Innkeeper.h"
//#include "functionAssistant.h"

void TownCrierTest();
void MarketplaceTest();
void ReduceTest();
void boostInnRun();

static const bool isTesting = true; // Set to true/false to run tests or not


int main(int argc, char *argv[])
{

	std::cout << "c++ version: " << __cplusplus << std::endl;

	// Initialization:
	Marketplace myMarketplace;
	Smith mySmith(&myMarketplace);
	BakerKing myBakerKing;
	Innkeeper boostInnkeeper;
	stableBoy John;
	John.name_ = "John";
	stableBoy Jim;
	Jim.name_ = "Jim";
	Barmaid Mary;
	Mary.name_ = "Mary";

	if constexpr(isTesting)
	{
		ReduceTest();
		MarketplaceTest();
		boostInnRun();
		TownCrierTest();
	}
	else
	{
		// Initialization:
		TimeOfDay *timeOfDay = timeOfDay->createTimeOfDay();
		TownCrier townCrier(timeOfDay);
		Marketplace marketplace;
		Smith smith(&marketplace);
		boostInnRun();

		// Running the village:
	
		mySmith.CalloutMetalType();
		mySmith.HandOverMetal();
		mySmith.CalloutMetalType();

		myMarketplace.YellStock();
		myMarketplace.SortStock();
		myMarketplace.YellStock();

		myBakerKing.OrderBasicBread();
		myBakerKing.OrderStrongBread();

		boostInnRun();
		

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


void TownCrierTest()
{

	TimeOfDay *timeOfDay = timeOfDay->createTimeOfDay();
	TownCrier townCrier(timeOfDay);


	townCrier.WakeMeWhenItIsEvning();
    std::cout << "      Villagers: \"Going to the pub!!\"" << std::endl;

	townCrier.WakeMeWhenItIsNight();
    std::cout << "      Villagers: \"Going to bed :C\"" << std::endl;

}

void boostInnRun()
{    
	Innkeeper boostInnkeeper;

	//Variants
	boostInnkeeper.getTavern().variantFood();

	//Signals
	stableBoy John;
	John.name_ = "John";
	stableBoy Jim;
	Jim.name_ = "Jim";
	Barmaid Mary;
	Mary.name_ = "Mary";
	stableBoy Bob;
	Bob.name_ = "Bob";
	boostInnkeeper.addToCleaning(John);
	boostInnkeeper.addToCleaning(Jim);
	boostInnkeeper.tempWorker(Bob);
	boostInnkeeper.addToCleaning(Mary);
	boostInnkeeper.addToCleaning(&dishwasher);
	boostInnkeeper.addToSpecificCleaning(&specificDishwasher);
	boostInnkeeper.clean();
	boostInnkeeper.clean("Poul");
	boostInnkeeper.fireFromCleaning(John);
	boostInnkeeper.clean();
	//Det er også muligt at sende connect slots (slot_type&) som argumenter. Det er lidt involveret og ikke implementeret

	//bind
	boostInnkeeper.getBindMixer().bindTasks();

	//boost::function
	FunctionAssistant boostAssistant;
	int&& regRef = boostAssistant.getRegister();
	boostAssistant.runSaved(6, regRef);
	Patron André;
	boostAssistant.saveFunction(André);
	boostAssistant.runSaved(4, regRef);
	boostAssistant.swapSaved(&donation);
	boostAssistant.runSavedOnce(2, regRef);
	boostAssistant.runSavedOnce(1, regRef);
	boostInnkeeper.tellAssistantToGetReadyToPay(std::ref(boostAssistant));
	std::cout << "Total coins: " << boostAssistant.getRegister() << std::endl;
	boostAssistant.runSaved(3, regRef);
	//boostInnkeeper.removeMoneyFromTheRegister(5, regRef);
	std::cout << "Total coins: " << boostAssistant.getRegister() << std::endl;	
}

void MarketplaceTest()
{
	Marketplace myMarketplace;

	myMarketplace.YellStock();

	myMarketplace.SortStock();

	myMarketplace.YellStock();
}

