

#include "MetalBar.h"
#include <utility>
#include<iostream>




MetalBar::MetalBar()
{
    std::cout << "Metal created" << std::endl;
    data_ = nullptr;
}


MetalBar::~MetalBar()
{
    std::cout << "Metal Deleted" << std::endl;
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
		std::swap(other.data_, data_);
	}
	return *this;
}

// Move Constructor
MetalBar::MetalBar(MetalBar&& other) noexcept
{
	data_ = nullptr;
	std::swap(data_ = new MetalType,other.data_);
}





Iron::Iron()
{
	data_ = new MetalType();
	*data_ = iron;
}


Steel::Steel()
{
	data_ = new MetalType();
	*data_ = steel;
}

Copper::Copper()
{
	data_ = new MetalType();
	*data_ = copper;
}