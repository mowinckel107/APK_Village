
#include "Smith.h"
#include "Marketplace.h"
#include "Innkeeper.h"


int main(int argc, char *argv[])
{
	// Initialization:
	Marketplace myMarketplace;
	Smith mySmith(&myMarketplace);
    //Tavern t;
    //Innkeeper i;


	// Running the village:
	
	mySmith.CalloutMetalType();
	mySmith.HandOverMetal();
	mySmith.CalloutMetalType();



	return 0;
}

