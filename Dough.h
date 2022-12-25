#pragma once
class Dough
{
public:
    Dough(int, int, int);
    bool CheckIngridients() noexcept;
private:
    int flour;
	int water;
	int salt;
};