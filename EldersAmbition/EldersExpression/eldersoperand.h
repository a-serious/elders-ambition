#ifndef ELDERSOPERAND_H
#define ELDERSOPERAND_H

#include "eldersvarient.h"
#include "../eldersmap.h"

class EldersOperand
{
    EldersVarient *value;
public:
    EldersOperand();
    EldersOperand(EldersVarient);

    virtual EldersVarient getValue(EldersMap *);
};

#endif // ELDERSOPERAND_H
