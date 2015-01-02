#include "elderswit.h"
#include "../eldersmap.h"

EldersWit::EldersWit(int x, int y, int level, EldersMap *parent)
    : EldersInventory(x, y, level, parent)
{
    pix = new QPixmap(":/images/wit");
    property["label"] = "wit";
    appendClass("wit");
}

bool EldersWit::move(EldersMap *map)
{
    map->property["wisdomEnabled"] = 1;
    return EldersInventory::move(map);
}
