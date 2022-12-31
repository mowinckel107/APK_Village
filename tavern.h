#include <string>

class Tavern
{
private:
    std::string localFood0 = "Pork";
    std::string localFood1 = "Venison";
    std::string localFood2 = "Lamb";
    double small;
    double medium;
    double large;
    std::string mead;
public:
    std::string getFood(int menuItem);
    void variantFood();
};