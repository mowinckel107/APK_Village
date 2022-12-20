#include<stdint.h>





enum MetalType 
{
	iron, 
	steel,
	copper
};




class Smith
{
	public:
		void makeMetal();
};




// TODO, move stuff to the .cpp file
struct Iron
{
	public:
    	// Constructor
    	Iron(MetalType iron)
    	{
        	data_ = new MetalType{iron};    
    	}
	
    	// Destructor
    	~Iron()
    	{
        	delete data_;
    	}
	
	// Copy constructor and copy assignment operator not defined, so object cannot be copied.
    	// Copy Constructor
    	// Iron(const Iron &other)
    	// {
        // 	data_ = new MetalType{*other.data_};
    	// }

    	// Copy assignment operator 
    	// Iron& operator= (const Iron &other )
    	//{
		//	data_ = new MetalType{*other.data_};
        //    return *this;
    	//}
	
	
    	//Move assignment operator
    	Iron& operator=(Iron&& other) noexcept
    	{
        	if (this != &other) // protect against self assignment
        	{
            	std::swap(other.data_, data_);
        	}
        	return *this;
    	}
	
	
    	// Move Constructor
    	Iron(Iron&& other) noexcept
    	{
        	data_ = nullptr;
        	std::swap(data_ = new MetalType,other.data_);
    	}
	

    private:
    	MetalType* data_;
};



struct Steel
{
	public:
    	// Constructor
    	Steel()
    	{
        	data_ = new MetalType{steel};    
    	}
	
    	// Destructor
    	~Steel()
    	{
        	delete data_;
		}
	
	// Copy constructor and copy assignment operator not defined, so object cannot be copied.
    	// Copy Constructor
		// Steel(const Steel &other)
		// {
		// 	data_ = new MetalType{*other.data_};
		// }

    	// Copy assignment operator
		// Steel& operator= (const Steel &other )
    	// {
		// 	data_ = new MetalType{*other.data_};
        //     return *this;
    	// }
	
    	//Move assignment operator
    	Steel& operator=(Steel&& other) noexcept
    	{
        	if (this != &other) // protect against self assignment
        	{
            	std::swap(other.data_, data_);
        	}
        	return *this;
    	}
	
    	// Move Constructor
    	Steel(Steel&& other) noexcept
    	{
        	data_ = nullptr;
        	std::swap(data_ = new MetalType,other.data_);
    	}
	

    private:
    	MetalType* data_;
};


struct Copper
{
	public:
    	// Constructor
    	Copper(MetalType copper)
    	{
        	data_ = new MetalType{copper};    
    	}
	
    	// Destructor
    	~Copper()
    	{
        	delete data_;
    	}
	
	// Copy constructor and copy assignment operator not defined, so object cannot be copied.
    	// Copy Constructor
    	// Copper(const Copper &other)
    	// {
        // 	data_ = new MetalType{*other.data_};
    	// }

    	// Copy assignment operator 
    	// Iron& operator= (const Copper &other )
    	//{
		//	data_ = new MetalType{*other.data_};
        //  return *this;
    	//}
	
	
    	//Move assignment operator
    	Copper& operator=(Copper&& other) noexcept
    	{
        	if (this != &other) // protect against self assignment
        	{
            	std::swap(other.data_, data_);
        	}
        	return *this;
    	}
	
	
    	// Move Constructor
    	Copper(Copper&& other) noexcept
    	{
        	data_ = nullptr;
        	std::swap(data_ = new MetalType,other.data_);
    	}
	

    private:
    	MetalType* data_;
};
