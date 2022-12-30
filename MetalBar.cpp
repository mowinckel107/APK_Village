

#include "MetalBar.h"
#include <utility>
#include<iostream>


MetalBar::MetalBar()
{
    data_ = nullptr;
}


MetalBar::~MetalBar()
{
	delete data_;
}



// IF the copy constructor and copy assiigment operator was to be defined, they would look like this:

/*
MetalBar::MetalBar(const MetalBar &other) // Copy Constructor
{
    data_ = new MetalBar{*other.data_};
}

MetalBar& MetalBar::operator= (const MetalBar &other ) // Copy assignment operator 
{
    data_ = new MetalType{*other.data_};
    return *this;
}
*/


//Move assignment operator
MetalBar& MetalBar::operator=(MetalBar&& other) noexcept
{
	if (this != &other) // protect against self assignment
	{
		// std::cout << "Move assignment operator" << std::endl;
		std::swap(other.data_, data_);
	}
	return *this;
}

// Move Constructor
MetalBar::MetalBar(MetalBar&& other) noexcept
{
	// std::cout << "Move Constructor" << std::endl;
	data_ = nullptr;
	std::swap(data_ = new MetalType,other.data_);
}





Iron::Iron()
{
	data_ = new MetalType();
	*data_ = iron;
}


Iron::Iron(MetalBar&& other) noexcept
{
	data_ = nullptr;
	std::swap(data_ = new MetalType,other.data_);
}



Steel::Steel()
{
	data_ = new MetalType();
	*data_ = steel;
}


Steel::Steel(MetalBar&& other) noexcept
{
	data_ = nullptr;
	std::swap(data_ = new MetalType,other.data_);
}



Copper::Copper()
{
	data_ = new MetalType();
	*data_ = copper;
}

Copper::Copper(MetalBar&& other) noexcept
{
	data_ = nullptr;
	std::swap(data_ = new MetalType,other.data_);
}