#ifndef ELDERSANY_H
#define ELDERSANY_H

#include "eldersdisplayobject.h"

class EldersAny : public EldersDisplayObject
{
    QPixmap *pix;

public:
    EldersAny(int, int ,int, EldersMap *);
    ~EldersAny();
    virtual void setProperty(QString, EldersVarient, bool = true);
    virtual void paint(QPainter *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSANY_H
