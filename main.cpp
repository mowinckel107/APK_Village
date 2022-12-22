
#include "Smith.h"
#include "Marketplace.h"
#include "Innkeeper.h"
#include "BakerKing.h"



int main(int argc, char *argv[])
{
	// Initialization:
	Marketplace myMarketplace;
	Smith mySmith(&myMarketplace);
    //Tavern t;
    //Innkeeper i;

	BakerKing myBakerKing;


	// Running the village:
	mySmith.CalloutMetalType();
	mySmith.HandOverMetal();
	mySmith.CalloutMetalType();

	myBakerKing.OrderBasicBread();
	myBakerKing.OrderStrongBread();



	return 0;
}

