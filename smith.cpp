
#include<stdint.h>
#include<string>

#include"smith.h"


enum Mixer 
{
	tin,
	carbon,
	nothing
};


template<MetalType NN , Mixer N>
struct Metal
{
    // empty, to give compile errors if used
};


// A partial specialization for use of "nothing" as mixer. This just returns the metal as is
template<MetalType N>
struct Metal<N, nothing>
{
    static const MetalType metalType = N;
};


// A full specialization for use of "bronce". bronce is legal to use, and so this specialization will catch these legal uses.
template<>
struct Metal<copper, tin>
{
    static const MetalType metalType = bronce;
};


// A full specialization for use of "steel". steel is legal to use, and so this specialization will catch these legal uses.
template<>
struct Metal<iron, carbon>
{
    static const MetalType metalType = steel;
};





void Smith::makeMetal()
{


}
