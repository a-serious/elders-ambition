#ifndef ELDERSASSIGNMENT_H
#define ELDERSASSIGNMENT_H

#include "eldersexpression.h"
#include "eldersreference.h"
#include "eldersoperand.h"

class EldersAssignment : public EldersExpression
{

public:
    EldersOperand *operand;
    EldersAssignment(EldersOperand *);
    virtual void run(EldersMap *);
};

#endif // ELDERSASSIGNMENT_H
