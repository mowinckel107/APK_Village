#pragma once
class Dough
{
public:
    Dough(int, int, int);
    bool CheckIngridients();
private:
    int flour;
	int water;
	int salt;
};