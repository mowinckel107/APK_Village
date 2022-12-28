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

#include "dishwasherFunction.h"
#include "Bank/RichPerson.h"
#include "Bank/MiddelClassPerson.h"
#include "Bank/PoorPerson.h"
#include "Bank/Bank.h"
#include "Bank/Bank2.h"
#include "Bank/Bank3.h"

#include "dishwasherFunction.cpp"

void TownCrierTest();
void MarketplaceTest();
void ReduceTest();
void boostInnRun();
void BankTest();

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
		BankTest();
		ReduceTest();
		MarketplaceTest();
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

void BankTest()
{
	Bank myBank = Bank();
	Bank2 myBank2 = Bank2();
	Bank3 myBank3 = Bank3();

	RichPerson myRich1 = RichPerson(2, 400);
	RichPerson myRich2 = RichPerson(3);
	myRich1.Brag();
	myRich2.Brag();

	MiddelClassPerson myMiddel = MiddelClassPerson(4, 200);
	PoorPerson myPoor = PoorPerson();

	myBank.customerArrives(myRich1);
	myBank.customerArrives(myMiddel);
	//myBank.customerArrives(myPoor);

	myBank2.customerArrives(myRich1);
	myBank2.customerArrives(myMiddel);
	//myBank2.customerArrives(myPoor);

	myBank3.customerArrives(myRich1);
	myBank3.customerArrives(myMiddel);
	myBank3.customerArrives(myPoor);
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
	//boostInnkeeper.addAssistant();
	//Bring drinks

	//bind
	boostInnkeeper.getBindAssistant().bindTasks();
}
void MarketplaceTest()
{
	Marketplace myMarketplace;

	myMarketplace.YellStock();

	myMarketplace.SortStock();

	myMarketplace.YellStock();
}

