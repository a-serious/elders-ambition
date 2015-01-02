#ifndef ELDERSWALL_H
#define ELDERSWALL_H

#include "eldersdisplayobject.h"

#include <QPainter>

class EldersWall : public EldersDisplayObject
{

public:
    QPixmap *pix;
    EldersWall(int, int, int, EldersMap *);
    ~EldersWall();
    virtual void paint(QPainter *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSWALL_H
