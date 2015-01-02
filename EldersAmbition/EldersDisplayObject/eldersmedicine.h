#ifndef ELDERSMEDICINE_H
#define ELDERSMEDICINE_H

#include "eldersdisplayobject.h"

class EldersMedicine : public EldersDisplayObject
{
    QPixmap *pix;

public:
    EldersMedicine(int, int, int, QString, EldersMap *);
    ~EldersMedicine();
    virtual void paint(QPainter *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSMEDICINE_H
