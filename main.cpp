
#include "Smith.h"
#include "Marketplace.h"
#include "Innkeeper.h"


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

	// Running the village:	
	mySmith.CalloutMetalType();
	mySmith.HandOverMetal();
	mySmith.CalloutMetalType();

	//boostInnkeeper.addToCleaning(John);
	//boostInnkeeper.addToCleaning(Jim);
	//boostInnkeeper.addToCleaning(Mary);
	//boostInnkeeper.addAssistant();
	//boostInnkeeper.getTavern().variantFood();
	//boostInnkeeper.clean();


	return 0;
}

