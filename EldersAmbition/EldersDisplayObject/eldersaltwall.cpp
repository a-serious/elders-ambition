#include "eldersaltwall.h"

EldersAltWall::EldersAltWall(int x, int y, int level, EldersMap *parent, QString name)
    : EldersWall(x, y, level, parent)
{
    property["label"] = "altwall_" + name;
    pix = new QPixmap(":/images/altwall_" + name);
}

void EldersAltWall::paint(QPainter *painter)
{
    painter->save();
    painter->translate(x, y);
    if (--cnt > 10)
    {
        painter->translate(50, 0);
        painter->scale(-1, 1);
    }
    painter->drawPixmap(0, 0, *pix);
    painter->restore();
    if (cnt < 0) cnt = 20;
}
