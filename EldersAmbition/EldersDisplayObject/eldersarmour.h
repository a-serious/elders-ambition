#ifndef ELDERSARMOUR_H
#define ELDERSARMOUR_H

#include "eldersinventory.h"

class EldersArmour : public EldersInventory
{
    QString name;
public:
    EldersArmour(int, int, int, QString, EldersMap *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSARMOUR_H
