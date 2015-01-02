#include "eldersdoor.h"
#include "../eldersmap.h"

#define yellow 0
#define blue 1
#define red 2
#define silver 3
#define lock 4

EldersDoor::EldersDoor(int x, int y, int level, EldersMap *parent, int color)
    : EldersWall(x, y, level, parent)
{
    property["label"] = "door";
    appendClass("door");
    this->color = color;
    switch(color)
    {
    case yellow:
        pix = new QPixmap(":/images/door_yellow");
        break;
    case red:
        pix = new QPixmap(":/images/door_red");
        break;
    case blue:
        pix = new QPixmap(":/images/door_blue");
        break;
    case lock:
        pix = new QPixmap(":/images/door_lock");
        break;
    default:
        pix = new QPixmap(":/images/door_silver");
        break;
    }

}

bool EldersDoor::move(EldersMap *map)
{
    if (map->Tom()->consumeInventory("key", color))
    {
        map->appendAnimate(new EldersOpen(map, this), true);
        //property["enabled"] = 0;
        return runAction(map, true);
    }
    return runAction(map, false);
}

