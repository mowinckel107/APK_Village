#include "Bread.h"

class BasicBakery
{
public: 
	BasicBakery();
	Bread* BakeBread();
	void AddIngredients(int, int, int);
private:
	int flour;
	int water;
	int salt;
};