#ifndef ELDERSINVENTORY_H
#define ELDERSINVENTORY_H

#include "eldersdisplayobject.h"
#include "../eldersmap.h"

class EldersInventory : public EldersDisplayObject
{

public:
    QPixmap *pix;
    EldersInventory(int, int, int, EldersMap *);
    ~EldersInventory();
    virtual void paint(QPainter *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSINVENTORY_H
