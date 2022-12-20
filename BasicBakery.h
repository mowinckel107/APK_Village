#include "Bread.h"

class BasicBakery
{
public: 
	Bread BakeBread();
	void AddIngredients(int, int, int);
private:
	int flour;
	int water;
	int salt;
};