#include "Bread.h"
#include "Oven.h"

class StrongBakery
{
public:
	StrongBakery();
	Bread* BakeBread();
	void AddIngredients(int, int, int) noexcept;
private:
	int flour;
	int water;
	int salt;
	Oven myOven;
};