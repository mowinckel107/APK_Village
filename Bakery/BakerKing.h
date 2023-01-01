#include "BasicBakery.h"
#include "StrongBakery.h"


class BakerKing
{
public:
    BakerKing();
    void OrderBasicBread();
    void AddIngredientsToBasicBakery(int, int, int);
    void OrderStrongBread();
    void AddIngredientsToStrongBakery(int, int, int);
private:
    BasicBakery theBasicBakery;
    StrongBakery theStrongBakery;
};