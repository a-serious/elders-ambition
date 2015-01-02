#ifndef ELDERSOPEN_H
#define ELDERSOPEN_H

#include "eldersanimate.h"

class EldersDoor;

class EldersOpen : public EldersAnimate
{
    int direction;
    EldersDoor *target;

public:
    EldersOpen(EldersMap *, EldersDoor *);
    virtual bool paint(QPainter *); // false -> please destroy me.
};

#endif // ELDERSOPEN_H
