#ifndef ELDERSFLOOR_H
#define ELDERSFLOOR_H

#include "eldersdisplayobject.h"

class EldersFloor : public EldersDisplayObject
{

public:
    QPixmap *pix;
    EldersFloor(int, int, int, EldersMap *);
    ~EldersFloor();
    virtual void paint(QPainter *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSFLOOR_H
