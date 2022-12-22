#include "BasicBakery.h"
#include "StrongBakery.h"


class BakerKing
{
public:
    BakerKing();
    Bread* OrderBasicBread();
    Bread* OrderStrongBread();
private:
    BasicBakery theBasicBakery;
    StrongBakery theStrongBakery;
};