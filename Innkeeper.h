#include "tavern.h"

class Innkeeper
{
private:
    Tavern t;
public:
    std::string makeFood();
    std::string bringFood();
    std::string bringAle(std::string);
    std::string replaceFood(std::string);
    void addAssistant();
};