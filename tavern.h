#include <string>

class Tavern
{
private:
    std::string localFood0 = "Pork";
    std::string localFood1 = "Venison";
    std::string localFood2 = "Lamb";
    int small;
    int medium;
    int large;
    std::string mead;
public:
    std::string getFood(int menuItem);
    void variantFood();
};