#include "eldersinventory.h"

EldersInventory::EldersInventory(int x, int y, int level, EldersMap *parent)
    : EldersDisplayObject(x, y, level, parent)
{

}

EldersInventory::~EldersInventory()
{
    delete pix;
}

void EldersInventory::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, *pix);
}

bool EldersInventory::move(EldersMap *map)
{
    //if (map->Tom()->inventory.size() < 33)
    {
        property["enabled"] = 0;
        setProperty("pick", 1);
    }
    return runAction(map, false);
}
