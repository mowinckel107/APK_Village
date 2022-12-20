#include "Bread.h"

class StrongBakery
{
public:
	StrongBakery();
	Bread* BakeBread();
private:
	int flour;
	int water;
	int salt;
};