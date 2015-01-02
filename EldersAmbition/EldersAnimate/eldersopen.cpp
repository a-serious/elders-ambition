#include "eldersopen.h"
#include "../EldersDisplayObject/eldersdoor.h"

EldersOpen::EldersOpen(EldersMap *map, EldersDoor *target)
    : EldersAnimate(map, 16)
{
    this->direction = direction;
    this->target = target;
    target->setProperty("enabled", 0);
}

bool EldersOpen::paint(QPainter *painter) // false -> please destroy me.
{
    if (duration > 0)
    {
        painter->drawPixmap(QPoint(target->x, target->y), *target->pix,
                            QRect(QPoint(25 - duration, 0), QPoint(25, 50)));
        painter->drawPixmap(QPoint(target->x + 50 - duration, target->y), *target->pix,
                            QRect(QPoint(25, 0), QPoint(25 + duration, 50)));
        duration--;
        return true;
    }
    else
        return false;
}
