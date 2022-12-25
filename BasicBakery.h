#include "Bread.h"
#include "Oven.h"

class BasicBakery
{
public: 
	BasicBakery();
	Bread* BakeBread();
	Bread* BakeBreadNoRAII();
	void AddIngredients(int, int, int) noexcept;
private:
	int flour;
	int water;
	int salt;
	Oven myOven;
};