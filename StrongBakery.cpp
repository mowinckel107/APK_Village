#include "StrongBakery.h"
#include <iostream>


StrongBakery::StrongBakery()
{
	flour = 500;
	water = 1000;
	salt = 1;
}

//bread requires 500g flour 400ml water and 2g salt
Bread StrongBakery::BakeBread()
{
	if (flour >= 500 && water >= 400 && salt >= 2)
	{
		flour -= 500;
		water -= 400;
		salt -= 2;
		std::cout << "Succes! here is your bread" << std::endl;
		return new Bread();
	}
	else
	{
		throw("Insufficient ingridients");
	}
}