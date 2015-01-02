#ifndef ELDERSDOOR_H
#define ELDERSDOOR_H

/*
#define yellow 0
#define blue 1
#define red 2
#define silver 3
*/

#include "elderswall.h"
#include "../EldersAnimate/eldersopen.h"

class EldersDoor : public EldersWall
{
    friend class EldersOpen;

    int color;

public:
    EldersDoor(int, int, int, EldersMap *, int);
    virtual bool move(EldersMap *);
};

#endif // ELDERSDOOR_H
