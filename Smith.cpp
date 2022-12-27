
#include<stdint.h>
#include<string>
#include<iostream>


#include"Smith.h"






Smith::Smith(Marketplace * marketplacePointer)
{
	marketplacePointer_ = marketplacePointer;
}


void Smith::HandOverMetal()
{
	marketplacePointer_->HandoverMetal(&storedMetal.metal);
	std::cout << "   Smith: \"Handed over Metal to the Marketplace\"" << std::endl;
}




void Smith::CalloutMetalType()
{
	if(storedMetal.metal.data_ == nullptr || *storedMetal.metal.data_ == empty)
	{
		std::cout << "   Smith: \"I have no metal\"" << std::endl;
	}
	else if(*storedMetal.metal.data_ == iron)
	{
		std::cout << "   Smith: \"I have Iron\"" << std::endl;
	}
	else if(*storedMetal.metal.data_ == steel)
	{
		std::cout << "   Smith: \"I have Steel\"" << std::endl;
	}
	else if(*storedMetal.metal.data_ == copper)
	{
		std::cout << "   Smith: \"I have Copper\"" << std::endl;
	}
	else
	{
		std::cout << "   Smith: \"No idea\"" << *storedMetal.metal.data_ << storedMetal.metal.data_ <<   std::endl;
	}

}
