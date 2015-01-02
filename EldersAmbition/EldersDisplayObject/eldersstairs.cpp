#include "eldersstairs.h"
#include "../eldersmap.h"

EldersStairs::EldersStairs(int x, int y, int level, EldersMap *parent, int direction)
    : EldersFloor(x, y, level, parent)
{
    property["label"] = "stairs";
    appendClass("stairs");
    this->direction = direction;
    if(direction == 1)
        pix = new QPixmap(":/images/upstairs");
    else
        pix = new QPixmap(":/images/downstairs");
}

bool EldersStairs::move(EldersMap *map)
{
    map->Tom()->property.remove("_level");
    bool ret = runAction(map, false);

    EldersVarient targetLevel;
    switch (direction)
    {
    case 1:
        targetLevel = map->Tom()->property["level"] + 1;
        break;
    default:
        targetLevel = map->Tom()->property["level"] - 1;
        break;
    }

    QHash<QString, EldersVarient>::iterator i;
    if ((i = map->Tom()->property.find("_level")) != map->Tom()->property.end())
        targetLevel = i.value();
    map->Tom()->property.remove("_level");
    map->Tom()->setProperty("level", targetLevel);

    return ret;
}
