#ifndef ELDERSDESTINATION_H
#define ELDERSDESTINATION_H

#include "eldersfloor.h"

class EldersDestination : public EldersFloor
{
    int from;

public:
    EldersDestination(int, int, int, int, EldersMap *);
};

#endif // ELDERSDESTINATION_H
