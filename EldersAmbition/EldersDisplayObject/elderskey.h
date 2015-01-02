#ifndef ELDERSKEY_H
#define ELDERSKEY_H

#include "eldersinventory.h"

class EldersKey : public EldersInventory
{
    int color;

protected:
    virtual QString getLabel();

public:
    EldersKey(int, int, int, EldersMap *, int);
    virtual bool move(EldersMap *);

    static const int yellow, blue, red, silver;
};

#endif // ELDERSKEY_H
