


#pragma once

#include<stdint.h>

#include "Marketplace.h"


class Smith
{
	public:
		Smith(Marketplace* marketplacePointer);
		void HandOverMetal();
		void CalloutMetalType();
	private:
		Metal<Iron, carbon> storedMetal;
		// Metal<Copper, carbon> storedMetal; // Copper and carbon is not a legal mix, and will create errors

		Marketplace * marketplacePointer_;
};




