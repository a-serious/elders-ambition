#ifndef ELDERSALTWALL_H
#define ELDERSALTWALL_H
#include "elderswall.h"

class EldersAltWall : public EldersWall
{
    int cnt = 20;
public:
    EldersAltWall(int, int, int, EldersMap *, QString);
    virtual void paint(QPainter *);
};

#endif // ELDERSALTWALL_H
