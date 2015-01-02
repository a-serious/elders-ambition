#ifndef ELDERSOPERATION_H
#define ELDERSOPERATION_H

#include "eldersoperand.h"

class EldersOperation : public EldersOperand
{

public:
    QString mOperator;
    EldersOperand *operand[2];
    EldersOperation(EldersOperand *, EldersOperand *, QString);
    EldersOperation(EldersOperand *, QString);
    virtual EldersVarient getValue(EldersMap *);
};

#endif // ELDERSOPERATION_H
