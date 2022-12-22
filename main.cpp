
#include "Smith.h"
#include "Marketplace.h"



int main(int argc, char *argv[])
{
	// Initialization:
	Marketplace myMarketplace;
	Smith mySmith(&myMarketplace);


	// Running the village:
	
	mySmith.CalloutMetalType();
	mySmith.HandOverMetal();
	mySmith.CalloutMetalType();



	return 0;
}
