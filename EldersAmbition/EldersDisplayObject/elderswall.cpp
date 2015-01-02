#include "elderswall.h"
#include "../eldersmap.h"

EldersWall::EldersWall(int x, int y, int level, EldersMap *parent)
    : EldersDisplayObject(x, y, level, parent)
{
    property["label"] = "wall";
    appendClass("wall");
    pix = new QPixmap(":/images/wall");//ymj
}

EldersWall::~EldersWall()
{
    delete pix;
}

void EldersWall::paint(QPainter *painter)
{
    painter->drawPixmap(x, y, *pix);
}

bool EldersWall::move(EldersMap *map)
{
    if (!runAction(map, false))
    {
        parent->appendSound(":/sounds/beep");
        return false;
    }
    return true;
}
