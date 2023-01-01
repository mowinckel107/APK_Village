#include "BasicBakery.h"
#include "StrongBakery.h"


class BakerKing
{
public:
    BakerKing();
    void OrderBasicBread();
    void OrderStrongBread();
private:
    BasicBakery theBasicBakery;
    StrongBakery theStrongBakery;
};