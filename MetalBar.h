

#pragma once



enum MetalType 
{
	iron, 
	steel,
	copper
};

enum Mixer 
{
	carbon,
	nothing
};




struct MetalBar
{
	public:
    	MetalBar();
    	~MetalBar();


        // The copy assignment operator and copy Constructor are explicitly deleted to showcase
        // If they were not, because they are not defined, they would be implicitly deleted

        MetalBar& operator= (const MetalBar &other ) = delete; // Copy assignment operator 
        MetalBar(const MetalBar &other) = delete;  // Copy Constructor


    	// MetalBar(const MetalBar &other); // Copy Constructor
    	// MetalBar& operator= (const MetalBar &other ); // Copy assignment operator 
    	MetalBar& operator=(MetalBar&& other) noexcept; //Move assignment operator
    	MetalBar(MetalBar&& other) noexcept; // Move Constructor


    	MetalType* data_;
};



struct Iron: public MetalBar
{
	Iron();
};

struct Steel: public MetalBar
{
	Steel();
};

struct Copper: public MetalBar
{
	Copper();
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

