#ifndef ELDERSWIT_H
#define ELDERSWIT_H

#include "eldersinventory.h"

class EldersWit : public EldersInventory
{
public:
    EldersWit(int, int, int, EldersMap *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSWIT_H
