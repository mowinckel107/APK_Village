#include "BasicBakery.h"
#include "Dough.h"
#include <iostream>
#include <memory>


BasicBakery::BasicBakery()
{
	flour = 500;
	water = 1000;
	salt = 1;
	myOven = Oven();
}


Bread* BasicBakery::BakeBread()
{
	std::auto_ptr d(new Dough(flour, water, salt));
	flour = 0;
	water = 0;
	salt = 0;
	return myOven.BakeBread(d.get());
}

//less readable implementation not using RAII
Bread* BasicBakery::BakeBreadNoRAII()
{
	Dough* d = new Dough(flour, water, salt);
	Bread* b;

	try
	{
		b = myOven.BakeBread(d);
	}
	catch(const std::exception& e)
	{
		delete d;
		throw e;
	}
	delete d;
	return b;
}