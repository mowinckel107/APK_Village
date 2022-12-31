

#pragma once

#include<stdint.h>

enum MetalType : uint8_t 
{
	empty, 
	iron, 
	steel,
	copper
};

enum Mixer  : uint8_t 
{
	carbon,
	nothing
};



	// The copy assignment operator and copy Constructor are explicitly deleted to showcase
	// if they were not, because they are not defined, they would be implicitly deleted

struct MetalBar
{
	public:
    	MetalBar();
    	~MetalBar();

		// Copy assignment operator 
        MetalBar& operator= (const MetalBar &other ) = delete;

		// Copy Constructor
        MetalBar(const MetalBar &other) = delete;  
 		
 		//Move assignment operator
    	MetalBar& operator=(MetalBar&& other) noexcept;

 		// Move Constructor
    	MetalBar(MetalBar&& other) noexcept;

    	MetalType* data_;

		// Copy Constructor
    	// MetalBar(const MetalBar &other);

		// Copy assignment operator 
    	// MetalBar& operator= (const MetalBar &other ); 
};



struct Iron: public MetalBar
{
	Iron();
	Iron(MetalBar&& other) noexcept;
};

struct Steel: public MetalBar
{
	Steel();
	Steel(MetalBar&& other) noexcept;
};

struct Copper: public MetalBar
{
	Copper();
	Copper(MetalBar&& other) noexcept;
};



// uses both type determined at compile time, and value determined at compile time
template<typename NN, Mixer N>
struct Metal
{
    // empty, to give compile errors if used
};

// A partial specialization for use of "nothing" as mixer. This just returns the metal as is
template<typename N>
struct Metal<N, nothing>
{
    N metal = N();
};

// A full specialization for use of "steel". steel is legal to use, and so this specialization will catch these legal uses.
template<>
struct Metal<Iron, carbon>
{
	Steel metal = Steel();
};

