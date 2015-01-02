#include "eldersteleport.h"

EldersTeleport::EldersTeleport(int x, int y, int level, EldersMap *parent)
    : EldersInventory(x, y, level, parent)
{
    property["label"] = "teleport";
    appendClass("teleport");
    pix = new QPixmap(":/images/teleport");
}

bool EldersTeleport::move(EldersMap *map)
{
    map->property["teleportEnabled"] = 1;
    return EldersInventory::move(map);
}
