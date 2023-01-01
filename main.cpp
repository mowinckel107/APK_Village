#include <iostream>
#include<stdint.h>
#include <cstdarg> 
// #include <cstdio>


#include "Smith.h"
#include "Marketplace.h"
#include "Bakery/BakerKing.h"
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
#include "Bank/Bank4.h"

#include "Innkeeper.h"

void SmithRun(Marketplace* marketplace);
void TownCrierTest();
void ReduceTest();
void boostInnRun();
void BankTest();


static int counter = 1;
void doPrint()
{
	counter = 1;
}

template <typename T, typename... Args>
void doPrint(T t, Args... args)
{
    std::cout << "option " << counter << ": " <<  t << std::endl;
	counter++;
    doPrint(args...);
}




int main(int argc, char *argv[])
{
	std::cout << "c++ version: " << __cplusplus << std::endl;

	// Initialization:
	Marketplace myMarketplace;
	BakerKing myBakerKing;
//	Innkeeper boostInnkeeper;
//	stableBoy John;
//	John.name_ = "John";
//	stableBoy Jim;
//	Jim.name_ = "Jim";
//	Barmaid Mary;
//	Mary.name_ = "Mary";



	bool isRunning = true;
	while(isRunning)
	{
		int options = 0;

		std::cout << std::endl << std::endl << "What part would you like to run?" << std::endl << std::endl;
		
		doPrint
		(
			"The Smith",
			"The Inn",
			"The Bakery",
			"The Towncrier",
			"The Marketplace",
			"The Bank",
			"Quit"
		);

		std::cin >> options;

		switch (options)
		{
			case 1:
				SmithRun(&myMarketplace);
			break;



			case 2:
				boostInnRun();
			break;



			case 3:
				myBakerKing.OrderBasicBread();
				myBakerKing.OrderStrongBread();
				myBakerKing.AddIngredientsToStrongBakery(100, 100, 100);
				myBakerKing.OrderStrongBread();
			break;



			case 4:
				TownCrierTest();
			break;



			case 5:
				myMarketplace.YellStock();
				myMarketplace.SortStock();
				myMarketplace.YellStock();
			break;



			case 6:
				//ReduceTest();
				BankTest();
			break;



			case 7:
				std::cout << "Ok... Bye" << std::endl;
				isRunning = false;
			break;
		


			default:
				std::cout << "	What?" << std::endl << std::endl;
			break;
		}
	}
		// ReduceTest();	// TODO, not sure where to put this

	return 0;
}

void BankTest()
{
	Bank myBank = Bank();
	Bank2 myBank2 = Bank2();
	Bank3 myBank3 = Bank3();
	Bank4 myBank4 = Bank4();

	RichPerson myRich1 = RichPerson(2, 400);
	RichPerson myRich2 = RichPerson(3);
	myRich1.Brag();
	myRich2.Brag();

	MiddelClassPerson myMiddel = MiddelClassPerson(6, 200);
	PoorPerson myPoor = PoorPerson(8);

	std::cout << "the bank has " << myBank.getTotalMoneyInBank() << " money" << std::endl;
	myBank.PrintPassbook();
	myBank.customerArrives(myRich1);
	myBank.customerArrives(myMiddel);
	//myBank.customerArrives(myPoor);
	myBank.PrintPassbook();
	std::cout << "the bank has " << myBank.getTotalMoneyInBank() << " money" << std::endl;
	std::cout << "smallest payment in the bank: " << myBank.getsmallestTransaction() << std::endl;


	myBank2.customerArrives(myRich1);
	myBank2.customerArrives(myMiddel);
	//myBank2.customerArrives(myPoor);

	myBank3.customerArrives(myRich1);
	myBank3.customerArrives(myMiddel);
	myBank3.customerArrives(myPoor);

	myBank4.customerArrives(myRich1);
	myBank4.customerArrives(myMiddel);
	myBank4.customerArrives(myPoor);
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

	auto result2 = reduce<int>(num, num+5);
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
	std::cout << std::endl << std::endl << "Boost Tavern options (It's not all boost)" << std::endl;
	doPrint("Variants", "Cleaning Signals", "BindMixer", "BoostFunction the Assistant", "Future Cook and future hunter");

	int options = 0;

	std::cin >> options;

	//signals


	//boost::function


	switch (options)
	{
		case 1:
		{
			//variants
			boostInnkeeper.getTavern().variantFood();
		}
		break;
		case 2:
		{
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
		}
		break;
		case 3:
		{
			//bind
			boostInnkeeper.getBindMixer().bindTasks();
		}
		break;
		case 4:
		{
			//boost::function
			FunctionAssistant boostAssistant;
			Patron André;

			int&& regRef = boostAssistant.getRegister();
			boostAssistant.runSaved(6, regRef);
			boostAssistant.saveFunction(André);
			boostAssistant.runSaved(4, regRef);
			boostAssistant.swapSaved(&donation);
			boostAssistant.runSavedOnce(2, regRef);
			boostAssistant.runSavedOnce(1, regRef);
			boostInnkeeper.tellAssistantToGetReadyToPay(std::ref(boostAssistant));
			std::cout << "Total coins: " << boostAssistant.getRegister() << std::endl;
			boostAssistant.runSaved(3, regRef);
			std::cout << "Total coins: " << boostAssistant.getRegister() << std::endl;
		}
		break;
		case 5:
		{
			//futures and promises
			boostInnkeeper.startCook("Venison");	
		}
		break;
		default:
			std::cout << "1 through 5 are the available options" << std::endl;
		break;
	}





}
void Variant()
{

}

void CleaningSignals()
{

}

void BindMixer()
{

}

void InnMixer()
{

}

void InnFunction()
{

}

void FutureCookAndHunter()
{

}

void SmithRun(Marketplace* marketplace)
{
	Smith smith(marketplace);
	smith.CalloutMetalType();
	smith.HandOverMetal();
}



