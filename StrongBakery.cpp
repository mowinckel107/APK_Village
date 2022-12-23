#include "StrongBakery.h"
#include "Dough.h"
#include <iostream>
#include <memory>

StrongBakery::StrongBakery()
{
	flour = 500;
	water = 1000;
	salt = 1;
	myOven = Oven();
}

//bread requires 500g flour 400ml water and 2g salt
Bread* StrongBakery::BakeBread()
{
	if (flour >= 500 && water >= 400 && salt >= 2)
	{
		std::auto_ptr d(new Dough(flour, water, salt));
		flour = 0;
		water = 0;
		salt = 0;
		return myOven.BakeBread(d.get());
	}
	else
	{
		throw std::runtime_error("Insufficient ingridients");
	}
}

void StrongBakery::AddIngredients(int flour, int water, int salt) noexcept
{
	this->flour += flour;
	this->water += water;
	this->salt += salt;
}