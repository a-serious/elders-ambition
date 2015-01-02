#include "eldersfloor.h"

EldersFloor::EldersFloor(int x, int y, int level, EldersMap * parent)
    : EldersDisplayObject(x, y, level, parent)
{
    property["label"] = "floor";
    appendClass("floor");
    pix = new QPixmap(":/images/assets/Images/test50.jpg");
}

EldersFloor::~EldersFloor()
{
    delete pix;
}

void EldersFloor::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, *pix);
}

bool EldersFloor::move(EldersMap *map)
{
    return runAction(map, true);
}
