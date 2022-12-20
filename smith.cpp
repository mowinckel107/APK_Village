
#include<stdint.h>
#include<string>

#include"smith.h"


enum Mixer 
{
	carbon,
	nothing
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
    const N metalType = N();
};


// A full specialization for use of "steel". steel is legal to use, and so this specialization will catch these legal uses.
template<>
struct Metal<Iron, carbon>
{
	const Steel metaltype = Steel();
};






void Smith::makeMetal()
{
	//if(ex)
	{
	
	}

}



