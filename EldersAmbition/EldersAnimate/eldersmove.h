#ifndef ELDERSMOVE_H
#define ELDERSMOVE_H

#include "eldersanimate.h"

class EldersMove : public EldersAnimate
{
    int direction;
    int distance;
    int step;
    EldersDisplayObject *target;
public:
    EldersMove(EldersMap *, int, int, EldersDisplayObject *, int = -1);
    virtual bool paint(QPainter *); // false -> please destroy me.
};

#endif // ELDERSMOVE_H
