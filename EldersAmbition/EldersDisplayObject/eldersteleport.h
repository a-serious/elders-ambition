#ifndef ELDERSTELEPORT_H
#define ELDERSTELEPORT_H

#include "eldersinventory.h"

class EldersTeleport : public EldersInventory
{

public:
    EldersTeleport(int, int, int, EldersMap *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSTELEPORT_H
