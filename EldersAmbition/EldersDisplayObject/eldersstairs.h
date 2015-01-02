#ifndef ELDERSSTAIRS_H
#define ELDERSSTAIRS_H

#include "eldersfloor.h"

class EldersStairs : public EldersFloor
{
    int direction; //only 1 and -1 are allowed

public:
    EldersStairs(int, int, int, EldersMap *, int);
    virtual bool move(EldersMap *);
};

#endif // ELDERSSTAIRS_H
