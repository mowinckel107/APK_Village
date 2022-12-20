#include "BasicBakery.h"
#include <iostream>


BasicBakery::BasicBakery()
{
	flour = 500;
	water = 1000;
	salt = 1;
}

//bread requires 500g flour 400ml water and 2g salt
Bread* BasicBakery::BakeBread()
{
	flour -= 500;
	water -= 400;
	salt -= 2;
	if (flour >= 0 && water >= 0 && salt >= 0)
	{
		std::cout << "Succes! here is your bread" << std::endl;
		return new Bread();
	}
	else
	{
		throw std::runtime_error("Insufficient ingridients");
	}
}