#ifndef ELDERSWEAPON_H
#define ELDERSWEAPON_H

#include "eldersinventory.h"

class EldersWeapon : public EldersInventory
{
    QString name;
public:
    EldersWeapon(int, int, int, QString, EldersMap *);
    virtual bool move(EldersMap *);
};

#endif // ELDERSWEAPON_H
